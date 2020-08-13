#include "pilot.hpp"
#include "motor/motor.hpp"
#include "tracker/tracker.hpp"
#include "tracker/roadLayout.hpp"
#include "motionName.hpp"
#include "turnLeftFromLine.hpp"

TurnLeftFromLine::TurnLeftFromLine(Pilot& pilot, Tracker& tracker, Motor& motor) :
    _pilot { pilot },
    _tracker { tracker },
    _motor { motor }
{}

void TurnLeftFromLine::move()
{
    _motor.turnLeft();
    if ( _tracker.checkRoad() == RoadLayout::sharpRight )
    {
        _pilot.changeMotion( MotionName::alignInLeftTurn );
    }
}