
#ifndef SIMPLEUI_H
#define SIMPLEUI_H

#include "UiInterface.h"
#include "CustomerDb.h"

namespace MovieDB {

class SimpleUi : public UiInterface {

public:
    SimpleUi() : customers(CustomerDb::getInstance()){};

    virtual ~SimpleUi() {};

    virtual void drawUi();

    virtual bool doUserActions(const std::string &userInput);

    void addCustomer(const Customer& c) override;

    void addMovie(const Movie& movie) override;

    void addCustomerRental(Customer &c , const Rental &r)  override;

    void returnRental(Customer&, const Rental&) override;

private:
    CustomerDb customers;
};

}

#endif //SIMPLEUI_H
