/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:51 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/07 19:35:21 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char    **split_arg(char *str)
{
    char **splited_cmd;

    splited_cmd = ft_split(str, ' ');
    return (splited_cmd);
}