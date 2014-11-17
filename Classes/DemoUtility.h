#ifndef _DEMO_UTILITY_H_
#define _DEMO_UTILITY_H_
#include "cocos2d.h"
USING_NS_CC;

//the utility is for general using
namespace DemoUtility{
	//估计模型的相对位置
	//caculate the relative translation for the model
	Vec3 translateRelative(Vec3 pos,Vec3 rotateAngle,Vec3 speed);
	//get the player current track
	int getTrack(float x);
}

#endif _DEMO_UTILITY_H_