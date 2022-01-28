
from movie_interface import *


class MovieLibrary:
    ROBOT_LIBRARY_SCOPE = "SUITE"

    def __init__(self):
        self._counter = 0
        self._movie = 0
        self._customer = 0
        self._rental = 0

    def add_movie(self, name):
        self._movie = createRegularMovie(name)

    def add_rental(self, days_rented):
        self._rental = Rental(self._movie, days_rented)

    def add_customer(self, name):
        self._customer = Customer(name)

    def add_customer_rental(self):
        self._customer.addRental(self._rental)

    def get_statement(self):
        return self._customer.statement()

if __name__ == "__main__":
    ml = MovieLibrary()
    ml.add_movie("Gone")
    ml.add_rental(3)
    ml.add_customer("Sally")
    ml.add_customer_rental()
    print(ml.get_statement())
    
