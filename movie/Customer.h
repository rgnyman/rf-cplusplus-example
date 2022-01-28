#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include <iostream>
#include "Rental.h"

namespace MovieDB {

class Customer {
public:
	Customer() {};
	Customer( const std::string& name );
	virtual ~Customer();
	void addRental( const Rental& arg );
	std::string getName() const;
	std::string statement();
	// for UnitTesting
	int getNumberRentals() const;

    friend std::ostream & operator << (std::ostream &out, const Customer & o)
    {
        out << o._name;
        out << std::endl;
        out << o.getNumberRentals();
        out << std::endl;
        for (int i = 0; i < o.getNumberRentals(); ++i) {
            out << o._rentals[i];
        }
        return out;
    }

    friend std::istream & operator >> (std::istream &in,  Customer &o)
    {
        in >> o._name;
        int numberofRentals;
        in >> numberofRentals;
        for (int i = 0; i < numberofRentals; i++) {
            Rental r(Movie(), 0);
            in >> r;
            o._rentals.push_back(r);
        }
        return in;
    }

private:
  std::string _name;
  std::vector<Rental> _rentals;
};

}

#endif /* CUSTOMER_H_ */
