#include <iostream>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

int main() {
    // Test LinkedList operations
    LinkedList list1;
    list1 += 1;
    list1 += 2;
    list1 += 3;

    LinkedList list2;
    list2 += 4;
    list2 += 5;

    std::cout << "List1: ";
    list1.print(std::cout);
    std::cout << "List2: ";
    list2.print(std::cout);

    // Concatenate list1 and list2
    LinkedList* concatenatedList = dynamic_cast<LinkedList*>(list1 + list2);
    std::cout << "Concatenated List: ";
    concatenatedList->print(std::cout);

    // Comparison
    std::cout << "List1 == List2? " << (list1 == list2 ? "Yes" : "No") << std::endl;
    std::cout << "List1 != List2? " << (list1 != list2 ? "Yes" : "No") << std::endl;

    // Testing remove operations
    std::cout << "Removing from List1: ";
    list1 -= 3;  // Removing element 2 from list1
    list1.print(std::cout);

    // Test Stack operations
    Stack stack1;
    stack1 += 10;
    stack1 += 20;
    stack1 += 30;

    Stack stack2;
    stack2 += 40;
    stack2 += 50;

    std::cout << "Stack1: ";
    stack1.print(std::cout);

    std::cout << "Stack2: ";
    stack2.print(std::cout);

    // Comparison
    std::cout << "Stack1 == Stack2? " << (stack1 == stack2 ? "Yes" : "No") << std::endl;
    std::cout << "Stack1 != Stack2? " << (stack1 != stack2 ? "Yes" : "No") << std::endl;

    // Testing remove operations
    std::cout << "Removing from Stack1: ";
    stack1 -= 30;  
    stack1.print(std::cout);

    // Test Queue operations
    Queue queue1;
    queue1 += 100;
    queue1 += 200;
    queue1 += 300;

    Queue queue2;
    queue2 += 400;
    queue2 += 500;

    std::cout << "Queue1: ";
    queue1.print(std::cout);

    std::cout << "Queue2: ";
    queue2.print(std::cout);

    // Comparison
    std::cout << "Queue1 == Queue2? " << (queue1 == queue2 ? "Yes" : "No") << std::endl;
    std::cout << "Queue1 != Queue2? " << (queue1 != queue2 ? "Yes" : "No") << std::endl;

    std::cout << "Removing from Queue1: ";
    queue1 -= 300;  // Removing element 100 from queue
    queue1.print(std::cout);

    return 0;
}
