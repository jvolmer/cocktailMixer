#include "coordinate.hpp"
#include "direction.hpp"
#include "gridPosition.hpp"
#include <math.h>

GridPosition::GridPosition(const Coordinate& location, const Direction& direction) :
    _location { location },
    _forwardDirection { direction }
{}

GridPosition::GridPosition(Coordinate&& location, Direction&& direction) :
    _location { location },
    _forwardDirection { direction }
{}

int GridPosition::getTurnTrendToReach(const Coordinate& coordinate) const
{
    const double pi = 3.141592653589793;
    Coordinate diff = coordinate - _location;
    double directDirectionToCoordinateInPi = atan2(diff.gety(), diff.getx()) / pi;
    double forwardDirectionInPi = ((4 - (int)_forwardDirection) % 4) * .5;
    double turningDirectionInPi = forwardDirectionInPi - directDirectionToCoordinateInPi;
    
    if ( ((turningDirectionInPi > -.25) && (turningDirectionInPi < .25)) ||
         ((turningDirectionInPi > 1.75) && (turningDirectionInPi < 2.25)) )
    {
        return 0;
    }
    else if ( ((turningDirectionInPi >= -1) && (turningDirectionInPi <=-.25)) ||
              ((turningDirectionInPi >= 1)  && (turningDirectionInPi <= 1.75)) )
    {
        return -1;
    }
    else
        return 1;
}

bool operator== (const GridPosition& lhs, const GridPosition& rhs)
{
    return ( lhs.getLocation() == rhs.getLocation() &&
             lhs.getForwardDirection() == rhs.getForwardDirection() );
}
