#include "TAArray.h"
#include <iostream>

// Constructor
TAArray::TAArray(int capacity) : capacity(capacity), size(0) {
    textAreas = new TextArea*[capacity]; // Allocate memory for the array
    for (int i = 0; i < capacity; ++i) {
        textAreas[i] = nullptr; // Initialize all pointers to nullptr
    }
}

// Destructor
TAArray::~TAArray() {
    for (int i = 0; i < size; ++i) {
        delete textAreas[i]; // Delete each TextArea object
    }
    delete[] textAreas; // Delete the array itself
}

// Add a TextArea to the back of the array
bool TAArray::add(TextArea* ta) {
    if (size >= capacity) return false; // Array is full
    textAreas[size++] = ta; // Add to the end
    return true;
}

// Add a TextArea at a specific index
bool TAArray::add(TextArea* ta, int index) {
    if (index < 0 || index > size || size >= capacity) return false; // Invalid index or array is full

    // Shift elements to the right to make space for the new TextArea
    for (int i = size; i > index; --i) {
        textAreas[i] = textAreas[i - 1];
    }

    textAreas[index] = ta; // Insert the new TextArea
    size++;                // Increment size
    return true;
}

// Get the number of TextAreas in the array
int TAArray::getSize() const {
    return size;
}

// Get the TextArea at a specific index
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) return nullptr; // Invalid index
    return textAreas[index];
}

// Remove the TextArea at a specific index
TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) return nullptr; // Invalid index

    TextArea* removed = textAreas[index]; // Store the TextArea to be removed

    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; ++i) {
        textAreas[i] = textAreas[i + 1];
    }

    textAreas[--size] = nullptr; // Clear the last element
    return removed;              // Return the removed TextArea
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (textAreas[i] && textAreas[i]->getId() == id) return textAreas[i];
    }
    return nullptr;
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (textAreas[i] && textAreas[i]->getId() == id) {
            TextArea* removed = textAreas[i];
            for (int j = i; j < size - 1; ++j) textAreas[j] = textAreas[j + 1];
            textAreas[--size] = nullptr;
            return removed;
        }
    }
    return nullptr;
}


// Print all TextAreas in the array (for debugging)
void TAArray::print() const {
    for (int i = 0; i < size; ++i) {
        if (textAreas[i] != nullptr) {
            textAreas[i]->print(); // Call the print function of each TextArea
        }
    }
}