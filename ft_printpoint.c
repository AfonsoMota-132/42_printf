/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:18:32 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/30 12:18:52 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printpoint(unsigned int pointer)
{
	int	len;

	len = 0;
	if (!pointer)
		return (ft_printfstr("(nil)"));
	else
		len += ft_printfstr("0x");
	len += ft_printhex((unsigned long) pointer, 0);
	return (len);
}
