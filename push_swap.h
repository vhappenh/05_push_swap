/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/17 14:51:29 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# define PUSH_SWAP_H

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

char	**ft_input_prepare(char **input);
int		ft_input_check(char **input);
int		ft_isdigit(int c);
int		ft_check_for_doubles(char **input);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_inputs(char *dest, char **src);
char	**ft_split(char const *s, char c);
int		ft_free_pushswap(t_list *a_stack, char **input);

int		ft_strlen_pushswap(char **input);
int		ft_input_to_list(t_list **a_stack, int argc, char **argv);
t_list	*ft_lstnew_pushswap(long content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_sort_index(char **index, int max, t_list **a_stack);
long	ft_atoi_long(const char *nptr);
void	ft_lst_index(char **index, int max, t_list **a_stack);

void	ft_push_swap(t_list **a_stack, t_list **b_stack, int length);
void	sa(t_list **a_stack);
void	pa(t_list **a_stack, t_list **b_stack);
void	pb(t_list **a_stack, t_list **b_stack);
void	ra(t_list **a_stack);
void	rra(t_list **a_stack);
int		ft_stack_sorted(t_list *a_stack, t_list *b_stack);
int		ft_lstsize(t_list *lst);

#endif
