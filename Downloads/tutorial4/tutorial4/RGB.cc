#include "RGB.h"
#include "defs.h"

using namespace std;

RGB::RGB(int red, int green, int blue) : r(red), g(green), b(blue) {}

RGB::RGB(CuColour colour) {
    setColour(colour);
}

RGB::RGB() : r(0), g(0), b(0) {}

int RGB::getR() const {
    return r;
}

int RGB::getG() const {
    return g;
}

int RGB::getB() const {
    return b;
}

CuColour RGB::getColour() const {
    return (static_cast<CuColour>(r) << 16) |
           (static_cast<CuColour>(g) << 8) |
           static_cast<CuColour>(b);
}

void RGB::setR(int r) {
    this->r = r;
}

void RGB::setG(int g) {
    this->g = g;
}

void RGB::setB(int b) {
    this->b = b;
}

void RGB::setColour(CuColour colour) {
    b = colour & 0xFF;
    g = (colour >> 8) & 0xFF;
    r = (colour >> 16) & 0xFF;
}

// Static functions for commonly used colors
RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}

RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}

RGB RGB::RED() {
    return RGB(255, 0, 0);
}

RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}

RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}