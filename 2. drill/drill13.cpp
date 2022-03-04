/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a3.out
*/
#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){
	try{
			//ablak létrehozása
			Point t1(300, 50);
			Simple_window win(t1, 1000, 800, "My window");

			//grid létrehozása
			Lines grid;
			int x_size = 800;
			int y_size = 800;
			for(int i = 100; i <= x_size; i += 100){
				grid.add(Point(i, 0), Point(i, y_size));
				grid.add(Point(0, i), Point(x_size, i));
			}
			win.attach(grid);
			win.wait_for_button();

			//puritán módon létrehzott négyzetek
			Rectangle r1 {Point{0, 0}, 100, 100};
			win.attach(r1);
			r1.set_fill_color(Color::red);

			Rectangle r2 {Point{100, 100}, 100, 100};
			win.attach(r2);
			r2.set_fill_color(Color::red);

			Rectangle r3 {Point{200, 200}, 100, 100};
			win.attach(r3);
			r3.set_fill_color(Color::red);

			Rectangle r4 {Point{300, 300}, 100, 100};
			win.attach(r4);
			r4.set_fill_color(Color::red);

			Rectangle r5 {Point{400, 400}, 100, 100};
			win.attach(r5);
			r5.set_fill_color(Color::red);

			Rectangle r6 {Point{500, 500}, 100, 100};
			win.attach(r6);
			r6.set_fill_color(Color::red);

			Rectangle r7 {Point{600, 600}, 100, 100};
			win.attach(r7);
			r7.set_fill_color(Color::red);

			Rectangle r8 {Point{700, 700}, 100, 100};
			win.attach(r8);
			r8.set_fill_color(Color::red);
			win.set_label("Rectangles");
			win.wait_for_button();

			//képek létrehozása
			Image duo1 {Point {200,400}, "img.jpg"};
			Image duo2 {Point {400,100}, "img.jpg"};
			Image duo3 {Point {600,100}, "img.jpg"};
			win.set_label("Bitto Hexa");
			win.attach(duo1);
			win.attach(duo2);
			win.attach(duo3);
			win.wait_for_button();

			//100x100 kép létrehozása...
			Image rostas {Point {0,0}, "img2.jpg"};
			win.set_label("Rostas");
			win.attach(rostas);

			//...és mozgatása
			for (int i = 0; i < 15; ++i)
			{
				win.wait_for_button();
				if (i>6 && i<14) rostas.move(0,100);
				else rostas.move(100,0);
			}

	} catch(exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "exception\n";
		return 2;
	}
}