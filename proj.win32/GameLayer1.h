#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"

class GameLayer1 :
	public cocos2d::CCLayer
{
public:
	GameLayer1(void);
	~GameLayer1(void);
	CREATE_FUNC(GameLayer1);
	virtual bool init();

	//触屏事件
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);

	//生命周期
	virtual void onEnter();
	virtual void onExit();

	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);

};

