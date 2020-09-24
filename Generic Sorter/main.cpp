/*
 * Lab 3
 * @file main.cpp
 * @author Walter Tang
 * The purpose of this lab is to write a program that will be able to
 * sort a template array of data
 * @version 7/14/2020
 */
#include "Array.h"
#include <iostream>
#include <fstream>
using namespace std;
int SORT_MAX_SIZE = 16;
/*
 * Writes information to an output file
 * Pre: filename - name of the file
 *      list - array of generic types
 *      size - size of array
 * Post: writes to output file
 * Return:
 */
template<typename TheType>
void writeToFile(string, Array<TheType> &, int);

/*
 * Calls the mergeSortHelper function to start the process of mergeSort in a descending order.
 * Pre: list - an Array of TheType (generic)
 *      size - the size of the array
 * Post: Sorts the array using merge sort
 * Return:
 */
template<typename TheType>
void recurMergeSort(Array<TheType> &list, int size) {
    int left = 0;
    int right = size - 1;
    mergeSortHelper(list, left, right);
}

/*
 * Sorts the first half of array, then second, then merges the sorted halves
 * Pre: list - an Array of a generic TheType
 *      left - index of first element in list
 *      right - index of the last element in the list
 * Post: Divides the array into partitions to sort
 * Return:
 */
template<typename TheType>
void mergeSortHelper(Array<TheType> &list, int left, int right) {
    for(int i = 0; i < list.getSize(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    writeToFile("output.txt", list, list.getSize());
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        mergeSortHelper(list, left, mid);
        mergeSortHelper(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}


/*
 * Merges the sorted partitions of the array [left...mid] and [mid+1..right] into one descending sorted array
 * Pre: left <= mid <= right
 *      list - Array of a generic TheType
 *      left - index of the first partition of the array
 *      mid - index of the end of first partition of the array
 *      right - index of the end of the second partition of the array
 * Post: Merges the sorted arrays into a temporary array then back into the original
 * Return:
 */
template<typename TheType>
void merge(Array<TheType> &list, int left, int mid, int right) {
    int leftPos = left;
    int rightPos = mid + 1;
    int leftEnd = mid;
    int rightEnd = right;
    int mergePos = leftPos;
    TheType mergedList[SORT_MAX_SIZE];
    while(leftPos <= leftEnd && rightPos <= rightEnd) {
        if(list[leftPos] > list[rightPos] || list[leftPos] == list[rightPos]) {
            mergedList[mergePos] = list[leftPos];
            ++leftPos;
        }
        else {
            mergedList[mergePos] = list[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }
    while(leftPos <= leftEnd)  {
        mergedList[mergePos] = list[leftPos];
        ++mergePos;
        ++leftPos;
    }
    while(rightPos <= rightEnd) {
        mergedList[mergePos] = list[rightPos];
        ++rightPos;
        ++mergePos;
    }
    for(mergePos = left; mergePos <= right; mergePos++) {
        list[mergePos] = mergedList[mergePos];

    }
}
/*
 * The program prompts the user to input the number of elements they want to enter (maximum of 16) and checks for input
 * validation. Then it prompts the user to choose (0-3) to exit or enter integers, strings, or dollars. The user enters
 * the inputs, and the program sorts the elements in a descending order using mergeSort() on a generic type Array class.
 * The program then prints all the screen output to an output.txt file while printing how the array looks every time
 * a recursive step returns back to its caller.
 *
 */
int main() {
    cout << "How many elements would you like to enter? (Less than or equal to 16)\n";
    int size;
    cin >> size;
    while(size < 1 || size > SORT_MAX_SIZE || cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Please enter a number from 1 to 16\n";
        cin >> size;
    }
    string filename = "output.txt";
    cout << "What data type will you enter? Enter the number corresponding to your choice (int, string, Dollar)\n";
    cout << "0: Exit\n";
    cout << "1: Integer\n";
    cout << "2: String\n";
    cout << "3: Dollar\n";
    int choice;
    cin >> choice;
    while(choice < 0 || choice > 3 || cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Please enter a valid choice\n";
        cin >> choice;
    }
     Array<int> intArray(size);
     Array<string> stringArray(size);
     Array<Dollar> dollarArray(size);
     ofstream outfile;
     outfile.open(filename);
     if(outfile.fail()) {
         cout << filename << " file error\n";
         exit(0);
     }
    outfile << "Lab 3\n";
    outfile << "@file output.txt\n";
    outfile << "@author Walter Tang\n";
    outfile << "The purpose of this lab is to write a program that will be able to sort a template array of data\n";
    outfile << "@version 7/19/2020\n";
    outfile << endl;
    switch(choice) {
        //exiting program
        case 0:
            cout << "Program paused. Press any key to continue\n";
            char pause;
            cin >> pause;
            break;
                //integer array
                case 1: {
                cout << "Enter your " << size << " integers\n";
                for (int i = 0; i < size; i++) {
                    cin >> intArray[i];
                    while(cin.fail()) {
                        cout << "Enter an integer value\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> intArray[i];
                    }
                }
                recurMergeSort(intArray, size);
                cout << "Sorted Array: ";
                for(int i = 0; i < size; i++) {
                    cout << intArray[i] << " ";
                }
                cout << endl;
                writeToFile("output.txt", intArray, size);
                break;
            }
            //strings
            case 2: {
                cout << "Enter your " << size << " strings\n";
                for (int i = 0; i < size; i++) {
                    cin >> stringArray[i];
                    while(cin.fail()) {
                        cout << "Enter a string\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> stringArray[i];
                    }
                }
                recurMergeSort(stringArray, size);
                cout << "Sorted Array: ";
                for(int i = 0; i < size; i++) {
                    cout << stringArray[i] << " ";
                }
                cout << endl;
                writeToFile("output.txt", stringArray, size);
                break;
            }
            //Dollars
            case 3: {
                cout << "Enter your " << size << " Dollars (Enter each dollar object like 50 20 = $50.20)\n";
                int w, f;
                Dollar d;
                for (int i = 0; i < size; i++) {
                    cin >> w >> f;
                    d.setWhole(w);
                    d.setFraction(f);

                    dollarArray[i] = d;
                    while(cin.fail()) {
                        cout << "Enter an dollar object\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> w >> f;
                    }

                }
                recurMergeSort(dollarArray, size);
                cout << "Sorted Array: ";
                for(int i = 0; i < size; i++) {
                    cout << dollarArray[i];
                }

                writeToFile("output.txt", dollarArray, size);
                break;
            }
        }
        cout << "\nProgram paused. Press any key to continue\n";
        char pause;
        cin >> pause;
        return 0;
}
/*
 * Writes information to an output file
 * Pre: filename - name of the file
 *      list - array of generic types
 *      size - size of array
 * Post: writes to output file
 * Return:
 */
template<typename TheType>
void writeToFile(string filename, Array<TheType> &list, int size) {
    ofstream outfile;
    outfile.open(filename, ios::app);
    if(outfile.fail()) {
        cout << filename << " file error\n";
        exit(0);
    }
    for(int i = 0; i < size; i++) {
        outfile << list[i] << " ";
    }
    outfile << endl;
    outfile.close();
}




