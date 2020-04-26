#ifndef IO_OPERATOR_OVERLOADING_H
#define IO_OPERATOR_OVERLOADING_H

#include "entity/transmission.hpp"
#include "entity/coordinate.hpp"
#include "entity/direction.hpp"
#include <iostream>

std::ostream& operator<< (std::ostream& out, const TransmissionToCar& transmission);
std::ostream& operator<< (std::ostream& out, const Coordinate& point);
std::ostream& operator<< (std::ostream& out, const Direction& direction);

#endif