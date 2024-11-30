#ifndef QUEUE_H
#define QUEUE_H

#include "ds.h"
#include "linkedlist.h"

class Queue : public DataStructure {
private:
    LinkedList list;

public:
    Queue() = default;
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

void Queue::append(int value) {
    list.append(value); 
}

void Queue::remove() {
    list.remove(); 
}

void Queue::print(std::ostream& os) const {
    list.print(os); 
}

bool Queue::operator==(const DataStructure& other) const {
    return list == dynamic_cast<const Queue&>(other).list; 
}

bool Queue::operator!=(const DataStructure& other) const {
    return !(*this == other); 
}

DataStructure& Queue::operator=(const DataStructure& other) {
    list = dynamic_cast<const Queue&>(other).list; 
    return *this;
}

DataStructure& Queue::operator+=(int value) {
    append(value); 
    return *this;
}

DataStructure& Queue::operator-=(int value) {
    list -= value; 
    return *this;
}

DataStructure* Queue::operator+(const DataStructure& other) {
    std::cout<<"NA"<<std::endl;
    return this;
}

#endif
