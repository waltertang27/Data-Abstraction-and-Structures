/*
 * Lab 4
 * @author Walter Tang
 * @file Stack.h
 * Includes Queue.h
 * The purpose of this lab is to use LinkedList, Stack, and Queues  and manipulate their data
 */


#ifndef LAB4_STACK_H
#define LAB4_STACK_H
#include "LinkedList.h"

class Stack : private LinkedList {
public:
    /*
     * Default constructor
     * Pre:
     * Post: Sets the start and end nodes
     * Return:
     */
    Stack();

    /*
     * Destructor
     * Pre:
     * Post: Disconnects the nodes in the stack (not dynamically allocated so no delete)
     * Return:
     */
    ~Stack();

    /*
     * Inserts an element to the top of the stack.
     * Pre: *n - Node pointer to add to stack
     * Post: Pushes the object to the end of the stack
     * Return:
     */
    void push(Node *n);

    /*
     * Removes an element from the top of the stack.
     * Pre: &d - reference variable to retrieve data
     * Post: Removes an element from the top of the stack
     * Return: true (if popped) or false (if stack is empty)
     */
    bool pop(Dollar &d);

    /*
     * Retrieves the element from the top of the stack without modifying the stack
     * Pre: &d - reference to retrieve data
     * Post:
     * Return: true (if not empty) or false (if empty)
     */
    bool peek(Dollar &d);


    /*
     * Clears the contents in the stack
     * Pre:
     * Post: sets the Nodes in the stack to null (not dynamically allocated, can't delete or free())
     * Return:
     */
    void destroy();

    /*
     * Displays the contents of the stack
     * Pre:
     * Post: prints to screen
     * Return:
     */
    void displayStack();

    /*
  * Overloads ostream << operator to print Stack
  * Pre: strm - reads objects
  *      *stack - stack
  * Post:
  * Return: strm
  */
    friend std::ostream &operator << (std::ostream &strm, Stack *stack);




};

class Queue : private LinkedList {
public:
    /*
     * Default constructor
     * Pre:
     * Post: Sets the start and end nodes.
     * Return:
     */
    Queue();

    /*
     * Destructor
     * Pre:
     * Post: Disconnects the nodes in the queue (not dynamically allocated so no delete)
     * Return:
     */
    ~Queue();

    /*
     * Adds a Node to the end of the queue
     * Pre: *n - Node pointer to add to queue
     * Post: Adds a node to the end of the queue
     * Return:
     */
    void enqueue(Node *n);

    /*
     * Removes the first node in the queue
     * Pre: &d - reference variable to retrieve data
     * Post:
     * Return: true (if retrieved) or false (if not retrieved)
     */
    bool dequeue(Dollar &d);
    /*
     * Gets the first element in the queue without modifying the queue
     * Pre: &d - reference variable to retrieve data
     * Post:
     * Return: true (if retrieved) or false (if not retrieved)
     */
    bool peekFront(Dollar &d);

    /*
     * Gets the last element of the queue without modifying the queue
     * Pre: &d - reference variable to retrieve data
     * Post:
     * Return: true (if retrieved) or false (if not retrieved)
     */
    bool peekRear(Dollar &d);


    /*
     * Clears the contents in the queue
     * Pre:
     * Post: sets the Nodes in the queue to null (not dynamically allocated, can't delete or free())
     * Return:
     */
    void destroy();


    /*
     * Displays the contents of the queue.
     * Pre:
     * Post: prints to screen
     * Return:
     */
    void displayQueue();


    /*
  * Overloads ostream << operator to print Queue
  * Pre: strm - reads objects
  *      *queue - queue
  * Post:
  * Return: strm
  */
    friend std::ostream &operator << (std::ostream &strm, Queue *q);
};

Stack::Stack() {
    setStart(new Node);
    getStart()->next = NULL;
    setStart(NULL);
    setEnd(getStart());
    setCount(0);
}

Stack::~Stack() {
    Node *pCur;
    Node *pNext;
    pCur = getStart()->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    setStart(NULL);
    setEnd(NULL);
    //can call destroy() as well, didn't reuse for testing purposes
    //destroy();
}

void Stack::push(Node *n) {
    if(isEmpty()) {
        setStart(n);
    }
    else {
        n->next = getStart();
        setStart(n);
    }
    setCount(getCount() + 1);
}

bool Stack::pop(Dollar &d) {
    if(isEmpty()) {
        return false;
    }
    else {
        d = getStart()->data;
        setStart(getStart()->next);
        setCount(getCount() - 1);
        return true;
    }
}

bool Stack::peek(Dollar &d) {
    if(isEmpty()) {
        return false;
    }
    else {
        d = getStart()->data;
        return true;
    }
}

void Stack::destroy() {
    /*
    Node *pCur;
    Node *pNext;
    pCur = getStart()->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    setStart(NULL);
    setEnd(NULL);
    setCount(0);
     */
    LinkedList::destroy();
}

void Stack::displayStack() {
    Node *pCur;
    pCur = getStart();
    std::cout << "--------------------------\n";
    std::cout << "Displaying Stack:\n";
    std::cout << getCount() << " elements in stack\n";
    if (isEmpty()) {
        std::cout << "Stack is empty";
    }
    else {
        while (pCur != NULL) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";
}

std::ostream &operator << (std::ostream &strm, Stack *stack) {
    Node *pCur;
    pCur = stack->getStart();
    std::cout << "--------------------------\n";
    std::cout << "Displaying Stack:\n";
    std::cout << stack->getCount() << " elements in stack\n";
    if (stack->isEmpty()) {
        std::cout << "Stack is empty";
    }
    else {
        while (pCur != NULL) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";
    return strm;
}

Queue::Queue() {
    setStart(new Node);
    getStart()->next = NULL;
    setStart(NULL);
    setEnd(getStart());
    setCount(0);
};

Queue::~Queue() {
    Node *pCur;
    Node *pNext;
    pCur = getStart()->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    setStart(NULL);
    setEnd(NULL);
    //can call destroy() as well, didn't reuse for testing purposes
    //destroy();
}

void Queue::enqueue(Node *n) {
    if(isEmpty()) {
        setStart(n);
    }
    else {
        Node *pPre = getStart();
        Node *pCur = getStart()->next;
        while(pCur != NULL) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = n;
    }
    n->next = NULL;
    setCount(getCount() + 1);
    setEnd(n);
}


bool Queue::dequeue(Dollar &d) {
    if(isEmpty()) {
        return false;
    }
    else {
        Node *pTemp;
        pTemp = getStart();
        d = pTemp->data;
        setStart(getStart()->next);
        pTemp = NULL;
        setCount(getCount() - 1);
    }
    return true;
}

bool Queue::peekFront(Dollar &d) {
    if(isEmpty()) {
        return false;
    }
    else {
        d = getStart()->data;
        return true;
    }
}

bool Queue::peekRear(Dollar &d) {
    if(isEmpty()) {
        return false;
    }
    else {
        Node *pCur = getStart();
        while(pCur->next!=NULL) {
            pCur = pCur->next;
        }
        d = pCur->data;
    }
    return true;
}

void Queue::destroy() {
   /* Node *pCur;
    Node *pNext;
    pCur = getStart()->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    setStart(NULL);
    setEnd(NULL);
    setCount(0); */
    LinkedList::destroy();
}

void Queue::displayQueue() {
    Node *pCur;
    pCur = getStart();
    std::cout << "--------------------------\n";
    std::cout << "Displaying Queue:\n";
    std::cout << getCount() << " elements in queue\n";
    if (isEmpty()) {
        std::cout << "Queue is empty";
    }
    else {
        while (pCur != NULL) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";

}

std::ostream &operator << (std::ostream &strm, Queue *queue) {
    Node *pCur;
    pCur = queue->getStart();
    std::cout << "--------------------------\n";
    std::cout << "Displaying Queue:\n";
    std::cout << queue->getCount() << " elements in queue\n";
    if (queue->isEmpty()) {
        std::cout << "Queue is empty";
    }
    else {
        while (pCur != NULL) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";
    return strm;
}

#endif //LAB4_STACK_H
