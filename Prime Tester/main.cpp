/*
 * Lab 2
 * @file main.cpp
 * @author Walter Tang
 * The purpose of this lab is to use and differentiate iteration and recursion and determine
 * how to use each as efficiently as possible
 * @version 7/9/2020
 */

#include <iostream>
#include <math.h>
using namespace std;
//function prototypes
bool IsArrayPrimeIter(int list[], int);
bool IsArrayPrimeRecur(int list[], int);
bool isPrime(int, int);
int main() {
    /*
     * First, the program prompts the user to enter in the amount of numbers they want to enter.
     * If their size is greater than 16, it loops and asks the user to input a different number.
     * The user then enters their list of numbers. If they enter a number less than 1 or greater
     * than 99, inclusive, it loops and asks the user to enter a different number.
     * The program will then use an iteration method to determine if all the numbers are prime.
     * Then, it switches to a recursive method to determine if all the numbers are prime.
     */
    int SORT_MAX_SIZE = 16;
    cout << "How many elements would you like to enter? (Less than or equal to 16)" << endl;
    int size;
    cin >> size;
    //If the user enters a size that is greater than 16, it will loop and ask the user to enter a different number
    while(size > SORT_MAX_SIZE) {
        cout << "Please enter a number less than or equal to 16" << endl;
        cin >> size;
    }
    //creates an array based on the size the user inputs
    int list[size];
    cout << "Enter your numbers (integers between 1 and 99, inclusive)\n";
    for(int i = 0; i < size; i++) {
        cin >> list[i];
        //checks if user enters numbers not between 1 to 99, inclusive
        while(list[i] < 1 || list[i] > 99) {
            cout << "Choose numbers between 1 and 99, inclusive\n";
            cout << list[i] << " is not between 1 and 99" << endl;
            cin >> list[i];
        }

    }
    //checks if array is prime using iteration function
    bool iter = IsArrayPrimeIter(list, size);
    cout << endl;
    if(iter) {
        cout << "Prime Array using iteration\n";
    }
    else {
        cout << "Not a Prime Array using iteration\n";
    }
    cout << endl;
    //checks if array is prime using recursion function
    bool recur = IsArrayPrimeRecur(list, size);
    cout << endl;
    if(recur) {
        cout << "Prime Array using recursion\n";
    }
    else {
        cout << "Not a Prime Array using recursion\n";
    }
    cout << endl;
    char pause;
    cout << "Program paused. Enter any key to end the program\n";
    cin >> pause;
    return 0;
}
/*
 * The IsArrayPrimeIter determines if an integer array contains only prime numbers using iteration (loops)
 * Pre: list[] - An array of integers (that you want to determine if it contains only primes)
 *      size - size of the array
 * Post:
 * Return: true or false
 */
bool IsArrayPrimeIter(int list[], int size) {
    cout << "IsArrayPrimeIter" << endl;
    for(int i = 0; i < size; i++) {
        //checks if array has a number less than or equal to 2 (0, 1 are "not" prime numbers)
        if(list[i] <= 1) {
            cout << "Leaving IsArrayPrimeIter\n";
            return false;
        }
        else {
            for(int j = 2; j <= sqrt(list[i]); j++) {
                if(list[i] % j == 0) {
                    cout << "Leaving IsArrayPrimeIter" << endl;
                    return false;
                }
            }
        }
    }
    cout << "Leaving IsArrayPrimeIter" << endl;
    return true;
}

/*
 * A recursion function to determine if all the numbers in an integer array are prime. Starts from end of array.
 * Pre: list - an array of integers
 *      size - size of the array
 * Post:
 * Return: True or false
 */
bool IsArrayPrimeRecur(int list[], int size) {
    cout << "EnteringIsArrayPrimeRecur" << endl;
    if(size == 0) {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return true;
    }
    if(isPrime(list[size - 1], 2)) {
        return IsArrayPrimeRecur(list, size - 1);
    }
    cout << "Leaving IsArrayPrimeReucr" << endl;
    return false;
}
/*
 * A helper function to determine if a number is prime (used in isArrayPrimeRecur)
 * Pre: num - an integer
 *      divisor - the starting divisor to check (normally 2)
 * Post:
 * Return: True or false
 */
bool isPrime(int num, int divisor) {
    cout << "   Entering isPrime\n";
    if(num <= 1) {
        cout << "   Leaving isPrime\n";
        return false;
    }
    if(sqrt(num) < divisor) {
        cout << "   Leaving isPrime\n";
        return true;
    }
    if(num % divisor == 0) {
        cout << "   Leaving isPrime\n";
        return false;
    }
    return isPrime(num, divisor + 1);
}
