#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Clover_ModeLayer :
	public cocos2d::CCLayer
{
public:
	Clover_ModeLayer(void);
	~Clover_ModeLayer(void);
	CREATE_FUNC(Clover_ModeLayer);
	virtual bool init();
	 
	//´¥ÆÁÊÂ¼þ
//	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void ccTouchesMoved(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	//virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
		void Timeout(float dt);

		void enlarge(CCObject *pSender);
		void store(CCObject *pSender);

		void GamePause(CCObject *pSender);
		void GameResume(CCObject *pSender);


         CCSprite *m_pausebg;

	 
};

