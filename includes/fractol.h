/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:47:41 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/20 08:27:35 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "../libs/libft/libft.h"
#include "../libs//libftprintf/ft_printf.h"


/*  Dimensions	*/
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITERATIONS 60

#define	INITIAL_CENTER_X -0.5
#define INITIAL_CENTER_Y 0
#define	INITIAL_REAL_SPAN 3

#define CLOSE_EVENT_NUMBER 17

# define ESCAPE_KEY_CODE 65307

typedef enum e_fractal_set
{
	MANDELBROT,
	JULIA
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

typedef struct s_img_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_fractol_data
{
	t_fractal_set	set;
	t_img_data		img;
	void			*mlx_ptr;
	void			*win_ptr;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			r_span;
	double			i_span;
	double			r_center;
	double			i_center;
	double			kr;
	double			ki;
	int				color;
}	t_fractol_data;

void	parse_args(int argc, const char *argv[], t_fractol_data *f);
void	set_copmplex_square(t_fractol_data *f);
int		mandelbrot(double cr, double ci);
int		julia(double cr, double ci, double kr, double ki);
void	draw_image(t_fractol_data *f);
int		mouse_handler(int button, int x, int y, void *param);
int		keyboard_handler(int key_code, void *param);
int		close_handler(void *param);
void	zoom(t_zoom zoom, t_fractol_data *f);
void	set_square_center(int x, int y, t_fractol_data *f);
void	parse_args(int argc, const char *argv[], t_fractol_data *f);
void	clean_and_exit(t_fractol_data *f, int status);
void	display_help_exit(void);