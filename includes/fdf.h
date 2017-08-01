/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:20:34 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 18:15:08 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <math.h>

# define TILE_WIDTH 64
# define TILE_HEIGHT 32
# define SIGN(x) ((x > 0)? 1 : ((x < 0)? -1: 0))
# define TO_RADS(deg) (deg * M_PI / 180.0)

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
}						t_map;

typedef struct			s_segment
{
	t_tuple				*start;
	t_tuple				*end;
	int					color;
	struct s_segment	*next;
}						t_segment;

void					draw_line(t_display *display, t_tuple *start, t_tuple *end, int color);
t_tuple					*new_tuple(int x, int y);
int						arr_len(char **arr);
void					*create_window(int x, int y);
t_map					*load_map(int fd);
void					push_segment(t_segment **segs, t_segment *new);
t_segment				*build_segments(t_map *map, int scale);
t_tuple					*project_point(int x, int y, int z, int size);
t_segment				*new_segment(t_tuple *start, t_tuple *end, int color);
void					render_segments(t_display *display, t_segment *segment);
int						gen_color(int z);
void					mult_matrix(int point[4], float proj[16], int res[4]);
int						*build_point(int x, int y, int z, int scale);
# endif
