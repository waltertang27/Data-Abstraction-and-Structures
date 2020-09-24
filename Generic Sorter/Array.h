/*
 * Lab 3
 * @file Array.h
 * @author Walter Tang
 * The purpose of this lab is to write a program that will be able to
 * sort a template array of data
 * @version 7/14/2020
 */
#ifndef LAB3_ARRAY_H
#define LAB3_ARRAY_H
#include "Dollar.h"
template<typename TheType>
class Array {
private:
    int size;
    TheType *list;
public:
    /*
     * Default destructor. Sets fields to 0
     */
    Array() {size = 0; list = 0;}
    /*
     * Destructor.
     * Pre: size - size of the array
     * Post: Sets this->size to size and creates an Array of generic types of size
     */
    Array(int size) {this->size = size; list = new TheType[size];}
    /*
     * Destructor
     */
    ~Array() {delete [] list; size = 0;}
    /*
     * Returns the size of the array:
     * Pre:
     * Post:
     * Return: size
     */
    int getSize() {return size;}

    /*
     * Sets the size of the array.
     * Pre: size
     * Post: sets this->size to size
     * Return:
     */
    void setSize(int size) {this->size = size;}

    /*
     * Prints out the contents of the array to the screen.
     * Pre:
     * Post: prints to screen
     * Return:
     */

    void print() const {
        for(int i = 0; i < size; i++) {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;

    }
    /*
     * Overloaded []
     * Pre: index - index of the element
     * Post:
     * Return: the generic element at index, or if index is out of range, it returns the first element
     */
    TheType & operator[] (int & index) {
        if (index >= 0 && index < size) {
            return list[index];
        }
        return list[0];
    }


};


#endif //LAB3_ARRAY_H
