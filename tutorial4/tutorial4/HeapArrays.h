#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include "TextArea.h"
#include "defs.h"

class HeapArrays {
private:
    TextArea* objectArray;
    TextArea** pointerArray;
    int count;

public:
    HeapArrays();
    ~HeapArrays();

    TextArea* getObjectArray();
    TextArea** getPointerArray();

    TextArea* getPointer(int index);
    TextArea& getReference(int index);

    void addTextArea(const TextArea& ta);
};

#endif