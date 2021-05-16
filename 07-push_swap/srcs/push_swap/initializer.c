/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:11 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/16 16:21:12 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init(t_all *all)
{
	all->moves = 0;
	all->size = 0;
}

// void    split_to_stack(t_all *all, char *arg)
// {
//     char    **tmp;
//     tmp = ft_split(arg, ' ');
//     all->a.nbrs = malloc((all->size(tmp)) * sizeof(int));
//     all->b.nbrs = malloc((all->size(tmp)) * sizeof(int));
//     all->a.size = all->size(tmp);
//     //check_args(a->size, tmp);
//     init_stack(tmp, all->a, 0);
//     //free_matrix(tmp);
// }

// void    ft_init_stack(char **argv, t_all *all)
// {
//     long long   i;

//     i = 0;
//     while (i < all->size)
//     {
//         all->a.nbrs[i] = atoi(argv[i]);
//         i++;
//     }
// }
