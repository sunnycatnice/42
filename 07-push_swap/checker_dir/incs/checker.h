/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:32:10 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:32:13 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define V_CHARSET "0123456789+- "
# define V_DIGITS "0123456789"
# define V_SYMBOLS "+-"
# define NODOUBLES ""
# define BUFFER_SIZE 1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_numbers
{
	long				number;
	struct s_numbers	*next;
	struct s_numbers	*prev;
	int					position;
}	t_numbers;

int			ft_isdigit(char c);
int			ft_isvalidchar(char c);
int			ft_validarg(char *str);
int			ft_issymbol(char c);
long		ft_atoi(char *str);
void		*ft_calloc(long count, long size);
t_numbers	*ft_new_node(long nu, t_numbers *prev);
void		ft_lst_add(long nu, t_numbers **head);
void		ft_split_nu(t_numbers **head, char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		ft_freelist(t_numbers *head);
int			ft_checkdoubles(t_numbers *head);
int			ft_isordered(t_numbers *head);
void		ft_swap(t_numbers **head);
void		ft_do_move(t_numbers **stack_a, t_numbers **stack_b, char *move);
void		ft_push(t_numbers **dest, t_numbers **src);
void		ft_rotate(t_numbers **stack);
void		ft_reverse_rotate(t_numbers **stack);
size_t		ft_strlen(const char *str);
int			ft_iscinstr(char c, char const *str, size_t len);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);
int			ft_strcmp_wo_n(char *str1, char *str2);
void		ft_copynu(t_numbers *dest, t_numbers *src);
t_numbers	*ft_last_elem(t_numbers *list);
void		ft_fill_stack_a(char **argv, t_numbers **stack_a);
void		ft_print_list(t_numbers *head);

#endif
