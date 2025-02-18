#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include <X11/Xlib.h> // For Display, Window, GC
#include "RGB.h"
#include "defs.h"

class TextArea {
private:
    Rectangle dimensions;
    std::string text;
    std::string id;
    RGB fill;
    RGB border;

public:
    TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(const Rectangle& rect, const std::string& id, const std::string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(); // No-argument constructor
    TextArea(const TextArea& other); // Copy constructor

    // Getters and setters
    Rectangle getDimensions() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

    void setDimensions(const Rectangle& dimensions);
    void setText(const std::string& text);
    void setId(const std::string& id);
    void setFill(const RGB& fill);
    void setBorder(const RGB& border);

    // Other functions
    void draw(Display* display, Window win, GC gc, int x, int y) const;
    bool overlaps(const TextArea& ta) const;
    void print() const;
};

#endif