#include "GameScene1.h"
#include "cocos2d.h"
#include "StartGame.h"

using namespace cocos2d;


GameScene1::GameScene1(void)
{
	_gameLayer=NULL;
}


GameScene1::~GameScene1(void)
{
}
bool GameScene1::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());

		CCSize size=CCDirector::sharedDirector()->getWinSize();
		//±³¾°
		CCSprite *sp_bg=CCSprite::create("pick1.png");
		sp_bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_bg);
		_gameLayer=GameLayer1::create();
		this->addChild(_gameLayer,1);

	


		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(GameScene1::GameReturn));
		gamereturnmenu->setPosition(ccp(350,-270));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);


		bRet=true;
	} while (0);
	return true;
}

void GameScene1::GameReturn(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=StartGame::create();
	float t=1.5f;
    rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);


}