#include <pybind11/pybind11.h>
#include "Customer.h"
#include "Rental.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
using namespace MovieDB;

Movie* createRegularMovie(const std::string &name) {
    return new Movie(name, new Regular{});
}

PYBIND11_MODULE(movie_interface, m) {

    m.def("createRegularMovie", &createRegularMovie);

    py::class_<Customer>(m, "Customer")
	.def(py::init())
	.def(py::init<const std::string &>())
	.def("addRental", &Customer::addRental)
	.def("getName", &Customer::getName)
	.def("statement", &Customer::statement);    

    py::class_<Rental>(m, "Rental")
	.def(py::init<const Movie &, int>())
	.def("getDaysRented", &Rental::getDaysRented)
	.def("getMovie", &Rental::getMovie);

    py::class_<Movie>(m, "Movie")
	.def(py::init<const std::string &, MovieType *>())
	.def("getPriceCode", &Movie::getPriceCode)
	.def("getTitle", &Movie::getTitle)
    .def("getPrice", &Movie::getPrice)
    .def("getFrequentRenterPoints", &Movie::getFrequentRenterPoints);

    py::class_<Regular>(m, "Regular")
    .def(py::init<>())
    .def("getType", &Regular::getType)
    .def("getPrice", &Regular::getPrice);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

