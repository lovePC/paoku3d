#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "DrawNode3D.h"
#include "cocos2d.h"
#include "Player.h"
using namespace cocos2d;

class GameScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void upDateScene(float dt);

	static cocos2d::DrawNode* drawnode;

	Player* player;
};


#endif _GAME_SCENE_H_
