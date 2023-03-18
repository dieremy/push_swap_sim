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

/*
	* PSEUDOCODE
		- Per girare il visualizer (di default sta sul Turk Alghoritm) dare i comandi:
		> pip3 install push_swap_gui
		> python3 -m push_swap_gui
		- Imposta un ambiente di lavoro funzionante (Makefile).
		- Acquisisci numeri e mettili in una stack.
			- Da gestire se nella stringa passo tra le virgolette piu numeri, deve considerarli tali (prendi le stringhe separate con split).
			- Prendi con ATOI i numeri, e buttali dentro lo stack A.
			! SE SONO TUTTI NUMERI FACCIO PER OGNUNO ATOI E LI METTO IN UN ARRAY CHE SAREBBE LA MIA PILA A
			! INFILATI NELLA PILA CONTROLLO SE CI SONO DOPPIONI E CHE SIANO NEL RANGE INTERI (-2147483648 e 2147483647)

		- Crea le funzioni che si occupano delle operazioni (SA, SA, SS, RA, RB, RR, RRA, RRB, RRR), le funzioni verranno eseguite quando vengono chiamate da terminale.
		- Testa le funzioni con numeri casuali.
		- Capisci quale algoritmo conviene utilizzare. (turk algorithm or LIS algorithm)
*/

t_data	*initialize_val(t_data *data, int counter)
{
	data->a = malloc(counter * sizeof(int));
	data->b = malloc(counter * sizeof(int));
	data->len_a = counter;
	ft_printf("LEN A: %d\n", data->len_a);
	data->len_b = 0;
	return (data);
}

void	ft_free_data(t_data *data)
{
	// int i;
	free(data->a);
	free(data->b);
	// i = 0;
	// while (i < data->len_a)
	// {
		// free(data->a);
	// }
	
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

void	free_mat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_fill_a(t_data *data, char **av)
{
	int		j;
	int		i;
	int		k;
	char	**value_to_split;
	
	k = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		value_to_split = ft_split(av[j], 32);
		while (value_to_split[i])
			i++;
		ft_printf("Numero di valori del parametro inserito: %d\n", i);
		if (i > 1)
		{
			i = 0;
			while (value_to_split[i])
			{
				data->a[k] = ft_atoi(value_to_split[i]);
				free(value_to_split[i]);
				k++;
				i++;
			}
			free(value_to_split);
		}
		else
		{
			data->a[k] = ft_atoi(value_to_split[0]);
			free(value_to_split[0]);
			k++;
		}
		j++;
	}
	// free(value_to_split[i]);
	// free(value_to_split);
	// free_mat(value_to_split);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	**value_to_split;
	int		i;
	int		j;
	int		k;
	int		counter;

	counter = 0;
	k = 0;
	// i = 0;
	j = 1;
	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		counter = get_input_num(av);
		data = initialize_val(data, counter);
		// ft_fill_a(data, av);
		while (av[j])
		{
			i = 0;
			value_to_split = ft_split(av[j], 32);
			while (value_to_split[i])
			{
				i++;
				free(value_to_split[i]);
			}
			// free(value_to_split[i]);
			free(value_to_split);			
			ft_printf("Numero di valori del parametro inserito: %d\n", i);
			if (i > 1)
			{
				i = 0;
				value_to_split = ft_split(av[j], 32);
				while (value_to_split[i])
				{
					data->a[k] = ft_atoi(value_to_split[i]);
					ft_printf("VAL MULTI PAR: %d\n", data->a[k]);
					free(value_to_split[i]);
					i++;
					k++;
				}
				free(value_to_split[i]);
				// free(value_to_split);
			}
			else
			{
				value_to_split = ft_split(av[j], 32);
				// ft_printf("VAL UNI PAR: %s\n", value_to_split[0]);
				data->a[k] = ft_atoi(value_to_split[0]);
				ft_printf("VAL UNI PAR: %d\n", data->a[k]);
				free(value_to_split[0]);
				k++;
				free(value_to_split);
			}
			j++;
		}
		// free(value_to_split[i]);
		// free(value_to_split);
	}
	else
	{
		ft_printf("Few arguments:\n");
		return (0);
	}
	ft_print_stack_A(data);
	ft_free_data(data);
	free(data);
	ft_printf("Non é stato passato alcun parametro:\n");
	return (0);
}
