/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:00:14 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/14 16:49:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		is_upper(char *str, int i);
int		is_lower(char *str, int i);
int		is_begin(char *str, int i);
int		is_alpha_num(char *str, int i);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lower(str, i) && is_begin(str, i))
			str[i] += 'A' - 'a';
		else if (is_upper(str, i) && !is_begin(str, i))
			str[i] -= 'A' - 'a';
		i++;
	}
	return (str);
}

int	is_upper(char *str, int i)
{
	return (str[i] >= 'A' && str[i] <= 'Z');
}

int	is_lower(char *str, int i)
{
	return (str[i] >= 'a' && str[i] <= 'z');
}

int	is_begin(char *str, int i)
{
	if (i == 0)
		return (1);
	else
		return (!is_alpha_num(str, i - 1));
}

int	is_alpha_num(char *str, int i)
{
	return ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9'));
}
