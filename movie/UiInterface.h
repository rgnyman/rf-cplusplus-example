
#ifndef UIINTERFACE_H
#define UIINTERFACE_H

#include "Customer.h"
#include "Movie.h"
#include "Rental.h"

namespace MovieDB {


class UiInterface {
public:
    virtual void addCustomer(const Customer&) = 0;
    virtual void addMovie(const Movie&) = 0;
    virtual void addCustomerRental(Customer&, const Rental&) = 0;
    virtual void returnRental(Customer&, const Rental&) = 0;
};

}

#endif //UIINTERFACE_H
