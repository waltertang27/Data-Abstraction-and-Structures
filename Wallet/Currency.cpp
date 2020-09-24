//
// Lab 1, Walter Tang, the purpose of this assignment is to use inheritance and
//polymorphism to simulate physical currency
//

#include "Currency.h"

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
 * --------------------------------------------------------------------------------------------------------
 * CanadianDollar function definitions
 */

/*
 * Converts the given Canadian Dollar to a Dollar
 */
Dollar CanadianDollar::convertToDollar() {
    Dollar d;
    double x, y, total;
    x = getWhole() * getCToUSD();
    y = (double) getFraction() / 100 * getCToUSD();
    total = x + y;
    d.setWhole((int) total);
    d.setFraction((total - int(total)) * 100);
    update();
    return d;
}
/*
 * Converts the given Dollar to a Canadian Dollar
 */
CanadianDollar CanadianDollar::convertFromDollar(const Dollar &d) {
    CanadianDollar cd;
    double x, y, total;
    x = d.getWhole() * getCFromUSD();
    y = (double) d.getFraction() / 100 * getCFromUSD();
    total = x + y;
    cd.setWhole((int) total);
    cd.setFraction((total - (int) total) * 100);
    update();
    return cd;
}

void CanadianDollar::print() const {
    std::cout << whole << " " << getNoteName() << " and " << fraction << " " << getCoinName() << std::endl;
}
/*
 * --------------------------------------------------------------------------------------------------------
 * Wallet function definitions
 */
//default constructor, sets the values to default
Wallet::Wallet() {
    list[0] = new Dollar();
    list[1] = new CanadianDollar();
}
//destructor
Wallet::~Wallet() {
    delete list[0];
    delete list[1];
}
/*
 * adds a USD amount in the wallet using the overloaded + operator
 */
void Wallet::addMoney(const Dollar &d) {
    *list[0] = *list[0] + d;
}
/*
 * adds a CAD amount in the wallet using the overloaaded + operator
 */
void Wallet::addMoney(const CanadianDollar &cd) {
    *list[1] = *list[1] + cd;
    *list[1] = CanadianDollar(list[1]->getWhole(), list[1]->getFraction());
}
/*
 * subtracts an amount of USD in the wallet using the overloaded - operator
 */
void Wallet::subtractMoney(const Dollar &d) {
    *list[0] = *list[0] - d;
}
/*
 * subtracts an amount of CAD in the wallet using the overloaded - operator
 */
void Wallet::subtractMoney(const CanadianDollar &cd) {
    *list[1] = *list[1] - cd;
    *list[1] = CanadianDollar(list[1]->getWhole(), list[1]->getFraction());
}
/*
 * returns 1 if the USD parameter is greater than the USD amount
 * in the wallet, 2 if it is less, and 0 if they are equal
 * Uses the overloaded comparison operators
 */
int Wallet::compareMoney(Dollar d) {
    if(d > *list[0]) {
        return 1;
    }
    else if (d < *list[0]){
        return 2;
    }
    else {
        return 0;
    }
}
/*
 * returns 1 if the CAD parameter is greater than the CAD amount
 * in the wallet, 2 if it is less, and 0 if they are equal
 * Uses the overloaded comparison operators
 */
int Wallet::compareMoney(CanadianDollar cd) {
    if(cd > *list[1]) {
        return 1;
    }
    else if (cd < *list[1]){
        return 2;
    }
    else {
        return 0;
    }
}
/*
 * prints out the contents in the wallet
 */
void Wallet::print() const {
    std::cout << "You have ";
    list[0]->print();
    std::cout << "You have ";
    list[1]->print();
}