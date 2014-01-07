#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "ccsprite.h"
using namespace cocos2d;
class CCSpriteEX :
	public cocos2d::CCSprite,public cocos2d::CCTargetedTouchDelegate,public CCLayer

{

 
public:
	CCSpriteEX(void);
	~CCSpriteEX(void);
	CCRect rect();
	virtual void onEnter();
	virtual void onExit();
	bool containTouchPoint(CCTouch *touch);
	virtual bool ccTouchBegan(CCTouch *touch,CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *touch,CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *touch,CCEvent *pEvent);

};

