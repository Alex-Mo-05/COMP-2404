#include <iomanip>
#include "Button.h"
#include "Panel.cc"
#include "defs.h"

using namespace std;

Button::Button() {
    this->x=0; 
    this->y=0; 
    this->width=0;
    this->height=0;
    this->label=("Default"); 
    this->fill=(CuWhite); 
    this->border=(CuBlack);
}

Button::Button(int x, int y, int width, int height, const std::string &label, const RGB &fill, const RGB &border) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this->border = border;
}

Button::Button(int x, int y, int width, int height, const std::string &label, CuColour fill, CuColour border) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this->border = border;
}

void Button::draw(Display *display, Window win, GC gc, int parentX, int parentY) {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, parentX + this->x, parentY + this->y, this->width, this->height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, parentX + this->x, parentY + this->y, this->width, this->height);

    XSetForeground(display, gc, border.getColour());
    XDrawString(display, win, gc, parentX + this->x + (this->width/2), parentY + this->y + (this->height/2), label.c_str(), label.length());
}

bool Button::overlaps(const Button &b) const {
    bool horizontalOverlap = (this->x + this->width > b->x) && (b->x + b->width > this->x);
    bool verticalOverlap = (this->y + this->height > b->y) && (b->y + b->height > this->y);

    return horizontalOverlap && verticalOverlap;
}

void Button::print() const {
    cout << "Button: " << this->label << "\nPosition: " << this->x << ", " << this->y
              << "\nSize: " << this->width << ", " << this->height << endl << "";
}


int Button::getx() {
    return this->x;
}
int Button::gety() {
    return this->y;
}
int Button::getWidth() {
    return this->width;
}
int Button::getHeight() {
    return this->height;
}