#pragma once
#include "cocos2d.h"
#include "Normal_ModeLayer.h"
class Normal_ModeScene :
	public cocos2d::CCScene
{
public:
	Normal_ModeScene(void);
	~Normal_ModeScene(void);
	 virtual bool init();
	 void ReturnGame(CCObject *pSender);
	 CREATE_FUNC(Normal_ModeScene);
	 CC_SYNTHESIZE(Normal_ModeLayer*,_normal_modelayer,Normal_ModeLayer);

};

