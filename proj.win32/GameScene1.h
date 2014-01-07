#pragma once
#include "cocos2d.h"
#include "GameLayer1.h"

class GameScene1 :public cocos2d::CCScene
{
public:
	GameScene1(void);
	~GameScene1(void);
	 CREATE_FUNC(GameScene1);
	 virtual bool init();
	 void GameReturn(CCObject *pSender);
	 CC_SYNTHESIZE(GameLayer1*,_gameLayer,GameLayer1);
	 


};

