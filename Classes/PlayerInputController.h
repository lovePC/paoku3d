#ifndef _PLAYER_INPUT_CONTROLLER_H_
#define _PLAYER_INPUT_CONTROLLER_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;

//handle the player input
class PlayerInputController{
public:
	PlayerInputController(Player* player);
	void receiveTouchBegin(Vec2 pos);
	void receiveTouchEnd(Vec2 pos);
private:
	Player* player;
	Vec2 touch_begin_pos;
	Vec2 touch_end_pos;
};


#endif _PLAYER_INPUT_CONTROLLER_H_