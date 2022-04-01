//g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Lines_window.cpp drill16.cpp `fltk-config --ldflags --use-images` -o drill16

#include <iostream>
#include <string>
#include "GUI/Lines_window.h"

int main(){
try{

	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();

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