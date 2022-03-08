#include "Lines_window.h"
#include "Graph.h"

//g++ lines_main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o lines_main `fltk-config --ldflags --use-images`

int main()
{
    Lines_window win {Point{100,100}, 1920, 1080, "Lines"};
    
    return gui_main();
}
