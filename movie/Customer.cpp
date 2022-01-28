#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;
using std::string;


namespace MovieDB {

Customer::Customer(const std::string& name) : _name(name) {
}

Customer::~Customer() {
}

void Customer::addRental( const Rental& arg ) {
	_rentals.push_back( arg ); }

std::string Customer::getName() const {
	return _name; }




string Customer:: statement() {

	double totalAmount = 0;
	int frequentRenterPoints = 0;
	ostringstream result;
	result << "Rental Record for " << getName() << "\n";
	for (vector<Rental>::iterator iter = _rentals.begin(); iter != _rentals.end(); ++iter ) {
		double thisAmount = 0;
		Rental each = *iter;

		// determine amounts for each line
		thisAmount = each.getMovie().getPrice(each.getDaysRented());

		// add frequent renter points
		frequentRenterPoints++;
		// add bonus for a two day new release rental

        frequentRenterPoints += each.getMovie().getFrequentRenterPoints(each.getDaysRented());


		// show figures for this rental
		result << "\t" << each.getMovie().getTitle() << "\t"
		<< thisAmount << "\n";
		totalAmount += thisAmount;
	}
	// add footer lines
	result << "Amount owed is " << totalAmount << "\n";
	result << "You earned " << frequentRenterPoints	<< " frequent renter points";
	return result.str();
}



    int Customer::getNumberRentals() const
    {
    	return _rentals.size();
    }


}
