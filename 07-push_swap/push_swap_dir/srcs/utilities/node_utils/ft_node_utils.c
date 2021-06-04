/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:52:15 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:52:16 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*ft_min_node(t_numbers *stack)
{
	t_numbers	*ret;
	t_numbers	*curr_nu;

	ret = stack;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (ret->number > curr_nu->number)
		{
			ret = curr_nu;
		}
		curr_nu = curr_nu->next;
	}
	return (ret);
}

t_numbers	*ft_succ_node(t_numbers *stack, t_numbers *rel_prev)
{
	t_numbers	*ret;
	t_numbers	*curr_nu;

	curr_nu = stack;
	ret = 0;
	if (!curr_nu || !rel_prev)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->number > rel_prev->number)
		{
			if (ret)
			{
				if (curr_nu->number < ret->number)
					ret = curr_nu;
			}
			else
				ret = curr_nu;
		}
		curr_nu = curr_nu->next;
	}
	return (ret);
}

int	ft_node_pos(t_numbers *stack, t_numbers *node)
{
	int			index;
	t_numbers	*curr_pos;

	curr_pos = stack;
	index = 0;
	while (curr_pos->position != node->position)
	{
		index += 1;
		curr_pos = curr_pos->next;
	}
	return (index);
}

t_numbers	*ft_node_with_pos(t_numbers *stack, int pos)
{
	t_numbers	*curr_pos;

	curr_pos = stack;
	while (curr_pos->position != pos)
	{
		curr_pos = curr_pos->next;
	}
	return (curr_pos);
}
