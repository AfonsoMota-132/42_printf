/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:00:56 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/27 12:11:09 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	average(int num, ...);

int	main()
{
	printf("%i", average(2, 100, 1));;
}

int	average(int num, ...)
{
	va_list	valist;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	va_start(valist, num);
	while (va_arg(va)
	{
		sum += va_arg(valist, int);
		i++;
	}
	va_end(valist);
	return (sum/3);
}
