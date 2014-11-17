#ifndef _OBSTACLE_ACTION_H_
#define _OBSTACLE_ACTION_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class ObstacleAction:public Action
{
public:
	ObstacleAction(Player* player,Node* render_node);
	ObstacleAction();
	virtual bool isDone() const;
	virtual void step(float time);
private:
	Node* render_node;
	Player* player;
};

#endif _OBSTACLE_ACTION_H_