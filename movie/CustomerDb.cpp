
#include <iostream>
#include <fstream>

#include "CustomerDb.h"

namespace MovieDB {

CustomerDb::CustomerDb() {
    readCustomerDb();
}

void CustomerDb::readCustomerDb() {
    std::ifstream myfile;
    myfile.open("customers.txt");
    std::string line;
    int dbSize = 0;
    if (myfile.is_open()) {
        if (std::getline(myfile, line)) {
            dbSize = std::stoi(line);
        }
        for (int i = 0; i < dbSize; i++) {
            Customer c("");
            myfile >> c;
            if (myfile.eof()) {
                break;
            }
            if (!c.getName().empty()) {
                customers.insert(std::__1::pair<std::string, Customer>(c.getName(), c));
            }
        }
    }
    myfile.close();
}

CustomerDb::~CustomerDb() {
    std::ofstream myfile;
    myfile.open("customers.txt");
    if (myfile.is_open()) {
        myfile << static_cast<int>(customers.size());
        myfile << std::endl;
        for (auto const&[key, value]: customers) {
            if (!value.getName().empty()) {
                myfile << value;
            }
        }
    }
    myfile.close();
}

void CustomerDb::addCustomerRentals(const Customer &c) {
    customers.insert(std::pair<std::string, Customer>(c.getName(), c));
}

std::map<std::string, Customer> CustomerDb::getCustomers() {
    return customers;
}
}
