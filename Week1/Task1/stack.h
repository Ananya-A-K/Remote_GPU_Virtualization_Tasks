#ifndef STACK_H
#define STACK_H
#include "ds.h"
#include "linkedlist.h"
template <typename T>
class Stack : public DS<T> {
private:
    LL<T> ll;  // Stackes w/ LL
public:
    Stack() {};  // cons
    ~Stack() {};  // des
    void append(const T& item) override {
        ll.append(item);  // Push 
    }
    void removeLast() override {
        ll.removeLast();  // Pop 
    }
    bool isEqual(const DS<T>& other) const {
        const Stack<T>* st2=dynamic_cast<const Stack<T>*>(&other);
        if (!st2) {
            return false;
        }
        return ll.isEqual(other);
    }
    bool isNotEqual(const DS<T>& other) const {
        return !isEqual(other);
    }
    void print(std::ostream& os) const override {
        ll.print(os);
    }
    DS<T>* cpy() const override {  // deep cpy
        return ll.cpy();
    }
};
#endif
