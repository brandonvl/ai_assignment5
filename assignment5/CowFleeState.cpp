#include "CowFleeState.h"
#include "CowWanderState.h"
#include "Cow.h"
#include "Game.h"
#include "Rabbit.h"
#include "SteeringBehaviors.h"

#include <iostream>

CowFleeState::CowFleeState(std::string name) : State(name) {

}

bool CowFleeState::onMessage(Cow *entity, const Telegram &msg, Game &game)
{
	return false;
}

void CowFleeState::enter(Cow *entity, Game &game)
{
	entity->setMaxSpeed(entity->getFleeSpeed());
	std::cout << "Cow Entered FleeState";
}

void CowFleeState::update(Cow *entity, Game &game)
{
	if (entity->getSteeringBehaviors().isWanderOn())
		entity->getSteeringBehaviors().wanderOff();

	if (!entity->getSteeringBehaviors().isEvadeOn())
		entity->getSteeringBehaviors().evadeOn(&game.getRabbit(), entity->getFleeDistance());

	if (Vec2DDistanceSq(*entity->getPos(), *game.getCow().getPos()) > entity->getSafeDistance())
		entity->getStateMachine().changeState(new CowWanderState("CowWanderState"));
}

void CowFleeState::exit(Cow *entity, Game &game)
{
	std::cout << "Cow Left FleeState";
}