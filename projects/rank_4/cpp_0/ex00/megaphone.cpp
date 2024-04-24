/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:40:12 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/24 21:30:43 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	megaphone(std::string str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *")
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
			std::cout << megaphone(argv[i]);
		std::cout << std::endl;
	}
	else
		std::cout << megaphone() << std::endl;
	return (0);
}