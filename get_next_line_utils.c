/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:28:46 by vbronov           #+#    #+#             */
/*   Updated: 2024/11/17 15:06:52 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst_node	*create_node(char **buf)
{
	t_lst_node	*node;

	node = (t_lst_node *)malloc(sizeof(t_lst_node));
	if (!node)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	node->buf = *buf;
	node->next = NULL;
	return (node);
}

ssize_t	find_new_line(t_list *list)
{
	int	i;

	if (!list || !list->tail)
		return (-1);
	i = 0;
	while (list->tail->buf[i] != '\0')
	{
		if (list->tail->buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	free_helper(t_list **list)
{
	if ((*list)->head)
	{
		free((*list)->head->buf);
		(*list)->head->buf = NULL;
		free((*list)->head);
		(*list)->head = NULL;
	}
	(*list)->tail = NULL;
	(*list)->len = 0;
	free(*list);
	*list = NULL;
}

void	free_list(t_list **list, int free_all)
{
	t_lst_node	*temp;

	if (!*list)
		return ;
	while ((*list)->head != (*list)->tail)
	{
		temp = (*list)->head;
		(*list)->head = (*list)->head->next;
		if (temp->buf)
			free(temp->buf);
		temp->buf = NULL;
		temp->next = NULL;
		free(temp);
	}
	if (free_all)
		free_helper(list);
}

t_list	*init_list(t_list **list)
{
	if (!*list)
	{
		*list = (t_list *)malloc(sizeof(t_list));
		if (!*list)
			return (NULL);
		(*list)->head = NULL;
		(*list)->tail = NULL;
		(*list)->len = 0;
	}
	return (*list);
}
