/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:22:22 by vbronov           #+#    #+#             */
/*   Updated: 2024/11/17 15:45:52 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 
# define FALSE 0
# define TRUE 1

typedef struct s_node
{
	char			*buf;
	struct s_node	*next;
}				t_lst_node;

typedef struct s_list
{
	t_lst_node	*head;
	t_lst_node	*tail;
	ssize_t		len;
}			t_list;

char		*get_next_line(int fd);
int			prepare_next_line(int fd, t_list *list);
char		*copy_new_line(t_list *list);
void		cleanse(t_list **list);
int			append_to_list(t_list *list, ssize_t bytes_read, char *buf);
t_lst_node	*create_node(char **buf);
ssize_t		find_new_line(t_list *list);
void		free_list(t_list **list, int free_all);
t_list		*init_list(t_list **list);

#endif
