#pragma once
#include "cocos2d.h"
#include "Clover_ModeLayer.h"
class Clover_ModeScene :
	public cocos2d::CCScene
{
public:
	Clover_ModeScene(void);
	~Clover_ModeScene(void);
	virtual bool init();
	void ReturnGame(CCObject *pSender);
	CREATE_FUNC(Clover_ModeScene);
	CC_SYNTHESIZE(Clover_ModeLayer*,_clover_modelayer,Clover_ModeLayer);

};

