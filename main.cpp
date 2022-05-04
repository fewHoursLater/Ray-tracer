#include "Header.h"
#include "Functions.h"
#include "Vector_3_float.h"
#include "Figure.h"
#include "Sphere.h"
#include "Box.h"
#include "Tetrahedron.h"
#include "Spectator.h"
#include "Screen.h"
#include "Light.h"



int main()
{
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
				float v1;
				float v2;
				float v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				camera.set_x(v1);
				camera.set_y(v2);
				camera.set_z(v3);
			}

			if (mark == "normal")
			{
				float v1;
				float v2;
				float v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				screen.set_norm_x(v1);
				screen.set_norm_y(v2);
				screen.set_norm_z(v3);

				Vector_3_float tmp(v1, v2, v3);

				if (tmp.magnitude() == 0)
				{
					throw std::runtime_error("Error.\n");
				}

			}

			if (mark == "up")
			{
				float v1;
				float v2;
				float v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				screen.set_up_x(v1);
				screen.set_up_y(v2);
				screen.set_up_z(v3);

			}

			if (mark == "screen")
			{
				float v1;
				str_stream >> v1;
				camera.set_dist_spec_screen(v1);

				if (v1 <= 0.0)
				{
					throw std::runtime_error("Error.\n");
				}
			}

			if (mark == "limit")
			{
				float v1;
				str_stream >> v1;
				camera.set_dist_spec_scene(v1);

			}

			if (mark == "alpha")
			{
				float v1;
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
				float v1;
				float v2;
				float v3;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;

				lamp.set_x(v1);
				lamp.set_y(v2);
				lamp.set_z(v3);
			}

			if (mark == "sphere")
			{
				float v1;
				float v2;
				float v3;
				float r;

				str_stream >> v1;
				str_stream >> v2;
				str_stream >> v3;
				str_stream >> r;

				shapes.push_back(new Sphere(v1, v2, v3, r));

			}

			if (mark == "box")
			{
				float v1;
				float v2;
				float v3;

				float w1;
				float w2;
				float w3;

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
				float a1;
				float a2;
				float a3;

				float b1;
				float b2;
				float b3;

				float c1;
				float c2;
				float c3;

				float d1;
				float d2;
				float d3;

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

				shapes.push_back(new Tetrahedron(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3));
			}
		}

		if (camera.get_dist_spec_scene() <= camera.get_dist_spec_screen())
		{
			throw std::runtime_error("Error1.\n");
		}

		if (camera.get_angle_of_view() <0.0 || camera.get_angle_of_view() >=180.0)
		{
			throw std::runtime_error("Error2.\n");
		}

		if (screen.get_height() <= 0 || screen.get_width() <=0 )
		{
			throw std::runtime_error("Error3.\n");
		}

		screen.tangent_();

		Vector_3_float normal(screen.get_norm_x(), screen.get_norm_y(), screen.get_norm_z());
		Vector_3_float up(screen.get_up_x(), screen.get_up_y(), screen.get_up_z());
		Vector_3_float tangent(screen.get_tangent_x(), screen.get_tangent_y(), screen.get_tangent_z());

		normal.normalize();
		up.normalize();
		tangent.normalize();

		screen.set_x(camera.get_x() + (camera.get_dist_spec_screen() * screen.get_norm_x()) / normal.magnitude()); /// Координаты центра Экрана
		screen.set_y(camera.get_y() + (camera.get_dist_spec_screen() * screen.get_norm_y()) / normal.magnitude());
		screen.set_z(camera.get_z() + (camera.get_dist_spec_screen() * screen.get_norm_z()) / normal.magnitude());

		Vector_3_float center(screen.get_x(), screen.get_y(), screen.get_z());
		Vector_3_float viewer(camera.get_x(), camera.get_y(), camera.get_z());

		if (fabs((up ^ normal) - 90.0f) > 0.0001)
		{
			throw std::runtime_error("Wrong angle betwen normal and up\n");
		}

		/// 1. Все точки фигур должны быть между двумя плоскостями !
		/// 2. Доработать глянец
		/// 3. Распределить цвет !

		CImg<unsigned char> image(screen.get_width(), screen.get_height(), 1, 3, 0);

		map<float, Figure*> color_map;

		for (auto j : shapes)
		{
			Vector_3_float center_of_body = j->return_centroid();
			Vector_3_float tmp_forward = center - viewer;

			float tmp = center_of_body.D_product(tmp_forward);

			color_map.insert(make_pair(tmp,j));

		}

		int g = 0;

		for (auto y : color_map)
		{
			y.second->set_color(64 + 8 * g);
			g++;
		}

		map <float, Figure*>::iterator color_it = color_map.begin();

		color_it->second->set_color(191);

		color_it = color_map.end();

		color_it--;

		color_it->second->set_color(64);

		for (auto L : shapes)
		{
			int randomColor[3];

			randomColor[0] = L->get_color();
			randomColor[1] = L->get_color();
			randomColor[2] = L->get_color();

			auto start = high_resolution_clock::now();

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

						//// Cx, Cy - координаты точки в плоскости экрана, через которую надо пускать луч, которую надо красить

						float Vx = (float)Cx / (float)screen.get_width(); ///// Объемные координаты точки в плоскости, через которую надо пускать луч
						float Vy = (float)Cy / (float)screen.get_width();

						Vector_3_float unit_up(up.get_v1(), up.get_v2(), up.get_v3());
						Vector_3_float unit_tangent(tangent.get_v1(), tangent.get_v2(), tangent.get_v3());
						Vector_3_float current;

						unit_up.normalize();
						unit_tangent.normalize();

						unit_tangent = unit_tangent * -1.0; ////////

						current = unit_up * Vy + unit_tangent * Vx;

						Vector_3_float dir = center + current - viewer;

						//cout << "i am here" << endl;

						float origin_x = viewer.get_v1(); /// Точка из которой должен идти луч. dir - Луч
						float origin_y = viewer.get_v2();
						float origin_z = viewer.get_v3();

						float dir1 = dir.get_v1();
						float dir2 = dir.get_v2();
						float dir3 = dir.get_v3();

						Vector_3_float forward = center - viewer; // луч, идущий от камеры в центр экрана
						Vector_3_float variation = forward + unit_up * Vy;

						if (Greater(forward ^ variation, (camera.get_angle_of_view() / 2.0f)))
						{
							continue;
						}

						if (L->ray_intersect(origin_x, origin_y, origin_z, dir.get_v1(), dir.get_v2(), dir.get_v3()))
						{
							Vector_3_float point = L->ret_point(origin_x, origin_y, origin_z, dir.get_v1(), dir.get_v2(), dir.get_v3()); // Точка точно на поверхности
							Vector_3_float normal_surface = L->ret_normal(point.get_v1(), point.get_v2(), point.get_v3()); //  Нормаль из точки, которая уже на поверхности

							normal_surface.normalize();

							Vector_3_float limit = normal * camera.get_dist_spec_scene();
							Vector_3_float from_center_to_point = point - center;

							if (fabs((from_center_to_point.magnitude()*cos(Pi*(limit^from_center_to_point)/180.0f)- 20.0f)>0.001 || from_center_to_point.magnitude() * cos(Pi * (limit ^ from_center_to_point) / 180.0) < 0.001))
							{
								throw std::runtime_error("Shapes is out of range.\n");
							}

							Vector_3_float light(lamp.get_x(), lamp.get_y(), lamp.get_z()); // Вектор света
							Vector_3_float point_to_lamp = light - point; // Вектор от точки на поверхности до света

							
							Vector_3_float lamp_to_point = point - light; // От света до точки на поверхности
							Vector_3_float point_to_camera = viewer - point; // От точки к камере

							point_to_lamp.normalize();

							unsigned char curcolor[3];

							curcolor[0] = randomColor[0];
							curcolor[1] = randomColor[1];
							curcolor[2] = randomColor[2];

							float light_intense = point_to_lamp.D_product(normal_surface);

							if (light_intense <= 0)
							{
								curcolor[0] = (char)0;
								curcolor[1] = (char)0;
								curcolor[2] = (char)0;

								image.draw_point(i, j, curcolor);

								continue;
							}

							Vector_3_float reflection = normal_surface * 2.0 * normal_surface.D_product(point_to_lamp) - point_to_lamp; // Отраженнный луч
																				
							float shine = 125.0f;
							float diffuse_coeff = 0.5f;
							float mirror_coeff = 0.9f;

							float phong_intense = -diffuse_coeff * (normal_surface.D_product( lamp_to_point)) + mirror_coeff * pow((normal_surface.D_product(reflection)), shine);

							curcolor[0] = curcolor[1] = curcolor[2] = (curcolor[0] + phong_intense) * light_intense;

							image.draw_point(i, j, curcolor);

						}
				}
			}

			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(stop - start);

			cout << "==================" << endl;
			cout << duration.count() << " microseconds." << endl;
			cout << "==================" << endl;
		}

		image.display();

		image.normalize(0, 255);
		image.save_bmp("render.bmp");

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
		return 1;
	}
}