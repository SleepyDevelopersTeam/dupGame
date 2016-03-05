#include "Profile.h"

Profile * Profile::instance = nullptr;
SingleToonDestr Profile::destoyer;

SingleToonDestr::~SingleToonDestr()
{
	delete instance;
}

void SingleToonDestr::initilize(Profile * p)
{
	instance = p;
}

Profile * Profile::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Profile();
		destoyer.initilize(instance);
	}
	return instance;
}

int Profile::getLastLevel() const
{
	return this->numberLastLevel;
}

void Profile::setLastLevel(int number)
{
	this->getLastLevel = number;
}

void Profile::setMoney(int number)
{
	this->money = number;
}

int Profile::getMoney() const
{
	return this->money;
}

void Profile::setNumberKills(int number)
{
	this->numberKills = number;
}

int Profile::getNumberKills() const
{
	return this->numberKills;
}

void Profile::setNumberDeaths(int number)
{
	this->numberDeaths = number;
}

int Profile::getNumberDeaths() const
{
	return this->numberDeaths;
}

void Profile::setName(std::string name)
{
	this->name = name;
}

std::string Profile::getName()
{
	return name;
}



