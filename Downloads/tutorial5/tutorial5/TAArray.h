#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"

class TAArray {
private:
    TextArea** textAreas; // Dynamically allocated array of TextArea pointers
    int capacity;         // Maximum capacity of the array
    int size;             // Current number of TextAreas in the array

public:
    // Constructor
    TAArray(int capacity = 10);

    // Destructor
    ~TAArray();

    // Add a TextArea to the back of the array
    bool add(TextArea* ta);

    // Add a TextArea at a specific index
    bool add(TextArea* ta, int index);

    // Get the number of TextAreas in the array
    int getSize() const;

    // Get the TextArea at a specific index
    TextArea* get(int index) const;

    TextArea* get(const std::string& id) const;


    // Remove the TextArea at a specific index
    TextArea* remove(int index);


    TextArea* remove(const std::string& id);


    // Print all TextAreas in the array (for debugging)
    void print() const;
};

#endif