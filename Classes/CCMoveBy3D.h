#ifndef _CC_MOVE_BY_3D_H_
#define _CC_MOVE_BY_3D_H_
#include <vector>

#include "2d/CCAction.h"
#include "2d/CCAnimation.h"
#include "base/CCProtocols.h"
#include "base/CCVector.h"

#include "2d/CCActionInterval.h"
//命名空间开始
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
	//变量增量
	Vec3 _positionDelta;
	Vec3 _startPosition;
	//事先，以前
	Vec3 _previousPosition;
	//相对的
	bool _isRelative;
private:
	//不接受复制并且进行编制
	CC_DISALLOW_COPY_AND_ASSIGN(MoveBy3D);
};

NS_CC_END
#endif _CC_MOVE_BY_3D_H_