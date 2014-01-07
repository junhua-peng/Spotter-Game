#include "StartGame.h"
#include "cocos2d.h"
#include "GameScene1.h"
#include "pick_pattern.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;


StartGame::StartGame(void)
{
}


StartGame::~StartGame(void)
{
}
bool StartGame::init()
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



	//CCLabelAtlas* diceCount=CCLabelAtlas::create()
	
	CCSprite *sp_bg=CCSprite::create("startbg.png");
	sp_bg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sp_bg);

	CCSprite *logo1=CCSprite::create("bgimage/logo2.png");
	logo1->setPosition(ccp(size.width/2,size.height/2));
	logo1->setOpacity(200);
	this->addChild(logo1,1);

	CCSprite *gamename=CCSprite::create("gamename.png");
	gamename->setPosition(ccp(size.width/2,size.height-100));
	this->addChild(gamename);

	//开始游戏
	CCMenuItemImage *GameStartMenu=CCMenuItemImage::create("startgame1.png","startgame2.png",this,menu_selector(StartGame::GameStart));
	GameStartMenu->setPosition(ccp(-100,-250));
 
	//游戏说明
	CCMenuItemImage *GameStateMenu=CCMenuItemImage::create("gamesay1.png","gamesay2.png",this,menu_selector(StartGame::GameHelp));
	GameStateMenu->setPosition(ccp(100,-250));

	//游戏退出
	CCMenuItemImage *GameExit=CCMenuItemImage::create("exit1.png","exit2.png",this,menu_selector(StartGame::GameExit));
	GameExit->setPosition((ccp(400,-280)));
	 
   
	CCMenu *pMenu=CCMenu::create(GameStartMenu,GameStateMenu,GameExit,NULL);
	this->addChild(pMenu,1);
	

	bRet=true;
	}while(0);
	return bRet;
}

void StartGame::GameStart(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=pick_pattern::create();
	float t=1.5f;
	rescene=CCTransitionProgressRadialCCW::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void StartGame::GameMode(CCObject *pSender)
{

}
void StartGame::GameHelp(CCObject *pSender)
{

}
void StartGame::GameMusic(CCObject *pSender)
{

}
void StartGame::GameExit(CCObject *pSender)
{
	CCDirector::sharedDirector()->end();
}