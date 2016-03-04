#include "Actor.h"



Actor::Actor()
{
	hp = 0;
	mp = 0;
	stun = false;
}

Actor::Actor(int hp, int mp )
{
	this->hp = hp;
	this->mp = mp;
	stun = false;
}
int Actor::getHp()
{
	return hp;
}
void Actor::setHp(int hp)
{
	this->hp = hp;
}
int Actor::getMana()
{
	return mp;
}
void Actor::setMp(int mp)
{
	this->mp = mp;
}
void Actor::increaseHp(int hp)
{
	this->hp += hp;
}
void Actor::decreaseHp(int hp)
{
	this->hp -= hp;
}
void Actor::increaseMana(int mp)
{
	this->mp += mp;
}
void Actor::decreaseMana(int mp)
{
	this->hp -= hp;
}
	
void Actor::setStun(bool stun)
{
	this->stun = stun;
}
bool Actor::isStun()
{
	return stun;
}
