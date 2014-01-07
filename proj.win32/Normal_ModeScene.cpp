#include "Normal_ModeScene.h"
#include "cocos2d.h"
#include "StartGame.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
using namespace cocos2d;
Normal_ModeScene::Normal_ModeScene(void)
{
	_normal_modelayer=NULL;
}



Normal_ModeScene::~Normal_ModeScene(void)
{
}
bool Normal_ModeScene::init()
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


		/*
		CCLabelAtlas *scorecount=CCLabelAtlas::create("1222","ui/digit.png",20,25,'1');
		scorecount->setPosition(ccp(size.width/2,size.height-50));
		addChild(scorecount,5);
		*/
	

		/*
		//±³¾°
		CCSprite *sp_bg=CCSprite::create("pick1.png");
		sp_bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_bg);
		*/


		_normal_modelayer=Normal_ModeLayer::create();
		this->addChild(_normal_modelayer,1);
	 


		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(Normal_ModeScene::ReturnGame));
		gamereturnmenu->setPosition(ccp(450,-300));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);




		bRet=true;
	} while (0);
	return true;
}

void Normal_ModeScene::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *replacescene=pick_pattern::create();
	float t=1.5f;
	rescene=CCTransitionProgressHorizontal::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}