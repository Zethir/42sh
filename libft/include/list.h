/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 10:59:19 by tvallee           #+#    #+#             */
/*   Updated: 2016/09/13 14:18:28 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewcopy(void const *data, size_t data_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstpushback(t_list **list, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *lst);
void				**ft_lsttotab(t_list *list, int free);
int					**ft_strlsttoitab(t_list *lst, int destroy);
int					*ft_atabtoistr(char **tab);
int					ft_lstremove(t_list **list, t_list *elem, int i);

/*
** Miscellaneous sorting functions
*/

#endif
