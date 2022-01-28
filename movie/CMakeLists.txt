project(movie)

set(CMAKE_CXX_STANDARD 17)


add_library(movie_lib Customer.cpp Movie.cpp Rental.cpp CustomerDb.cpp SimpleUi.cpp MovieTypes.cpp MovieTypes.h)
