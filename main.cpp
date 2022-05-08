#include "Header.h"
#include "Functions.h"
#include "Vector3d.h"
#include "Figure.h"
#include "Sphere.h"
#include "Box.h"
#include "Tetrahedron.h"
#include "Spectator.h"
#include "Screen.h"
#include "Light.h"


int main()
{

	/*map<int, int> pair;

	pair.insert(make_pair(5, 543));
	pair.insert(make_pair(1, 542));
	pair.insert(make_pair(2, 541));
	pair.insert(make_pair(4, 544));
	pair.insert(make_pair(3, 545));

	for (auto& i : pair)
	{
		std::cout << i.first << " " << i.second << endl;
	}

	cout << pair.size() << endl;

	return 1;*/



	//***** Throw не работает при parallel for *****//

//	try
//	{
//#pragma omp parallel for
//		for (int t = 0; t < 10; t++)
//		{
//			if (t == 5)
//			{
//				cout << "errrr" << endl;
//				throw std::runtime_error("err");
//			}
//		}
//	}
//	catch (const std::exception& e)
//	{
//		std::cerr << e.what() << endl;
//		return 1;
//	}


	try
	{
		Spectator camera;
		Screen screen;
		Light lamp;

		vector<Figure*> shapes;

		string file_name;
		string cur_string;

		ifstream file;

		std::cout << "Enter a file name:" << endl;
		cin >> file_name;

		file.open(file_name);

		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file.\n");
		}

		while (getline(file, cur_string))
		{
			stringstream str_stream;

			str_stream << cur_string;

			string mark;

			str_stream >> mark;

			if (mark == "cam")
			{
				double v1;
				double v2;
				double v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				camera.set_position(v1, v2, v3);
			}

			if (mark == "normal")
			{
				double v1;
				double v2;
				double v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				screen.set_normal_to_screen(v1,v2,v3);

			}

			if (mark == "up")
			{
				double v1;
				double v2;
				double v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				screen.set_up_direction_on_screen(v1, v2, v3);

			}

			if (mark == "screen")
			{
				double v1;
				str_stream >> v1;
				camera.set_dist_spec_screen(v1);

			}

			if (mark == "limit")
			{
				double v1;
				str_stream >> v1;
				camera.set_dist_screen_scene(v1);

			}

			if (mark == "alpha")
			{
				double v1;
				str_stream >> v1;
				camera.set_angle_of_view(v1);

			}

			if (mark == "width")
			{
				int width;
				str_stream >> width;
				screen.set_width(width);
			}

			if (mark == "height")
			{
				int height;
				str_stream >> height;
				screen.set_height(height);
			}

			if (mark == "light")
			{
				double v1;
				double v2;
				double v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				lamp.set_position(v1, v2, v3);
			}

			if (mark == "sphere")
			{
				double v1;
				double v2;
				double v3;
				double r;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;
				str_stream >> r;

				shapes.push_back(new Sphere(v1, v2, v3, r));

			}

			if (mark == "box")
			{
				double v1;
				double v2;
				double v3;

				double w1;
				double w2;
				double w3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				str_stream >> w1;
				str_stream >> w2;
				str_stream >> w3;

				shapes.push_back(new Box(v1, v2, v3, w1, w2, w3));

			}

			if (mark == "tetra")
			{
				double a1;
				double a2;
				double a3;

				double b1;
				double b2;
				double b3;

				double c1;
				double c2;
				double c3;

				double d1;
				double d2;
				double d3;

				str_stream >> a1;
				str_stream >> a2;
				str_stream >> a3;

				str_stream >> b1;
				str_stream >> b2;
				str_stream >> b3;

				str_stream >> c1;
				str_stream >> c2;
				str_stream >> c3;

				str_stream >> d1;
				str_stream >> d2;
				str_stream >> d3;

				shapes.push_back(new Tetrahedron((double)a1, (double)a2, (double)a3, (double)b1, (double)b2, (double)b3, (double)c1, (double)c2, (double)c3, (double)d1, (double)d2, (double)d3));
			}
		}

		screen.create_tangent_on_screen();

		Vector3d normal_to_screen = screen.get_normal_to_screen();
		Vector3d up_on_screen = screen.get_up_direction_on_screen();
		Vector3d tangent_on_screen = screen.get_tangent_on_screen();

		screen.set_center_of_screen((camera.get_position().get_v1()+camera.get_dist_spec_screen()*normal_to_screen.get_v1()),(camera.get_position().get_v2() + camera.get_dist_spec_screen() * normal_to_screen.get_v2()),(camera.get_position().get_v3() + camera.get_dist_spec_screen() * normal_to_screen.get_v3()));

		Vector3d center_of_screen = screen.get_center_of_screen();
		Vector3d spectator_position = camera.get_position();

		if (fabs((up_on_screen ^ normal_to_screen) - 90.0) > 0.0001)
		{
			throw std::runtime_error("Wrong angle betwen normal and up.\n");
		}

		CImg<double> image(screen.get_width(), screen.get_height(), 1, 3, 0);

		auto start = high_resolution_clock::now();

		Vector3d current;

		Vector3d forward = center_of_screen - spectator_position;



		Vector3d from_spectator_to_center_of_figure;

		map<double, Figure*> distribution;

		for (auto P : shapes)
		{
			from_spectator_to_center_of_figure = P->return_centroid() - spectator_position;

			double dist = from_spectator_to_center_of_figure.magnitude();

			distribution.insert(make_pair(dist, P));

		}

		int g = 1;

		for (auto& i : distribution)
		{

			if (g == distribution.size() && g!= 1)
			{
				i.second->set_color(191);
				continue;
			}

			i.second->set_color(64 + 16*(g-1));

			g++;
		}

		for (auto L : shapes)
		{
			double object_color[3];

			object_color[0] = L->get_color();
			object_color[1] = L->get_color();
			object_color[2] = L->get_color();
			

#pragma omp parallel for
			
			for (int j = 0; j < screen.get_height(); j++)
			{
				for (int i = 0; i < screen.get_width(); i++)
				{
					
						int Cx = 0;
						int Cy = 0;

						if (screen.get_width() % 2 == 0)
						{
							Cx = i - screen.get_width() / 2;
						}

						if (screen.get_width() % 2 != 0)
						{
							Cx = i - (screen.get_width() - 1) / 2;
						}

						if (screen.get_height() % 2 == 0)
						{
							Cy = (screen.get_height() / 2) - j;
						}

						if (screen.get_height() % 2 != 0)
						{
							Cy = ((screen.get_height() - 1) / 2) - j;
						}

						double Vx = (double)Cx / (double)screen.get_width();
						double Vy = (double)Cy / (double)screen.get_width();

						current = up_on_screen * Vy + tangent_on_screen * Vx;

						Vector3d ray_direction = center_of_screen + current - spectator_position;
						Vector3d ray_origin = spectator_position;

						Vector3d variation = forward + up_on_screen * Vy;

						if (Greater(forward ^ variation, (camera.get_angle_of_view() / 2.0)))
						{
							continue;
						}

						if (L->ray_intersect(ray_origin, ray_direction))
						{
							Vector3d point_on_object = L->ret_point(ray_origin, ray_direction);
							Vector3d normal_to_object = L->ret_normal(point_on_object);

							Vector3d from_center_of_screen_to_point = point_on_object - center_of_screen;

							double projection = from_center_of_screen_to_point.D_product(normal_to_screen);

							/*if (Greater(projection, camera.get_dist_screen_scene()) || projection < 0.001) /// Throw не работает при parallel for
							{
								throw std::runtime_error("Some figure has gone beyond the boundaries.\n");
							}*/

							Vector3d light_position = lamp.get_position();
							Vector3d from_point_on_object_to_lamp = light_position - point_on_object;
							Vector3d from_point_on_object_to_camera = spectator_position - point_on_object;

							from_point_on_object_to_lamp.normalize();

							double cur_color[3];

							double light_intense = from_point_on_object_to_lamp.D_product(normal_to_object);

							if (light_intense <= 0.0)
							{
								cur_color[0] = 0.0;
								cur_color[1] = 0.0;
								cur_color[2] = 0.0;

								image.draw_point(i, j, cur_color);

								continue;
							}

							cur_color[0] = object_color[0] * light_intense;
							cur_color[1] = object_color[1] * light_intense;
							cur_color[2] = object_color[2] * light_intense;

							Vector3d R = normal_to_object * 2.0 * normal_to_object.D_product(from_point_on_object_to_lamp) - from_point_on_object_to_lamp;
							Vector3d N = normal_to_object;
							Vector3d L = from_point_on_object_to_lamp;
							Vector3d C = from_point_on_object_to_camera;
							Vector3d H = (L + C);

							double k = 128.0;

							H.normalize();
							C.normalize();
							L.normalize();
							N.normalize();
							R.normalize();

							Vector3d color(cur_color[0], cur_color[1], cur_color[2]);

							double ambientStrength = 0.9;
							Vector3d ambient = color * ambientStrength;

							double diffuse_component = std::max(0.0, N.D_product(L));
							Vector3d diffuse = color * diffuse_component;

							double specularStrength = 0.9;
							double specular_component = pow(max(0.0, R.D_product(C)), k);
							Vector3d specular = color * specularStrength * specular_component;

							Vector3d result = (ambient + specular + diffuse);

							cur_color[0] = result.get_v1();
							cur_color[1] = result.get_v2();
							cur_color[2] = result.get_v3();

							image.draw_point(i, j, cur_color);

						}	
				}
			}
		}

		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(stop - start);

		std::cout << "--------------" << endl;
		std::cout << duration.count() << " mcs spent." << endl;
		std::cout << "--------------" << endl;

		image.display();

		image.normalize(0, 255);
		image.save_bmp("render.bmp");

		std::cout << "Rendering is complete.\n";

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
		return 1;
	}
}