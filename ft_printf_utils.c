/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:45:55 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/27 13:48:05 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printfstr(char *str)
{
	int i;

	i = 0;
	ft_putstr_fd(str, 1);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		len += 2;
		n = 147483648;
	}
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_printfnbr(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_nbrlen(nbr));
}

int	ft_printfunbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_printfunbr(nbr / 10);
		len += ft_printfnbr(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	return (len + 1);
}

int	ft_printhex(unsigned int nbr, int uporlow)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_printhex((nbr / 16), uporlow);
		len +=  ft_printhex((nbr % 16), uporlow);
	}
	if (nbr < 16 && uporlow == 0)
		write(1, &"0123456789abcdef"[nbr], 1);	
	else if (nbr < 16 && uporlow == 1)
		write(1, &"0123456789ABCDEF"[nbr], 1);	
	return (len + 1);
}

int	ft_printpoint(unsigned int pointer)
{
	int	len;

	len = 0;
	if (!pointer)
		return(ft_printfstr("(nil)"));
	else
		len += ft_printfstr("0x");
	len += ft_printhex((unsigned long) pointer, 0);
	return (len);
}
