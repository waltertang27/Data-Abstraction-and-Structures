/*
 * Lab 5
 * @author Walter Tang
 * @file main.cpp
 * The purpose of this lab is to implement and traverse a BST
 */
#include "BST.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * The program seeds the tree with 10 dollar object. The user is then given a menu to make choices, including
 * adding to the BST, removing objects from the BST, search the BST, and print the BST, and exit the program.
 * Everything printed to output screen is also printed to an output file.
 */
int main() {
    BST *tree = new BST();
    Dollar d1(0, 99);
    Dollar d2(25, 1);
    Dollar d3(100, 50);
    Dollar d4(78, 39);
    Dollar d5(9, 99);
    Dollar d6(600, 55);
    Dollar d7(19, 98);
    Dollar d8(12, 14);
    Dollar d9(44, 44);
    Dollar d10(101, 1);

    tree->insertBSTNode(d1);
    tree->insertBSTNode(d2);
    tree->insertBSTNode(d3);
    tree->insertBSTNode(d4);
    tree->insertBSTNode(d5);
    tree->insertBSTNode(d6);
    tree->insertBSTNode(d7);
    tree->insertBSTNode(d8);
    tree->insertBSTNode(d9);
    tree->insertBSTNode(d10);

    ofstream outfile;

    string filename = "output.txt";
    outfile.open(filename);
    if(outfile.fail()) {
        cout << filename << " file error\n";
        exit(0);
    }
    outfile << "Lab 5\n";
    outfile << "@file output.txt\n";
    outfile << "@author Walter Tang\n";
    outfile << "The purpose of this lab is to implement and traverse a BST\n";
    outfile << "@version 8/3/2020\n";
    outfile << endl;

    bool status = true;
    while(status) {

        int choice;
        cout << "Menu:\n";
        cout << "1: Add to BST\n";
        cout << "2: Remove from BST\n";
        cout << "3: Search BST\n";
        cout << "4: Print BST\n";
        cout << "5: Exit\n";

        outfile << "Menu:\n";
        outfile << "1: Add to BST\n";
        outfile << "2: Remove from BST\n";
        outfile << "3: Search BST\n";
        outfile << "4: Print BST\n";
        outfile << "5: Exit\n";
        cin >> choice;
        while (cin.fail() || choice < 0 || choice > 5) {
            cout << "Invalid choice. Please choose again\n";
            outfile << choice << ": Invalid choice. Please choose again\n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                cout << "Enter your Dollars: (50 50 = $50.50)\n";
                outfile << "Enter your Dollars: (50 50 = $50.50)\n";
                //Dollar d;
                int w, f;
                cin >> w;
                while (cin.fail() || w < 0) {
                    cout << w << " is an invalid input. Enter a valid amount of dollars\n";
                    outfile << endl << w << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> w;
                }
                cin >> f;
                while (cin.fail() || f < 0) {
                    cout << f << " is an invalid input. Enter a valid amount of cents\n";
                    outfile << endl << w << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> f;
                }
                Dollar d(w, f);
                cout << d << " was added to the BST\n";
                outfile << d << " was added to the BST\n";
                tree->insertBSTNode(d);
                break;
            }
            case 2: {
                cout << "What Dollar object would you like to remove? Enter like 50 50 = $50.50\n";
                outfile << "What Dollar object would you like to remove? Enter like 50 50 = $50.50\n";
                int w, f;
                cin >> w;
                while (cin.fail() || w < 0) {
                    cout << w << " is an invalid input. Enter a valid amount of dollars\n";
                    outfile << w << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> w;
                }
                cin >> f;
                while (cin.fail() || f < 0) {
                    cout << f << " is an invalid input. Enter a valid amount of cents\n";
                    outfile << endl << f << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> f;
                }
                Dollar d;
                d.setWhole(w);
                d.setFraction(f);
                if(tree->BSTsearch(d)) {
                    cout << d << " was deleted from the BST\n";
                    outfile << d << " was deleted from the BST\n";
                    tree->deleteBSTNode(d);
                }
                else {
                    cout << d << " was not found in the BST!\n";
                    outfile << d << " was not found in the BST!\n";
                }
                break;
            }
            case 3: {
                cout << "Which Dollar object would you like to search for?\n";
                outfile << "Which Dollar object would you like to search for?\n";
                Dollar d;
                int w, f;
                cin >> w;
                while (cin.fail() || w < 0) {
                    cout << w << " is an invalid input. Enter a valid amount of dollars\n";
                    outfile << endl << w << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> w;
                }
                cin >> f;
                while (cin.fail() || f < 0) {
                    cout << f << " is an invalid input. Enter a valid amount of cents\n";
                    outfile << f << " is an invalid input\n";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> f;
                }
                d.setWhole(w);
                d.setFraction(f);
                if (tree->BSTsearch(d) == NULL) {
                    cout << d << " was not found!\n";
                    outfile << d << " was not found!\n";
                } else {
                    cout << d << " was found!\n";
                    outfile << d << " was found!\n";
                }
                break;
            }
            case 4:
                int printChoice;
                cout << "What would you like to print?\n";
                cout << "1: Breadth First\n";
                cout << "2: Inorder\n";
                cout << "3: Preorder\n";
                cout << "4: Postorder\n";

                outfile << "What would you like to print?\n";
                outfile << "1: Breadth First\n";
                outfile << "2: Inorder\n";
                outfile << "3: Preorder\n";
                outfile << "4: Postorder\n";
                cin >> printChoice;
                if(cin.fail() || printChoice < 1 || printChoice > 4) {
                    cout << "Going back to menu\n";
                    outfile << "Going back to menu\n";
                }
                else {
                    switch(printChoice) {
                        case 1:
                            tree->breadthFirst(tree->getRoot(), outfile);
                            cout << endl;
                            break;
                        case 2:
                            tree->inorder(tree->getRoot(), outfile);
                            cout << endl;
                            break;
                        case 3:
                            tree->preorder(tree->getRoot(), outfile);
                            cout << endl;
                            break;
                        case 4:
                            tree->postorder(tree->getRoot(), outfile);
                            cout << endl;
                            break;
                    }
                }
                break;

            case 5:
                status = false;
                break;
        }


    }
    outfile << "Breadth First: \n";
    cout << "\nBreadth First: \n";
    tree->breadthFirst(tree->getRoot(), outfile);
    outfile << "\nInorder: \n";
    cout << "\nInorder: \n";
    tree->inorder(tree->getRoot(), outfile);
    outfile << "\nPreorder: \n";
    cout << "\nPreorder: \n";
    tree->preorder(tree->getRoot(), outfile);
    outfile << "\nPostorder: \n";
    cout << "\nPostorder: \n";
    tree->postorder(tree->getRoot(), outfile);



    cout << "\nProgram paused. Enter any key to exit\n";
    char next;
    cin >> next;
    tree->empty(tree->getRoot());

    return 0;
}




