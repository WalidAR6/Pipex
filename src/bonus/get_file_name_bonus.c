/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:02:43 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/21 01:13:45 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char	*get_file_name(char **envp)
{
	int		i;
	char	**splited_line;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		{
			splited_line = ft_split(envp[i], '=');
			return (splited_line[1]);
		}
		i++;
	}
	return (ft_printf(2, "commands not found\n"), NULL);
}
