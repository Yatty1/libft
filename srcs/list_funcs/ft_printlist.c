/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:28:04 by syamada           #+#    #+#             */
/*   Updated: 2018/07/14 15:06:33 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		ft_putstr("Element #");
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putstr("Content: ");
		ft_putendl((char*)list->content);
		ft_putstr("Content size: ");
		ft_putnbr((int)list->content_size);
		ft_putchar('\n');
		list = list->next;
		i++;
	}
}
