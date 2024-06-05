/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:40:19 by txisto-d          #+#    #+#             */
/*   Updated: 2024/05/21 13:42:45 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name = "FR4G_TP");
        ~FragTrap();
        FragTrap(FragTrap& FR4G_TP);
        FragTrap &operator=(const FragTrap& FR4G_TP);

        void    highFivesGuys(void);
};

#endif