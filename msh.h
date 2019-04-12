/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:39:59 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/11 20:06:19 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# define MAG "\x1B[35m"
# define CYAN "\x1B[36m"
# define GREEN "\x1B[32m"
# define RESET "\x1B[0m"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

void	prompt(void);
void	title(void);
int		parse(char *input);
int		is_bin(char *input);
int		is_builtin(char *input);
int		cd(char *input);
void	pwd(void);

#endif
