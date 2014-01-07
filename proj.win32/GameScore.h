#pragma once
#include "cocos2d.h"

class GameScore:public cocos2d::CCScene
{
public:
	GameScore(void);
	~GameScore(void);
	virtual bool init();
	CREATE_FUNC(GameScore);
	void GameReturn(CCObject *pSender);
};

