#include "Puzzle_ModeScene.h"
#include "cocos2d.h"
#include  "StartGame.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;
Puzzle_ModeScene::Puzzle_ModeScene(void)
{
	_puzzle_modelayer=NULL;
}


Puzzle_ModeScene::~Puzzle_ModeScene(void)
{
}
bool Puzzle_ModeScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());


		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/bg_music.mp3",true);
		/*
		CCSize size=CCDirector::sharedDirector()->getWinSize();
		CCSprite *spbg=CCSprite::create("pick1.png");
		spbg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(spbg);
		*/
		_puzzle_modelayer=Puzzle_ModeLayer::create();
		this->addChild(_puzzle_modelayer);


	 

	 
		/*
		CCMenuItemImage *returnMenu=CCMenuItemImage::create("return_bg1.png","return_bg2.png",this,menu_selector(Puzzle_ModeScene::ReturnGame));
		returnMenu->setPosition(ccp(350,-270));
		CCMenu *pmenu=CCMenu::create(returnMenu,NULL);
		this->addChild(pmenu,2);
	 */
 


		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Puzzle_ModeScene::ReturnGame));
	     gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);



		bRet=true;
	} while (0);
	return true;
}

void Puzzle_ModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *replacescene=pick_pattern::create();
	float t=2.0f;
	rescene=CCTransitionFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}