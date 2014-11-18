#ifndef _COIN_ACTION_H_
#define _COIN_ACTION_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;

class CoinAction:public Action
{
public:
	CoinAction();
	CoinAction(Player* player,Node* node);
	virtual bool isDone() const;
	virtual void step(float time);
private:
	bool is_triggered;//´¥·¢
	Node* render_node;
	float angle;
	Player* player;
};


#endif _COIN_ACTION_H_