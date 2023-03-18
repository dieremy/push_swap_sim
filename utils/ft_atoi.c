/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:18:13 by startagl          #+#    #+#             */
/*   Updated: 2023/03/18 12:31:29 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	whitespaces(char *str, int *ptr_i)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43)
	{
		i++;
		*ptr_i = i;
		return (1);
	}
	else if (str[i] == 45)
	{
		i++;
		*ptr_i = i;
		return (-1);
	}
	else if (!(str[i] >= 48 && str[i] <= 57))
	{
		*ptr_i = i;
		return (0);
	}
	*ptr_i = i;
	return (1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = whitespaces(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	// free(str);
	return (result);
}