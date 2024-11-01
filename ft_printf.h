/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:23:32 by afogonca          #+#    #+#             */
/*   Updated: 2024/10/27 13:39:32 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *strs, ...);
int	ft_printfstr(char *str);
int	ft_printfnbr(int nbr);
int	ft_printfunbr(unsigned int nbr);
int	ft_printfhex(unsigned int nbr, int uporlow);
int	ft_printfpointer(void *pointer);

#endif 
