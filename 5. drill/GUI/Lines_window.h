#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

private:
    Open_polyline lines;

    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    Menu color_menu;
    Button comenu_button;
    Menu style_menu;
    Button stmenu_button;

    void change(Color c) { lines.set_color(c); }
	void change_style(Line_style s) { lines.set_style(s); }

	void hide_comenu() { color_menu.hide(); comenu_button.show(); }
	void hide_stmenu() { style_menu.hide(); stmenu_button.show(); }

	void red_pressed() { change(Color::red); hide_comenu(); }
	void blue_pressed() { change(Color::blue); hide_comenu(); }
	void black_pressed() { change(Color::black); hide_comenu(); }

	void comenu_pressed() { comenu_button.hide(); color_menu.show(); }
	

	void dot_pressed() { change_style(Line_style::dot); hide_stmenu(); }
	void dash_pressed() { change_style(Line_style::dash); hide_stmenu(); }
	void solid_pressed() { change_style(Line_style::solid); hide_stmenu(); }

	void stmenu_pressed() { stmenu_button.hide(); style_menu.show(); }

	void next();
	void quit();

	static void cb_red(Address,Address);
    static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
    static void cb_comenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_stmenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);
};