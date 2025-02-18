#include "StackArrays.h"

StackArrays::StackArrays() : count(0) {
    for (int i = 0; i < MAX_ARRAY; ++i) {
        pointerArray[i] = nullptr;
    }
}

StackArrays::~StackArrays() {
    for (int i = 0; i < MAX_ARRAY; ++i) {
        delete pointerArray[i];
    }
}

TextArea* StackArrays::getObjectArray() {
    return objectArray;
}

TextArea** StackArrays::getPointerArray() {
    return pointerArray;
}

TextArea* StackArrays::getPointer(int index) {
    if (index >= 0 && index < MAX_ARRAY) {
        return pointerArray[index];
    }
    return nullptr;
}

TextArea& StackArrays::getReference(int index) {
    return objectArray[index];
}

void StackArrays::addTextArea(const TextArea& ta) {
    if (count < MAX_ARRAY) {
        objectArray[count] = ta;
        pointerArray[count] = new TextArea(ta);
        count++;
    }
}