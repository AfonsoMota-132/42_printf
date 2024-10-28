/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:12:34 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/27 12:25:05 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	args_type(va_list args, char var_type)
{
	if (var_type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (var_type == 's')
		return (ft_printfstr(va_arg(args, char *)));
	else if (var_type == 'p')
		return (ft_printpoint(va_arg(args, unsigned int)));
	else if (var_type == 'd' || var_type == 'i')
		return (ft_printfnbr(va_arg(args, int)));
	else if (var_type == 'u')
		return (ft_printfunbr(va_arg(args, unsigned int)));
	else if (var_type == 'x')
		return (ft_printhex(va_arg(args, unsigned int), 0));
	else if (var_type == 'X')
		return (ft_printhex(va_arg(args, unsigned int), 1));
	else if (var_type == '%')
		ft_putchar_fd('%', 1);
	if (var_type == 'c' || var_type == '%')
		return (1);
	return (0);
}
int	ft_printf(const char *strs, ...)
{
	int			i;
	va_list		args;
	int			len;

	va_start(args, strs);
	i = 0;
	len = 0;
	while (strs[i])
	{
		if (strs[i] != '%')
		{
			ft_putchar_fd(strs[i], 1);
			len++;
		}
		else
		{
			len	+= args_type(args, strs[++i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main(void)
{
	//ft_printf("my onw printf(c): %c\n", 'a');
	//ft_printf("my onw printf(s): %s\n", "abcdef");
	printf("original printf(p): %p\n", &("abcdef"));
	ft_printf("my own printf(p): %p\n", &("abcdef"));
	ft_printf("my onw printf(d): %d\n", -123456789);
	ft_printf("my onw printf(i): %i\n", 123456789);
	ft_printf("my onw printf(u): %u\n", 123456789);
	ft_printf("my onw printf(x): %x\n", 123456789);
	ft_printf("my onw printf(X): %X\n", 123456789);
	ft_printf("my onw printf(%%): %%\n", 123456789);
}*/
