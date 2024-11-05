#ifndef DS_H
#define DS_H
#include <iostream>
template <typename T>
class DS{
public:
    DS() {}  //cons?
    ~DS() {}  // des
    virtual void append(const T& item)=0; 
    virtual void removeLast()=0; 
    virtual bool isEqual(const DS<T>& other) const  = 0; 
    virtual bool isNotEqual(const DS<T>& other) const = 0;
    virtual void print(std::ostream& os) const = 0; // ofstream..check?
    virtual DS<T>* cpy() const = 0;  

    // appnd
    DS<T>& operator+=(const T& item) {
        append(item);
        return *this;
    }
    // remove from last
    DS<T>& operator-=(const T& item) {
        removeLast();
        return *this;
    }
    // eqaul
    bool operator==(const DS<T>& other) const {
        return isEqual(other);
    }
    // not equal
    bool operator!=(const DS<T>& other) const {
        return isNotEqual(other);
    }
    // concat
    DS<T> operator+(const DS<T>& other) const {
        DS<T>* newDS=cpy();
        const DS<T>& temp=other;
        return *newDS;
    }
    // ofstream
    friend std::ostream& operator<<(std::ostream& os, const DS<T>& ds) {
        ds.print(os);
        return os;
    }
};
#endif
