#ifndef REFACTORING_MOVIETYPES_H
#define REFACTORING_MOVIETYPES_H

#include <string>
#include <map>
#include <iostream>

namespace MovieDB {

class MovieType {
public:
    virtual int getType() = 0;
    virtual const std::string getName() = 0;
    virtual double getPrice(int daysRented) = 0;
    virtual int getFrequentRenterPoints(int daysRented) {
        return 0;
    }
    virtual ~MovieType() = default;
};

class Childrens : public MovieType {
public:
    int getType() override {
        return 2;
    }

    double getPrice(int daysRented) override {
        double price{1.5};
        if (daysRented > 3) {
            price += (daysRented - 3) * 1.5;
        }
        return price;
    }

    const std::string getName() override {
        return getTypeName();
    }
    static const std::string getTypeName() {
        return typeid(Childrens).name();
    }

};

class Regular : public MovieType {
public:
    int getType() override {
        return 0;
    }

    double getPrice(int daysRented) override {
        double price{2};
        if (daysRented > 2 )
            price += ( daysRented - 2 ) * 1.5;
        return price;
    }

    const std::string getName() override {
        return getTypeName();
    }


    static const std::string getTypeName() {
        return typeid(Regular).name();
    }


};

class NewRelease : public MovieType {
public:
    int getType() override {
        return 1;
    }

    double getPrice(int daysRented) override {
        return daysRented * 3;
    }

    int getFrequentRenterPoints(int daysRented) override {
        if (daysRented > 1) {
            return 1;
        } else {
            return 0;
        }
    }

    const std::string getName() override {
        return getTypeName();
    }
    static const std::string getTypeName() {
        return typeid(NewRelease).name();
    }
};

class MovieTypeCreator {
public:
    virtual MovieType* createMovieType() = 0;
    virtual ~MovieTypeCreator() = default;
};

class MovieRegular : public MovieTypeCreator {
public:
    MovieType* createMovieType() override {
        return new Regular{};
    }
};

class MovieChildrens : public MovieTypeCreator {
public:
    MovieType* createMovieType() override {
        return new Childrens{};
    }
};

class MovieNewRelease : public MovieTypeCreator {
public:
    MovieType* createMovieType() override {
        return new NewRelease{};
    }
};

class MovieTypes {
public:
    MovieTypes() {
        factories[Childrens::getTypeName()] = std::unique_ptr<MovieTypeCreator>(new MovieChildrens{});
        factories[NewRelease::getTypeName()] = std::unique_ptr<MovieTypeCreator>(new MovieNewRelease{});
        factories[Regular::getTypeName()] = std::unique_ptr<MovieTypeCreator>(new MovieRegular{});
    }

    std::shared_ptr<MovieType> createMovieType(std::string &name) {
        return std::shared_ptr<MovieType>(factories.find(name)->second->createMovieType());
    }
private:
    std::map<const std::string, std::unique_ptr<MovieTypeCreator>> factories;
};

} //Namespace

#endif //REFACTORING_MOVIETYPES_H
