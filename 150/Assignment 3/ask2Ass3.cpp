#include <Graph.h> 
#include <Simple_window.h>

using namespace Graph_lib;

int main ()
{ 
    Point window(100,100);  
    Simple_window win(window,300,540,"Olympic Symbol");

	win.color(Color::white);

	Graph_lib::Text text(Point(85,40),"Olympic Games");
	win.attach(text);
    text.set_font(Font::times_bold);
    text.set_font_size(20);

    Graph_lib::Circle circle1(Point(60,120),40);
	circle1.set_color(Color::blue);
	circle1.set_style(Line_style(Line_style::solid,5));
	win.attach(circle1);

	Graph_lib::Circle circle2(Point(150,120),40);
	circle2.set_color(Color::black);
	circle2.set_style(Line_style(Line_style::solid,5));
	win.attach(circle2);

	Graph_lib::Circle circle3(Point(240,120),40);
	circle3.set_color(Color::red);
	circle3.set_style(Line_style(Line_style::solid,5));
	win.attach(circle3);

	Graph_lib::Circle circle4(Point(105,170),40);
	circle4.set_color(Color::yellow);
	circle4.set_style(Line_style(Line_style::solid,5));
	win.attach(circle4);

	Graph_lib::Circle circle5(Point(195,170),40);
	circle5.set_color(Color::green);
	circle5.set_style(Line_style(Line_style::solid,5));
	win.attach(circle5);

	Image ii(Point(-40,250),"2004.jpg"); 
    win.attach(ii);

	win.wait_for_button();
} 
