void	PmergeMe::_insertVector(t_vec& main, t_vec& pend, unsigned int odd, t_vec& left, t_vec& vec, bool is_odd, int order)
{
	i_vec end;

	// --- Special case: If only one pending element, insert it directly ---
	if (pend.size() == 1)
	{
		end = std::upper_bound(main.begin(), main.end(), *pend.begin());  // Find correct position using binary search
		main.insert(end, *pend.begin());  // Insert at found position
	}
	// --- If more than one pending element, insert in Jacobsthal order ---
	else if (pend.size() > 1)
	{
		size_t jacob = 3;  // Start with J(3) since J(0), J(1), J(2) are trivial
		size_t count = 0;
		size_t idx;
		size_t decrease;

		while (!pend.empty())  // Continue until all elements are inserted
		{
			idx = this->_jacobsthal(jacob) - this->_jacobsthal(jacob - 1);  
			if (idx > pend.size())
				idx = pend.size();  // Ensure index does not exceed size

			decrease = 0;

			// --- Insert elements based on Jacobsthal numbers ---
			while (idx)
			{
				end = main.begin();
				if (this->_jacobsthal(jacob + count) - decrease <= main.size())
					end = main.begin() + this->_jacobsthal(jacob + count) - decrease;
				else
					end = main.end();

				// Find correct position using binary search
				end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));  

				// Insert the element at the correct position
				main.insert(end, *(pend.begin() + idx - 1));  
				pend.erase(pend.begin() + idx - 1);  // Remove inserted element
				
				idx--;
				decrease++;
				count++;
			}
			jacob++;  // Move to next Jacobsthal number
		}
	}

	t_vec yaslam;

	// If there was an odd element, insert it as well
	if (is_odd)
	{
		end = std::upper_bound(main.begin(), main.end(), odd);
		main.insert(end, odd);
	}

	// --- Reconstruct `vec` in sorted order ---
	for (i_vec it = main.begin(); it != main.end(); it++)
	{
		i_vec ite = std::find(vec.begin(), vec.end(), *it);
		yaslam.insert(yaslam.end(), ite - (order - 1), ite + 1);
	}
	yaslam.insert(yaslam.end(), left.begin(), left.end());
	vec = yaslam;
}




void	PmergeMe::_mergeVector(t_vec& vec)
{
	static int order = 1;  // Controls the size of merging blocks (starts with single elements)
	
	int unit_size = vec.size() / order;  // Determines the number of blocks in this recursion
	if (unit_size < 2)
		return ;  // Base case: If we reach individual elements, stop recursion

	bool is_odd = unit_size % 2 == 1;  // Check if we have an odd number of elements
	i_vec start = vec.begin();  
	i_vec end = vec.begin() + ((order * unit_size) - (is_odd * order));  // Exclude last element if odd

	// --- First for-loop: Swaps larger elements forward ---
	for (i_vec it = start; it < end; it += (order * 2))
	{
		// Compare pairs: Swap if first element is larger than second element
		if (*(it + (order - 1)) > *(it + ((order  * 2) - 1)))
		{
			for (int i = 0; i < order; i++)
			{
				std::swap(*(it + i), *(it + i + order));  // Swap entire block
			}
		}
	}

	// --- Recursive call to sort the larger elements first ---
	order *= 2;  // Double the size of merging blocks
	this->_mergeVector(vec);  // Recur on the larger elements
	order /= 2;  // Restore the order after recursion

	// --- Second for-loop: Extract sorted main sequence and pending elements ---
	t_vec			main;  // Stores the sorted sequence
	t_vec			pend;  // Stores the pending (smaller) elements
	t_vec			left;  // Stores remaining elements
	unsigned int	odd = 0;
	
	// Add the first two largest elements to the sorted main sequence
	main.push_back(*(start + order - 1));
	main.push_back(*(start + order * 2 - 1));

	// Extract elements: Alternating between sorted (main) and pending (pend)
	for (i_vec it = start + order * 2; it < end; it += order)
	{
		pend.push_back(*(it + order - 1));  // Store the pending smaller element
		it += order;  // Skip to the next larger element
		main.push_back(*(it + order - 1));  // Store the next larger element into sorted sequence
	}

	// If we had an odd number of elements, store the last remaining one
	if (is_odd)
		odd = *(end + order - 1);

	// Store remaining elements into `left`
	left.insert(left.end(), end + (order * is_odd), vec.end());

	// Insert pending elements into main using Jacobsthal order
	if (is_odd || !pend.empty())
		this->_insertVector(main, pend, odd, left, vec, is_odd, order);
}
