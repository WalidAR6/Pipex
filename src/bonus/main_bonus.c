/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:36 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 19:30:57 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int main(int ac, char **av, char **envp)
{
    here_doc(ac, av, envp);
    multiple_pipes(ac, av, envp);
    return 0;
}

