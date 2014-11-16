#include "Player.h"
USING_NS_CC;

Player::Player()
{
	this->player=Sprite3D::create("model/zhanshi_pao.c3b");
	player->setRotation3D(Vec3(0,165,0));

	auto animation=Animation3D::create("model/zhanshi_pao.c3b");
	auto animate=Animate3D::create(animation);
	player->runAction(RepeatForever::create(animate));
}

Sprite3D* Player::getPlayer()
{
	return player;
}