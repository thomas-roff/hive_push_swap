/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 18:44:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// ARRAY UTILITIES

int	check_dup(char **array);
int	ft_arrcheck(char **array, int (f)(int));
int	ft_arraylen(char **array);

// STACK UTILITIES

int	ft_stacklen(int **stack);
int	ft_issorted(int **stack);
void	free_and_exit(int **stack_a, int **stack_b);
void	error_free_and_exit(int **stack, int len);
void	print_stack(int **stack);

// BUILD FUNCTIONS

int	**build_stack(char **array, int len);
int	**build_empty_stack(int len);

// SORT OPERATIONS

void	op_sa(int **stack);
void	op_ra(int **stack, int len);
void	op_rra(int **stack, int len);
void	op_pa(int **stack_a, int **stack_b);
void	op_pb(int **stack_a, int **stack_b);

// SMALL STACKS

void	three_stack(int **stack);
int		find_min(int **stack);
void	push_min(int **stack_a, int **stack_b, int len);
void	four_stack(int **stack_a, int **stack_b);
void	five_stack(int **stack_a, int **stack_b);

// PUSH SWAP

long long	ft_super_atoi(const char *nptr);
void	small_stack(int **stack_a, int **stack_b, int len);
int	neg_max_bits(int **stack);
int	pos_max_bits(int **stack);
int	get_max_bits(int **stack);
void	radix_sort(int **stack_a, int **stack_b);
void	check_build_sort(char **array);
char	**string_input(char *str);
void	free_array(char **array);
int	main(int argc, char *argv[]);

#endif
