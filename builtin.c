/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:20:42 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/12 20:47:57 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int     cd(char *input)
{
	char *ptr_arg;
	char *end_arg;

	ptr_arg = input;
	while (!ft_isspacer(*ptr_arg))
		ptr_arg++;
	while (ft_isspacer(*ptr_arg))
		ptr_arg++;
	end_arg = ptr_arg;
	while (!ft_isspacer(*end_arg))
		end_arg++;
	*end_arg = '\0';
	if (!ft_strlen(ptr_arg))
		chdir(getenv("HOME"));
	else if (chdir(ptr_arg))
	{
		perror("error: ");
		return (-1);
	}
	return (0);
}

void	pwd(void)
{
	char	cwd_buff[1000];

	ft_putstr(getcwd(cwd_buff, 999));
	ft_putchar('\n');
}
