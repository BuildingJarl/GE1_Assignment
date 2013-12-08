#pragma once
#include "GameComponent.h"
#include "Leap.h"
#include "Game.h"
#include <btBulletDynamicsCommon.h>
#include "PhysicsController.h"
#include "KinematicController.h"
#include "PhysicsFactory.h"

namespace BGE 
{
	
	struct XSmaller
	{
		bool operator()( const Leap::Vector& lx, const Leap::Vector& rx ) const {
    		return lx.x < rx.x;
		}
	};
		

	class Hand:
		public GameComponent
	{
	private:
		Leap::Controller leapmotionController;
		btDiscreteDynamicsWorld * dynamicsWorld;


	public:
		Hand(Leap::Controller leapmotionController,btDiscreteDynamicsWorld * dynamicsWorld);
		~Hand(void);

		void Update(float timeDelta);
		bool Initialise();

		std::shared_ptr<PhysicsFactory> physicsFactory;

		shared_ptr<KinematicController> palm;
		shared_ptr<KinematicController> thumbTip;
		shared_ptr<KinematicController> indexTip;
		shared_ptr<KinematicController> middleTip;
		shared_ptr<KinematicController> ringTip;
		shared_ptr<KinematicController> pinkyTip;

		shared_ptr<PhysicsController> thumbLower;
		shared_ptr<PhysicsController> indexLower;
		shared_ptr<PhysicsController> middleLower;
		shared_ptr<PhysicsController> ringLower;
		shared_ptr<PhysicsController> pinkyLower;

		shared_ptr<PhysicsController> thumbUpper;
		shared_ptr<PhysicsController> indexUpper;
		shared_ptr<PhysicsController> middleUpper;
		shared_ptr<PhysicsController> ringUpper;
		shared_ptr<PhysicsController> pinkyUpper;

		float elapsedLeapFrameTime;
	};

}


