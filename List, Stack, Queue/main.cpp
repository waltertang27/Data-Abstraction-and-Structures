/*
 * Lab4
 * @author Walter Tang
 * @file main.cpp
 * The purpose of this lab is to use LinkedList, Stack, and Queues  and manipulate their data
 */

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;
/*
 * This program tests the LinkedList, Stack, and Queue methods
 */
int main() {
    bool status;
    cout << "LinkedList~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    LinkedList *list = new LinkedList();
    Dollar d1(50, 50);
    Node n1(d1);
    list->insertNode(&n1, 1);
    cout << n1.data << " was inserted to the LinkedList as the #1 element\n";
    cout << list;
    Dollar d2(100, 20);
    Node n2(d2);
    list->insertNode(&n2, 2);
    cout << n2.data << " was inserted to the LinkedList as the #2 element\n";
    cout << list;
    Dollar d3(10, 20);
    Node n3(d3);
    list->insertNode(&n3, 3);
    cout << n3.data << " was inserted to the LinkedList as the #3 element\n";
    cout << list;
    Dollar d4(3, 3);
    Node n4(d4);
    list->insertNode(&n4, 4);
    cout << n4.data << " was inserted to the LinkedList as the #4 element\n";
    cout << list;
    Dollar d5(25, 26);
    Node n5(d5);
    list->insertNode(&n5, 5);
    cout << n5.data << " was inserted to the LinkedList as the #5 element\n";
    cout << list;
    Dollar d6(11, 99);
    Node n6(d6);
    list->insertNode(&n6, 6);
    cout << n6.data << " was inserted to the LinkedList as the #6 element\n";
    cout << list;
    Dollar d7(300, 15);
    Node n7(d7);
    list->insertNode(&n7, 7);
    cout << n7.data << " was inserted to the LinkedList as the #7 element\n";
    cout << list;

    cout << n4.data << " is the #" << list->searchList(&n4) << " element in the LinkedList\n";
    cout << list;
    cout << n1.data << " is the #" << list->searchList(&n1) << " element in the LinkedList\n";
    cout << list;

    Dollar dTemp = n1.data;
    if(list->deleteNode(&n1)) {
        cout << dTemp << " was deleted from the list!\n";
    }
    else {
        cout << dTemp << " was not found in the list!\n";
    }
    cout << list;
    list->destroy();
    cout  << "LinkedList destroyed:\n";
    cout << list;

    cout << "Stack~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Stack *stack = new Stack();
    Dollar d8(20, 21);
    Node s1(d8);
    stack->push(&s1);
    cout << s1.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d9(50, 60);
    Node s2(d9);
    stack->push(&s2);
    cout << s2.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d10(11, 55);
    Node s3(d10);
    stack->push(&s3);
    cout << s3.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d11(99, 99);
    Node s4(d11);
    stack->push(&s4);
    cout << s4.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d12(111, 22);
    Node s5(d12);
    stack->push(&s5);
    cout << s5.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d13(14, 0);
    Node s6(d13);
    stack->push(&s6);
    cout << s6.data << " was pushed to the stack!\n";
    cout << stack;
    Dollar d14(1, 1);
    Node s7(d14);
    stack->push(&s7);
    cout << s7.data << " was pushed to the stack!\n";
    cout << stack;

    cout << stack;

    Dollar test;

    status = stack->pop(test);
    if(status) {
        cout << test << " was popped from the stack!\n";
    }
    else {
        cout << "Stack is empty!\n";
    }

    cout << stack;


    status =  stack->peek(test);
    if(status) {
        cout << test << " was peeked from the stack!\n";
    }
    else {
        cout << "Stack is empty!\n";
    }

    cout << stack;

    stack->destroy();
    cout << "Stack destroyed:\n";
    cout << stack;


    cout << "Queue~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Queue *queue = new Queue();

    Dollar d15(0, 99);
    Node q1(d15);
    queue->enqueue(&q1);
    cout << q1.data << " was enqueued!\n";
    cout << queue;
    Dollar d16(0, 50);
    Node q2(d16);
    queue->enqueue(&q2);
    cout << q2.data << " was enqueued!\n";
    cout << queue;
    Dollar d17(49, 99);
    Node q3(d17);
    queue->enqueue(&q3);
    cout <<q3.data << " was enqueued!\n";
    cout << queue;
    Dollar d18(500, 0);
    Node q4(d18);
    queue->enqueue(&q4);
    cout << q4.data << " was enqueued!\n";
    cout << queue;
    Dollar d19(45, 45);
    Node q5(d19);
    queue->enqueue(&q5);
    cout << q5.data << " was enqueued!\n";
    cout << queue;
    status = queue->peekRear(test);
    if(status) {
        cout << test << " was peeked from the rear!\n";
    }
    else {
        cout << "Queue is empty!\n";
    }
    cout << queue;
    Dollar d20(20, 25);
    Node q6(d20);
    queue->enqueue(&q6);
    cout << q6.data << " was enqueued!\n";
    cout << queue;
    Dollar d21(89, 76);
    Node q7(d21);
    queue->enqueue(&q7);
    cout << q7.data << " was enqueued!\n";
    cout << queue;

    Dollar x;
    status = queue->dequeue(x);
    if(status) {
        cout << x << " was dequeued!\n";
    }
    else {
        cout << "Queue is empty!\n";
    }
    cout << queue;

    Dollar x1, x2;
    status = queue->peekFront(x1);
    if(status) {
        cout << x1 << " is peeked from the front\n";
    }
    else {
        cout << "Queue is empty!\n";
    }
    cout << queue;
    status = queue->peekRear(x2);
    if(status) {
        cout << x2 << " is peeked from the rear\n";
    }
    else {
        cout << "Queue is empty!\n";
    }
    cout << queue;

    queue->destroy();
    cout << "Queue destroyed:\n";
    cout << queue;

    return 0;
}
