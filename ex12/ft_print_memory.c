/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:20:18 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/15 17:40:28 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	print_hex_addr(void *addr, unsigned int i);
void	print_hex_data(void *addr, unsigned int i, unsigned int size);
void	print_rbl_data(void *addr, unsigned int i, unsigned int size);
void	print_dec_to_hex(int nbr, int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i_addr;

	i_addr = 0;
	while (i_addr < size)
	{
		print_hex_addr(addr, i_addr);
		write(1, ": ", 2);
		print_hex_data(addr, i_addr, size);
		print_rbl_data(addr, i_addr, size);
		i_addr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

void	print_hex_addr(void *addr, unsigned int i)
{
	int	dec_addr;

	dec_addr = (int)&addr[i];
	print_dec_to_hex(dec_addr, 16);
}

void	print_hex_data(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && ((char *)addr)[i + j] && i + j < size)
	{
		print_dec_to_hex(((char *)addr)[i + j], 2);
		if(j % 2)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, " ", 1);
		if (i % 2)
			write(1, " ", 1);
		j++;
	}
}

void	print_rbl_data(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && ((char *)addr)[i + j] && i + j < size)
	{
		if (((char *)addr)[i + j] >= ' ' && ((char *)addr)[i + j])
			write(1, &((char *)addr)[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	print_dec_to_hex(int nbr, int size)
{
	char *base;

	base = "0123456789abcdef";
	if (size > 0)
	{
		print_dec_to_hex(nbr / 16, size - 1);
		write(1, &base[nbr % 16], 1);
	}
}
