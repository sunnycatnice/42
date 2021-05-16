/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:51 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/16 16:21:52 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_all *all, t_stack *a)
{
	int y;
	int temp;

	y = 0;
	temp = a->nbrs[y];
	while (y < all->size)
	{
		a->nbrs[y] = a->nbrs[y+1];
		y++;
	}
	a->nbrs[y-1] = temp;
	//printf("ra\n");
	all->moves++;
}

void	ft_rotate_rev(t_all *all, t_stack *a)
{
	int y;
	int temp;

	y = all->size - 1;
	temp = a->nbrs[y];
	while (y > 0)
	{
		a->nbrs[y] = a->nbrs[y-1];
		y--;
	}
	a->nbrs[y] = temp;
	//printf("ra\n");
	all->moves++;
}
