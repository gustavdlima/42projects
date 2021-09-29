/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:41:47 by gusalves          #+#    #+#             */
/*   Updated: 2021/09/29 18:01:32 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	list;
	size_t	i;	
	int		num_of_char;

	if(!format)
		return (NULL);
	i = 0;
	num_of_char = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			num_of_char = find_type(format, list);
		}
		else
		{
			num_of_char += 1;
			write(1, &format[i],i);
		}
	}
	va_end(list); 
	return (num_of_char);
}
