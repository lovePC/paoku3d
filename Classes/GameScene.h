#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "DrawNode3D.h"
#include "cocos2d.h"
#include "Player.h"
#include "PlayerInputController.h"
#include "PG_Controller.h"
#include "ui/UIButton.h"
#include "ui/UITextAtlas.h"
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

	static DrawNode3D* drawnode;
	void earnGold();
	void hitplayer();
private:
	Player* player;
	friend class ObstacleAction;
	friend class CoinAction;
	int current_gold;
	PlayerInputController* input_controller;
	Vec2 touch_begin_pos;
	Vec2 touch_end_pos;
	Camera* the_camera;
	PG_Controller pg_controller;
	ui::TextAtlas* gold_text;
};


#endif _GAME_SCENE_H_
