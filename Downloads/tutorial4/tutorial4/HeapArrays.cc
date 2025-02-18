#include "HeapArrays.h"

HeapArrays::HeapArrays() : count(0) {
    objectArray = new TextArea[MAX_ARRAY];
    pointerArray = new TextArea*[MAX_ARRAY];
    for (int i = 0; i < MAX_ARRAY; ++i) {
        pointerArray[i] = nullptr;
    }
}

HeapArrays::~HeapArrays() {
    delete[] objectArray;
    for (int i = 0; i < MAX_ARRAY; ++i) {
        delete pointerArray[i];
    }
    delete[] pointerArray;
}

TextArea* HeapArrays::getObjectArray() {
    return objectArray;
}

TextArea** HeapArrays::getPointerArray() {
    return pointerArray;
}

TextArea* HeapArrays::getPointer(int index) {
    if (index >= 0 && index < MAX_ARRAY) {
        return pointerArray[index];
    }
    return nullptr;
}

TextArea& HeapArrays::getReference(int index) {
    return objectArray[index];
}

void HeapArrays::addTextArea(const TextArea& ta) {
    if (count < MAX_ARRAY) {
        objectArray[count] = ta;
        pointerArray[count] = new TextArea(ta);
        count++;
    }
}