/*
 * Lab 5
 * @author Walter Tang
 * @file BST.h
 * The purpose of this lab is to implement and traverse a BST
 */
#ifndef LAB5_BST_H
#define LAB5_BST_H
#include "Dollar.h"
#include <string>
#include <fstream>
struct BSTNode {
    BSTNode *left;
    BSTNode *right;
    Dollar data;

    BSTNode() {
        left = NULL;
        right = NULL;
    }
    BSTNode(Dollar d) {
        left = NULL;
        right = NULL;
        data = d;
    }
};

class BST {
private:
    BSTNode *root;
public:
    /*
     * Default constructor. sets root to NULL
     */
    BST();

    /*
     * Destructor. clears the nodes
     */
    ~BST() {empty(root);}

    /*
     * Returns the left child of a node
     * Pre: *node
     * Post:
     * Return: BSTNode*
     */
    BSTNode *getLeft(BSTNode *node) {return node->left;}

    /*
     * Returns the right child of a node
     * Pre: *node
     * Post:
     * Return: BSTNode*
     */
    BSTNode *getRight(BSTNode *node) {return node->right;}
    /*
     * Returns the Dollar of a node
     * Pre: *node
     * Post:
     * Return: Dollar
     */
    Dollar getData(BSTNode *node) {return node->data;}

    /*
     * Getter method for root
     * Pre:
     * Post:
     * Return: root
     */
    BSTNode *getRoot() {return root;}


    /*
     * Checks if BST is empty
     * Pre:
     * Post:
     * Return: true (if empty) or false (if not empty)
     */
    bool isEmpty();

    /*
     * Empties the BST
     * Pre: *node - root of the BST
     * Post: Deletes the BST
     * Return:
     */
    void empty(BSTNode *node);

    /*
     * Returns the height of the of the BST
     * Pre: *node - the root of the tree
     * Post:
     * Return: integer height of tree
     */
    int getHeight(BSTNode *node);

    /*
     * Prints the BST in preorder traversal
     * Pre: *node - root
     *      &outfile - ofstream
     * Post: prints to screen
     * Return:
     */
    void preorder(BSTNode *node, std::ofstream &outfile);


    /*
     * Prints the BST in inorder traversal
     * Pre: *node - root
     *      &outfile - ofstream
     * Post: prints to screen
     * Return: none
     */
    void inorder(BSTNode *node, std::ofstream &outfile);

    /*
     * Prints the BST in postorder traversal
     * Pre: *node - root
     *      &outfile - oftream
     * Post: prints to screen
     * Return: none
     */
    void postorder(BSTNode *node, std::ofstream &outfile);

    /*
     * Prints the BST in breadth first traversal
     * Pre: *node - root
     *      &outfile - ofstream
     * Post:
     * Return: none
     */
    void breadthFirst(BSTNode *node, std::ofstream &outfile);

    /*
     * Helper function for breadth search. prints the given level
     * Pre: *node - root
     *      int height - level to print
     *      &outfile - ofstream
     * Post: prints to screen
     * Return:
     */
    void breadthHelper(BSTNode *node, int height, std::ofstream &outfile);

    /*
     * Inserts a Dollar object into a BST
     * Pre: d - Dollar object
     * Post: adds a Dollar object to the BST. adjusts nodes accordingly
     * Return:
     */
    void insertBSTNode(Dollar d);


    /*
     * Deletes a Dollar object from the BST
     * Pre: d - Dollar object
     * Post: deletes a Dollar object to the BST. readjusts nodes accordingly
     * Return:
     */
    void deleteBSTNode(Dollar d);

    /*
     * Helper function for deleteBSTNode
     * Pre: *&node - the node to delete
     *      d - the dollar object to delete
     * Post: deletes a Dollar object from the BST. readjusts nodes accordingly
     * Return:
     */
    void deleteHelper(BSTNode *&node, Dollar d);

    /*
     * Helper function fro deleteBSTNode
     * Pre: *&node - node to delete
     * Post: deletes the node from the BST
     * Return:
     */
    void remove(BSTNode *&node);


    /*
     * Searches the BST for a Dollar object
     * Pre: d - reference to a Dollar object
     * Post:
     * Return: Node of the found Dollar object (or null)
     */
    BSTNode* BSTsearch(Dollar &d);

    /*
     * Returns the parent node of a node
     * Pre: *node - node to find the parent node
     * Post:
     * Return: BSTNode*
     */
    BSTNode* getParent(BSTNode *node);

    /*
     * Helper function for getParent
     * Pre: n - root
     *      node - node to find the parent of
     * Post:
     * Return: BSTNode*
     */
    BSTNode* getParentHelper(BSTNode *n, BSTNode *node);
};

BST::BST() {
    root = NULL;
}

int BST::getHeight(BSTNode *node) {
    if(node == NULL) {
        return -1;
    }
    else {
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if(left > right) {
            return (left + 1);
        }
        else {
            return (right + 1);
        }
    }
}

void BST::empty(BSTNode *node) {
    if(node != NULL) {
        if(node->left) {
            empty(node->left);
        }
        if(node->right) {
            empty(node->right);
        }
        delete node;
    }
}

bool BST::isEmpty() {
    if(root == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void BST::insertBSTNode(Dollar d) {
    BSTNode *node = new BSTNode;
    node->data = d;

    if(isEmpty()) {
        root = node;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        BSTNode *cur;
        cur = root;
        while(cur != NULL) {
            if(node->data < cur->data) {
                if (cur->left == NULL) {
                    cur->left = node;
                    cur = NULL;
                } else {
                    cur = cur->left;
                }
            }
            else {
                if (cur->right == NULL) {
                    cur->right = node;
                    cur = NULL;
                } else {
                    cur = cur->right;
                }
            }
        }
    }
    node->left = NULL;
    node->right = NULL;
}


BSTNode* BST::getParent(BSTNode *node) {
    return getParentHelper(root, node);
}


BSTNode* BST::getParentHelper(BSTNode *n, BSTNode *node) {
    if(n == NULL) {
        return NULL;
    }
    if(n->left == node || n->right == node) {
        return n;
    }
    if(node->data < n->data) {
        return getParentHelper(n->left, node);
    }
    return getParentHelper(n->right, node);

}

void BST::deleteBSTNode(Dollar d) {
    deleteHelper(root, d);
}

void BST::deleteHelper(BSTNode *&node, Dollar d) {
    if(d < node->data) {
        deleteHelper(node->left, d);
    }
    else if(d > node->data) {
        deleteHelper(node->right, d);
    }
    else {
        remove(node);
    }
}

void BST::remove(BSTNode *&node) {
    BSTNode *temp = NULL;
    if(node == NULL) {
        return;
    }
    else if(node->right == NULL) {
        temp = node;
        node = node->left;
        delete temp;
    }
    else if(node->left == NULL) {
        temp = node;
        node = node->right;
        delete temp;
    }
    else {
        temp = node->right;
        while(temp->left) {
            temp = temp->left;
        }
            temp->left = node->left;
            temp = node;
            node = node->right;
            delete temp;

    }

}


BSTNode* BST::BSTsearch(Dollar &d) {
    BSTNode *cur = root;
    while(cur != NULL) {
        if(d == cur->data) {
            return cur;
        }
        else if (d < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return NULL;
}

void BST::postorder(BSTNode *node, std::ofstream &outfile) {
    if(node == NULL) {
        return;
    }
    postorder(node->left, outfile);
    postorder(node->right, outfile);
    std::cout << node->data;
    outfile << node->data;
}

void BST::preorder(BSTNode *node, std::ofstream &outfile) {
    if(node == NULL) {
        return;
    }
    std::cout << node->data;
    outfile << node->data;
    preorder(node->left, outfile);
    preorder(node->right, outfile);
}

void BST::inorder(BSTNode *node, std::ofstream &outfile) {
    if(node == NULL) {
        return;
    }
    inorder(node->left, outfile);
    std::cout << node->data;
    outfile << node->data;
    inorder(node->right, outfile);
}

void BST::breadthHelper(BSTNode *node, int height, std::ofstream &outfile) {
    if(node == NULL) {
        return;
    }
    else if(height == 1) {
        std::cout << node->data;
        outfile << node->data;
    }
    else if(height > 1){
        breadthHelper(node->left, height - 1, outfile);
        breadthHelper(node->right, height -  1, outfile);
    }
}

void BST::breadthFirst(BSTNode *node, std::ofstream &outfile) {
    int height = getHeight(node);
    for(int i = 0; i <= height + 1; i++) {
        breadthHelper(node, i, outfile);
    }
}





#endif //LAB5_BST_H
