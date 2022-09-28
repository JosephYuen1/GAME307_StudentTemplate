#include "KinematicArrive.h"


KinematicArrive::KinematicArrive(Body* character_, Body* target_, float radius_, float timeToTarget_)
{
	character = character_;
	target = target_;
	radius = radius_;
	timeToTarget = timeToTarget_;
	result = new KinematicSteeringOutput();
}

KinematicArrive::~KinematicArrive()
{
	if (result) { delete result; }
}

KinematicSteeringOutput* KinematicArrive::getSteering()
{
	result->velocity = target->getPos() - character->getPos();
	//magnitude of the velocity
	if (VMath::mag(result->velocity) < radius)
	{
		return 0;
	}
	result->velocity /= timeToTarget;

	if (VMath::mag(result->velocity) > character->getMaxSpeed())
	{
		result->velocity = VMath::normalize(result->velocity);
		result->velocity = character->getMaxSpeed() * result->velocity;
	}

	result->rotation = 0.0f;
	
	return result;
}

