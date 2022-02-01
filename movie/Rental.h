#ifndef RENTAL_H_
#define RENTAL_H_

#include "Movie.h"

namespace MovieDB {

class Rental {
public:
	Rental( const Movie& movie, int daysRented );
	virtual ~Rental();
	int getDaysRented() const;
	const Movie& getMovie() const;

    friend std::ostream & operator << (std::ostream &out, const Rental & o)
    {
        out << o._movie << "\n" <<o._daysRented<<"\n";
        return out;
    }

    friend std::istream & operator >> (std::istream &in,  Rental &o)
    {
        in >> o._movie;
        std::string daysRented;
        std::getline(in, daysRented);
        o._daysRented = std::stoi(daysRented);
        return in;
    }

private:
  Movie _movie;
  int _daysRented;
};

}

#endif /* RENTAL_H_ */
