#include "Panel.h"
#include <string>

using namespace std;


Panel::Panel() {
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->id = "Default";
    this->buttonCount = 0;
}

Panel::Panel(int x, int y, int width, int height, string id) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->buttonCount = 0;
}

bool Panel::addButton(const Button &button) {
    if (buttonCount >= MAX_COMPONENTS) return false;

    for (int i = 0; i < buttonCount; i++) {
        if (buttons[i].overlaps(button)) return false;
    }

    buttons[buttonCount++] = button;
    return true;
}

bool Panel::removeButton(string id) {
    for (int i = 0; i < buttonCount; i++) {
        if (buttons[i].getLabel() == id) {
            for (int j = i; j < buttonCount - 1; j++) {
                buttons[j] = buttons[j + 1];
            }
            buttonCount--;
            return true;
        }
    }
    return false;
}

void Panel::draw(Display *display, Window win, GC gc) {
    XDrawRectangle(display, win, gc, this->x, this->y, this->width, this->height);
    for (int i = 0; i < buttonCount; i++) {
        buttons[i].draw(display, win, gc, this->x, this->y);
    }
}

bool Panel::overlaps(const Panel &p) const {
    bool horizontalOverlap = (this->x + this->width > p->x) && (p->x + p->width > this->x);
    bool verticalOverlap = (this->y + this->height > p->y) && (p->y + p->height > this->y);

    return horizontalOverlap && verticalOverlap;
}

void Panel::print() const {
    cout << "Panel: " << this->id << "\nPosition: " << this->x << ", " << this->y
              << "\nSize: " << this->width << ", " << this->height;

}