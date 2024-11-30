#ifndef STACK_H
#define STACK_H

#include "ds.h"
#include "linkedlist.h"

class Stack : public LinkedList {
private:
    LinkedList list;

public:
    Stack() = default;
    void append(int value) override;
    void remove() override;
    void print(std::ostream& os) const override;

    bool operator==(const DataStructure& other) const override;
    bool operator!=(const DataStructure& other) const override;
    DataStructure& operator=(const DataStructure& other) override;
    DataStructure* operator+(const DataStructure& other) override;
    DataStructure& operator+=(int value) override;
    DataStructure& operator-=(int value) override;
};

void Stack::append(int value) {
    list.append(value);
}

void Stack::remove() {
    list.remove(); 
}

void Stack::print(std::ostream& os) const {
    list.print(os);
}

bool Stack::operator==(const DataStructure& other) const {
    return list == dynamic_cast<const Stack&>(other).list;
}

bool Stack::operator!=(const DataStructure& other) const {
    return !(*this == other);
}

DataStructure& Stack::operator=(const DataStructure& other) {
    list = dynamic_cast<const Stack&>(other).list;
    return *this;
}

DataStructure* Stack::operator+(const DataStructure& other) {
    std::cout<<"NA"<<std::endl;
    return this;
}

DataStructure& Stack::operator+=(int value) {
    append(value);
    return *this;
}

DataStructure& Stack::operator-=(int value) {
    list -= value;
    return *this;
}

#endif
