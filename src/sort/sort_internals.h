/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_internals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:16 by poss              #+#    #+#             */
/*   Updated: 2024/08/19 13:40:27 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_INTERNALS_H
# define SORT_INTERNALS_H

# include "error/t_error.h"
# include "stack/t_stacks.h"

t_error	radix_sort(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort2(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort3(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort5(t_stacks *stacks, t_int_deque *ops_out);

// sort5 internals
t_error	move_top_element(t_stacks *stacks, t_int_deque *ops_out);

#endif
