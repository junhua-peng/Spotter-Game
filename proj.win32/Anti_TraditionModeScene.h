#pragma once
#include "cocos2d.h"
 
#include "Anti_TraditionModeLayer.h"
class Anti_TraditionModeScene :
	public cocos2d::CCScene
{
public:
	Anti_TraditionModeScene(void);
	~Anti_TraditionModeScene(void);
	virtual bool init();
	void ReturnGame(CCObject *pSender);
	CREATE_FUNC(Anti_TraditionModeScene);
	CC_SYNTHESIZE(Anti_TraditionModeLayer*,_anti_traditionmodelayer,Anti_TraditionModeLayer);
};

