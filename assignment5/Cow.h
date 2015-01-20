#pragma once
#include "Vehicle.h"
#include "StateMachine.h"

class Cow :
	public Vehicle
{
private:
	bool _hasPill, _hasWeapon;
	StateMachine<Cow> *_stateMachine;
	void makeMachine(Game &game);
public:
	StateMachine<Cow> &getStateMachine() { return *_stateMachine; }
	Cow(Game &game);
	virtual ~Cow();
	virtual void update(Game &game, const double &time_elapsed) override;
	virtual void draw(Game &game) override;
	
	double getFleeDistance() { return 300; }
	double getSafeDistance() { return 150 * 150; }
	int getWanderSpeed() { return 100; }
	int getFleeSpeed() { return 150; }

	bool getHasPill() { return _hasPill; }
	void setHasPill(bool has) { _hasPill = has; }

	bool getHasWeapon() { return _hasWeapon; }
	void setHasWeapon(bool has) { _hasWeapon = has; }
};

