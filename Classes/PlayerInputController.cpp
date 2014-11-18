#include "PlayerInputController.h"
#include "CCMoveBy3D.h"

PlayerInputController::PlayerInputController(Player* player)
{
	this->player=player;
}

void PlayerInputController::receiveTouchBegin(Vec2 pos)
{
	//pos��Ϊ�գ�touch_begin_posռ��pos�ĳ�ʼ����
	//�������Ͽ���
	this->touch_begin_pos=std::move(pos);
}
void PlayerInputController::receiveTouchEnd(Vec2 pos)
{
	this->touch_end_pos=std::move(pos);

	Vec2 diff=touch_end_pos-touch_begin_pos;
	//x=x/б��   y=y/б��
	//������׼��
	diff.normalize();
	auto a=std::move(Vec2(1,0));//horizontal lineˮƽ��
	//��������������
	//�õ��������нǵ�cosֵ
	auto result=Vec2::dot(diff,a);
	const int TURN_LEFT=1;
	const int TURN_RIGHT=2;
	//�����cos45��
	if (abs(result)>0.7)//left or right
	{
		if (result>0)//right
		{
			if (player->getPlayer()->getPositionX()<10&&!player->getPlayer()->getActionByTag(TURN_RIGHT)&&!player->getPlayer()->getActionByTag(TURN_LEFT))
			{
				auto action=MoveBy3D::create(0.2,Vec3(-10,0,0),false);
				action->setTag(TURN_RIGHT);
				this->player->getPlayer()->runAction(action);
				CCLOG("right");
			}
		}else//left
		{
			if (player->getPlayer()->getPositionX()>-10&&!player->getPlayer()->getActionByTag(TURN_RIGHT)&&!player->getPlayer()->getActionByTag(TURN_LEFT))
			{
				auto action=MoveBy3D::create(0.2,Vec3(10,0,0),false);
				action->setTag(TURN_RIGHT);
				this->player->getPlayer()->runAction(action);
				CCLOG("left");
			}
		}
	}else
	{
		if (diff.y>0)//up
		{
			//
			CCLOG("up");
		}else//down
		{
			//
			CCLOG("down");
		}
	}
}