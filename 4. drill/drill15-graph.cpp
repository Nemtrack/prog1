//g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill15-graph.cpp `fltk-config --ldflags --use-images` -o drill15-graph

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) {return cos(x) + slope(x);}


int main(){
try{

	Simple_window win {Point{100, 100}, 600, 600, "Function graphs."};
	
	int length = 400;
	int notch = 20;

	Axis x {Axis::x, Point{100, 300}, length, notch, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, length, notch, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);


	int min = -10;
	int max = 11;
	int numberOfPoints = 400;
	int xscale = 20;
	int yscale = 20;

	Point t1{300, 300};

	Function fone {one, min, max, t1, numberOfPoints, xscale, yscale};
	win.attach(fone);

	Function fslope {slope, min, max, t1, numberOfPoints, xscale, yscale};
	win.attach(fslope);

	Text ftext {Point{300 - length/2 + min, 300 + ((300 - length/2 + min))}, "x/2"};
	win.attach(ftext);

	Function fsquare {square, min, max, t1, numberOfPoints, xscale, yscale};
	win.attach(fsquare);

	Function fcos { cos, min, max, t1, numberOfPoints, xscale, yscale};
	win.attach(fcos);

	Function fsloping_cos {sloping_cos, min, max, t1, numberOfPoints, xscale, yscale};
	win.attach(fsloping_cos);

	win.wait_for_button();
}


catch(exception& e){
	cerr << "exception: " << e.what() << endl;
	return 1;
}

catch(...){
	cerr << "exception\n";
	return 2;
}
}