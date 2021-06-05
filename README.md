# PPP2_FLTK
Updates to GUI files from Programming: Principles and Practice using C++ (Second Edition) using FLTK 1.3.6, Visual Studio 2019.

# Usage
Put where your project file is.

# VS Settings
Make sure to add the location of FLTK to your paths (header and libs).  I didn't follow the book on putting in the VC directories.  I just built FLTK and then added the paths.

For example: say I built FLTK in c:\source\FLTK-1.3.6.
In VC++ Directories add the path as is for Included Directories.  For Library Directories it would be c:\source\FLTK-1.3.6\lib

Under Linker-->Input add these to Additional Dependencies
* fltkd.lib
* fltkjpegd.lib
* fltkimagesd.lib
* comctl32.lib

# Odds and Ends

1.  I took away some of the use of namespace in the files.
2.  Lot's of warnings.  I chose not to correct as just for this course and any issues seem minor.
3.  In the code for the course, if puting Graph_lib into the namespace (using namespace Graph_lib), some types will still need Graph_lib (e.g., Ploygon will need Graph_lib::Polygon).  VS will let you know.  Since I don't use the using namespace.. I didn't work on this nusicance.  I just use Graph_lib:: on everything, like:
```C++
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    Graph_lib::Point tl(100, 100);           // to become top left  corner of window

    Graph_lib::Simple_window win(tl, 600, 400, "Canvas");    // make a simple window

    Graph_lib::Polygon poly;                // make a shape (a polygon)

    poly.add(Graph_lib::Point(300, 200));    // add a point
    poly.add(Graph_lib::Point(350, 100));    // add another point
    poly.add(Graph_lib::Point(400, 200));    // add a third point 

    poly.set_color(Graph_lib::Color::red);  // adjust properties of poly

    win.attach(poly);           // connect poly to the window

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
```
