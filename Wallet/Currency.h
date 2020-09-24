//
// Lab 1, Walter Tang, the purpose of this assignment is to use inheritance and
//polymorphism to simulate physical currency
//

#ifndef LAB1FINAL_CURRENCY_H
#define LAB1FINAL_CURRENCY_H

#include <string>
#include <iostream>
/*
 * --------------------------------------------------------------------------------------------------------
 * Dollar class
 */
class Dollar {
protected:
    int whole, fraction;    //represent the whole and fraction part of money
    std::string noteName, coinName; //the name of the note and coin

    /*
    * This function checks if fraction is greater than 100. If such
    * a value is found, the whole and fraction numbers are adjusted
    * to conform to the standard dollar and cent expression. For example,
    * 3 dollars and 104 cents would be adjusted to 4 dollars and 4 cents.
    * Pre: None
    * Post: Updates the values in whole and fraction
     */
    void update();
public:
    /*
     * Default Dollar constructor
     * Pre:
     * Post: sets data values to the default values, whole = 0, fraction = 0; noteName = USD;
     *       coinName = Cents;
     * Return: creates a Dollar object with the given values
     */
    Dollar() {
        whole = 0;
        fraction = 0;
        noteName = "USD";
        coinName = "Cents";
        update();
    };
    /*
     * Dollar constructor with whole and fraction parameters
     * Pre: takes in integers w and f
     * Post: sets data values whole and fraction to w and f, and noteName and coinName
     *       to the default
     * Return: creates a dollar object with the given values
    */
    Dollar(int w, int f) {
        whole = w;
        fraction = f;
        noteName = "USD";
        coinName = "Cents";
        update();
    }
    /*
     * Dollar constructor with whole, fraction, note name, and coin name
     * Pre: Takes in integers w and f, strings n and c
     * Post: Sets data values whole, fraction, noteName, and coinName to those values, respectively
     * Return: creates a Dollar object with the given data values
    */
    Dollar(int w, int f, std::string n, std::string c) {
        whole = w;
        fraction = f;
        noteName = n;
        coinName = c;
        update();
    }
    /*
     * Copy constructor to copy a Dollar object.
     * Pre: takes a reference to a Dollar object
     * Post: sets a Dollar object with the same values as the given Dollar object
     * Return: creates a Dollar object with the same values as the given Dollar object
     */
    Dollar(Dollar &d) {
        whole = d.whole;
        fraction = d.fraction;
        noteName = d.noteName;
        coinName = d.coinName;
        update();
    }
    //getters
    /*
     * returns the values of a Dollar object's whole field
     * Pre:
     * Post:
     * Return: an integer whole data field
     */
    int getWhole() const {return whole;}
    /*
     * returns the value of a Dollar object's fraction field
     * Pre:
     * Post:
     * Return: an integer fraction data field
     */
    int getFraction() const {return fraction;}
    /*
     * returns the value of a Dollar object's noteName field
     * Pre:
     * Post:
     * Return: a string noteName data field
     */
    std::string getNoteName() const {return noteName;}
    /*
     * returns the value of a Dollar object's coinName field
     * Pre:
     * Post:
     * Return: a string coinName data field
     */
    std::string getCoinName() const {return coinName;}

    //setters
    /*
     * Sets the whole data field with a value given.
     * Pre: an integer value of whole
     * Post: sets a Dollar object's whole data field with that value
     */
    void setWhole(int whole) {this->whole = whole;}
    /*
     * Sets the whole data field with a value given.
     * Pre: an integer value of fraction
     * Post: sets a Dollar object's whole data field with that value
     */
    void setFraction(int fraction) {this->fraction = fraction;}
    /*
     * Sets the fraction data field with a value given.
     * Pre: an integer given value of fraction
     * Post: sets a Dollar object's fraction data field with that value
     */
    /*
     * Sets the noteName data field with a value given.
     * Pre: a string value of noteName
     * Post: sets a Dollar object's noteName data field with that value
     */
    void setNoteName(std::string noteName) {this->noteName = noteName;}
    /*
     * Sets the coinName data field with a value given.
     * Pre: a string value of coinName
     * Post: sets a Dollar object's coinName data field with that value
     */
    void setCoinName(std::string coinName) {this->coinName = coinName;};

    //overloaded operators
    /*
     * Overloads the + operator to add the whole and fraction values in two Dollar objects
     * Pre: a const reference to a Dollar object
     * Post: adds the whole and fraction data members from that object
     * Return: a Dollar object with the added values
     */
    Dollar operator+ (const Dollar &);

    /*
     * Overloads the - operator to subtract the whole and fraction values in two Dollar objects
     * Pre: a const reference to a Dollar object
     * Post: subtracts the whole and fraction data members from that object
     * Return: a Dollar object with the subtracted values
     */
    Dollar operator- (const Dollar &);

    /*
     * Overloads the < operator to compare the whole and fraction values in two Dollar objects (less than)
     * Pre: a const reference to a Dollar object
     * Post: compares the whole and fraction data members from that object
     * Return: true or false
     */
    bool operator< (const Dollar &);

    /*
     * Overloads the > operator to compare the whole and fraction values in two Dollar objects (greater than)
     * Pre: a const reference to a Dollar object
     * Post: compares the whole and fraction data members from that object
     * Return: true or false
     */
    bool operator> (const Dollar &);
    /*
     * Overloads the == operator to compare the whole and fraction values in two Dollar objects (equal to)
     * Pre: a const reference to a Dollar object
     * Post: compares the whole and fraction data members from that object
     * Return: true or false
     */
    bool operator== (const Dollar &);

    //methods
    /*
     * prints the data values of a dollar object
     * Pre:
     * Post: prints to screen
     */
    virtual void print() const;
};
/*
 * --------------------------------------------------------------------------------------------------------
 * CanadianDollar class
 */
class CanadianDollar : public Dollar {
private:
    double cToUSD = 0.74;   //conversion factor from CAD to USD
    double cFromUSD = 1.36; //conversion factor from USD to CAD
public:
    /*
     * Default CanadianDollar constructor
     * Pre:
     * Post: sets data values to the default values, whole = 0, fraction = 0; noteName = CAD;
     *       coinName = Cents;
     * Return: creates a CanadianDollar object with the given values
     */
    CanadianDollar() {
        whole = 0;
        fraction = 0;
        noteName = "CAD";
        coinName = "Cents";
        update();
    };
    /*
     * CanadianDollar constructor with whole and fraction parameters
     * Pre: takes in integers w and f
     * Post: sets data values whole and fraction to w and f, and noteName and coinName
     *       to the default
     * Return: creates a dollar object with the given values
    */
    CanadianDollar(int w, int f) {
        whole = w;
        fraction = f;
        noteName = "CAD";
        coinName = "Cents";
        update();
    }
    /* CandianDollar constructor with whole, fraction, note name, and coin name
     * Pre: Takes in integers w and f, strings n and c
     * Post: Sets data values whole, fraction, noteName, and coinName to those values, respectively
     * Return: creates a CanadianDollar object with the given data values
    */
    CanadianDollar(int w, int f, std::string n, std::string c) {
        whole = w;
        fraction = f;
        noteName = n;
        coinName = c;
        update();
    }
    /*
     * Copy constructor to copy a CanadianDollar object.
     * Pre: takes a reference to a CanadianDollar object
     * Post: sets a CanadianDollar object with the same values as the given CanadianDollar object
     * Return: creates a CanadianDollar object with the same values as the given CanadianDollar object
     */
    CanadianDollar(const CanadianDollar &cd) {
        whole = cd.whole;
        fraction = cd.fraction;
        noteName = cd.noteName;
        coinName = cd.coinName;
        update();
    };

    //setters
    /*
     * sets the conversion factor from CAD to USD
     * Pre: a given double cToUSD factor
     * Post: sets a CanadianDollar object's cToUSD to the given one
     */
    void setCToUSD(double cToUSD) {this->cToUSD = cToUSD;}

    /*
    * sets the conversion factor from USD to CAD
    * Pre: a given double cFromUSD factor
    * Post: sets a CanadianDollar object's cFromUSD to the given one
    */
    void setCFromUSD(double cFromUSD) {this->cFromUSD = cFromUSD;}

    //getters
    /*
     * returns the value of a CanadianDollar object's cToUSD data field
     * Pre:
     * Post:
     * Return: a double CToUSD data field
     */
    double getCToUSD() const {return cToUSD;}
    /*
     * returns the value of a CanadianDollar object's cFromUSD data field
     * Pre:
     * Post:
     * Return: a double CFromUSD data field
     */
    double getCFromUSD() const {return cFromUSD;}
    //methods
    /*
     * Converts CAD to USD.
     * Pre:
     * Post: converts a CanadianDollar's whole/fraction to USD values
     * Return: a Dollar object with the new USD values
     */
    Dollar convertToDollar();

    /*
     * Converts USD to CAD.
     * Pre: a const Dollar object reference
     * Post: converts the whole/fraction to CAD values
     * Return: a CanadianDollar object with the new CAD values
     */
    CanadianDollar convertFromDollar(const Dollar &);

    /*
     * Overloaded print() function to print a CanadianDollar object's data values
     * Pre:
     * Post: prints to screen
     */
    void print() const override;
};
/*
 * --------------------------------------------------------------------------------------------------------
 * Wallet class
 */
class Wallet {

private:
    Dollar *list[2];
public:
    /*
     * Default constructor
     * Pre:
     * Post: creates an array of two Dollar pointers with the first element being a default
     *       Dollar object and the second element being a default CanadianDollar object
     * Return: creates a new Wallet object
     */
    Wallet();
    /*
     * Destructor
     * Pre:
     * Post: Deletes the values in the array of pointers created by the default Wallet constructor
     */
    ~Wallet();

    //methods
    /*
     * Adds a Dollar object into the wallet.
     * Pre: a const Dollar object reference
     * Post: adds the data values of the Dollar object into the wallet using overloaded +
     */
    void addMoney(const Dollar &);

    /*
     * Adds a CanadianDollar object into the wallet.
     * Pre: a const CanadianDollar object reference
     * Post: adds the data values of the CanadianDollar object into the wallet using overloaded +
     */
    void addMoney(const CanadianDollar &);

    /*
     * Subtracts a Dollar object into the wallet.
     * Pre: a const Dollar object reference
     * Post: subtracts the data values of the Dollar object into the wallet using overloaded -
     */
    void subtractMoney(const Dollar &);

    /*
     * Subtracts a CanadianDollar object into the wallet.
     * Pre: a const CanadianDollar object reference
     * Post: subtracts the data values of the CanadianDollar object into the wallet using overloaded -
     */
    void subtractMoney(const CanadianDollar &);

    /*
     * Compares a Dollar object to the amount in your wallet.
     * Pre: A Dollar object
     * Post: uses the overloaded comparison operators to compare data values
     * Return: returns 1 if the USD parameter is greater than the USD amount
     *         in the wallet, 2 if it is less, and 0 if they are equal
     */
    int compareMoney(Dollar);

    /*
     * Compares a CanadianDollar object to the amount in your wallet.
     * Pre: A CanadianDollar object
     * Post: uses the overloaded comparison operators to compare data values
     * Return: returns 1 if the CAD parameter is greater than the CAD amount
     *         in the wallet, 2 if it is less, and 0 if they are equal
     */
    int compareMoney(CanadianDollar);

    /*
     * Overloaded print operator. Prints the USD and CAD amounts.
     * Pre:
     * Post: prints to screen
     */
    void print() const;
};


#endif //LAB1FINAL_CURRENCY_H
