/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:19:14 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/15 17:45:35 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		spot;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			spot = str[i] / 16;
			write(1, &base[spot], 1);
			spot = str[i] % 16;
			write(1, &base[spot], 1);
		}
		i++;
	}
}
