#include "cocos2d.h"

class Actor: public cocos2d::Sprite
{
protected:
	int hp, mp;
	bool stun;
public:
	Actor();
	Actor(int hp, int mp );
	int getHp();
	void setHp(int hp);
	int getMana();
	void setMp(int mp);
	void increaseHp(int hp);
	void decreaseHp(int hp);
	void increaseMana(int mp);
	void decreaseMana(int mp);
	void setStun(bool stun);
	bool isStun();
};
