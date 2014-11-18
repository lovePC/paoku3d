#ifndef _COIN_H_
#define _COIN_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;

class Coin{
public:
	Coin(Player* player,Node* render_node);
	void bindToLayer(Node* render_node);
	Sprite3D* getSprite();
private:
	Sprite3D* sprite;
	Player* player;
};


#endif _COIN_H_