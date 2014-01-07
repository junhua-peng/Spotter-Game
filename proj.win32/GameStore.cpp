#include "GameStore.h"
#include "cocos2d.h"
#include "pick_pattern.h"
using namespace  cocos2d;

GameStore::GameStore(void)
{
}


GameStore::~GameStore(void)
{
}
bool GameStore::init()
{
  bool bRet=false;
  do 
  {
	  CC_BREAK_IF(!CCScene::init());

	  CCSize size=CCDirector::sharedDirector()->getWinSize();

	  CCSprite *storebg=CCSprite::create("storebg.png");
	  storebg->setPosition(ccp(size.width/2,size.height/2));
	  this->addChild(storebg);


	  CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(GameStore::GameReturn));
	  gamereturnmenu->setPosition(ccp(400,-280));
	  CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
	  this->addChild(pmenu,2);

	   bRet=true;
  } while (0);
 
  return bRet;


}

void GameStore::GameReturn(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *resplayscene=pick_pattern::create();
	float t=2.0f;
	rescene=CCTransitionProgressHorizontal::create(t,resplayscene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}