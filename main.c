/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:42 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/03 22:27:09 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int main(void)
{
    int id = fork();
    int n;
    if (id == 0)
    {
        n = 1;
    }
    else
        n = 6;
    wait(NULL);
    int i = n;
    while (i < n + 5)
    {
        ft_printf("%d",i);
        i++;
    }
    ft_printf("\n");
}