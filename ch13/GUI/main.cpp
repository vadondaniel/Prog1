#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win {Point{100,100}, 800, 1000, "Canvas"};

    initializer_list<Point> points = {
        {0  ,0},{0  , 800},
        {100,0},{100, 800},
        {200,0},{200, 800},
        {300,0},{300, 800},
        {400,0},{400, 800},
        {500,0},{500, 800},
        {600,0},{600, 800},
        {700,0},{700, 800},
        {800,0},{800, 800},
        {0  ,0},{800,   0},
        {0,100},{800, 100},
        {0,200},{800, 200},
        {0,300},{800, 300},
        {0,400},{800, 400},
        {0,500},{800, 500},
        {0,600},{800, 600},
        {0,700},{800, 700},
        {0,800},{800, 800}
    };
    Lines v {points};
    
    Rectangle r0 {Point{0,0}, 100, 100};
    r0.set_fill_color(Color::red);
    Rectangle r1 {Point{100,100}, 100, 100};
    r1.set_fill_color(Color::red);
    Rectangle r2 {Point{200,200}, 100, 100};
    r2.set_fill_color(Color::red);
    Rectangle r3 {Point{300,300}, 100, 100};
    r3.set_fill_color(Color::red);
    Rectangle r4 {Point{400,400}, 100, 100};
    r4.set_fill_color(Color::red);
    Rectangle r5 {Point{500,500}, 100, 100};
    r5.set_fill_color(Color::red);
    Rectangle r6 {Point{600,600}, 100, 100};
    r6.set_fill_color(Color::red);
    Rectangle r7 {Point{700,700}, 100, 100};
    r7.set_fill_color(Color::red);

    Image i1 {Point{300, 600}, "plz.jpg"};
    Image i2 {Point{600, 200}, "plz.jpg"};
    Image i3 {Point{000, 500}, "plz.jpg"};

    int move_x = 0;
    int move_y = 0;

        move_x = rand() % 8;
        move_y = rand() % 8;
        move_x *= 100;
        move_y *= 100;

    Image mover {Point{move_x, move_y}, "move.jpg"};

    win.attach(v);
    win.attach(r0);
    win.attach(r1);
    win.attach(r2);
    win.attach(r3);
    win.attach(r4);
    win.attach(r5);
    win.attach(r6);
    win.attach(r7);
    win.attach(i1);
    win.attach(i2);
    win.attach(i3);
    //win.attach(mover);


    for (size_t i = 0; i < 10; i++)
    {
        move_x = rand() % 8;
        move_y = rand() % 8;
        move_x *= 100;
        move_y *= 100;
        
        Image mover {Point{move_x, move_y}, "move.jpg"};
        win.attach(mover);
        
        win.wait_for_button();
    }
    win.wait_for_button();
}