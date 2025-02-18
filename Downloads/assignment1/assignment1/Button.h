#ifndef BUTTON_H

#include "defs.h"
#include "RGB.h"
#include <string>
#include <iostream>

class Button {
private:
    int x, y, width, height;
    std::string label;
    RGB fill, border;

public:
    Button();
    Button(int x, int y, int width, int height, const std::string &label, const RGB &fill, const RGB &border);
    Button(int x, int y, int width, int height, const std::string &label, CuColour fill, CuColour border);

    void draw(Display *display, Window win, GC gc, int parentX, int parentY);
    bool overlaps(const Button &b);
    void print();
    int getx();
    int gety();
    int getWidth();
    int getHeight();
};

#endif