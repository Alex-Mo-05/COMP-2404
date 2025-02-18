#include "RGB.h"
#include "defs.h"

using namespace std;


RGB::RGB (int red, int green, int blue) {
    if ((red < 255 && red > 0) && (green < 255 && green > 0) && (blue < 255 && blue > 0)) {
        setR(red);
        setG(green);
        setB(blue);
    }
} 

RGB::RGB (CuColour colour)  {
    setColour(colour);
        }
RGB::RGB () {
            r = 0;
            g = 0;
            b = 0;
        }

int RGB::getR() {
    return this->r;
}

int RGB::getB() {
    return this->b;
}

int RGB::getG() {
    return this->g;
}

CuColour RGB::getColour () {
    return (static_cast<CuColour>(r) << 16) |
           (static_cast<CuColour>(g) << 8) |
           static_cast<CuColour>(b);
}

void RGB::setR(int r) {
    this->r = r;
}

void RGB::setB(int b) {
    this->b = b;
}

void RGB::setG(int g) {
    this->g = g;
}

void RGB::setColour(CuColour colour) {
    b = colour & 0xFF;
    g = (colour >> 8) & 0xFF;
    r = (colour >> 16) & 0xFF;
}

