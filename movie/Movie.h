
#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <iostream>
#include "MovieTypes.h"

namespace MovieDB {

class Movie {
public:
  Movie();

  Movie(const std::string& name, MovieType *type) : Movie(name, std::shared_ptr<MovieType>(type)) {
  }

  Movie( const std::string& title, std::shared_ptr<MovieType> type = std::shared_ptr<MovieType>(new Regular{}));
  virtual ~Movie();

  int getPriceCode() const;

  double getPrice(int daysRented) const {
      return type->getPrice(daysRented);
  }

  int getFrequentRenterPoints(int daysRented) const {
      return type->getFrequentRenterPoints(daysRented);
  }

  void setPriceCode( int arg );
  std::string getTitle() const;

    friend std::ostream & operator << (std::ostream &out, const Movie & o)
    {
        out << o._title;
        out << std::endl;
        out << o.type->getName();
        return out;
    }

    friend std::istream & operator >> (std::istream &in,  Movie &o)
    {
        std::getline(in, o._title);
        std::string typeName;
        std::getline(in, typeName);
        MovieTypes typeFactory{};
        o.type = typeFactory.createMovieType(typeName);
        return in;
    }

private:
  std::string _title;
  int _priceCode;
  std:: shared_ptr<MovieType> type;
};

}

#endif /* MOVIE_H_ */
