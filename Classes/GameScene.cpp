#include "GameScene.h"

#include "MapSequence.h"
#include "CCMoveBy3D.h"
#include "cocostudio/CCSGUIReader.h"
#include <functional>

Scene* GameScene::createScene()
{
	auto scene=Scene::create();

	//正投影
	//x y 近裁面 远裁面
	auto camera_1=Camera::createOrthographic(960,640,0,1000);
	camera_1->setCameraFlag(CameraFlag::USER2);
	auto bg_layer=Layer::create();
	scene->addChild(camera_1);
	
	scene->addChild(bg_layer,-100,"model.back ground");

	auto the_background=Sprite::create("model/back_ground.jpg");
	the_background->setAnchorPoint(Vec2(0,0));
	bg_layer->addChild(the_background);
	bg_layer->setCameraMask(4);

	auto layer=GameScene::create();
	scene->addChild(layer,100,"game main");
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->current_gold=0;
	player=new Player();
	this->addChild(player->getPlayer(),10);

	player->getPlayer()->setPosition3D(Vec3(0,0,-40));

	input_controller=new PlayerInputController(player);
	//加入camera
	auto size=Director::getInstance()->getWinSize();
	//视线左右能看到的角度   所有的宽高比   近裁面   远裁面
	//透视投影
	auto camera=Camera::createPerspective(60,(GLfloat)size.width/size.height,1,200);
	//设置相机的身份
	camera->setCameraFlag(CameraFlag::USER1);
	camera->setPosition3D(Vec3(0,15,-15));
	//x向右为正y向上为正z面向你的方向为正，离开你的方向为负
	//这是两个向量  看向的方向  向上的方向
	camera->lookAt(Vec3(0,0,-60),Vec3(0,1,0));
	this->addChild(camera);
	/*
	请注意这个函数只是将Node下当前的子节点设为使用这个相机，
	在SetCameraMask之后添加的子节点不属于此范畴——它们仍然
	会使用默认的相机，所以大家一定要十分小心，在确定使用相机
	的时候，一定要新添加节点之后重新SetCameraMask。
	*/
	this->setCameraMask((unsigned short)CameraFlag::USER1);

	auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(GameScene::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(GameScene::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
	schedule(schedule_selector(GameScene::upDateScene));

	//加入障碍物
	auto map_sequence=new MapSequence();
	pg_controller.insertMapSequence(map_sequence);
	pg_controller.preGenerate(this);
	//加入UI层
	auto widget=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HUD/HUD.json");
	//加入暂停按钮
	auto pause_button=(ui::Button*)widget->getChildByName("Button_1");
	pause_button->addTouchEventListener([&](Ref* sender,ui::Widget::TouchEventType type){
		static bool is_pause=false;
		if (type==ui::Widget::TouchEventType::ENDED)
		{
			if (!is_pause)
			{
				Director::getInstance()->pause();
				is_pause=true;
			}else
			{
				is_pause=false;
				Director::getInstance()->resume();
			}
		}
	});
	//加入金币计数
	gold_text=(ui::TextAtlas*)widget->getChildByName("gold");
	gold_text->setStringValue("0");
	this->addChild(widget);

	return true;
}

void GameScene::upDateScene(float dt)
{
	pg_controller.randomGenerate(player,this,dt);
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	input_controller->receiveTouchBegin(touch->getLocation());
	return true;
}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event)
{
	input_controller->receiveTouchEnd(touch->getLocation());
}

void GameScene::earnGold()
{
	this->current_gold++;
	char str[100];
	sprintf(str,"%d",current_gold);
	gold_text->setStringValue(str);
}

void GameScene::hitplayer()
{
	auto widget=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Menu/Menu.json");
	this->addChild(widget);
	auto restart_btn=(ui::Button*)widget->getChildByName("restart");
	restart_btn->addTouchEventListener([&](Ref* sender,ui::Widget::TouchEventType type){
		Director::getInstance()->replaceScene(GameScene::createScene());
	});
	this->pauseSchedulerAndActions();
	this->_actionManager->removeAllActions();
	this->player->getPlayer()->stopAllActions();
}
