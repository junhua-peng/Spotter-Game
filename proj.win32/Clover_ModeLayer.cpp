#include "Clover_ModeLayer.h"
#include "cocos2d.h"
#include "Clover_ModeScene.h"
#include "pick_pattern.h"
using namespace cocos2d;
Clover_ModeLayer::Clover_ModeLayer(void)
{
}


Clover_ModeLayer::~Clover_ModeLayer(void)
{
}

bool Clover_ModeLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize  size=CCDirector::sharedDirector()->getWinSize();

		
		//从左到右
		CCSprite *banner=CCSprite::create("ui/progress_bg.png");
		banner->setPosition(ccp(size.width/2,20));
		this->addChild(banner,6);
		CCProgressTo *toHorizontalBar1 = CCProgressTo::create(120, 100);
		CCProgressTimer *leftHorizontalBar = CCProgressTimer::create(CCSprite::create("ui/progress.png"));
		leftHorizontalBar->setType( kCCProgressTimerTypeBar );
		leftHorizontalBar->setBarChangeRate(ccp(1,0));
		leftHorizontalBar->setMidpoint(ccp(0,0));
		addChild(leftHorizontalBar,6);
		leftHorizontalBar->setPosition(CCPointMake(size.width/2+18, 20));
		leftHorizontalBar->runAction( CCRepeatForever::create(toHorizontalBar1));
		this->schedule(schedule_selector(Clover_ModeLayer::Timeout),120);

		//剩余时间
		CCSprite *time_remain=CCSprite::create("ui/time.png");
		time_remain->setPosition(ccp(150,20));
		addChild(time_remain,1,2);


		//放大按钮
		CCMenuItemImage *enlarge=CCMenuItemImage::create("ui/enlarge.png","ui/enlarge.png",this,menu_selector(Clover_ModeLayer::enlarge));
		enlarge->setPosition(ccp(250,-280));

		//商城
		CCMenuItemImage *store=CCMenuItemImage::create("ui/store.png","ui/store.png",this,menu_selector(Clover_ModeLayer::store));
		store->setPosition(ccp(300,-280));

		CCMenu *pmenu=CCMenu::create(enlarge,store,NULL);
		this->addChild(pmenu,2);


		//标题
		CCSprite *title1=CCSprite::create("ui/title.png");
		title1->setPosition(ccp(150,size.height-20));
		this->addChild(title1);
		//张数
		CCSprite *number=CCSprite::create("ui/number.png");
		number->setPosition(ccp(320,size.height-20));
		this->addChild(number);


		//分数

		CCSprite *star=CCSprite::create("ui/star1.png");
		star->setPosition(ccp(size.width-200,size.height-20));
		this->addChild(star);
		CCSprite *star2=CCSprite::create("ui/star1.png");
		star2->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star2);

		CCSprite *star3=CCSprite::create("ui/star2.png");
		star3->setPosition(ccp(size.width-140,size.height-20));
		this->addChild(star3);


		//游戏暂停
		CCMenuItemImage *GamePause=CCMenuItemImage::create("ui/pause.png","ui/pause.png",this,menu_selector(Clover_ModeLayer::GamePause));
		//GamePause->setPosition((ccp(400,280)));

		CCMenu *pausemenu=CCMenu::create(GamePause,NULL);
		pausemenu->setPosition(ccp(size.width-30,size.height-30));
		addChild(pausemenu,4,10);










		CCSprite *sp1=CCSprite::create("bgimage/logo1.png");
		sp1->setPosition(ccp(size.width/2,size.height/2));
		sp1->setVisible(false);
		this->addChild(sp1,1,1);

		CCSprite *sp2=CCSprite::create("sp1.png");
		sp1->setPosition(ccp(300,300));
		this->addChild(sp2,2,2);

		CCSprite *sp3=CCSprite::create("sp2.png");
		sp3->setPosition(ccp(400,400));
		this->addChild(sp3,3,3);

		CCSprite *sp4=CCSprite::create("sp3.png");
		sp4->setPosition(ccp(500,450));
		this->addChild(sp4,3,4);

	 

		bool bRet=true;
	} while (0);
	return true;
}

void Clover_ModeLayer::Timeout(float dt)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite *success_sp=CCSprite::create("lose.png");
	success_sp->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(success_sp,2);
	CCActionInterval *pass_jump=CCJumpTo::create(3,CCPointMake(size.width/2,size.height/2),100,5);
	CCActionInterval *fail=CCBlink::create(3,5);
	success_sp->runAction(fail);

	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=pick_pattern::create();
	float t=1.5f;
	rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}


void Clover_ModeLayer::GamePause(CCObject *pSender)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pausebg=CCSprite::create("pausebg.png");
	m_pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(m_pausebg,20,20);

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(false);
	//重新开始
	//	CCMenuItemFont *ResumeItem=CCMenuItemFont::create("resume",this,menu_selector(Anti_TraditionModeLayer::GameResume));
	CCMenuItemImage *resumeItem=CCMenuItemImage::create("ui/resume.png","ui/resume.png",this,menu_selector(Clover_ModeLayer::GameResume));

	CCMenu *ResumeMenu=CCMenu::create(resumeItem,NULL);
	ResumeMenu->setPosition(ccp(size.width/2,size.height/2));
	m_pausebg->addChild(ResumeMenu,1,11);

	//暂停游戏
	CCDirector::sharedDirector()->pause();

}
void Clover_ModeLayer::GameResume(CCObject *pSender)
{

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(true);
	//恢复游戏

	CCSprite *pausebg_sp=(CCSprite*)this->getChildByTag(20);
	this->removeChild(m_pausebg);
	CCDirector::sharedDirector()->resume();

}

void Clover_ModeLayer::enlarge(CCObject *pSender)
{

}
void Clover_ModeLayer::store(CCObject *pSender)
{


}