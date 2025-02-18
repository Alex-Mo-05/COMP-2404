#ifndef RGB_H
#include "defs.h"

using namespace std;


class RGB {
    public:
        int r;
        int g;
        int b;

        RGB(int red, int green, int blue);
        RGB (CuColour colour);
        RGB () ;


int getR();

int getB();

int getG();

CuColour getColour () ;

void setR(int r);

void setB(int b);

void setG(int g) ;

void setColour(CuColour colour);


};


#endif