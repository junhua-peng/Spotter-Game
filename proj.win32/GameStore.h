#pragma once
#include "cocos2d.h"

class GameStore:public cocos2d::CCScene
{
public:
	GameStore(void);
	~GameStore(void);
	virtual bool init();
	CREATE_FUNC(GameStore);
	void GameReturn(CCObject *pSender);
};

