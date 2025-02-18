#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
private:
    int r;
    int g;
    int b;

public:
    RGB(int red = 0, int green = 0, int blue = 0);
    RGB(CuColour colour);
    RGB();

    int getR() const;
    int getG() const;
    int getB() const;

    CuColour getColour() const;

    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setColour(CuColour colour);

    // Static functions for commonly used colors
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif
