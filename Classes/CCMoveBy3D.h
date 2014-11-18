#ifndef _CC_MOVE_BY_3D_H_
#define _CC_MOVE_BY_3D_H_
#include <vector>

#include "2d/CCAction.h"
#include "2d/CCAnimation.h"
#include "base/CCProtocols.h"
#include "base/CCVector.h"

#include "2d/CCActionInterval.h"
//�����ռ俪ʼ
NS_CC_BEGIN

class MoveBy3D:public ActionInterval
{
public:
	static MoveBy3D* create(float duration,const Vec3& deltaPosition,bool is_relative=false);

	virtual MoveBy3D* clone() const override;
	virtual MoveBy3D* reverse() const override;
	virtual void startWithTarget(Node *target) override;
	virtual void update(float time) override;
	void setIsRelative(bool is_relative);
CC_CONSTRUCTOR_ACCESS://protected
	MoveBy3D(){};
	virtual ~MoveBy3D(){};

	bool initWithDuration(float duration,const Vec3& deltaPosition);
protected:
	//��������
	Vec3 _positionDelta;
	Vec3 _startPosition;
	//���ȣ���ǰ
	Vec3 _previousPosition;
	//��Ե�
	bool _isRelative;
private:
	//�����ܸ��Ʋ��ҽ��б���
	CC_DISALLOW_COPY_AND_ASSIGN(MoveBy3D);
};

NS_CC_END
#endif _CC_MOVE_BY_3D_H_