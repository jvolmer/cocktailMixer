#include "pilot.hpp"
#include "position/position.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "findLineInLeftTurn.hpp"

FindLineInLeftTurn::FindLineInLeftTurn(Pilot& pilot, Position& position, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _position { position },
    _tracker { tracker },
    _motor { motor }
{}

void FindLineInLeftTurn::move()
{
    _motor.turnLeft();
    if ( _tracker.checkRoad() == RoadLayout::straight )
    {
        _position.turnLeft();
        _pilot.changeMotion( MotionName::followLine );
    }
}