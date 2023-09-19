/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:02:46 by hichokri          #+#    #+#             */
/*   Updated: 2023/09/18 18:58:07 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unitd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	check_exist(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] == c)
	{
		return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (check_base(base) != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (check_exist(str[i], base) && str[i] != '\0')
		{
			res *= len;
			res += base[check_exist(str[i], base)];
			i++;
		}
	}
	return (sign * res);
}
