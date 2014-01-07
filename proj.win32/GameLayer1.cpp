#include "GameLayer1.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

GameLayer1::GameLayer1(void)
{
}


GameLayer1::~GameLayer1(void)
{
}
bool GameLayer1::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());


		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pd_hit0.wav");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pd_hit1.wav");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pd_herodeath.wav");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pd_botdeath.wav");


		CCSize  size=CCDirector::sharedDirector()->getWinSize();
		CCSprite *sp1=CCSprite::create("bgimage/logo1.png");
		sp1->setPosition(ccp(size.width/2,size.height/2));
		sp1->setVisible(false);
		this->addChild(sp1,1,1);

		CCSprite *sp2=CCSprite::create("sp1.png");
		sp1->setPosition(ccp(300,300));
		this->addChild(sp2,2,2);

		CCSprite *sp3=CCSprite::create("sp2.png");
		sp3->setPosition(ccp(400,400));
		sp3->addChild(sp3,3,3);

		CCSprite *sp4=CCSprite::create("sp3.png");
		sp4->setPosition(ccp(500,450));
		sp4->addChild(sp4,3,4);



		bRet=true;
	} while (0);
	return bRet;
}

bool GameLayer1::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{

	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	bool IsSelect;
	CCSprite *sp1=(CCSprite*)this->getChildByTag(3);

	//IsSelect=CCRect::CCRectContainsPoint(sp1->boundingBox,)


	CCSprite *sp2=CCSprite::create("test1.png");
	sp2->setPosition(ccp(500,500));
	this->addChild(sp2);
    return true;
}
void GameLayer1::ccTouchesMoved(CCSet *pTouches,CCEvent *pEvent)
{
	CCSprite *sp2=CCSprite::create("test1.png");
	sp2->setPosition(ccp(400,400));
	this->addChild(sp2);
}
void GameLayer1::ccTouchesEnded(CCSet *pTouches,CCEvent *pEvent)
{
    CCSprite *sp3=CCSprite::create("test1.png");
	sp3->setPosition(ccp(300,300));
	this->addChild(sp3);
}
void GameLayer1::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}
void GameLayer1::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}