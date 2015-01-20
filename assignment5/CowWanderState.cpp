#include "CowWanderState.h"
#include "CowFleeState.h"
#include "Cow.h"
#include "Game.h"
#include "Rabbit.h"
#include "SteeringBehaviors.h"

#include <iostream>

CowWanderState::CowWanderState(std::string name) : State(name) {

}

bool CowWanderState::onMessage(Cow *entity, const Telegram &msg, Game &game)
{
	return false;
}

void CowWanderState::enter(Cow *entity, Game &game)
{
	entity->setMaxSpeed(entity->getWanderSpeed());
	std::cout << "Cow Entered WanderState";
}

void CowWanderState::update(Cow *entity, Game &game)
{
	if (entity->getSteeringBehaviors().isEvadeOn())
		entity->getSteeringBehaviors().evadeOff();

	if (!entity->getSteeringBehaviors().isWanderOn())
		entity->getSteeringBehaviors().wanderOn();


	if (Vec2DDistance(*entity->getPos(), *game.getCow().getPos()) < entity->getFleeDistance())
		entity->getStateMachine().changeState(new CowFleeState("CowFleeState"));

}

void CowWanderState::exit(Cow *entity, Game &game)
{
	std::cout << "Cow left WanderState";
}