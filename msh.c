/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:36:12 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/12 20:44:23 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	*extract_cmd(char *input)
{
	char	*cmd;
	int		i;

	i = 0;
	while (!ft_isspacer(input[i]))
		i++;
	cmd = strndup(input, i);
	return (cmd);
}

/*char **extract_arg(char *input)
{
	char **argv;
	char *roam;

	roam = input;
	while (!ft_isspacer(*roam))
		roam++;
	while (*roam != '\0')
	{

	}
}*/
int		execute(char *path)
{
	pid_t	mother;
	char **argv;

	argv = malloc(sizeof(argv) * 2);
	argv[0] = ft_strdup(path);
	argv[1] = NULL;

	mother = fork();
	if (mother > 0)
		wait(NULL);
	if (mother == 0)
		execve(path, argv, NULL);
	return (1);
}

int		is_builtin(char *input)
{
	char *cmd;

	cmd = extract_cmd(input);
	/*if (!ft_strcmp(cmd, "echo"))
		ft_putstr("ECHO: built-in command\n");
	else */if (!ft_strcmp(cmd, "cd"))
		cd(input);
	else if (!ft_strcmp(cmd, "pwd"))
		pwd();
	else
	{
		free(cmd);
		return (0);
	}
	free(cmd);
	return (1);
}

int		is_bin(char *input)
{
	char *cmd;
	char **argv;

	argv = malloc(sizeof(argv) * 2);
	argv[0] = ft_strdup("ls");
	argv[1] = NULL;
	cmd = extract_cmd(input);
//	argv = extract_arg(input);
	if (!ft_strcmp(cmd, "ls"))
		execute("/bin/ls");
	if (!ft_strcmp(cmd, "netstat"))
		execute("/usr/sbin/netstat");
	if (!ft_strcmp(cmd, "ifconfig"))
		execute("/sbin/ifconfig");
	if (!ft_strcmp(cmd, "echo"))
		execute("/bin/echo");
	return (1);
}

int		parse(char *input)
{
	if (!ft_strcmp(input, "exit\n"))
		return (1);
	else
	{
		if (!is_builtin(input))
			if (!is_bin(input))
				ft_putstr("command not found.\n");
		return (0);
	}
}

int		main(void)
{
	char	*input;
	int		quit;

	title();
	quit = 0;
	while (!quit)
	{
		prompt();
		get_next_line(0, &input);
		quit = parse(input);
	}
	free(input);
	return (0);
}
