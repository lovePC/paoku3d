#include "GameScene.h"

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
	return true;
}

void GameScene::upDateScene(float dt)
{

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

}

void GameScene::hitplayer()
{

}
