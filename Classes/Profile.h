#pragma once
#include <string>

class Profile;

class SingleToonDestr
{
private:
	Profile* instance;
public:
	~SingleToonDestr();
	void initilize(Profile* p);
};

class Profile
{
public:
	static Profile* getInstance();
	int	getLastLevel() const;
	void setLastLevel(int number);
	void setMoney(int number);
	int getMoney() const;
	void setNumberKills(int number);
	int getNumberKills() const;
	void setNumberDeaths(int number);
	int getNumberDeaths() const;
	void setName(std::string name);
	std::string getName();
private:
	static Profile* instance;
	static SingleToonDestr destoyer;
	Profile() { }
	~Profile() { }
	friend class SingleToonDestr;
	std::string name;
	int numberLastLevel;
	int money;
	int numberKills;
	int numberDeaths;
};

