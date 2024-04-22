/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:51 by anon              #+#    #+#             */
/*   Updated: 2024/01/25 17:03:26 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put(unsigned int num, t_arg *a);
static int	ft_wid(unsigned int num, t_arg *a);

void	ft_hxu(va_list args, t_arg *a)
{
	unsigned int	hex;
	int				len;
	char			*is_neg;

	hex = va_arg(args, unsigned int);
	len = 0;
	is_neg = ft_strchr(a->flg, '-');
	if (!is_neg)
		len += ft_wid(hex, a);
	len += ft_put(hex, a);
	if (is_neg)
		len += ft_wid(hex, a);
	a->len = len;
}

static int	ft_put(unsigned int hex, t_arg *a)
{
	int	len;
	int	num_len;
	int	zeros;
	int	sig_len;

	len = 0;
	zeros = 0;
	num_len = ft_nbrlen(hex, 16);
	sig_len = 0;
	if (ft_strchr(a->flg, '#'))
	{
		if (hex != 0)
			len += write(1, "0X", 2);
		sig_len += 2;
	}
	if (ft_strchr(a->flg, '.'))
		while (a->prc > num_len + zeros)
			zeros += write(1, "0", 1);
	else if (ft_strchr(a->flg, '0') && !ft_strchr(a->flg, '-'))
		while (a->wid > num_len + sig_len + zeros)
			zeros += write(1, "0", 1);
	if (!(ft_strchr(a->flg, '.') && hex == 0 && a->prc == 0))
		len += ft_based(hex, UHX);
	return (len + zeros);
}

static int	ft_wid(unsigned int hex, t_arg *a)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(hex, 16);
	if (ft_strchr(a->flg, '.') && num_len < a->prc)
		num_len = a->prc;
	if (ft_strchr(a->flg, '.') && a->prc == 0 && hex == 0)
		num_len = 0;
	if (!ft_strchr(a->flg, '0')
		|| ft_strchr(a->flg, '-') || ft_strchr(a->flg, '.'))
		while (a->wid > num_len + len)
			len += write(1, " ", 1);
	return (len);
}
