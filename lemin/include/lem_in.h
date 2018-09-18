/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:59:02 by lchant            #+#    #+#             */
/*   Updated: 2017/11/21 11:59:03 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct			s_input
{
	char				*str;
	struct s_input		*next;
}						t_input;

typedef struct			s_rooms
{
	char				*name;
	int					is_valid;
	int					in_room;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_links
{
	char				*link;
	char				**arr;
	struct s_links		*next;
}						t_links;

typedef struct			s_ants
{
	char				*name;
	char				*room;
	char				*last;
	struct s_ants		*next;
}						t_ants;

typedef	struct			s_main
{
	t_input				*data;
	char				*gnl;
	int					ants_num;
	int					num_rooms;
	int					num_links;
	t_rooms				*rooms;
	t_links				*links;
	t_ants				*ants;
	char				*start_room;
	char				*end_room;
	int					nr_end;
	int					start_flag;
	int					end_flag;
}						t_main;

void					error();
void					get_start_end(char *str, t_main *g);
void					travel(t_main *g);
void					check_end(t_main *g, t_ants *a, t_rooms *r, char **arr);
void					find_path(t_main *g);
void					print_name(char *name, char *room);
void					free_all(t_links *l, t_rooms *r, t_ants *a, t_input *i);
void					print_map(t_main *g);
void					print_arr(char **arr);
void					check_error(t_main *g);
void					fill_start_room(t_main *g);
int						get_map(t_main *g);
int						big_if(t_main *g, t_rooms *r, t_ants *a,
						char *str);
int						is_room_valid(t_main *g, t_rooms *r, char *str);
int						ants_in_room(t_main *g, t_rooms *r, char *str);
t_input					*save_input(t_main *g);
t_ants					*save_ants(t_main *g);
t_ants					*assign_rooms(t_main *g);
t_rooms					*add_room(char *str, t_rooms *node, t_main *g);
t_rooms					*go_to_start(t_main *g, t_rooms *r);
t_rooms					*go_to_room(t_main *g, char *str);
t_rooms					*move_from_to(t_main *g, t_rooms *r, char *from,
						char *to);
t_links					*add_link(char *str, t_links *node, t_main *g);
char					*get_link(t_main *g, char *str);
char					**links(t_main *g, char *test);
char					*save_room(char *str);
char					**links(t_main *g, char *test);

#endif
