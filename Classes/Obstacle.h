#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class Obstacle:public Sprite3D
{
public:
	Obstacle();
	void initByFile(const char* file_name);
	void initDefault(Player* player,Node* render_node);
	Sprite3D* getSpirte();
	void bindTo(Node* render_node);
	void setLength(int new_length);
	int getLength();
	void update(float delta);
private:
	int length;
	Sprite3D* obstacle_sprite;
};


#endif _OBSTACLE_H_