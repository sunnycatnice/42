/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:50:17 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 13:33:40 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s1);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);


#endif