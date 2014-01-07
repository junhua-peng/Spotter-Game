#include "Clover_ModeScene.h"
#include "Clover_ModeLayer.h"
#include  "StartGame.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;
Clover_ModeScene::Clover_ModeScene(void)
{
	_clover_modelayer=NULL;
}


Clover_ModeScene::~Clover_ModeScene(void)
{
}
bool Clover_ModeScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());

		CCSize size=CCDirector::sharedDirector()->getWinSize();

		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/bg_music.mp3",true);



		//±³¾°
		CCSprite *sp_bg=CCSprite::create("pick1.png");
		sp_bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_bg);
		_clover_modelayer=Clover_ModeLayer::create();
		this->addChild(_clover_modelayer,1);




		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Clover_ModeScene::ReturnGame));
		gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);


		bRet=true;
	} while (0);
	return true;
}
void Clover_ModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *replacescene=pick_pattern::create();
	float t=2.0f;
    rescene=CCTransitionMoveInL::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}