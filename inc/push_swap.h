/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/18 12:59:30 by thblack-         ###   ########.fr       */
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

typedef struct s_index_arr
{
	int				*arr;
	unsigned int	*index;
	int				len;
}	t_index_arr;

// ARRAY UTILITIES

int				ft_arraylen(char **array);
void			free_array(char **array);

// CHECK UTILITIES

int				check_dup_strings(char **array);
int				check_valid_numbers(char **array);
int				ft_isarr(char **array, int (f)(int));
int				ft_arrchr(char **array, int (f)(int));
int				arraycheck(char **array);

// STACK UTILITIES

int				ft_issorted(t_int_arr *stack);
int				free_exit(t_int_arr *stack_a, t_int_arr *stack_b, int check);
void			free_exit_index(t_index_arr *stack);
long long		ft_super_atoi(const char *nptr);
int				check_dup_int(t_int_arr *stack);

// BUILD FUNCTIONS

t_int_arr		*build_stack(char **array, int len);
t_int_arr		*build_empty_stack(int len);
t_index_arr		*build_index_stack(t_int_arr *stack);
t_index_arr		*build_empty_index_stack(int len);
void			free_exit_index(t_index_arr *stack_a);

// SORT OPERATIONS

void			op_sa(t_int_arr *stack);
void			op_ra(t_int_arr *stack);
void			op_rra(t_int_arr *stack);
void			op_pa(t_int_arr *stack_a, t_int_arr *stack_b);
void			op_pb(t_int_arr *stack_a, t_int_arr *stack_b);

// INDEX SORT OPERATIONS

void			assign_index(t_index_arr *stack, int min_index);
void			index_op_ra(t_index_arr *stack);
void			index_op_pa(t_index_arr *stack_a, t_index_arr *stack_b);
void			index_op_pb(t_index_arr *stack_a, t_index_arr *stack_b);

// SMALL STACKS

void			three_stack(t_int_arr *stack);
int				find_min(t_int_arr *stack);
void			push_min(t_int_arr *stack_a, t_int_arr *stack_b, int len);
void			four_stack(t_int_arr *stack_a, t_int_arr *stack_b);
void			five_stack(t_int_arr *stack_a, t_int_arr *stack_b);

// RADIX SORT

int				check_bits_sorted(t_index_arr *stack, int bits);
void			bitsort(t_index_arr *a, t_index_arr *b, int bits);
void			radix(t_index_arr *stack_a, t_index_arr *stack_b);
void			convert_to_signed(t_int_arr *output, t_index_arr *input);
void			copy_values(t_int_arr *output, t_index_arr *input);

// PUSH SWAP

void			large_stack(t_int_arr *stack_a);
int				small_stack(t_int_arr *stack_a);
int				check_build_sort(char **array);
int				string_input(char *str);
int				main(int argc, char *argv[]);

#endif
