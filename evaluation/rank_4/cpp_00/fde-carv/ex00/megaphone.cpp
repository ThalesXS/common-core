/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:08:59 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/02 09:45:57 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // --> std::toupper
#include <cctype> // --> std::cout, std::endl

void megaphone(char *str)
{
    for(int i = 0; str[i]; i++)
    {
        std::cout << (char)std::toupper(str[i]);
    } 
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; av[i]; i++)
        {
            megaphone(av[i]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return 0;
}
