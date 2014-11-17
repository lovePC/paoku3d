#include "DemoUtility.h"
#include <math.h>
#define PI_OVER_180 (3.141592653/180.0)

namespace DemoUtility{
	Vec3 translateRelative(Vec3 pos,Vec3 rotateAngle,Vec3 speed)
	{
		Vec3 newPos=pos;
		float yaw=rotateAngle.y;
		float pitch=rotateAngle.x;
		float roll=rotateAngle.z;
		newPos.z+=cos(PI_OVER_180*pitch)*cos(PI_OVER_180*yaw)*speed.z
			-sin(PI_OVER_180*yaw)*speed.x
			+sin(PI_OVER_180*pitch)*speed.y;
		newPos.x+=sin(PI_OVER_180*yaw)*speed.z
			+cos(PI_OVER_180*yaw)*cos(PI_OVER_180*roll)*speed.x
			+sin(PI_OVER_180*roll)*speed.y;
		newPos.y+=-sin(PI_OVER_180*pitch)*cos(PI_OVER_180*yaw)*speed.z
			+cos(PI_OVER_180*roll)*cos(PI_OVER_180*pitch)*speed.y
			-sin(PI_OVER_180*roll)*speed.x;

		return newPos;
	}

	int getTrack(float x){
		if (x>=-10&&x<-5)
		{
			return 0;
		}
		else if (x>-5&&x<5)
		{
			return 1;
		}else if (x>5&&x<10)
		{
			return 2;
		}
	}
}

