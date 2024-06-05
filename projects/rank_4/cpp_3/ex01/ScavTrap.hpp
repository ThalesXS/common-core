/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:28:42 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:13:06 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name = "SC4V_TP");
        ~ScavTrap();
        ScavTrap(ScavTrap& SC4V_TP);
        ScavTrap &operator=(const ScavTrap& SC4V_TP);

        void    guardGate();
};


#endif