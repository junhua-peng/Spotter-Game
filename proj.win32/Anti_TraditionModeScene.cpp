#include "Anti_TraditionModeScene.h"
#include "cocos2d.h"
#include "StartGame.h"
#include "Anti_TraditionModeLayer.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;
Anti_TraditionModeScene::Anti_TraditionModeScene(void)
{
//	_anti_traditionmodelayer=NULL;
}


Anti_TraditionModeScene::~Anti_TraditionModeScene(void)
{
}
bool Anti_TraditionModeScene::init()
{
	bool bRet=false;
	do{
		CC_BREAK_IF(!CCScene::init());

		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/bg_music.mp3",true);


		CCSize size=CCDirector::sharedDirector()->getWinSize();
		//±³¾°
		/*
		CCSprite *sp_bg=CCSprite::create("pick1.png");
		sp_bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_bg);
		*/

		
		_anti_traditionmodelayer=Anti_TraditionModeLayer::create();
		this->addChild(_anti_traditionmodelayer,1);



		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Anti_TraditionModeScene::ReturnGame));
		gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);



	}while(0);
	return true;
}
void Anti_TraditionModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=pick_pattern::create();
	float t=1.5f;
	rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}