#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ds.h"

class LinkedList : public DataStructure {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    
    void append(int value) override;
    void remove() override;
    void print(std::ostream& os) const override;

    bool operator==(const DataStructure& other) const override;
    bool operator!=(const DataStructure& other) const override;
    DataStructure& operator=(const DataStructure& other) override;
    DataStructure* operator+(const DataStructure& other) override;
    DataStructure& operator+=(int value) override;
    DataStructure& operator-=(int value) override;
    //operator bool() const override;
};

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::remove() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::print(std::ostream& os) const {
    Node* temp = head;
    while (temp != nullptr) {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << std::endl;
}

bool LinkedList::operator==(const DataStructure& other) const {
    const LinkedList& otherList = dynamic_cast<const LinkedList&>(other);
    Node* temp1 = head;
    Node* temp2 = otherList.head;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1 == nullptr && temp2 == nullptr;
}

bool LinkedList::operator!=(const DataStructure& other) const {
    return !(*this == other);
}

DataStructure& LinkedList::operator=(const DataStructure& other) {
    const LinkedList& otherList = dynamic_cast<const LinkedList&>(other);
    while (head != nullptr) {
        remove();
    }
    Node* temp = otherList.head;
    while (temp != nullptr) {
        append(temp->data);
        temp = temp->next;
    }
    return *this;
}

DataStructure* LinkedList::operator+(const DataStructure& other) {
    LinkedList* newList = new LinkedList();
    const LinkedList& otherList = dynamic_cast<const LinkedList&>(other);
    Node* temp = head;
    while (temp != nullptr) {
        newList->append(temp->data);
        temp = temp->next;
    }
    temp = otherList.head;
    while (temp != nullptr) {
        newList->append(temp->data);
        temp = temp->next;
    }
    return newList;
}

DataStructure& LinkedList::operator+=(int value) {
    append(value);
    return *this;
}

DataStructure& LinkedList::operator-=(int value) {
    if (head != nullptr && head->data == value) {
        remove();
    } else {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == value) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                break;
            }
            temp = temp->next;
        }
    }
    return *this;
}

// LinkedList::operator bool() const {
//     return head != nullptr;
// }

#endif
