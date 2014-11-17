#ifndef _DECORATION_ACTION_H_
#define _DECORATION_ACTION_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class DecorationAction:public Action
{
public:
	virtual bool isDone() const;
	virtual void step(float time);
};

#endif _DECORATION_ACTION_H_