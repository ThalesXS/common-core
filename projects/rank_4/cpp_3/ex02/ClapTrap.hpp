/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:34 by txisto-d          #+#    #+#             */
/*   Updated: 2024/08/24 09:54:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum    clapAtt
{
    HP,
    EP,
    ATK
};

class ClapTrap
{
    protected:
        std::string     name;
        int    hitPoints;
        int    energyPoints;
        int    attackDamage;
    public:
        ClapTrap(std::string name = "CL4P_TP");
        virtual ~ClapTrap();
        ClapTrap(ClapTrap& CL4P_TP);
        ClapTrap &operator=(const ClapTrap& CL4P_TP);

        void            attack(const std::string& target);
        void            takeDamage(int amount);
        void            beRepaired(int amount);
        void            setAttribute(int value, clapAtt att);
        int             getAttribute(clapAtt att);
};

#endif