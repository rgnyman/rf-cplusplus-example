
#include <iostream>
#include "CustomerDb.h"
#include "Customer.h"
#include "Movie.h"
#include "Rental.h"
#include "SimpleUi.h"


int main(int arc, char **argv) {
    MovieDB::CustomerDb customerDb = MovieDB::CustomerDb::getInstance();
    auto *customerRentals = new MovieDB::Customer("Sally");
    auto *movie1 = new MovieDB::Movie("Gone with the Wind", new MovieDB::Regular{});
    auto *rental1 = new MovieDB::Rental(*movie1, 3); // 3 day rental
    customerRentals->addRental(*rental1);
    customerRentals->getNumberRentals();
    std::cout << customerRentals->statement() << std::endl;
    customerDb.addCustomerRentals(*customerRentals);
    customerDb.store();

    delete rental1;
    delete movie1;
    delete customerRentals;

}
