#ifndef KINEMATIC_ARRIVE_H
#define KINEMATIC_ARRIVE_H

#include "Vector.h"
#include "VMath.h"
#include "Body.h"
#include "KinematicSteeringOutput.h"

	using namespace MATH;

	class KinematicArrive
	{
	private:
		KinematicSteeringOutput* result;
		Body* character;
		Body* target;
		float radius;
		float timeToTarget;

	public:
		KinematicArrive(Body* character_, Body* target_, float radius_, float timeToTarget_);
		~KinematicArrive();
		KinematicSteeringOutput* getSteering();
		
	};
	
#endif

