/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:02:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/20 18:44:35 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include <stdio.h>
#include <time.h>

int				main(void)
{
	t_scene		*scene;
	//t_obj3d		*sphere;
	t_sun3d		*sun;
	t_camera	*camera;
	t_canvas	*canvas;

	scene = new_scene(10000, 1, rgb(30, 100, 30));
	/*t_obj3d *sphere = new_sphere(point3d(0, -200, 0),
			300,
			rgb(255, 30, 30),
			material(5, 5, 5, 5, 5, 5));*/
	t_obj3d *black = new_sphere(point3d(400, 0, 0),
			200,
			rgb(255, 0, 0),
			material(10, 10, 10, 10, 10, 10));
	t_obj3d *black2 = new_sphere(point3d(-400, 0, 0),
			200,
			rgb(255, 0, 0),
			material(15, 15, 15, 15, 15, 15));
	t_obj3d *black3 = new_sphere(point3d(0, 0, 400), 
			200,
			rgb(255, 0, 0),
			material(20, 20, 20, 20, 20, 20));
	t_obj3d *black4 = new_sphere(point3d(0, 0, -400),
			200,
			rgb(255, 0, 0),
			material(25, 25, 25, 25, 25, 25));
	//add_object(scene, sphere);
	add_object(scene, black);
	add_object(scene, black2);
	add_object(scene, black3);
	add_object(scene, black4);
	prepare_scene(scene);
	sun = new_light_source(point3d(-300, 300, 300),
			rgb(255, 255, 255));
	t_sun3d *sun2 = new_light_source(point3d(300, 300, 300),
			rgb(255, 255, 255));
	add_light_source(scene, sun);
	add_light_source(scene, sun2);
	float density = 0.001;
	set_exponential_fog(scene, density);
	set_no_fog(scene);
	camera = new_camera(point3d(0, 500, 0),
			-1.57,
			0,
			3.14,
			320);
	canvas = new_canvas(1000, 1000);
	render_scene(scene,
			camera,
			canvas);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1000, 1000, "test");
	//void *im_ptr = mlx_new_image(mlx, 1000, 1000);
	//int bpp = 4;
	//int len = 0;
	//int end = 0;
	//void *begin;
   	//begin = mlx_get_data_addr(im_ptr, &bpp, &len, &end);
	//int i = 0;
	//int j = 0;
	//unsigned char *split = begin;
	t_canvas *gray = grayscale_canvas(canvas);
	clock_t	sec1 = clock();
	void *im_ptr = canvas_to_image(mlx, gray);
	/*while (i < 1000)
	{
		while (j < 1000)
		{
			t_color color = get_pixel(point2d(i, j), gray);
			*split++ = color.b;
			*split++ = color.g;
			*split++ = color.r;
			split++;
			j++;
		}
		j = 0;
		i++;
	}*/
	clock_t sec2 = clock();
	printf("time: %.3f (sec)\n", (float)(sec2 - sec1)/1000000);
	mlx_put_image_to_window(mlx, win, im_ptr, 0, 0);
	printf("mlxput\n");
	mlx_loop(mlx);
	return (0);
}
