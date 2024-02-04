/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 06:56:19 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/10 07:04:52 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str	*array;

	if (ac > 1)
	{
		array = ft_strs_to_tab(ac - 1, &av[1]);
		ft_show_tab(array);
	}
	return (0);
}
