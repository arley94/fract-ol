/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:47:41 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/23 12:05:20 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs//libftprintf/ft_printf.h"

# ifdef LINUX 
#  include "../minilibx-linux/mlx.h"
#  include "linux_keys.h"
# else
#  include "../minilibx-mac/mlx.h"
#  include "mac_keys.h"
# endif

/*  Dimensions	*/
# define WIDTH 600
# define HEIGHT 600

/*  Iterations  */
# define MAX_ITERATIONS 60

/*  Complex set  */
# define INITIAL_CENTER_X -0.5
# define INITIAL_CENTER_Y 0
# define INITIAL_REAL_SPAN 3

/*  Events  */
# define CLOSE_EVENT_NUMBER 17

/*  Types  */
typedef enum e_fractal_set
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	BURNING_SHIP_FLIP
}				t_fractal_set;

typedef enum e_mouse_events
{
	LEFT_CLICK = 1,
	SCROLL_CLICK,
	RIGHT_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
}				t_mouse_events;

typedef enum e_zoom
{
	ZOOM_IN,
	ZOOM_OUT
}				t_zoom;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_fractol_data
{
	t_fractal_set			set;
	t_img_data				img;
	void					*mlx_ptr;
	void					*win_ptr;
	double					min_r;
	double					max_i;
	double					r_span;
	double					i_span;
	double					kr;
	double					ki;
	int						color;
	int						*pallette;
	int						color_shift;
	struct s_fractol_data	*julia;
}	t_fractol_data;

/*  Initializations functions  */
void	init_fractol_data(t_fractol_data *f);
void	init_aux_fractol(t_fractol_data *f);
void	init_mlx(t_fractol_data *f);
void	parse_args(int argc, const char *argv[], t_fractol_data *f);
void	generate_colors_pallette(t_fractol_data *f);

/*  Fractals  */
int		mandelbrot(double cr, double ci);
int		julia(double cr, double ci, double kr, double ki);
int		burning_ship(double cr, double ci);
int		burning_ship_flip(double cr, double ci);

/*  Events handlers  */
int		mouse_handler_1(int button, int x, int y, void *param);
int		mouse_handler_2(int button, int x, int y, void *param);
int		keyboard_handler_1(int key_code, void *param);
int		keyboard_handler_2(int key_code, void *param);
int		close_handler_1(void *param);
int		close_handler_2(void *param);

/*  Actions functions  */
void	close_window(t_fractol_data *f);

/*  render functios  */
void	re_draw_zoom(int x, int y, t_zoom zoom, t_fractol_data *f);
void	re_draw_move(int direction, t_fractol_data *f);
void	re_draw_shift_pallette(t_fractol_data *f);
void	re_draw_interpollated_pallete(t_fractol_data *f);
void	re_draw_random_pallete(t_fractol_data *f);
void	re_draw_change_fractal(t_fractol_data *f);
void	draw_image(t_fractol_data *f);

/*  Colors functions  */
int		get_color(int nb_iter, t_fractol_data *f);
void	create_colors_pallette(t_fractol_data *f);
void	interpolated_pallette(t_fractol_data *f);
void	random_pallette(t_fractol_data *f);

/*  exits functions  */
void	clean_and_exit(t_fractol_data *f, int status);
void	display_help_exit(t_fractol_data *f);

#endif
