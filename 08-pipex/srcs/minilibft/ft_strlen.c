/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:39 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/14 15:12:41 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

size_t	ft_strlen(const char *s1)
{
	size_t	count;

	count = 0;
	while (*(s1 + count) != '\0')
		count++;
	return (count);
}