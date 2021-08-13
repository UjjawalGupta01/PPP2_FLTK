
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    const Graph_lib::Point wind_start {100,100};
    constexpr auto win_size {1200};
    const auto smile_size {wind_start.x};


    Graph_lib::Simple_window win1  {wind_start,win_size,win_size,"Test of Circle"};

    Graph_lib::Circle cir {wind_start,smile_size};
    win1.attach(cir);

    win1.wait_for_button();
}
