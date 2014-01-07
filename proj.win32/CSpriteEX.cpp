#include "CSpriteEX.h"
#include "cocos2d.h"

using namespace cocos2d;


CCSpriteEX::CCSpriteEX(void)
{
}


CCSpriteEX::~CCSpriteEX(void)
{
}
void CCSpriteEX::onEnter()
{
	CCDirector* pDirector=CCDirector::sharedDirector();
	//pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);
	CCSprite::onEnter();
}
void CCSpriteEX::onExit()
{
	CCDirector *pDirector=CCDirector::sharedDirector();
	//pDirector->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}