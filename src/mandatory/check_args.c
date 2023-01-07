/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:54:56 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 20:46:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void    check_first_arg(char *arg)
{
    int fd;

    fd = open(arg, O_RDWR);
    if (fd == -1)
        ft_printf(2,"%s: No such file or directory\n", arg);
}