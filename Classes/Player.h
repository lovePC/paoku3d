#ifndef _PALYER_H_
#define _PALYER_H_
#include "cocos2d.h"
class Player{
public:
	Player();
	cocos2d::Sprite3D* getPlayer();
private:
	cocos2d::Sprite3D* player;
};

#endif _PALYER_H_