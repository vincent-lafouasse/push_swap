/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:36 by poss              #+#    #+#             */
/*   Updated: 2024/08/19 13:40:04 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "error/t_error.h"
# include "stack/t_stacks.h"

t_error	sort(t_stacks *stacks, t_int_deque *ops_out);
t_error	simplify_verify(t_int_deque *dq);

#endif
