#include "Simple_window.h"
#include "Graph.h"

// g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` //

double one(double x){return 1;}
double slope(double x){return x/2;}

int main()
{
    Simple_window win {Point{100,100}, 600, 600, "Function graphs"};

    Point origo {300, 300};
    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int scale = 20;
    constexpr int points = 400;

	Axis x {Axis::x, Point{100,300}, points, scale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300,500}, points, scale, "1 == 20 pixels"};
    x.set_color(Color::red);
	y.set_color(Color::red);

    Function fone{one, r_min, r_max, origo, points, scale, scale};

    Function fslope{slope, r_min, r_max, origo, points, scale, scale};
    Text t1{Point{100,380},"x/2"};

    Function cosine ( [] (double x) { return cos(x); }, r_min, r_max, origo, points, scale, scale);
    cosine.set_color(Color::blue);

    Function cosine_slope{[] (double x) {return cos(x) + slope(x);}, r_min, r_max, origo, points, scale, scale};

	win.attach(x);
	win.attach(y);
    win.attach(fone);
    win.attach(fslope);
    win.attach(t1);
    win.attach(cosine);
    win.attach(cosine_slope);

    win.wait_for_button();
}