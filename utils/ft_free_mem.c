/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:27:35 by startagl          #+#    #+#             */
/*   Updated: 2023/03/18 15:46:36 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_free_mem(char **matrix, int f)
{
	int	i;

	i = -1;
	if (f == 1)
	{
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
		write(2, "Errore\n", 6);
		exit(1);
	}
	else if (f == 2)
	{
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
		return (1);
	}
	else if (f == 0)
	{
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
		ft_printf("TUTTO OK:\n");
		exit(0);
	}
	return (0);
}