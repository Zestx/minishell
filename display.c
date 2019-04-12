/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:15:22 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/12 20:20:43 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void    prompt(void)
{
	char cwd_buff[1000];
	
	ft_putstr("user");
	ft_putstr(CYAN);
	ft_putstr("@");
	ft_putstr(RESET);
	ft_putstr("msh ");
	ft_putstr(MAG);
	ft_putstr(getcwd(cwd_buff, 999));
	ft_putstr(RESET);
	ft_putstr("> ");
}

void    title(void)
{
	ft_putstr("-------------------\n|");
	ft_putstr(MAG);
	ft_putstr("~");
	ft_putstr(RESET);
	ft_putstr(" MINISHELL 0.1 ");
	ft_putstr(MAG);
	ft_putstr("~");
	ft_putstr(RESET);
	ft_putstr("|\n-------------------\n\n");
}
