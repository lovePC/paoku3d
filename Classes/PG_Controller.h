#ifndef _PG_CONTROLLER_H_
#define _PG_CONTROLLER_H_
#include "cocos2d.h"
#include "Player.h"
#include <stack>
#include "MapSequence.h"
USING_NS_CC;

class PG_Controller
{
public:
	PG_Controller();
	~PG_Controller();

	void randomGenerate(Player* player,Node* render_node,float dt);
	void generateScene(Player* player,Node* render_node);
	void generateObsacle(Player* player,Node* render_node);
	void generateCoin(Player* player,Node* render_node);
	void generateGround(Node* render_node);
	//void insertMapSequence(MapSequence* map_sequence);
	void preGenerate(Node* render_node);
private:
	//
	void run(float dt);
	//
	//
};

#endif _PG_CONTROLLER_H_