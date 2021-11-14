/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:19:14 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/14 16:51:58 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	write_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &c, 1);
		else
		{
			write_hex(c);
		}
		i++;
	}
}

void	write_hex(char c)
{
	char	to_print;

	write(1, "\\", 1);
	to_print = c / 16 + '0';
	if (to_print > '9')
		to_print += 'a' - '0' - 10;
	write(1, &to_print, 1);
	to_print = c % 16 + '0';
	if (to_print > '9')
		to_print += 'a' - '0' - 10;
	write(1, &to_print, 1);
}
