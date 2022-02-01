#ifndef CUSTOMERDB_H
#define CUSTOMERDB_H

#include <map>
#include "Customer.h"

namespace MovieDB {

class CustomerDb {
public:
    //There can be only one
    static CustomerDb& getInstance() {
      static CustomerDb cDb = CustomerDb();
        return cDb;
    }

    virtual void addCustomerRentals(const Customer &c);

    virtual ~CustomerDb();

    virtual std::map<std::string, Customer> getCustomers();

    virtual void store();

protected:
    CustomerDb();
    virtual void readCustomerDb();

    std::map<std::string, Customer> customers;
};

}

#endif //CUSTOMERDB_H
