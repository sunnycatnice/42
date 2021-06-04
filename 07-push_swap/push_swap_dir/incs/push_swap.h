/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:37:02 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:37:04 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
# define PA 1
# define RA 2
# define RRA 3
# define SA 4
# define PB 5
# define RB 6
# define RRB 7
# define SB 8
# define RR 9
# define RRR 10
# define SS 11
# define TOGETHER 0
# define JUST_A 1
# define JUST_B 2
# define TOTAL_M 3
# define SEQ_RA 0
# define SEQ_RRA 1
# define SEQ_RB 2
# define SEQ_RRB 3
# define SEQ_RR 4
# define SEQ_RRR 5
# define MIN_PREV_H 1
# define MIN_NEXT_B 2

typedef struct s_distances
{
	int			r;
	int			rr;
	int			num;
}				t_distances;

typedef struct s_numbers
{
	long				number;
	struct s_numbers	*next;
	struct s_numbers	*prev;
	int					position;
	int					min_combi_moves;
	t_distances			dist_head;
	t_distances			dist_in_next_prev_h;
	t_distances			dist_in_next_next_b;
}	t_numbers;

typedef struct s_move
{
	int				operations;
	int				pos_of_nu;
	int				move_num;
	char			*move;
	struct s_move	*next;
}	t_move;

typedef struct s_near_positions
{
	int			next;
	int			prev;
}				t_near_positions;

typedef struct s_combined
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
}				t_combined;

typedef struct s_heads
{
	t_numbers	*head_a;
	t_numbers	*head_b;
}				t_heads;

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
int			ft_list_len(t_numbers *stack);
void		ft_indicize_list(t_numbers *stack);
int			ft_is_consequent_ordered(t_numbers *stack);
int			ft_is_consequent_ordered_rev(t_numbers *stack);
t_numbers	*ft_min_node(t_numbers *stack);
t_numbers	*ft_succ_node(t_numbers *stack, t_numbers *rel_prev);
int			ft_node_pos(t_numbers *stack, t_numbers *node);
t_numbers	*ft_node_with_pos(t_numbers *stack, int pos);
int			ft_max_pos_in_stack(t_numbers *stack);
int			ft_min_near_nu(t_numbers **stack_a, int medium);
char		*ft_convenient_rotation_a(t_numbers *stack, t_numbers *node);
char		*ft_convenient_rotation_b(t_numbers *stack, t_numbers *node);
char		*ft_convenient_rotation(t_numbers *stack, t_numbers *node);
void		ft_do_convenient_rot_to_top_a(t_numbers **stack, int pos);
void		ft_sort_three_a(t_numbers **stack_a);
void		ft_sort_five_a(t_numbers **stack_a, t_numbers **stack_b);
int			ft_max_near_nu(t_numbers **stack_a, int medium);
int			ft_min_pos_in_stack(t_numbers *stack);
int			ft_max_pos_in_stack(t_numbers *stack);
int			ft_median(t_numbers *stack);
t_numbers	*ft_nearest_next_in_stack(t_numbers *stack, int position);
t_numbers	*ft_nearest_prev_in_stack(t_numbers *stack, int position);
t_numbers	*ft_max_node_in_stack(t_numbers *stack);
void		ft_max_on_head_b(t_numbers **stack_b);
void		ft_clean_combi(int *combi);
void		ft_module_sub(int a, int b, int *res, int *rem);
int			ft_whitch_rem(int a, int b);
void		ft_combi_sum(int *combi);
int			ft_find_min(int	rrr_tot, int rr_tot, int rarrb, int rrarb);
int			ft_is_dist(t_distances *dist);
int			ft_min(int a, int b);
t_distances	*ft_ideal_move_target(t_numbers *node);
void		ft_do_min_comb(t_distances *dist_a, t_distances *dist_b, \
t_numbers **stack_a, t_numbers **stack_b);
t_numbers	*min_moves_node(t_numbers *stack);
void		ft_node_distances_from_head(t_numbers *node, \
t_distances *distances);
void		ft_set_distances_in_stack(t_numbers *stack, t_numbers *dest_stack);
void		ft_min_moves(t_numbers *head, t_numbers **stack_a, \
t_numbers **stack_b);
void		ft_min_on_head(t_numbers **stack_a);
t_numbers	*ft_first_elem(t_numbers *node);
void		ft_dist_clear(t_distances *dist);
int			ft_ideal_move_len(t_numbers *node);
void		ft_sort_more(t_numbers **stack_a, t_numbers **stack_b);
void		ft_clean_distances(t_distances *dist);

#endif
