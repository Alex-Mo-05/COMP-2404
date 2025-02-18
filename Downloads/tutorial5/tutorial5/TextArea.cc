#include "TextArea.h"
#include <iostream>

TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text, RGB fill, RGB border)
    : dimensions({x, y, width, height}), text(text), id(id), fill(fill), border(border) {}

TextArea::TextArea(const Rectangle& rect, const std::string& id, const std::string& text, RGB fill, RGB border)
    : dimensions(rect), text(text), id(id), fill(fill), border(border) {}

TextArea::TextArea() : dimensions({0, 0, 0, 0}), text(""), id(""), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& other)
    : dimensions(other.dimensions), text("DUPLICATE"), id(other.id), fill(other.fill), border(other.border) {}

Rectangle TextArea::getDimensions() const {
    return dimensions;
}

std::string TextArea::getText() const {
    return text;
}

std::string TextArea::getId() const {
    return id;
}

RGB TextArea::getFill() const {
    return fill;
}

RGB TextArea::getBorder() const {
    return border;
}

void TextArea::setDimensions(const Rectangle& dimensions) {
    this->dimensions = dimensions;
}

void TextArea::setText(const std::string& text) {
    this->text = text;
}

void TextArea::setId(const std::string& id) {
    this->id = id;
}

void TextArea::setFill(const RGB& fill) {
    this->fill = fill;
}

void TextArea::setBorder(const RGB& border) {
    this->border = border;
}

void TextArea::draw(Display* display, Window win, GC gc, int x, int y) const {
    // Implementation for drawing the TextArea (not required for this tutorial)
}

bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const {
    std::cout << "TextArea id: " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size: " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text: " << text << std::endl;
}