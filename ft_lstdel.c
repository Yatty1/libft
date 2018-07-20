/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:53:24 by syamada           #+#    #+#             */
/*   Updated: 2018/07/13 16:20:43 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*n_list;

	if (alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list)
	{
		n_list = list->next;
		ft_lstdelone(&list, del);
		list = n_list;
	}
	*alst = NULL;
}
