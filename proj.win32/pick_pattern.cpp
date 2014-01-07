#include "pick_pattern.h"
#include "cocos2d.h"
#include "StartGame.h"
#include "GameScene1.h"
#include "Normal_ModeScene.h"
#include "Mirror_ModeScene.h"
#include "Puzzle_ModeScene.h"
#include "Sliding_ModeScene.h"
#include "Clover_ModeScene.h"
#include "Anti_TraditionModeScene.h"


using namespace cocos2d;

pick_pattern::pick_pattern(void)
{
}


pick_pattern::~pick_pattern(void)
{
}
bool pick_pattern::init()
{
	bool bRet=false;
	do{
		CC_BREAK_IF(!CCScene::init());

	
		CCSize size=CCDirector::sharedDirector()->getWinSize();
		CCSprite *spbg=CCSprite::create("spbg.png");
		spbg->setPosition(ccp(size.width/2,size.height/2));
		addChild(spbg);

		CCMenuItemImage *normal_modeItem=CCMenuItemImage::create("menu/normal_mode1.png","menu/normal_mode2.png",this,menu_selector(pick_pattern::normal_mode));
		normal_modeItem->setPosition(ccp(-160,100));

		CCMenuItemImage *mirror_modeItem=CCMenuItemImage::create("menu/mirror_mode1.png","menu/mirror_mode2.png",this,menu_selector(pick_pattern::mirror_mode));
		mirror_modeItem->setPosition(ccp(-160,0));

		CCMenuItemImage *sliding_modeItem=CCMenuItemImage::create("menu/sliding_mode1.png","menu/sliding_mode2.png",this,menu_selector(pick_pattern::sliding_mode));
		sliding_modeItem->setPosition(ccp(160,100));

		CCMenuItemImage *clover_modeItem=CCMenuItemImage::create("menu/clover_mode1.png","menu/clover_mode2.png",this,menu_selector(pick_pattern::clover_mode));
		//clover_modeItem->setPosition(ccp(160,0));
		clover_modeItem->setPosition(ccp(12,-100));
			 

		CCMenuItemImage *anti_tradition_modeItem=CCMenuItemImage::create("menu/anti_tradition_mode1.png","menu/anti_tradition_mode2.png",this,menu_selector(pick_pattern::anti_tradition_mode));
		anti_tradition_modeItem->setPosition(ccp(12,-200));

		CCMenuItemImage *puzzle_modeItem=CCMenuItemImage::create("menu/puzzle_mode1.png","menu/puzzle_mode2.png",this,menu_selector(pick_pattern::puzzle_mode));
		puzzle_modeItem->setPosition(ccp(160,0));

		CCMenuItemImage *returnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(pick_pattern::ReturnGame));
		returnmenu->setPosition(ccp(390,-280));

		CCMenu *patternMenu=CCMenu::create(normal_modeItem,mirror_modeItem,sliding_modeItem,clover_modeItem,anti_tradition_modeItem,puzzle_modeItem,returnmenu,NULL);
		this->addChild(patternMenu);




		
		bRet=true;
	}while(0);
	return bRet;
}

void pick_pattern::normal_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Normal_ModeScene::create();
	float t=1.5f;
	rescene=CCTransitionProgressRadialCW::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::mirror_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Mirror_ModeScene::create();
	float t=1.5f;
	rescene=CCTransitionProgressRadialCCW::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::sliding_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Sliding_ModeScene::create();
	float t=1.5f;
	rescene=CCTransitionProgressInOut::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::clover_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Clover_ModeScene::create();
	float t=1.5f;
	rescene=CCTransitionPageTurn::create(t,replacescene,true);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::anti_tradition_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Anti_TraditionModeScene::create();
	float t=1.5f;
	rescene=CCTransitionProgressOutIn::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::puzzle_mode(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=Puzzle_ModeScene::create();
	float t=2.5f;
	rescene=CCTransitionRotoZoom::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void pick_pattern::ReturnGame(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=StartGame::create();
	float t=1.5f;
	rescene=CCTransitionFlipAngular::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}