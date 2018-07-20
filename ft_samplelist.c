/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:28:15 by syamada           #+#    #+#             */
/*   Updated: 2018/07/14 15:32:44 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_samplelist(size_t len)
{
	t_list	*list;
	char	*str;

	if (len <= 0)
		return (NULL);
	str = ft_strinit("Hey u made it boi!");
	list = ft_lstnew(str, ft_strlen(str));
	while (--len)
		ft_lstpush(&list, str, ft_strlen(str));
	return (list);
}
