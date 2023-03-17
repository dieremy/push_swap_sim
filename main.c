/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:27 by startagl          #+#    #+#             */
/*   Updated: 2023/03/17 16:52:23 by startagl         ###   ########.fr       */
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
			!DA CONTROLLARE SE I NUMERI VANNO DA -500 A +500 (COSI MI HANNO DETTO)

		- Crea le funzioni che si occupano delle operazioni (SA, SA, SS, RA, RB, RR, RRA, RRB, RRR), le funzioni verranno eseguite quando vengono chiamate da terminale.
		- Testa le funzioni con numeri casuali.
		- Capisci quale algoritmo conviene utilizzare. (turk algorithm or LIS algorithm)
*/
int	main(int ac, char **av)
{
	char	*test_char;
	char	**strings;
	int		i;

	i = -1;
	test_char = av[2];
	ft_printf("Numero argomenti:\t%d\n", ac);
	ft_printf("Valore argomento 2 da var:\t%s\n", test_char);
	strings = ft_split(test_char, 32);
	while (strings[++i])
		ft_printf("prima stringa:\t%s\n", strings[i]);
	i = -1;
	while (strings[++i])
		free(strings[i]);
	free(strings);
	return (0);
}
