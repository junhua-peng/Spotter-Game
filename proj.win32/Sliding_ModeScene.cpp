#include "Sliding_ModeScene.h"
#include "cocos2d.h"
#include "StartGame.h"
#include "Sliding_ModeLayer.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;

Sliding_ModeScene::Sliding_ModeScene(void)
{
	_sliding_modelayer=NULL;
}


Sliding_ModeScene::~Sliding_ModeScene(void)
{
}
bool Sliding_ModeScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());


		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/bg_music.mp3",true);


		CCSize size=CCDirector::sharedDirector()->getWinSize();

		/*
		CCSprite *spbg=CCSprite::create("pick1.png");
		spbg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(spbg);
		*/

		_sliding_modelayer=Sliding_ModeLayer::create();
		this->addChild(_sliding_modelayer,1);


	 

		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Sliding_ModeScene::ReturnGame));
		gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);



		bRet=true;
	} while (0);
	return true;
}

void Sliding_ModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *resplayscene=pick_pattern::create();
	float t=2.0f;
	rescene=CCTransitionProgressHorizontal::create(t,resplayscene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}