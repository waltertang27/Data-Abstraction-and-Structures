//
// Lab 1, Walter Tang, the purpose of this assignment is to use inheritance and
//polymorphism to simulate physical currency
//

/*
 * Assumptions made:
 * You cannot have a negative currency value
 */

using namespace std;

#include <iostream>
#include "Currency.h"

int main() {
    Wallet wallet;  //creates the Wallet object
    bool status = true; //menu continues to run while true
    while(status) {
        int choice;
        /*
         * Choice 0: Converts USD to CAD or CAD to USD. Does not affect the amount of currency in wallet
         * Choice 1: Adds a user inputted amount of CAD or USD. Enter like (20 50) -> (USD, Cents), or (CAD, Cents)
         * Choice 2: Subtracts a user inputted amount of CAD or USD. Enter like (20 50) -> (USD, Cents), or (CAD, Cents)
         * Choice 3: Compares a user inputted amount of USD/CAD to the amount you currently have in wallet.
         * Choice 4: Prints the contents of your wallet.
         * Choice 5: Exits the Program.
         */
        cout << "Menu:\n";
        cout << "0: Convert money\n";
        cout << "1: Add money\n";
        cout << "2: Subtract money\n";
        cout << "3: Compare money\n";
        cout << "4: Print wallet\n";
        cout << "5: Exit\n";
        cout << "Enter a number to select your choice\n";
        //Enter your choice
        cin >> choice;
        /*
         * In choices 0-3, you will be asked to use USD or CAD.
         * Enter 1 for USD and 2 for CAD, or 0 to exit.
         */
        int selection;
        switch(choice) {
            //Conversions
            case 0:
                cout << "What currency type do you choose to convert?\n";
                cout << "Enter 1 for USD, enter 2 for CAD, and 0 to exit\n";
                cin >> selection;
                //Converts USD to CAD
                if(selection == 1) {
                    Dollar d;
                    int w, f;
                    cout << "How much USD and cents would you like too convert? (Enter like 20 50)\n";
                    cin >> w >> f;
                    d.setWhole(w);
                    d.setFraction(f);
                    CanadianDollar cd;
                    cd = cd.convertFromDollar(d);
                    cout << w << " USD and " << f << " cents converts to ";
                    cd.print();
                }
                //Converts CAD to USD
                else if(selection == 2) {
                    CanadianDollar cd;
                    int w, f;
                    cout << "How much CAD and cents would you like to convert? (Enter like 20 5)\n";
                    cin >> w >> f;
                    cd.setWhole(w);
                    cd.setFraction(f);
                    Dollar d;
                    d = cd.convertToDollar();
                    cout << w << " CAD and " << f << " cents converts to ";
                    d.print();
                }
                //Invalid user input for currency selection
                else if(selection != 0) {
                    cout << "Invalid choice! Please choose again.\n";
                }
                //Goes back to menu
                else {
                    cout << "Going back to menu\n";
                    break;
                }
                break;
            //Adding currency to wallet
            case 1:
                cout << "What currency type do you choose to add?\n";
                cout << "Enter 1 for USD, enter 2 for CAD, and 0 to exit\n";
                cin >> selection;
                //Adds USD
                if(selection == 1) {
                    Dollar d;
                    int w, f;
                    cout << "How much USD and cents would you like to add? (Enter like 20 50)\n";
                    cin >> w >> f;
                    d.setWhole(w);
                    d.setFraction(f);
                    wallet.addMoney(d);
                    cout << w << " USD and " << f << " cents added to your wallet!\n";
                }
                //Adds CAD
                else if(selection == 2) {
                    CanadianDollar cd;
                    int w, f;
                    cout << "How much CAD and cents would you like to add? (Enter like 20 50)\n";
                    cin >> w >> f;
                    cd.setWhole(w);
                    cd.setFraction(f);
                    wallet.addMoney(cd);
                    cout << w << " CAD and " << f << " cents added to your wallet!\n";
                }
                //Invalid user input for currency selection
                else if(selection != 0) {
                    cout << "Invalid choice! Please choose again.\n";
                }
                //Goes back to menu
                else {
                    cout << "Going back to menu\n";
                    break;
                }
                break;
            //Subtracts currency from wallet
            case 2:
                cout << "What currency type do you choose to subtract?\n";
                cout << "Enter 1 for USD, enter 2 for CAD, and 0 to exit\n";
                cin >> selection;
                //subtracts USD
                if(selection == 1) {
                    Dollar d;
                    int w, f;
                    cout << "How much USD and cents would you like to subtract? (Enter like 20 50)\n";
                    cin >> w >> f;
                    d.setWhole(w);
                    d.setFraction(f);
                    //checks if you don't have enough money to subtract
                    if(wallet.compareMoney(d) == 1) {
                        cout << "You can't subtract more money than you have in your wallet!\n";
                        wallet.print();
                    }
                    else {
                        wallet.subtractMoney(d);
                        cout << w << " USD and " << f << " cents subtracted from your wallet!\n";
                    }
                }
                //subtracts CAD
                else if(selection == 2) {
                    CanadianDollar cd;
                    int w, f;
                    cout << "How much CAD and cents would you like to subtract? (Enter like 20 50)\n";
                    cin >> w >> f;
                    cd.setWhole(w);
                    cd.setFraction(f);
                    //checks if you don't have enough money to subtract
                    if(wallet.compareMoney(cd) == 1) {
                        cout << "You can't subtract more money than you have in your wallet!\n";
                        wallet.print();
                    }
                    else {
                        wallet.subtractMoney(cd);
                        cout << w << " CAD and " << f << " cents subtracted from your wallet!\n";
                    }
                }
                //Invalid user input for currency selection
                else if(selection != 0) {
                    cout << "Invalid choice! Please choose again." << endl;
                }
                //Back to menu
                else {
                    cout << "Going back to menu\n";
                    break;
                }
                break;
            //Comparing currency
            case 3:
                cout << "What currency type do you choose to compare?\n";
                cout << "Enter 1 for US, enter 2 for CAD, and 0 to exit\n";
                cin >> selection;
                //Comparing USD
                if (selection == 1) {
                    Dollar d;
                    int w, f;
                    cout << "How much USD and cents would you like to compare to the amount in your wallet? Enter like 20 50\n";
                    cin >> w >> f;
                    d.setWhole(w);
                    d.setFraction(f);
                    if (wallet.compareMoney(d) == 1) {
                        cout << w << " " << f << " is greater than the amount you have in your wallet!\n";
                    } else if (wallet.compareMoney(d) == 2) {
                        cout << w << " " << f << " is less than the amount you have in your wallet!\n";
                    } else {
                        cout << "You have exactly " << w << " USD and " << f << " cents in your wallet!\n";
                    }
                }
                //comparing CAD
                else if (selection == 2) {
                    CanadianDollar cd;
                    int w, f;
                    cout << "How much CAD and cents would you like to compare to the amount in your wallet? Enter like 20 50\n";
                    cin >> w >> f;
                    cd.setWhole(w);
                    cd.setFraction(f);
                    if (wallet.compareMoney(cd) == 1) {
                        cout << w << " " << f << " is greater than the amount you have in your wallet!\n";
                    } else if (wallet.compareMoney(cd) == 2) {
                        cout << w << " " << f << " is less than the amount you have in your wallet!\n";
                    } else {
                        cout << "You have exactly " << w << " CAD and " << f << " cents in your wallet!\n";
                    }
                }
                //Invalid user input for currency selectionn
                else if (selection != 0) {
                    cout << "Invalid choice! Please choose again." << endl;
                }
                //Back to menu
                else {
                    cout << "Going back to menu\n";
                    break;
                }
                break;
            //prints contents of wallet
            case 4:
                wallet.print();
                break;
            //pauses the program, asks for confirmation before exiting
            case 5:
                char pause;
                cout << "Program paused. Please enter any key to end program.\n";
                cin >> pause;
                status = false;
                break;
            //Invalid user choice in menu
            default:
                cout << "Invalid choice. Please enter again\n";
        }
    }
    cout << "Program ended." << endl;
    return 0;
}
