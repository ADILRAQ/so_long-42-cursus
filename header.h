/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:42:15 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/03 18:46:17 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

/*  __SO__LONG__  */

typedef struct s_cord
{
	int				i;
	int				j;
}	t_cord;

typedef struct s_list
{
	char			*str;
	int				len;
	int				indice;
	int				utile;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*plr;
	void	*pll;
	void	*enemy;
	void	*coll;
	void	*exit;
	void	*exit_o;
	void	*p_mov;
	void	*col_m;
	void	*t_j;
}	t_img;

typedef struct s_info
{
	char	dir;
	int		coins;
	int		to_coins;
	int		enemy;
	int		mov;
	char	**maze;
	int		x;
	int		y;
	int		x_win;
	int		y_win;
	int		x_max;
	int		y_max;
	void	*mlx;
	void	*win;
	t_img	ig;
	t_cord	lst;
}	t_info;

int		map_format(char *str);
void	ft_free_list(t_list **lst);
char	**ft_free(char **str);
char	**ft_both_free(char **str, t_list **lst);
int		ft_chk_rctgl(t_list *lst);
int		ft_chk_walls(t_list *lst);
int		ft_check_chars(t_list *lst, int *coins);
int		solve_maze(char **map, t_info *player);
char	**ft_fill(int y, int x);
char	**ft_fill_map(int fd, int *y, int *x, int *coins);
void	make_window(char **map, t_info *pl);
void	game_interaction(char **map, t_info player);
void	move_up(t_info *pl);
void	move_down(t_info *pl);
void	move_left(t_info *pl);
void	move_right(t_info *pl);
t_img	init_images(t_info	*pl);

/*  __GET__NEXT__LINE__  */

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t len);
void	ft_putnbr(int nb);

/*  __LIBFT__  */

size_t	ft_strlen_map(const char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *content, int idx);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);

/*  __BONUS__  */

char	**ft_fill_map_b(int fd, int *y, int *x, int *coins);
int		check_char_b(t_list *lst, int *coins);
int		solve_maze_b(char **map, t_info *player);
void	ft_string_aff(t_info *pl, t_img ig);
int		move_enemies(void *pl);
void	move_up_b(t_info *pl);
void	move_down_b(t_info *pl);
void	move_left_b(t_info *pl);
void	move_right_b(t_info *pl);
void	make_window_b(char **map, t_info *pl);
void	enemy_up(t_info **ply, int i, int j);
void	enemy_down(t_info **ply, int i, int j);
void	enemy_left(t_info **ply, int i, int j);
void	enemy_right(t_info **ply, int i, int j);

#endif