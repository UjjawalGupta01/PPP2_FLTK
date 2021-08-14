#pragma once

#include "Graph.h"
#include "Point.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <string>
#include <vector>

namespace Graph_lib {

class Shape;    // "forward declare" Shape
class Widget;

class Window : public Fl_Window
{
    public:
    Window(int w, int h,
           const std::string& title);    // let the system pick the location
    Window(Point xy, int w, int h,
           const std::string& title);    // top left corner in xy
    virtual ~Window()
    {
    }

    [[nodiscard]] int x_max() const
    {
        return w;
    }
    [[nodiscard]] int y_max() const
    {
        return h;
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
    void resize(int ww, int hh)
    {
#pragma GCC diagnostic pop
        w = ww, h = hh;
        size(ww, hh);
    }

    void set_label(const std::string& s)
    {
        label(s.c_str());
    }

    void attach(Shape& s);
    void attach(Widget& w);

    void detach(Shape& s);    // remove s from shapes
    void detach(Widget& w);    // remove w from window (deactivate callbacks)

    void put_on_top(Shape& p);    // put p on top of other shapes

    protected:
    void draw() final;

    private:
    std::vector<Shape*> shapes;    // shapes attached to window

    int w, h;    // window size

    void init();
};

int gui_main();    // invoke GUI library's main event loop

inline int x_max()
{
    return Fl::w();
}    // width of screen in pixels
inline int y_max()
{
    return Fl::h();
}    // height of screen in pixels

}    // namespace Graph_lib
