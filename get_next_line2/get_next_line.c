/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:01:34 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/13 13:32:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	ft_creat_list(&list, fd);
	if (!list)
	{
		free(list);
		return (NULL);
	}
	line = ft_fill_line(list);
	ft_clean_list(&list);
	return (line);
}

void	ft_creat_list(t_list **list, int fd)
{
	char	*buf;
	int	rcount;
	
	rcount = 0;
	
	while (!ft_newline_check(*list))
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return ;
		rcount = read(fd, buf, BUFFER_SIZE);
		if (!rcount)
		{
			free(buf);
			return ;
		}
		buf[rcount] = '\0';
		ft_apend_to_list(list, buf);
	}
}

void	ft_append_to_list(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node; 
	
	new_node = malloc(sizeof(t_list));
	last_node = ft_find_last_node(*list);
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	new_node->buf = buf;
	new_node->next = NULL;

}

t_list	*ft_find_last_node(t_list *list)
{
	while (list)
	{
		if (ft_new_line_check(list))
			return (list);
		list = list->next;
	}
	return (NULL);
}

int	ft_new_line_check(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		while (list->buf[i] && list->buf[i] != '\n')
			i++;
		if (list->buf[i] == '\n')
				return (1);
		list = list->next;
	}
	return (0);
}