/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 12:17:30 by tvallee           #+#    #+#             */
/*   Updated: 2015/10/10 12:20:43 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_TOOLS_H
# define TAB_TOOLS_H

# include "libft.h"

int					ft_freetab(void **tab);
size_t				ft_tablen(void **tab);
t_list				*ft_tabtolst(void **data);
void				**ft_tablineadd(void *line, void **tab);
void				**ft_tablinedel(void *line, void **tab);

#endif
