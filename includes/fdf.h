/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:20:34 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 14:54:30 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "clct.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE_WIDTH 32
# define TILE_HEIGHT 16
# define ZOOM_INC 0.1

# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
# define K_PLUS 69
# define K_MINUS 78

# define SIGN(x) ((x > 0)? 1 : ((x < 0)? -1: 0))
# define TO_RADS(deg) (deg * M_PI / 180.0)
# define TO_INT(f) (int)(lround((double)(f)))

typedef struct			s_display
{
	void				*display;
	void				*window;
	int					width;
	int					height;
}						t_display;

typedef struct			s_tuple
{
	int					x;
	int					y;
}						t_tuple;

typedef struct			s_line
{
	t_tuple				*dir;
	t_tuple				*start;
	t_tuple				*sign;
	int					swap;
}						t_line;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_map
{
	int					***map;
	int					width;
	int					height;
	int					offset_x;
	int					offset_y;
	int					tile_width;
	int					tile_height;
	float				scale;
}						t_map;

typedef struct			s_segment
{
	t_tuple				*start;
	t_tuple				*end;
	int					color;
	struct s_segment	*next;
}						t_segment;

typedef struct			s_params
{
	t_display			*display;
	t_map				*map;
}						t_params;

void					draw_line(t_display *display, t_tuple *start, t_tuple *end, int color);
t_tuple					*new_tuple(int x, int y);
int						arr_len(char **arr);
void					*create_window(int x, int y);
t_map					*load_map(char *file);
void					push_segment(t_segment **segs, t_segment *new);
t_segment				*build_segments(t_map *map);
t_tuple					*project_point(t_map *map, t_tuple *p);
t_segment				*new_segment(t_tuple *start, t_tuple *end, int color);
void					render_segments(t_display *display, t_segment *segment, t_tuple *offset);
int						gen_color(int z);
void					mult_matrix(int point[4], float proj[16], int res[4]);
int						*build_point(int x, int y, int z, int scale);
void					draw_map(t_display *display, t_map *map);
void					setup_hooks(t_params *params);
int						key_hook(int keycode, t_params *params);
void					handle_esc(t_params *params);
void					handle_zoom(t_params *params, int dir);
void					draw(t_params *params);
t_tuple					*offset_point(t_tuple *p, t_tuple *offset);
# endif
