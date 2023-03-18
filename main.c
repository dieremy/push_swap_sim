/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:27 by startagl          #+#    #+#             */
/*   Updated: 2023/03/18 18:04:47 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_val(t_data *data, int counter)
{
	data->a = malloc(counter * sizeof(int));
	data->b = malloc(counter * sizeof(int));
	data->len_a = counter;
	data->len_b = 0;
}

void	ft_free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_is_valid_num(char **av, int j)
{
	int		z;

	z = 0;
	while (av[j][z])
	{
		if (((av[j][z] == '-') && (!ft_isdigit(av[j][z + 1])))
		|| ((av[j][z] == '+') && (!ft_isdigit(av[j][z + 1]))))
			ft_print_error();
		if ((ft_isdigit(av[j][z])) || (av[j][z] == 32)
			|| (av[j][z] == '-') || (av[j][z] == '+'))
			z++;
		else
			ft_print_error();
	}
}

void	ft_print_stack_A(t_data	*data)
{
	int	i;

	i = 0;
	printf("\n\t####### STACK A #######\n");
	while (i < data->len_a)
		ft_printf("\t\t%d\n", data->a[i++]);
}

void	ft_print_stack_B(t_data	*data)
{
	int	i;

	i = 0;
	printf("\n\t####### STACK B #######\n");
	while (i < data->len_b)
		ft_printf("\t\t%d\n", data->b[i++]);
}

int	get_input_num(char **av)
{
	char	**value_to_split;
	int		j;
	int		i;
	int		counter;

	counter = 0;
	j = 0;
	while (av[++j])
	{
		ft_is_valid_num(av, j);
		i = 0;
		value_to_split = ft_split(av[j], 32);
		while (value_to_split[i])
			i++;
		if (i == 0)
			exit(1);
		if (i == 1)
			counter++;
		else if (i > 1)
			counter += i;
		ft_free_mem(value_to_split, 2);
	}
	return (counter);
}

t_data	*ft_fill_a(t_data *data, char **av)
{
	char	**value_to_split;
	int		j;
	int		i;
	int		k;
	
	k = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		value_to_split = ft_split(av[j], 32);
		while (value_to_split[i])
			i++;
		if (i > 1)
		{
			i = 0;
			while (value_to_split[i])
				data->a[k++] = ft_atoi(value_to_split[i++]);
		}
		else
			data->a[k++] = ft_atoi(value_to_split[0]);
		j++;
	}
	free(value_to_split);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		counter;

	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		counter = get_input_num(av);
		initialize_val(data, counter);
		data = ft_fill_a(data, av);
	}
	else
		return (0);
	ft_printf("LEN A: %d\n", data->len_a);
	ft_print_stack_A(data);
	ft_free_data(data);
	return (0);
}
