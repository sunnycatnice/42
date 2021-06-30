/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:40 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 17:01:41 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	minmax(int *i, int *a, int *min, int *max)
{
	while (i[1] < i[0])
	{
		if (a[i[1]] < min[0])
			min[0] = a[i[1]];
		if (a[i[1]] > max[0])
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = a[i[1]];
		}
		if (a[i[1]] < max[0] && a[i[1]] > max[1])
		{
			max[2] = max[1];
			max[1] = a[i[1]];
		}
		if (a[i[1]] < max[1] && a[i[1]] > max[2])
			max[2] = a[i[1]];
		i[1]++;
	}
}

static void	ra_or_rra1(int *a, int *b, int *n, int *i)
{
	if (i[0] < (n[1] - n[0]) / 2)
	{
		while (i[0] > 0)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
			i[0]--;
		}
	}
	else
	{
		while (i[0] < (n[1] - n[0]))
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			i[0]++;
		}
	}
	pb_asort(a, b, n);
}

static void	findx(int *min, int *max, int *x, int *i)
{
	x[0] = max[0] - min[0];
	if (i[1] <= 100)
		x[1] = 5;
	else if (i[1] <= 200)
		x[1] = 6;
	else if (i[1] <= 300)
		x[1] = 7;
	else if (i[1] <= 400)
		x[1] = 8;
	else
		x[1] = 11;
	x[0] = x[0] / x[1];
	min[1] = min[0];
}

static void	to_ra_or_rra(int *i, int *a, int *b, int *n)
{
	int		loop;

	loop = 0;
	while (loop != 1)
	{
		i[0] = 0;
		while (a[i[0]] > i[2] && i[0] < (n[1] - n[0]))
			i[0]++;
		if (i[0] == (n[1] - n[0]) || n[0] == n[1] - 3)
			loop = 1;
		else
			ra_or_rra1(a, b, n, i);
	}
}

void	ft_oversix(int *a, int *b, int *n)
{
	int		i[3];
	int		x[2];
	int		min[2];
	int		max[3];

	if (!checka(a, n[1]))
	{
		min[0] = a[0];
		max[0] = -2147483648;
		i[1] = 0;
		i[0] = n[1];
		minmax(i, a, min, max);
		findx(min, max, x, i);
		while (min[1] <= min[0] + (x[0] * x[1]))
		{
			i[0] = 0;
			i[1] = (n[1] - n[0]) - 1;
			min[1] = min[1] + x[0];
			ex(min, max, i);
			to_ra_or_rra(i, a, b, n);
			if (n[0] == n[1] - 3)
				min[1] = max[0] + x[0];
		}
		passb(a, b, n);
	}
}
