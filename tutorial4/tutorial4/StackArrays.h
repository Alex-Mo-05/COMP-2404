#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include "TextArea.h"
#include "defs.h"

class StackArrays {
private:
    TextArea objectArray[MAX_ARRAY];
    TextArea* pointerArray[MAX_ARRAY];
    int count;

public:
    StackArrays();
    ~StackArrays();

    TextArea* getObjectArray();
    TextArea** getPointerArray();

    TextArea* getPointer(int index);
    TextArea& getReference(int index);

    void addTextArea(const TextArea& ta);
};

#endif