#ifndef CUWINDOW_H
#include <string>
#include "defs.h"

using namespace std;


class CuWindow {
private:
    int width, height;
    string name;
    Panel panels[MAX_COMPONENTS];
    int panelCount;
    RGB background;

    Display* display;
    Window window;
    GC gc;

public:
    CuWindow();
    CuWindow(string name, int width, int height, RGB background);
    ~CuWindow();

    bool addPanel(const Panel &panel);
    bool removePanel(string id);
    Panel *getPanel(string id);

    void draw();
    void print();
    void printPanels();
    void printPanelButtons();
};

#endif