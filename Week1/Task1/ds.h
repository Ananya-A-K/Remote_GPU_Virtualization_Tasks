#ifndef DS_H
#define DS_H

#include <iostream>
#include <fstream>

class DataStructure {
public:
    virtual ~DataStructure() {}

    virtual void append(int value) = 0;
    virtual void remove() = 0;
    virtual void print(std::ostream& os) const = 0;
    
    virtual bool operator==(const DataStructure& other) const = 0;
    virtual bool operator!=(const DataStructure& other) const = 0;
    virtual DataStructure& operator=(const DataStructure& other) = 0;
    virtual DataStructure* operator+(const DataStructure& other) = 0;
    virtual DataStructure& operator+=(int value) = 0;
    virtual DataStructure& operator-=(int value) = 0;

};

// Definition of the assignment operator
DataStructure& DataStructure::operator=(const DataStructure& other) {
    if (this != &other) { // Check for self-assignment
        // Perform deep copy of the data members of 'other' to 'this'
        // If there are any member variables, copy them here
    }
    return *this; // Return the current object
}

#endif
