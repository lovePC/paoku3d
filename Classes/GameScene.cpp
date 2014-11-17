#include "GameScene.h"

#include "MapSequence.h"
#include "CCMoveBy3D.h"
#include "cocostudio/CCSGUIReader.h"
#include <functional>

Scene* GameScene::createScene()
{
	auto scene=Scene::create();

	//��ͶӰ
	//x y ������ Զ����
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
	//����camera
	auto size=Director::getInstance()->getWinSize();
	//���������ܿ����ĽǶ�   ���еĿ�߱�   ������   Զ����
	//͸��ͶӰ
	auto camera=Camera::createPerspective(60,(GLfloat)size.width/size.height,1,200);
	//������������
	camera->setCameraFlag(CameraFlag::USER1);
	camera->setPosition3D(Vec3(0,15,-15));
	//x����Ϊ��y����Ϊ��z������ķ���Ϊ�����뿪��ķ���Ϊ��
	//������������  ����ķ���  ���ϵķ���
	camera->lookAt(Vec3(0,0,-60),Vec3(0,1,0));
	this->addChild(camera);
	/*
	��ע���������ֻ�ǽ�Node�µ�ǰ���ӽڵ���Ϊʹ����������
	��SetCameraMask֮����ӵ��ӽڵ㲻���ڴ˷��롪��������Ȼ
	��ʹ��Ĭ�ϵ���������Դ��һ��Ҫʮ��С�ģ���ȷ��ʹ�����
	��ʱ��һ��Ҫ����ӽڵ�֮������SetCameraMask��
	*/
	this->setCameraMask((unsigned short)CameraFlag::USER1);

	auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(GameScene::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(GameScene::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
	schedule(schedule_selector(GameScene::upDateScene));

	//�����ϰ���
	auto map_sequence=new MapSequence();
	pg_controller.insertMapSequence(map_sequence);
	pg_controller.preGenerate(this);
	//����UI��
	auto widget=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HUD/HUD.json");
	//������ͣ��ť
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
	//�����Ҽ���
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
