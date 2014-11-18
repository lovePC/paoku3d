#include "CoinAction.h"
#include "GameScene.h"
#include "Effect.h"

bool CoinAction::isDone() const
{
	return !_target;
}

void CoinAction::step(float time)
{
	if (_target)
	{
		_target->setRotation3D(Vec3(90,angle,180));
		angle+=time*140;
		_target->setPosition3D(_target->getPosition3D()+Vec3(0,0,100*time));
		if (_target->getPositionZ()>-40&&_target->getPositionZ()<10)
		{
			Sprite3D* sprite=dynamic_cast<Sprite3D*>(_target);
			OBB obb(sprite->getAABB());

			Vec3 vertices[8];//¶¥µã
			auto player_aabb=player->getPlayer()->getAABB();
			auto dist=sprite->getPosition3D().distance(player->getPlayer()->getPosition3D());

			if (dist<5&&!is_triggered)
			{
				is_triggered=~is_triggered;
				sprite->setColor(Color3B(255,0,0));
				Effect::CoinEffect(render_node);
				auto a=(GameScene*)this->render_node;
				a->earnGold();
				CCLOG("Get Money!!~");
				return;
			}
		}
		if (_target->getPositionZ()>-10)
		{
			_target->removeFromParent();
			_target=nullptr;
		}
	}
}

CoinAction::CoinAction():player(NULL),angle(0),render_node(nullptr),is_triggered(false)
{

}

CoinAction::CoinAction(Player* player,Node* node):angle(0),is_triggered(false)
{
	this->player=player;
	this->render_node=node;
}