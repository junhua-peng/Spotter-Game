#include "GameScore.h"
#include "cocos2d.h"
#include "pick_pattern.h"
using namespace cocos2d;

GameScore::GameScore(void)
{
}


GameScore::~GameScore(void)
{
}
bool GameScore::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		CCSize size=CCDirector::sharedDirector()->getWinSize();


		

		
		CCSprite *scorebg=CCSprite::create("scorebg.png");
		scorebg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(scorebg);



		CCSprite *score=CCSprite::create("ui/score.png");
		score->setPosition(ccp(size.width/2,size.height-100));
		this->addChild(score);

		//ตรทึ
		CCLabelAtlas* digitCount=CCLabelAtlas::create("888", "ui/digit.png", 18,30, '1');
		digitCount->setPosition(size.width/2,size.height-200);
		addChild(digitCount,5);

		CCSprite *rank=CCSprite::create("ui/rank.png");
		rank->setPosition(ccp(size.width/2,size.height-300));
		this->addChild(rank);
		//rank
		CCLabelAtlas* digitCount2=CCLabelAtlas::create("1", "ui/digit.png", 18,30, '1');
		digitCount2->setPosition(size.width/2,size.height-400);
		addChild(digitCount2,5);



		CCMenuItemImage *gamereturnmenu=CCMenuItemImage::create("return_bt1.png","return_bt2.png",this,menu_selector(GameScore::GameReturn));
		gamereturnmenu->setPosition(ccp(400,-280));
		CCMenu *pmenu=CCMenu::create(gamereturnmenu,NULL);
		this->addChild(pmenu);

		bRet=true;
	} while (0);

	return bRet;


}
void GameScore::GameReturn(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene *resplayscene=pick_pattern::create();
	float t=2.0f;
	rescene=CCTransitionProgressHorizontal::create(t,resplayscene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}