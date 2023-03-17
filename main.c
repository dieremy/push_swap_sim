/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:27 by startagl          #+#    #+#             */
/*   Updated: 2023/03/17 22:56:15 by startagl         ###   ########.fr       */
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

char **get_clean_strings(char *string)
{
	// int	i;
	char	**strings;
	
	strings = ft_split(string, 32);
	// i = -1;
	// while (strings[++i])
	// 	ft_printf("prima stringa:\t%s\n", strings[i]);
	
	return (strings);
}

void	ft_free_mem(char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
		free(strings[i]);
	free(strings);
}

int	main(int ac, char **av)
{
	char	**strings_to_split;	
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	// test_char = av[2];
	ft_printf("\nNumero argomenti:\t%d\n", ac);
	// ft_printf("Valore argomento 2 da var:\t%s\n", test_char);
	// while (av[++i])
	// {
	
		
	// 	strings_to_split = get_clean_strings(av[i]);
	// 	ft_printf("stringa%d:\t%s\n",i, strings_to_split[j]);
	// 	j++;
	// }

	//! PROVARE STRADA DI FARE UNO SPLIT GIGANTE SU TUTTI I PARAMETRI IN INPUT, POI AVENDO SUDDIVISO TUTTO IN STRINGHE FARE I CONTROLLI SE SONO NUMERI, COSI FACENDO TOLGO I PARAMETRI PASSATI TRA VIRGOLETTE
	//! CICLO SU TUTTI GLI INPUT
	//! CONTROLLO SE TUTTI SONO NUMERI REGOLARI, QUINDI SE CI SONO PARAMETRI CON PIU NUMERI DENTRO LI RENDO UN UNICO NUMERO
	//! SE SONO TUTTI NUMERI FACCIO PER OGNUNO ATOI E LI METTO IN UN ARRAY CHE SAREBBE LA MIA PILA A
	//! INFILATI NELLA PILA CONTROLLO SE CI SONO DOPPIONI E CHE SIANO NEL RANGE INTERI (-2147483648 e 2147483647)
	
	while (av[++j])
	{	
		while (av[j][k])
		{
			ft_printf("%c",av[j][k]);
			k++;
		}
		ft_printf("\n");
		ft_printf("ft_split\t%s\n", ft_split(av[j], 32));
		ft_printf("atoi\t%d\n", ft_atoi(av[j]));
		

		k = 0;
	}

	
	// *check if all inputs are digit
	while (av[++j])
	{	
		while (av[j][k] == 32 )
		{
			/* code */
		}
		
		k = 0;
		while (av[j][k])
		{
			if(ft_isdigit(av[j][k]))
				k++;
			else
			{
				ft_printf("Error\n");
				return (0);
			}
		}
	}
	
	// // *check if are not duplicate
	// j = 0
	// while (av[++j])
	// {	
	// 	k = 0;
	// 	while (av[j][k])
	// 	{
	// 		if(ft_isdigit(av[j][k]))
	// 			k++;
	// 		else
	// 		{
	// 			ft_printf("Error\n");
	// 			return (0);
	// 		}
	// 	}
	// }

	
	j = 0;
	while (av[++j])
	{	
		
		ft_printf("stringaPrima:\t%s\n", av[j]);
		strings_to_split = ft_split(av[j], 32);
		ft_printf("stringaDopo:\t%s\n", strings_to_split[0]);


		while (strings_to_split[i])
		{
			// ft_printf("stringaOut:\t%s\n", strings_to_split[i]);
			i++;
		}
		ft_printf("i:\t%d\n", i);
	}
	
	// i = -1;
	// while (strings[++i])
	// 	free(strings[i]);
	// free(strings);
	return (0);
}
