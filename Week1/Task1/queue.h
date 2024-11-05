#ifndef QUEUE_H
#define QUEUE_H
#include "ds.h"
#include "linkedlist.h"
template <typename T>
class Queue : public DS<T> {
private:
    LL<T> ll;  // Queue implemented w/ LL
public:
    Queue() {}
    ~Queue() {}
    void append(const T& item) override {
        ll.append(item);  // Enqueue
    }
    void removeLast() override {
        ll.removeLast();  // Dequeue (removes first element)
    }
    bool isEqual(const DS<T>& other) const {
        const Queue<T>* q2= dynamic_cast<const Queue<T>*>(&other);
        if (!q2) {
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
    DS<T>* cpy() const override {
        return ll.cpy();
    }
};

#endif
