#ifndef _GROUND_ACTION_H_
#define _GROUND_ACTION_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class GroundAction:public Action
{
public:
	virtual bool isDone() const;
	virtual void step(float time);
};

#endif _GROUND_ACTION_H_