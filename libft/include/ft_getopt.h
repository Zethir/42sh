/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 10:16:50 by tvallee           #+#    #+#             */
/*   Updated: 2015/10/15 16:36:24 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

# define IS_SET(flag, bitmask) (1 << flag) & bitmask

int		ft_getopt(int *ac, char **av, char **validopts, uintmax_t *opts);
char	*ft_getopt_emsg(char *emsg);

#endif
