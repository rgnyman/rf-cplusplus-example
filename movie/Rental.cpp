#include "Rental.h"

namespace MovieDB {

Rental::Rental( const Movie& movie, int daysRented )
  : _movie( movie )
  , _daysRented( daysRented ) {}

Rental::~Rental() {
	// TODO Auto-generated destructor stub
}

int Rental::getDaysRented() const {
	return _daysRented;
}

const Movie& Rental:: getMovie() const {
	return _movie;
}

}
