/*
 * Lab 3
 * @file Dollar.h
 * @author Walter Tang
 * The purpose of this lab is to write a program that will be able to
 * sort a template array of data
 * @version 7/14/2020
 */
#ifndef LAB3_DOLLAR_H
#define LAB3_DOLLAR_H
#include <iostream>
#include <string>

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

    /*
    * Overloads ostream << operator to print Dollar objects
    * Pre: strm - reads objects
    *      d - Dollar object
    * Post:
    * Return: strm
    */
    friend std::ostream &operator << (std::ostream &,Dollar &);

    /*
     * Overloads ofstream << operator to output to filie
     * Pre: strm - ofstream
     *      d - Dollar object
     * Post:
     * Return: strm
     */
    friend std::ofstream &operator << (std::ofstream &, Dollar &);
    //methods
    /*
     * prints the data values of a dollar object
     * Pre:
     * Post: prints to screen
     */
     virtual void print() const;
};


#endif //LAB3_DOLLAR_H
