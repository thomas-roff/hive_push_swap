/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:30:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// CODES FOR ERROR TRACKING

// SUCCESSFUL EXECUTION
# ifndef OK
#  define OK 1
# endif

// UNSUCCEFUL EXECUTION
# ifndef KO
#  define KO 0
# endif

// CODES FOR CHECKING FUNCTIONS

// RETURNS TRUE
# ifndef TRUE
#  define TRUE 1
# endif

// RETURNS FALSE
# ifndef FALSE
#  define FALSE 0
# endif

// ARRAY NULL TERMINATOR
# ifndef ARR_NT
#  define ARR_NT 2
# endif

// ARRAY UTILITIES

int				check_no_dup(char **array);
int				ft_arrcheck(char **array, int (f)(int));
int				ft_arraylen(char **array);
void			free_array(char **array);
long long		ft_super_atoi(const char *nptr);

// STACK UTILITIES

int				ft_stacklen(int **stack);
int				ft_issorted(int **stack);
int				free_and_exit(int **stack_a, int **stack_b, int check);
void			error_free_and_exit(int **stack, int len);
int				ft_uinstacklen(unsigned int **stack);

// BUILD FUNCTIONS

int				**build_stack(char **array, int len);
int				**build_empty_stack(int len);
unsigned int	**build_uin_stack(int **stack, int len);
void			free_exit_uin(unsigned int **stack_a, unsigned int **stack_b);

// SORT OPERATIONS

void			op_sa(int **stack);
void			op_ra(int **stack, int len);
void			op_rra(int **stack, int len);
void			op_pa(int **stack_a, int **stack_b);
void			op_pb(int **stack_a, int **stack_b);

// UNSIGNED SORT OPERATIONS

void			uin_op_sa(unsigned int **stack);
void			uin_op_ra(unsigned int **stack, int len);
void			uin_op_rra(unsigned int **stack, int len);
void			uin_op_pa(unsigned int **stack_a, unsigned int **stack_b);
void			uin_op_pb(unsigned int **stack_a, unsigned int **stack_b);

// SMALL STACKS

void			three_stack(int **stack);
int				find_min(int **stack);
void			push_min(int **stack_a, int **stack_b, int len);
void			four_stack(int **stack_a, int **stack_b);
void			five_stack(int **stack_a, int **stack_b);

// RADIX SORT

int				check_bits_sorted(unsigned int **stack, int bits);
void			bitsort(unsigned int **a, unsigned int **b, int len, int bits);
void			radix(unsigned int **stack_a, unsigned int **stack_b, int len);
void			convert_to_signed(int **output, unsigned int **input);
void			large_stack(int **stack_a, int len);

// PUSH SWAP

void			small_stack(int **stack_a, int **stack_b, int len);
int				check_build_sort(char **array);
char			**string_input(char *str);
int				main(int argc, char *argv[]);

// TESTING FUNCTIONS

void			print_stack(int **stack);
void			print_uin_stack(unsigned int **stack);
void			print_stack_bits(unsigned int **stack);

#endif
