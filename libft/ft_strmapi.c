/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:07:46 by gusalves          #+#    #+#             */
/*   Updated: 2021/08/14 19:27:01 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*str;

	str = ft_strdup(s);
	if(str == 0)
		return (0);
	index = 0;
	if (!s)
		return (0);
	while (str[index])
	{
		str[index] = f(index, str[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}