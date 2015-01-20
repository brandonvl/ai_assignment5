#pragma once
#include "Vehicle.h"
#include "StateMachine.h"

class Rabbit :
	public Vehicle
{
private:
	int _points;
	StateMachine<Rabbit> *_stateMachine;
	void makeMachine(Game &game);
public:
	StateMachine<Rabbit> &getStateMachine() { return *_stateMachine; }
	int getPursuitSpeed() { return 300; }
	int getCatchDistance() { return 20; }
	int getPoints() { return _points; }
	void addPoints(int points) { _points += points; }
	void setPoint(int points) { _points = points; }
	Rabbit(Game &game);
	virtual ~Rabbit();
	virtual void update(Game &game, const double &time_elapsed) override;
	virtual void draw(Game &game) override;
};