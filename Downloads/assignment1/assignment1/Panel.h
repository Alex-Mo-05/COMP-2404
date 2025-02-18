#ifndef PANEL_H

#include "defs.h"
#include <string>

using namespace std;


class Panel {
private:
    int x, y, width, height;
    string id;
    Button buttons[MAX_COMPONENTS];
    int buttonCount;

public:
    Panel();
    Panel(int x, int y, int width, int height, string id);

    bool addButton(const Button &button);
    bool removeButton(string id);
    void draw(Display *display, Window win, GC gc);
    bool overlaps(Panel& p);
    void print();
    
};

#endif
