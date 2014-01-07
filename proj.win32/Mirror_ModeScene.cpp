#include "Mirror_ModeScene.h"
#include "Mirror_ModeLayer.h"
#include "cocos2d.h"
#include "StartGame.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;

Mirror_ModeScene::Mirror_ModeScene(void)
{
	_mirror_modelayer=NULL;
	
}


Mirror_ModeScene::~Mirror_ModeScene(void)
{
}
bool Mirror_ModeScene::init()
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
		//±³¾°
		CCSprite *sp_bg=CCSprite::create("pick1.png");
		sp_bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_bg);
		*/

		_mirror_modelayer=Mirror_ModeLayer::create();
		this->addChild(_mirror_modelayer,1);




		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Mirror_ModeScene::ReturnGame));
		gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);




	bRet=true;
	} while (0);
	return true;
}

void Mirror_ModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *replacescene=pick_pattern::create();
	float t=2.0;
	rescene=CCTransitionFlipX::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}