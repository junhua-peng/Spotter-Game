#pragma once
#include "cocos2d.h"
class StartGame :
	public cocos2d::CCScene
{
public:
	StartGame(void);
	~StartGame(void);
	virtual bool init();
	CREATE_FUNC(StartGame);
	void  GameStart(CCObject *pSender);
	void  GameMode(CCObject *pSender);
	void  GameHelp(CCObject *pSender);
	void  GameMusic(CCObject *pSender);
	void  GameExit(CCObject *pSender);

	//CC_SYNTHESIZE(GameLayer*,_gameLayer,GameLayer);


};

