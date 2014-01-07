#pragma once
#include "cocos2d.h"
#include "Sliding_ModeScene.h"
#include "Sliding_ModeLayer.h"
class Sliding_ModeScene :
	public cocos2d::CCScene
{
public:
	Sliding_ModeScene(void);
	~Sliding_ModeScene(void);
	virtual bool init();
	void ReturnGame(CCObject *pSender);
	CREATE_FUNC(Sliding_ModeScene);
	CC_SYNTHESIZE(Sliding_ModeLayer*,_sliding_modelayer,Sliding_ModeLayer);
	 void Timeout(float dt);
};

