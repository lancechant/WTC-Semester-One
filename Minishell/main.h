/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:53:20 by lchant            #+#    #+#             */
/*   Updated: 2017/09/30 18:53:23 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <term.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>

typedef	struct s_command	t_command;
typedef struct s_opps		t_opps;
typedef	struct s_args		t_args;
typedef struct s_heap		t_heap;
typedef	struct s_env		t_env;
typedef	struct s_shell		t_shell;

struct		s_heap
{
	void			*address;
	t_heap			*next;
}						heap;

struct		s_shell
{
	t_env	*env_list;
	char	*get_next_line;
	char	*buffer;
} g_shell;

struct		s_args
{
	char	*str;
	t_args	*next;
};

struct		s_command
{
	char		*file_name;
	char		*terminator;
	t_args		*args;
	t_command	*next;
};

struct		s_env
{
	char			*str;
	struct s_env	*next;
};

/*
** vaughan environment functions
*/
t_env		*ft_unset_env(char *key, t_env *list);
t_env		*ft_load_list(char **env);
t_env		*ft_set_env(char *key, char *value, t_env *list);
int			get_next_line(const int fd, char **line);
int			launch_program(t_command *command);
char		*ft_addchar(char *str, char c);
char		**list_to_arr(t_env *list);
char		*ft_get_env(char *key, t_env *list);
int			pos_equal(char *str);
t_env		*ft_create_env_list(char **env);
void		debug_print_env_list(t_env *env);
char		**env_list_to_arr(t_env *list);
void		ft_free_list(t_env *list);
void		init_shell(char **envp);
int			args_check(t_command *command);
int			check_path(t_command *command);
int			try_cd_path(t_command *command);
int			signal_signup(void);
void		ft_destroy_env_list(void);
/*
** builtin programs
*/
int			run_builtin_echo(t_command *command);
int			run_builtin_cd(t_command *command);
int			run_builtin_setenv(t_command *command);
int			run_builtin_unsetenv(t_command *command);
int			run_builtin_env(t_command *command);
void		run_builtin_exit(void);
char		*ft_strtrim_delim(char const *s, char delim);
char		*remove_quotes(char *str);
int			try_launch_builtins(t_command *command, t_command *prev);
int			is_builtin(t_command *cmd, t_command *prev);
/*
** printing-utility functions
*/
void		debug(char *str);
void		debug_print_env();
void		test_memory_manager(void);
int			change_dir(char *path);

char		*arg_list_to_line(t_args *list);
char		**arg_list_to_arr(t_args *list, t_command *cmd_list);
void		execute_command_pipe(t_command *command, int fd[], int state);
void		execute_command(t_command *command);

char		*format_input_string(char *line);
void		process_input(char *input);

void		print_command_list(t_command *command_list);
void		destroy_command_list(t_command *list);
t_command	*create_command_list(char **input);
t_args		*create_arg_list(char **input, t_command *cur_command, int *index);
char		**command_to_array(t_command *cmd);
void		handle_and_or(const char *format);
int			and_or_check(const char *str);
int			is_opp_str(char *str);
void		process_input_loop(t_command *list, t_command *prev, int *status);
char		**ft_split_semi(const char *line);
int			check_semicolon(const char *line);
/*
**	NORMAL FUKIN UNITLS
*/

void		add_to_stack(void *memory);
void		free_strsplit(char **arr);
t_command	*handle_opps(t_command *list, int *old_fd);

#endif
