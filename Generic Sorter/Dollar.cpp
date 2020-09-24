/*
 * Lab 3
 * @file Dollar.cpp
 * @author Walter Tang
 * The purpose of this lab is to write a program that will be able to
 * sort a template array of data
 * @version 7/14/2020
 */
#include "Dollar.h"
#include <fstream>
/*
 * --------------------------------------------------------------------------------------------------------
 * Dollar function definitions
 */
/*
 * This function checks if fraction is greater than 100. If such
 * a value is found, the whole and fraction numbers are adjusted
 * to conform to the standard dollar and cent expression. For example,
 * 3 dollars and 104 cents would be adjusted to 4 dollars and 4 cents.
 * Pre:
 * Post: Updates the values of whole and fraction in a Dollar object
 */
void Dollar::update()
{
    if (fraction < 0 && whole > 0)
    {
        int hold = abs(fraction);
        whole -= hold / 100 + 1;
        fraction = 100 - hold % 100;
    }
    else if(fraction > 0 && whole < 0) {
        int hold = abs(fraction);
        whole += hold / 100 + 1;
        fraction = -1 * (100 - hold % 100);
    }
    if (fraction >= 100)
    {
        whole += (fraction / 100);
        fraction = fraction % 100;
    }
}

/* Overloaded binary + operator. Adds two objects of the same currency.
 * Pre: a reference of a const Dollar object to add
 * Post:
 * Return: returns a Dollar object with the added values
*/

Dollar Dollar::operator+(const Dollar &right) {
    Dollar temp;
    temp.fraction = fraction + right.fraction;
    temp.whole = whole + right.whole;
    temp.update();
    return temp;
}

/* Overloaded binary - operator.
 * Subtracts one object from another object of the same currency
 * Pre: a reference of a const Dollar object to subtract
 * Post:
 * Return: returns a Dollar object with the subracted values
*/
Dollar Dollar::operator- (const Dollar &right) {
    Dollar temp;
    temp.fraction = fraction - right.fraction;
    temp.whole = whole - right.whole;
    temp.update();
    return temp;
}

/* Overloaded == operator. Returns true if the current object
 * is set to a value equal to that of right.
 * Pre: a reference of a const Dollar object to compare equality
 * Post:
 * Return: true or false
*/
bool Dollar::operator== (const Dollar &right) {
    return (whole == right.whole && fraction == right.fraction);
}

/* Overloaded < operator. Returns true if the current object
 * is less than that of right.
 * Pre: a reference of a const Dollar object to compare
 * Post:
 * Return: true or false
*/
bool Dollar::operator< (const Dollar &right) {
    bool status = false;
    if(whole < right.whole) {
        status = true;
    }
    else if(whole== right.whole && fraction < right.fraction) {
        status = true;
    }
    return status;
}
/* Overloaded > operator. Returns true if the current object
 * is greater than that of right.
 * Pre: a reference of a const Dollar object to compare
 * Post:
 * Return true or false
*/
bool Dollar::operator> (const Dollar &right)
{
    bool status = false;
    if (whole > right.whole)
        status = true;
    else if (whole == right.whole && fraction > right.fraction) {
        status = true;
    }
    return status;
}
/*
 * Prints the whole and fraction part of a Dollar object to the screen
 * Pre:
 * Post: prints to the screen
 */
void Dollar::print() const {
    std::cout << whole << " " << getNoteName() << " and " << fraction << " " << getCoinName() << std::endl;
}

/*
* Overloads ostream << operator to print Dollar objects
* Pre: strm - reads objects
*      d - Dollar object
* Post:
* Return: strm
*/
std::ostream &operator << (std::ostream &strm, Dollar &d) {
    if(d.getFraction() < 10) {
        std::cout << "$" << d.getWhole() << ".0" << d.getFraction() << " ";
    }
    else {
        std::cout << "$" << d.getWhole() << "." << d.getFraction() << " ";
    }
    d.update();
     return strm;
 }
/*
     * Overloads ofstream << operator to output to filie
     * Pre: strm - ofstream
     *      d - Dollar object
     * Post:
     * Return: strm
     */
 std::ofstream &operator << (std::ofstream &strm, Dollar &d) {
     if(d.getFraction() < 10) {
         strm << "$" << d.getWhole() << ".0" << d.getFraction() << " ";
     }
     else {
         strm << "$" << d.getWhole() << "." << d.getFraction() << " ";
     }
     d.update();
     return strm;
}
