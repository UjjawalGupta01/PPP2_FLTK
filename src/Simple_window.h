#pragma once

#include "Gui.h"
#include "Point.h"

#include <FL/Fl.H>
#include <string>

// Simple_window is basic scaffolding for ultra-simple interaction with
// graphics it provides one window with one "next" button for ultra-simple
// animation
namespace Graph_lib {
constexpr auto next_width {70};
constexpr auto next_bottom {20};

class Simple_window : public Window
{
    public:
    Simple_window(Point xy, int w, int h, const std::string& title):
        Window(xy, w, h, title), button_pushed(false),
        next_button(Point(x_max() - next_width, 0), next_width, next_bottom,
                    "Next", cb_next)
    {
        attach(next_button);
    }

    void wait_for_button()
    // modified event loop
    // handle all events (as per default), but quit when button_pushed becomes
    // true this allows graphics without control inversion
    {
        while (!button_pushed) {
            Fl::wait();
        }
        button_pushed = false;
        Fl::redraw();
    }

    Button next_button;

    private:
    bool button_pushed;

    static void cb_next(Address, Address addr)    // callback for next_button
    //  { reference_to<Simple_window>(addr).next(); }
    {
        static_cast<Simple_window*>(addr)->next();
    }

    void next()
    {
        button_pushed = true;
    }
};
}    // namespace Graph_lib
