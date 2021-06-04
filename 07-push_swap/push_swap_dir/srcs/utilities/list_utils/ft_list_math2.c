/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_math2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:51:21 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:51:22 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*ft_nearest_next_in_stack(t_numbers *stack, int position)
{
	t_numbers	*min_position;
	int			next_nu;
	t_numbers	*curr_nu;

	curr_nu = stack;
	min_position = 0;
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position > position)
		{
			min_position = curr_nu;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while (curr_nu)
	{
		if (curr_nu->position > position && \
		curr_nu->position < min_position->position)
			min_position = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (min_position);
}

t_numbers	*ft_nearest_prev_in_stack(t_numbers *stack, int position)
{
	t_numbers	*max_position;
	int			next_nu;
	t_numbers	*curr_nu;

	curr_nu = stack;
	max_position = ft_max_node_in_stack(stack);
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position < position)
		{
			max_position = curr_nu;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while (curr_nu)
	{
		if (curr_nu->position < position && \
		curr_nu->position > max_position->position)
			max_position = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (max_position);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
