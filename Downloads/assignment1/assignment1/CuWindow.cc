#include "CuWindow.h"
#include <unistd.h>

CuWindow::CuWindow() : width(800), height(600), name("Default"), panelCount(0), background(RGB()) {
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, width, height, 1, 0, background.getColour());
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
}

CuWindow::CuWindow(string name, int width, int height, RGB background)
    : name(name), width(width), height(height), panelCount(0), background(background) {
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, width, height, 1, 0, background.getColour());
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
}

CuWindow::~CuWindow() {
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

bool CuWindow::addPanel(const Panel &panel) {
    if (panelCount >= MAX_COMPONENTS) return false;

    for (int i = 0; i < panelCount; i++) {
        if (panels[i].overlaps(panel)) return false;
    }

    panels[panelCount++] = panel;
    return true;
}

bool CuWindow::removePanel(string id) {
    for (int i = 0; i < panelCount; i++) {
        if (panels[i].getId() == id) {
            for (int j = i; j < panelCount - 1; j++) {
                panels[j] = panels[j + 1];
            }
            panelCount--;
            return true;
        }
    }
    return false;
}

Panel *CuWindow::getPanel(cstring id) {
    for (int i = 0; i < panelCount; i++) {
        if (panels[i].getId() == id) {
            return &panels[i];
        }
    }
    return nullptr;
}

void CuWindow::draw() {
    usleep(100000);
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    for (int i = 0; i < panelCount; i++) {
        panels[i].draw(display, window, gc);
    }
}

void CuWindow::print() {
    std::cout << "CuWindow: " << name << "\nSize: " << width << "x" << height << "\nPanels: " << panelCount << std::endl;
    for (int i = 0; i < panelCount; i++) {
        panels[i].print();
    }
}

void CuWindow::printPanels() {
    for (int i = 0; i < panelCount; i++) {
        cout << "" << panels[i]->id << "";
    }
}

void CuWindow::printPanelButtons () {
    for (int i = 0; i < panelCount; i++) {
        for (int j = 0; j < buttonCount; j++) {
            cout << "" << panels[i]->buttons[j]->label << "";

        }
    }
}
