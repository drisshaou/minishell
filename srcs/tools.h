/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by pray              #+#    #+#             */
/*   Updated: 2020/02/21 14:13:49 by pray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4242

char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
void				ft_putstr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_split(char const *s, char c);
int					get_next_line(int fd, char **line);
void				free_tab(char *str[8]);
int					alphnum(char c);
int					trim_comment(char *str);
int					str_alphnum(char *str);
void				free_tab_arg(char **tab);
int					count_count_arg(char **tab);
int					space_found(char *str);
void				trm_cmd(void);
void				get_builtin(char *builtins[8]);

#endif
