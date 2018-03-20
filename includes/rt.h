/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:03:31 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/21 13:07:34 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include "libft.h"
# include "linear.h"
# include <float.h>
# include "utils.h"
# include "kdtree.h"
# include "color.h"
# include "material.h"

typedef struct			s_pixel
{
	struct s_point2d	position;
	struct s_color		color;
}						t_pixel;

typedef struct			s_canvas
{
	int					h;
	int					w;
	struct s_color		*data;
}						t_canvas;

typedef struct			s_sphere
{
	struct s_point3d	center;
	float				radius;
	struct s_color		color;
	struct s_material	material;
}						t_sphere;

typedef struct			s_triangle
{
	struct s_point3d	p1;
	struct s_point3d	p2;
	struct s_point3d	p3;
	struct s_color		color;
	struct s_vector3d	norm;
	struct s_material	material;
}						t_triangle;

typedef struct			s_sun3d
{
	struct s_point3d	location_world;
	struct s_point3d	location;
	struct s_color		color;
}						t_sun3d;

typedef struct			s_obj3d
{
	void				*data;
	int					(*intersect)(const void *data,
			const struct s_point3d ray_start,
			const struct s_vector3d ray,
			struct s_point3d *intersection_point);
	struct s_color		(*get_color)(const void *data,
			const struct s_point3d intersection_point);
	struct s_vector3d	(*get_normal_vector)(const void *data,
			const struct s_point3d intersection_point);
	struct s_point3d	(*get_min_boundary_point)(const void *data);
	struct s_point3d	(*get_max_boundary_point)(const void *data);
	struct s_material	(*get_material)(const void *data,
			const struct s_point3d intersection_point);
	void				(*release_data)(void *data);
}						t_obj3d;

typedef struct			s_scene
{
	struct s_obj3d		**objects;
	int					objects_count;
	int					last_object_index;
	struct s_sun3d		**light_sources;
	int					light_sources_count;
	int					last_light_source_index;
	struct s_color		background_color;
	float				(*fog_density)(const float distance,
			const void *fog_data);
	struct s_kdtree		*kd_tree;
	void				*fog_parameters;
}						t_scene;

typedef struct			s_camera
{
	t_point3d			camera_position;
	float				al_x;
	float				sin_al_x;
	float				cos_al_x;
	float				al_y;
	float				sin_al_y;
	float				cos_al_y;
	float				al_z;
	float				sin_al_z;
	float				cos_al_z;
	float				proj_plane_dist;
}						t_camera;

void					render_scene(const t_scene *const scene,
		const t_camera *const camera,
		t_canvas *canvas);

t_scene					*new_scene(const int objects_count,
		const int light_sources_count,
		const t_color background_color);
void					release_scene(t_scene *scene);
void					add_object(t_scene *const scene,
		t_obj3d *const object);
void					prepare_scene(t_scene *const scene);
void					set_exponential_fog(t_scene *const scene,
		const float k);
void					set_no_fog(t_scene *const scene);

t_color					trace(const t_scene	*const scene,
		const t_camera *const camera,
		t_vector3d vector);
void					add_light_source(t_scene *const scene,
		t_sun3d *const light_source);

t_obj3d					*new_triangle(const t_point3d p1,
		const t_point3d p2,
		const t_point3d p3,
		const t_color color,
		const t_material material);
t_obj3d					*new_sphere(const t_point3d center,
		const float radius,
		const t_color color,
		const t_material material);
void					release_object3d(t_obj3d *obj);
t_sun3d					*new_light_source(const t_point3d location,
		const t_color color);
t_material				material(const float ka,
		const float kd,
		const float ks,
		const float kr,
		const float kt,
		const float p);

t_camera				*new_camera(const t_point3d camera_position,
		const float al_x,
		const float al_y,
		const float al_z,
		const float proj_plane_dist);
void					release_camera(t_camera *const cam);
void					rotate_camera(t_camera *const cam,
		const float al_x,
		const float al_y,
		const float al_z);
void					move_camera(t_camera *const camera,
		const t_vector3d vector);

t_kdtree				*build_kd_tree(t_obj3d **const objects,
		const int objects_count);
void					release_kd_tree(t_kdtree *tree);
int						find_intersection_tree(t_kdtree *const tree,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d **const nearest_obj_ptr,
		t_point3d *const nearest_intersection_point_ptr,
		float *const nearest_intersection_point_dist_ptr);
t_kdnode				*rec_build(t_obj3d **const objects,
		const int objects_count,
		const t_voxel v,
		const int iter);
t_kdnode				*make_leaf(t_obj3d **objects,
		int objects_count);
void					find_plane(t_obj3d **objects,
		const int objects_count,
		const t_voxel v,
		const int tree_depth,
		enum e_plane *const p,
		t_coord *const c);
int						objects_in_voxel(t_obj3d **objects,
		const int objects_count,
		const t_voxel v);
void					split_voxel(const t_voxel v,
		const enum e_plane p,
		const t_coord c,
		t_voxel *const vl,
		t_voxel *const vr);
int						filter_overlapped_objects(t_obj3d **const objects,
		const int objects_count,
		const t_voxel v);
int						vector_plane_intersection(const t_vector3d vector,
		const t_point3d vector_start,
		const enum e_plane plane,
		const t_coord coord,
		t_point3d *const result);
int						voxel_intersection(const t_vector3d vector,
		const t_point3d vector_start,
		const t_voxel v);
int						object_in_voxel(t_obj3d *const obj,
		const t_voxel v);
int						point_in_voxel(const t_point3d p,
		const t_voxel v);
int						find_intersection_node(t_kdnode *const node,
		const t_voxel v,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d **const nearest_obj_ptr,
		t_point3d *const nearest_intersection_point_ptr,
		float *const nearest_intersection_point_dist_ptr);
int						is_intersect_anything_node(t_kdnode *const node,
		const t_voxel v,
		const t_point3d vector_start,
		const t_vector3d vector);
t_voxel					voxel(const t_point3d min,
		const t_point3d max);
t_canvas				*new_canvas(const int width, const int height);
t_canvas				*grayscale_canvas(t_canvas *base);
t_canvas				*detect_edges_canvas(t_canvas *base, int num_threads);
void					release_canvas(t_canvas *c);
void					clear_canvas(t_canvas *c);
void					set_pixel(const t_pixel p,
		t_canvas *const c);
t_color					get_pixel(t_point2d p,
		const t_canvas *const c);
t_pixel					pixel(const t_point2d point,
		const t_color color);

t_color					trace_recursively(const t_scene *const scene,
		const t_point3d vector_start,
		const t_vector3d vector,
		const float intensity,
		const int recursion_level);
int						is_viewable(const t_point3d target_point,
		const t_point3d starting_point,
		const t_scene *const scene);

t_color					get_lighting_color(const t_point3d point,
		const t_vector3d norm_v,
		const t_scene *const scene);
t_color					get_specular_color(const t_point3d point,
		const t_vector3d reflected_ray,
		const t_scene *const scene,
		const float p);
t_color					calculate_color(const t_scene *const scene,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d *const *obj_ptr,
		const t_point3d *const point_ptr,
		const float *const dist_ptr,
		const float intensity,
		const int recursion_level);

void					*canvas_to_image(void *const mlx,
		const t_canvas *const canvas);
#endif
