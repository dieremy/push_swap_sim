/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:10:04 by startagl          #+#    #+#             */
/*   Updated: 2023/03/18 15:27:41 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./utils/ft_printf/ft_printf.h"

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}				t_data;

void	ft_print_error(void);
char	**ft_split(char const *s, char c);
int		ft_free_mem(char **matrix, int f);
int		ft_atoi(char *str);
int		ft_isdigit(int c);

#endif