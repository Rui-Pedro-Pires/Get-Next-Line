/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:01:59 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/17 12:40:40 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_add_to_save(char *save, char *buffer);
char	*ft_fill_line(char *save);
char	*ft_clean_save(char *save);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_clean(char **save, char **buffer);
int		ft_find_new_line(char	*buffer);
int		ft_strlen(char *s1);
int		ft_find_new_line(char	*buffer);

#endif