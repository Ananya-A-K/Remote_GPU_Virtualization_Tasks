#include <iostream>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
int main() {
    LL<int> list1;
    list1+=10;
    list1+=20;
    list1+=30;
    LL<int> list2;
    list2+=10;
    list2+=20;
    list2+=30;
    std::cout<<"LL1: "<<list1<<std::endl;
    std::cout<<"LL2: "<<list2<<std::endl;
    std::cout<<"LL1 == LL2: "<<(list1==list2)<<std::endl;
    std::cout<<"LL1 != LL2: "<<(list1!=list2)<<std::endl;
    list1-=30;
    std::cout<<"LL1 after -= 30: "<<list1<<std::endl;

    Stack<int> stack1;
    stack1+=100;
    stack1+=200;
    stack1+=300;
    Stack<int> stack2;
    stack2+=100;
    stack2+=200;
    stack2+=300;
    std::cout<<"Stack1: "<<stack1<<std::endl;
    std::cout<<"Stack2: "<<stack2<<std::endl;
    // std::cout << "Stack1 == Stack2: " << (stack1 == stack2) << std::endl;
    // std::cout << "Stack1 != Stack2: " << (stack1 != stack2) << std::endl;
    stack1-=300;
    std::cout<<"Stack1 after removing last element: "<<stack2<<std::endl;

    Queue<int> queue1;
    queue1+=1;
    queue1+=2;
    queue1+=3;
    Queue<int> queue2;
    queue2+=1;
    queue2+=2;
    queue2+=3;
    std::cout<<"Queue1: "<<queue1<<std::endl;
    std::cout<<"Queue2: "<<queue2<<std::endl;
    // std::cout << "Queue1 == Queue2: " << (queue1 == queue2) << std::endl;
    // std::cout << "Queue1 != Queue2: " << (queue1 != queue2) << std::endl;
    queue1-=3;
    std::cout<<"Queue1 after -= 3: "<<queue1<<std::endl;

    return 0;
}
