/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:16 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/30 12:16:57 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printhex(unsigned int nbr, int uporlow)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_printhex((nbr / 16), uporlow);
		len += ft_printhex((nbr % 16), uporlow);
	}
	if (nbr < 16 && uporlow == 0)
		write(1, &"0123456789abcdef"[nbr], 1);
	else if (nbr < 16 && uporlow == 1)
		write(1, &"0123456789ABCDEF"[nbr], 1);
	return (len + 1);
}
