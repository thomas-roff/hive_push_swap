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

# include "../libft/libft.h"

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

// ARRAY SRUCT
typedef struct s_int_arr
{
	int	*arr;
	int	len;
}	t_int_arr;

typedef struct s_uint_arr
{
	unsigned int	*arr;
	int				len;
}	t_uint_arr;

// ARRAY UTILITIES

int				check_no_dup(char **array);
int				ft_arrcheck(char **array, int (f)(int));
int				ft_arraylen(char **array);
void			free_array(char **array);
long long		ft_super_atoi(const char *nptr);

// STACK UTILITIES

// int				ft_stacklen(t_int_arr *stack);
int				ft_issorted(t_int_arr *stack);
int				free_exit(t_int_arr *stack_a, t_int_arr *stack_b, int check);
void			error_free_exit(t_int_arr *stack);
// int				ft_uinstacklen(t_uint_arr *stack);

// BUILD FUNCTIONS

t_int_arr		*build_stack(char **array, int len);
t_int_arr		*build_empty_stack(int len);
t_uint_arr		*build_uin_stack(t_int_arr *stack);
t_uint_arr		*build_empty_uin_stack(int len);
void			free_exit_uin(t_uint_arr *stack_a, t_uint_arr *stack_b);

// SORT OPERATIONS

void			op_sa(t_int_arr *stack);
void			op_ra(t_int_arr *stack);
void			op_rra(t_int_arr *stack);
void			op_pa(t_int_arr *stack_a, t_int_arr *stack_b);
void			op_pb(t_int_arr *stack_a, t_int_arr *stack_b);

// UNSIGNED SORT OPERATIONS

void			uin_op_ra(t_uint_arr *stack);
void			uin_op_pa(t_uint_arr *stack_a, t_uint_arr *stack_b);
void			uin_op_pb(t_uint_arr *stack_a, t_uint_arr *stack_b);

// SMALL STACKS

void			three_stack(t_int_arr *stack);
int				find_min(t_int_arr *stack);
void			push_min(t_int_arr *stack_a, t_int_arr *stack_b, int len);
void			four_stack(t_int_arr *stack_a, t_int_arr *stack_b);
void			five_stack(t_int_arr *stack_a, t_int_arr *stack_b);

// RADIX SORT

int				check_bits_sorted(t_uint_arr *stack, int bits);
void			bitsort(t_uint_arr *a, t_uint_arr *b, int bits);
void			radix(t_uint_arr *stack_a, t_uint_arr *stack_b);
void			convert_to_signed(t_int_arr *output, t_uint_arr *input);
void			large_stack(t_int_arr *stack_a);

// PUSH SWAP

void			small_stack(t_int_arr *stack_a, t_int_arr *stack_b);
int				check_build_sort(char **array);
char			**string_input(char *str);
int				main(int argc, char *argv[]);

// TESTING FUNCTIONS

void			print_stack(t_int_arr *stack);
void			print_uin_stack(t_uint_arr *stack);
void			print_stack_bits(t_uint_arr *stack);

#endif
