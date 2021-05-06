/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_non_btin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <haouhaou.d@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:13:46 by pray              #+#    #+#             */
/*   Updated: 2021/05/06 02:08:39 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdlib.h"
#include "stdio.h"

char		**get_absolute_path(void)
{
	t_env	*env;
	char	*path_env;
	char	**path_arr;

	env = get_minish()->env;
	path_env = 0;
	while (env)
	{
		if (ft_strcmp_v2(env->key, "PATH"))
			path_env = env->value;
		env = env->next;
	}
	if (!path_env)
		return (0);
	path_arr = ft_split(path_env, ':');
	return (path_arr);
}

void		free_path(char **path_arr)
{
	int i;

	i = 0;
	while (path_arr[i])
	{
		free(path_arr[i]);
		i++;
	}
	free(path_arr);
}

void		free_env_2(char **env)
{
	int i;

	i = 0;
	if (env)
	{
		while (env[i])
			free(env[i++]);
		free(env);
	}
}

void		exec_with_path(t_cmd *cmd, char **path_arr)
{
	char	*path;
	char	*path_extend;
	char	**g_envp;
	int		i;

	i = 0;
	if (space_found(cmd->argv[0]) == 0 && cmd->start_dollars == 1)
		execrrr(cmd, path_arr);
	else
		while (path_arr[i])
		{
			path = ft_strjoin(path_arr[i], "/");
			path_extend = ft_strjoin(path, cmd->argv[0]);
			g_envp = get_env_full(get_minish()->env);
			execve(path_extend, cmd->argv, g_envp);
			free_env_2(g_envp);
			free(path);
			free(path_extend);
			i++;
		}
}

void		exec_non_builtin(t_cmd *cmd)
{
	char	**path_arr;
	char	**tmp;

	tmp = NULL;
	if (!handle_dollars_parse(cmd, -1))
		exit(EXIT_FAILURE);
	set_redirect_dup2(cmd);
	if ((cmd->argv[0] == NULL ||
		ft_strlen(cmd->argv[0]) == 0) && cmd->start_dollars == 1);
	else if (!cmd->has_path && (path_arr = get_absolute_path()))
	{
		exec_with_path(cmd, path_arr);
		free_path(path_arr);
		exit(error_commande(cmd->argv[0], 127));
	}
	else
		ext_non_built(cmd, tmp);
}
