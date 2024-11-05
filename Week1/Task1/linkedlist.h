#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ds.h"
template <typename T>
struct node {
    T data;
    node* next;
    node(const T& data) : data(data), next(nullptr) {}  // cons
};
template <typename T>
class LL : public DS<T> {
private:
    node<T>* head;
public:
    LL() : head(nullptr) {};  // cons
    ~LL() {};  // des
    void append(const T& item) override;
    void removeLast() override;
    bool isEqual(const DS<T>& other) const override;
    bool isNotEqual(const DS<T>& other) const override;
    void print(std::ostream& os) const override;
    DS<T>* cpy() const override;
};
template <typename T>
void LL<T>::append(const T& item) {
    node<T>* n=new node<T>(item);
    if (!head) {
        head=n;
    } else {
        node<T>* t=head;
        while (t->next) {
            t=t->next;
        }
        t->next=n;
    }
}
template <typename T>
void LL<T>::removeLast() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    node<T>* t=head;
    while (t->next && t->next->next) {
        t=t->next;
    }
    delete t->next;
    t->next=nullptr;
}
template <typename T>
bool LL<T>::isEqual(const DS<T>& other) const {
    const LL<T>& ll2=dynamic_cast<const LL<T>&>(other);
    node<T>* curr=head;
    node<T>* curr2=ll2.head;
    while (curr && curr2) {
        if (curr->data!=curr2->data) return false;
        curr=curr->next;
        curr2=curr2->next;
    }
    return curr==nullptr && curr2==nullptr;
}
template <typename T>
bool LL<T>::isNotEqual(const DS<T>& other) const {
    return !isEqual(other);
}
template <typename T>
void LL<T>::print(std::ostream& os) const {
    node<T>* t = head;
    while (t) {
        os<<t->data<<" ";
        t=t->next;
    }
    os<<std::endl;
}
template <typename T>
DS<T>* LL<T>::cpy() const {  // deep cpy
    LL<T>* l2= new LL<T>();
    node<T>* t= head;
    while (t) {
        l2->append(t->data);
        t= t->next;
    }
    return l2;
}
#endif
