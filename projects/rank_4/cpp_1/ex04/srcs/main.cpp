/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:03:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 04:02:54 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int	open_file(int argc, char **argv, std::ifstream &file)
{
	if (argc != 4)
	{
		std::cout << "<filename> <s1> <s2> to change all strings corresponding to <s1> into <s2>";
		return (0);
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "error: " << argv[1] << " is not a valid file or path";
		return (0);
	}
	return (1);
}

void	replace_line(std::string line, std::ofstream &out_file, std::string s1, std::string s2)
{
	std::string		replaced;

	while (!line.empty())
	{
		out_file << line.substr(0, line.find(s1));
		if (line.find(s1) != line.npos)
		{
			out_file << s2;
			line = line.substr(line.find(s1) + s1.length());
		}
		else
			line = "";
	}
	out_file << std::endl;
}

void	replace_file(std::ofstream &out_file, std::ifstream &in_file, char **argv)
{
	std::string	line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	while (getline(in_file, line))
		replace_line(line, out_file, s1, s2);
	in_file.close();
	out_file.close();
}

int	main(int argc, char **argv)
{
	std::ifstream		in_file;
	std::ofstream		out_file;
	std::stringstream	ss;
	std::string			filename;

	if (!open_file(argc, argv, in_file))
		return (1);
	ss << argv[1];
	filename = ss.str();
	filename.append(".replace");
	out_file.open(filename.c_str());
	if (!out_file.is_open())
	{
		std::cout << "error: " << argv[1] << ".replace" << " is not a valid file or path";
		in_file.close();
		return (1);
	}
	replace_file(out_file, in_file, argv);
	return (0);
}