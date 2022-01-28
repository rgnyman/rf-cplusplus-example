
#include "Movie.h"

namespace MovieDB {

Movie::Movie()
  : _title(""), type(new Regular{})
{}


Movie::Movie( const std::string& title, std::shared_ptr<MovieType> type)
  : _title(title)
  , type(type)
{}

Movie::~Movie() {
	// TODO Auto-generated destructor stub
}

int Movie:: getPriceCode() const {
	return type->getType();
}

void Movie::setPriceCode( int arg ) {
	_priceCode = arg; }

std::string Movie::getTitle() const {
	return _title; }




}
