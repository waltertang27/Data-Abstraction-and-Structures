/*
 * Lab 4
 * @author Walter Tang
 * @file LinkedList.h
 * The purpose of this lab is to use LinkedList, Stack, and Queues  and manipulate their data
 */

#pragma once
#include "Dollar.h"
#include <string>

struct Node {
    Dollar data;
    Node *next;
    /*
     * Default constructor.
     * Pre:
     * Post: sets *next to null
     * Return:
     */
    Node() {
        next = NULL;
    }
    /*
     * Constructor with a given Dollar object.
     * Pre: d - Dollar object
     * Post: sets *next to null, data to d
     * Return:
     */
    Node(Dollar d) {
        next = NULL;
        data = d;
    }
};

class LinkedList {
private:
    int count;
    Node *start;
    Node *end;

public:

    /*
     * Default constructor.
     * Pre:
     * Post: Sets the start and end nodes
     * Return:
     */
    LinkedList();



    /*
     * Destructor. Deletes the Nodes in the LinkedList
     * Pre:
     * Post: Deletes Nodes
     * Return:
     */
    ~LinkedList();

    /*
     * Returns the count field of the LinkedList
     * Pre:
     * Post:
     * Return: count
     */
    int getCount() const {
        return count;
    }

    /*
     * Sets the count field of the LinkedList
     * Pre: count
     * Post: sets this->count to count
     * Return:
     */
    void setCount(int count) {
        this->count = count;
    }

    /*
     * Returns the start pointer Node
     * Pre:
     * Post:
     * Return: *start
     */
    Node *getStart() {
        return start;
    }

    /*
     * Sets the start pointer Node
     * Pre: *start
     * Post: sets this->start to start
     * Return:
     */
    void setStart(Node *start) {
        this->start = start;
    }


    /*
     * Returns the end pointer Node
     * Pre:
     * Post:
     * Return: *end
     */
    Node *getEnd() {
        return end;
    }

    /*
     * Sets the end pointer Node
     * Pre: *end
     * Post: sets this->end = end;
     * Return:
     */
    void setEnd(Node *end) {
        this->end = end;
    }



    /*
     * Linked List operations-----------------------------------------------------------------
     */

    /*
     * Searches the LinkedList for a Dollar object.
     * Pre: *n - the node to find
     * Post:
     * Return: the "index" of the node found, or -1 if not found
     */
    int searchList(Node *n);


    /*
     * Inserts a node at [index] in the LinkedList
     * Pre: *n - a pointer Node
     *      index - where in the linked list you want to insert it. At the start = 0, after the first item = 1, etc.
     * Post: creates a Node at the end of the LinkedList pointing to d
     * Return:
     */
    void insertNode(Node *n, int index);


    /*
     * Deletes a node pointing to a Dollar object d
     * Pre: *n - a pointer Node
     * Post: deletes the node from the LinkedList
     * Return: true (if deleted) or false (Node not found)
     */
    bool deleteNode(Node *n);

    /*
     * Checks if the LinkedList is empty
     * Pre:
     * Post:
     * Return: true (if empty) or false (if not empty)
     */
    bool isEmpty() const;



    /*
     * Prints out the contents of the LinkedList
     * Pre:
     * Post: prints to screen
     * Return:
     */
    void displayList() const;

    /*
     * Clears the contents in the list
     * Pre:
     * Post: sets the Nodes in the stack to null (not dynamically allocated, can't delete or free())
     * Return:
     */
    void destroy();

    /*
   * Overloads ostream << operator to print LinkedLists
   * Pre: strm - reads objects
   *      *list - linked list
   * Post:
   * Return: strm
   */
    friend std::ostream &operator << (std::ostream &, LinkedList *list);



};

LinkedList::LinkedList() {
    start = new Node;
    start->next = NULL;
    end = start;
    count = 0;
}

LinkedList::~LinkedList() {
    Node *pCur;
    Node *pNext;
    pCur = start->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    start = NULL;
    end = NULL;
    //can call destroy() as well, didn't reuse for testing purposes
    //destroy();
}

int LinkedList::searchList(Node *n) {
    int found = -1;
    int i = 1;
    if(start == n) {
        return 1;
    }
    Node *pCur;
    pCur = start->next;

    while(pCur != NULL && pCur != n) {
        pCur = pCur->next;
        i++;
    }
    if(pCur != NULL && pCur == n) {
        i++;
        found = i;
    }
    return found;
}


void LinkedList::insertNode(Node *n, int index) {
    Node *newNode;
    Node *pCur;
    Node *pPre;
    int i = 2;

    pPre = start;
    pCur = start->next;

    if(index == 1) {
        n->next = pPre;
        start = n;
        count++;
    }
    else {
        while (pCur != NULL && i != index) {
            pPre = pCur;
            pCur = pCur->next;
            i++;
        }
        count++;
        pPre->next = n;
        n->next = pCur;
    }
}

bool LinkedList::deleteNode(Node *n) {

    Node *pCur;
    Node *pPre;
    pPre = start;
    pCur = start->next;
    bool deleted = false;
    if(start == n) {
        start = start->next;
        pPre->next = NULL;
        count--;
        return true;
    }
    while(pCur != NULL && pCur != n) {
        pPre = pCur;
        pCur = pCur->next;
    }
    if(pCur != NULL && pCur == n) {
        pPre->next = pCur->next;
        pCur = NULL;
        deleted = true;
        count--;
    }
    return deleted;

}

void LinkedList::displayList() const {
    Node *pCur;
    pCur = start;
    std::cout << "--------------------------\n";
    std::cout << "Displaying LinkedList:\n";
    std::cout << count << " elements in list\n";
    if (isEmpty()) {
        std::cout << "LinkedList is empty";
    }
    else {
        while (pCur != NULL && pCur != end) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";
}

bool LinkedList::isEmpty() const {
    Node *pCur;
    for(int i = 0; i < count; i++) {
        if(pCur != NULL) {
            return false;
        }
    }
    return true;
}

void LinkedList::destroy() {
    Node *pCur;
    Node *pNext;
    pCur = start->next;
    while(pCur != NULL) {
        pNext = pCur->next;
        pCur = NULL;
        pCur = pNext;
    }
    start = NULL;
    end = NULL;
    setCount(0);
}

std::ostream &operator << (std::ostream &strm, LinkedList  *list) {
    Node *pCur;
    pCur = list->getStart();
    std::cout << "--------------------------\n";
    std::cout << "Displaying LinkedList:\n";
    std::cout << list->getCount() << " elements in list\n";
    if (list->isEmpty()) {
        std::cout << "LinkedList is empty";
    }
    else {
        while (pCur != NULL && pCur != list->getEnd()) {
            std::cout << pCur->data;
            pCur = pCur->next;
        }
    }
    std::cout << "\n--------------------------\n";
    return strm;
}







