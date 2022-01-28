#include "SimpleUi.h"
#include "Customer.h"
#include <iostream>


using namespace MovieDB;
using namespace std;

void SimpleUi::addCustomer(const Customer &c) {
    customers.addCustomerRentals(c);
}

void SimpleUi::addMovie(const Movie &m) {
    //movies.add(m);
}

void SimpleUi::addCustomerRental(Customer &c, const Rental &r) {
    c.addRental(r);
    customers.addCustomerRentals(c);
}

void SimpleUi::drawUi() {
    string input{"a"};
    while (input.at(0) != 'X') {
        system("clear");
        cout << "****************************************************************************" << endl;
        cout << "||                                                                        ||" << endl;
        cout << "||                         Movie Rental System                            ||" << endl;
        cout << "||                                                                        ||" << endl;
        cout << "****************************************************************************" << endl;
        cout << endl << endl;
        cout << "Available commands:" << endl;
        cout << "Add Customer:                  a) Customer Name" << endl;
        cout << "Add Movie:                     m) Movie Name, Price Category(0, 1, 2) " << endl;
        cout << "Add Rental:                    r) Customer Name, Movie Name" << endl;
        cout << "Return Rental:                 t) Customer Name, Movie Name" << endl;
        cout << endl;
        cout << "Enter your command: ";
        cin >> input;
        if (!doUserActions(input)) break;

    }
}



void SimpleUi::returnRental(Customer &, const Rental &) {

}

bool SimpleUi::doUserActions(const string &userInput) {
    if (userInput.at(0) == 'X') return false;
    cout << userInput << endl;
    switch (userInput.at(0)) {
        case 'r': {
            auto posFirstComma = userInput.find_first_of(',');
            cout << posFirstComma << endl;
            string customerName = userInput.substr(0, posFirstComma);
            auto posSecondComma = userInput.find_last_of(',');
            string movieName = userInput.substr(posFirstComma + 1, posSecondComma);
            Customer c{customerName};
            //TODO addCustomerRental(c, Rental{movieName, 0});
            cout << customerName << movieName << endl;
            break;
        }
        default:
            cout << "Unknown command" << endl;
    }
    return true;
}

