#include "Anti_TraditionModeLayer.h"
#include "cocos2d.h"
#include "Anti_TraditionModeScene.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
#include "GameStore.h"
#include  "GameScore.h"
using namespace cocos2d;

Anti_TraditionModeLayer::Anti_TraditionModeLayer(void)
{
	count=0;
	m_timeleave=0;
	m_score=0;
	m_maxscore=0;
	m_rank=0;
    m_find1=false;
    m_find2=false;
	m_find3=false;
	m_find4=false;
	m_find5=false;
    m_selected1=false;
	m_selected2=false;
	m_selected3=false;
	m_selected4=false;
	m_selected5=false;
	m_selected6=false;
	m_selected7=false;
	m_selected8=false;
	m_selected9=false;
	m_timeleave=120;
}


Anti_TraditionModeLayer::~Anti_TraditionModeLayer(void)
{
}
bool Anti_TraditionModeLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());


		CCSize size=CCDirector::sharedDirector()->getWinSize();
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bg_music.mp3",true);


		/*
		//倒计时
		CCProgressTimer *countdown=CCProgressTimer::create(CCSprite::create("banner.png"));
		countdown->setPosition(ccp(size.width/2,550));
		countdown->setType(kCCProgressTimerTypeBar);
		countdown->setPercentage(100);
	//	countdown->setMidpoint(ccp(0,1));
	//	countdown->setBarChangeRate(ccp(0,1));
	    this->addChild(countdown,10);
	    CCProgressTo *to=CCProgressTo::create(120,100);
		countdown->runAction(CCRepeatForever::create(to));
		//this->addChild(countdown,3);
		*/



		/*

		//计分排名
       CCLabelAtlas* digitCount=CCLabelAtlas::create("123456789:", "ui/digit.png", 20,30, '1');
	   digitCount->setPosition(100,size.height-150);
	   addChild(digitCount,5);
	   */
	   //启动倒计时定时器

		//倒计时
		this->schedule(schedule_selector(Anti_TraditionModeLayer::second),1.0f);
		CCSprite *time=CCSprite::create("ui/times.png");
		time->setPosition(ccp(80,20));
		this->addChild(time);


	   //启动计分定时器
	//  this->schedule(schedule_selector(Anti_TraditionModeLayer::GameScore),1.0f);


		//进度条
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
		this->schedule(schedule_selector(Anti_TraditionModeLayer::Timeout),120);
		
		//剩余时间
		/*
		CCSprite *time_remain=CCSprite::create("ui/time.png");
		time_remain->setPosition(ccp(150,20));
		addChild(time_remain,1,2);
		*/
		
		//放大按钮
		CCMenuItemImage *enlarge=CCMenuItemImage::create("ui/enlarge.png","ui/enlarge.png",this,menu_selector(Anti_TraditionModeLayer::enlarge));
		enlarge->setPosition(ccp(250,-280));

		//商城
		CCMenuItemImage *store=CCMenuItemImage::create("ui/store.png","ui/store.png",this,menu_selector(Anti_TraditionModeLayer::store));
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
		CCMenuItemImage *GamePause=CCMenuItemImage::create("ui/pause.png","ui/pause.png",this,menu_selector(Anti_TraditionModeLayer::GamePause));
		//GamePause->setPosition((ccp(400,280)));

		CCMenu *pausemenu=CCMenu::create(GamePause,NULL);
		pausemenu->setPosition(ccp(size.width-30,size.height-30));
		addChild(pausemenu,4,10);




		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/wrong.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.ogg");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bad.mp3");



		//相应触摸事件
		setTouchEnabled(true);

	 
		CCSprite  *sp_mirror=CCSprite::create("pick_picture/anti_tradition_pic2.png");
		sp_mirror->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_mirror,2);

		CCSprite *pick11=CCSprite::create("number/d01.png");
		pick11->setPosition(ccp(96,462 ));
		pick11->setVisible(false);
		this->addChild(pick11,1,11);
		CCSprite *pick12=CCSprite::create("number/d01.png");
		pick12->setPosition(ccp(552,464));
		pick12->setVisible(false);
		this->addChild(pick12,1,12);


		CCSprite *pick21=CCSprite::create("number/d02.png");
		pick21->setPosition(ccp(224,472));
		pick21->setVisible(false);
		this->addChild(pick21,1,21);
		CCSprite *pick22=CCSprite::create("number/d02.png");
		pick22->setPosition(ccp(679,465));
		pick22->setVisible(false);
		this->addChild(pick22,1,22);


		CCSprite *pick31=CCSprite::create("number/d03.png");
		pick31->setPosition(ccp(358,463));
		pick31->setVisible(false);
		this->addChild(pick31,1,31);
		CCSprite *pick32=CCSprite::create("number/d03.png");
		pick32->setPosition(ccp(821,465));
		pick32->setVisible(false);
		this->addChild(pick32,1,32);

		CCSprite *pick41=CCSprite::create("number/d04.png");
		pick41->setPosition(ccp(359,332));
		pick41->setVisible(false);
		this->addChild(pick41,1,41);
		CCSprite *pick42=CCSprite::create("number/d04.png");
		pick42->setPosition(ccp(816,338));
		pick42->setVisible(false);
		this->addChild(pick42,1,42);

		CCSprite *pick51=CCSprite::create("number/d05.png");
		pick51->setPosition(ccp(99,206));
		pick51->setVisible(false);
		this->addChild(pick51,1,51);
		CCSprite *pick52=CCSprite::create("number/d05.png");
		pick52->setPosition(ccp(549,204));
		pick52->setVisible(false);
		this->addChild(pick52,1,52);

		CCSprite *pick61=CCSprite::create("number/d06.png");
		pick61->setPosition(ccp(234,208 ));
		pick61->setVisible(false);
		this->addChild(pick61,1,61);
		CCSprite *pick62=CCSprite::create("number/d06.png");
		pick62->setPosition(ccp(687,200));
		pick62->setVisible(false);
		this->addChild(pick62,1,62);

		CCSprite *pick71=CCSprite::create("number/d07.png");
		pick71->setPosition(ccp(232,95));
		pick71->setVisible(false);
		this->addChild(pick71,1,71);
		CCSprite *pick72=CCSprite::create("number/d07.png");
		pick72->setPosition(ccp( 678,101));
		pick72->setVisible(false);
		this->addChild(pick72,1,72);

		CCSprite *pick81=CCSprite::create("number/d08.png");
		pick81->setPosition(ccp(351,93  ));
		pick81->setVisible(false);
		this->addChild(pick81,1,81);
		CCSprite *pick82=CCSprite::create("number/d08.png");
		pick82->setPosition(ccp(812,88));
		pick82->setVisible(false);
		this->addChild(pick82,1,82);





		 
		bRet=true;
	} while (0);
	return true;
}

void Anti_TraditionModeLayer::registerwithTouchDispather()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);

}
 
bool Anti_TraditionModeLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	bool IsSelected=false;
	
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	CCSprite *pick_sp11=(CCSprite*)this->getChildByTag(11);
	CCRect   rect_sp11=pick_sp11->boundingBox();
	if(rect_sp11.containsPoint(point))
	{

		IsSelected=true;
		m_find1=true;
	   if(!m_selected1)
	   {
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(96,462));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(552,464));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");

        count++;
	   m_selected1=true;
	   }
	}

	CCSprite *pick_sp12=(CCSprite*)this->getChildByTag(12);
	CCRect rect_sp12=pick_sp12->boundingBox();
	if(rect_sp12.containsPoint(point))
	{
		IsSelected=true;
		m_find1=true;
		if(!m_selected1)
		{
	     CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
	    flag_sp->setPosition(ccp(96,462));
	    this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(552,464));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		count++;
		m_selected1=true;
		}
	}


	CCSprite *pick_sp21=(CCSprite*)this->getChildByTag(21);
	CCRect rect_sp21=pick_sp21->boundingBox();
	if(rect_sp21.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected2)
		{

 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(224,472));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(679,465));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		count++;
		m_selected2=true;
		}
	}
	CCSprite *pick_sp22=(CCSprite*)this->getChildByTag(22);
	CCRect rect_sp22=pick_sp22->boundingBox();
	if(rect_sp22.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected2)
		{

		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(224,472));
		this->addChild(flag_sp,2);
	 
		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(679,465));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		count++;
		m_selected2=true;
		}
	}

	CCSprite *pick_sp31=(CCSprite*)this->getChildByTag(31);
	CCRect rect_sp31=pick_sp31->boundingBox();
	if(rect_sp31.containsPoint(point))
	{
		IsSelected=true;
	    if(!m_selected3)
		{
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(358,463));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(821,465));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
        count++;
		m_selected3=true;
	 
		}
	}
	CCSprite *pick_sp32=(CCSprite*)this->getChildByTag(32);
	CCRect rect_sp32=pick_sp32->boundingBox();
	if(rect_sp32.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected3)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(358,463));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(821,465));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected3=true;
		}

	}

	CCSprite *pick_sp41=(CCSprite*)this->getChildByTag(41);
	CCRect rect_sp41=pick_sp41->boundingBox();
	if(rect_sp41.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected4)
		{
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(359,332));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(816,338));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected4=true;
		}
	}
	CCSprite *pick_sp42=(CCSprite*)this->getChildByTag(42);
	CCRect rect_sp42=pick_sp42->boundingBox();
	if(rect_sp42.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected4)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(359,332));
		this->addChild(flag_sp,2);


		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(816,338));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected4=true;
		}
	}

	CCSprite *pick_sp51=(CCSprite*)this->getChildByTag(51);
	CCRect rect_sp51=pick_sp51->boundingBox();
	if(rect_sp51.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected5)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(99,206));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(549,204));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected5=true;
		}
	}
	CCSprite *pick_sp52=(CCSprite*)this->getChildByTag(52);
	CCRect rect_sp52=pick_sp52->boundingBox();
	if(rect_sp52.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected5)
		{
			
			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(99,206));
			this->addChild(flag_sp,2);
		
			CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		   flag_sp2->setPosition(ccp(549,204));
		   this->addChild(flag_sp2,2);
		   CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	      count++;
	    m_selected5=true;
		}
	}


	CCSprite *pick_sp61=(CCSprite*)this->getChildByTag(61);
	CCRect rect_sp61=pick_sp61->boundingBox();
	if(rect_sp61.containsPoint(point))
	{

		IsSelected=true;


		if(!m_selected6)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(234,208));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(687,200));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	   count++;
	   m_selected6=true;
		}
	}

	CCSprite *pick_sp62=(CCSprite*)this->getChildByTag(62);
	CCRect rect_sp62=pick_sp62->boundingBox();
	if(rect_sp62.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected6)
		{
 

			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(234,208));
			this->addChild(flag_sp,2);

			CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
			flag_sp2->setPosition(ccp(687,200));
			this->addChild(flag_sp2,2);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
			count++;
	     m_selected6=true;
		}

	}

	CCSprite *pick_sp71=(CCSprite*)this->getChildByTag(71);
	CCRect rect_sp71=pick_sp71->boundingBox();
	if(rect_sp71.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected7)
		{

	 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(232,95));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(678,101));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected7=true;
		}

	}
	CCSprite *pick_sp72=(CCSprite*)this->getChildByTag(72);
	CCRect rect_sp72=pick_sp72->boundingBox();
	if(rect_sp72.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected7)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(232,95));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(678,101));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		count++;
		m_selected7=true;
		}
	}
	CCSprite *pick_sp81=(CCSprite*)this->getChildByTag(81);
	CCRect rect_sp81=pick_sp81->boundingBox();
	if(rect_sp81.containsPoint(point))
	{
		IsSelected=true;

	   if(!m_selected8)
	   {
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(351,93));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp( 812,88));
		this->addChild(flag_sp2,2);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		m_selected8=true;
	   }
	}
	CCSprite *pick_sp82=(CCSprite*)this->getChildByTag(82);
	CCRect rect_sp82=pick_sp82->boundingBox();
	if(rect_sp82.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected8)
		{
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp( 812,88));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(351,93));
		this->addChild(flag_sp2,2);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	    count++;
		m_selected8=true;
		}
	}

	if(IsSelected==false)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");

	}

	if(count==16)
	{
		CCSprite *success_sp=CCSprite::create("tongguan.png");
		success_sp->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(success_sp,2);
		CCActionInterval *pass_jump=CCJumpTo::create(3,CCPointMake(size.width/2,size.height/2),100,5);
		success_sp->runAction(pass_jump);
	}
	return true;
}
void Anti_TraditionModeLayer::ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent)
{

}
void Anti_TraditionModeLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{


}
void Anti_TraditionModeLayer::onEnter()
{

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}
void Anti_TraditionModeLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();


}
void Anti_TraditionModeLayer::Update(float dt)
{

}
void Anti_TraditionModeLayer::Timeout(float dt)
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

void Anti_TraditionModeLayer::enlarge(CCObject *pSender)
{

}
void Anti_TraditionModeLayer::store(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameStore::create();
	float t=1.5f;
	rescene=CCTransitionPageTurn::create(t,replacescene,true);
	CCDirector::sharedDirector()->replaceScene(rescene);
}

void Anti_TraditionModeLayer::GamePause(CCObject *pSender)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pausebg=CCSprite::create("pausebg.png");
	m_pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(m_pausebg,20,20);

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(false);
	//重新开始
//	CCMenuItemFont *ResumeItem=CCMenuItemFont::create("resume",this,menu_selector(Anti_TraditionModeLayer::GameResume));
    CCMenuItemImage *resumeItem=CCMenuItemImage::create("ui/resume.png","ui/resume.png",this,menu_selector(Anti_TraditionModeLayer::GameResume));

	CCMenu *ResumeMenu=CCMenu::create(resumeItem,NULL);
	ResumeMenu->setPosition(ccp(size.width/2,size.height/2));
	m_pausebg->addChild(ResumeMenu,1,11);

	//暂停游戏
	CCDirector::sharedDirector()->pause();

}
void Anti_TraditionModeLayer::GameResume(CCObject *pSender)
{

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(true);
	//恢复游戏

	CCSprite *pausebg_sp=(CCSprite*)this->getChildByTag(20);
	this->removeChild(m_pausebg);
	CCDirector::sharedDirector()->resume();

}

void Anti_TraditionModeLayer::second(float dt)
{
	 
	char var[256];
	CCSize size=CCDirector::sharedDirector()->getWinSize();
    /*
	CCSprite *timeleava=CCSprite::create("ui/timeleave.png");
	timeleava->setPosition(ccp(100,30));
	//this->addChild(timeleava,2);
	*/


	m_timeleave--;
	 
	sprintf(var,"%d:",m_timeleave);

	CCLabelAtlas* digitCount=CCLabelAtlas::create(var, "ui/digit3.png",14,21, '0');
	digitCount->setPosition(120,10);
	//digitCount->setScale()
	addChild(digitCount,5);
}

//计分统计
void Anti_TraditionModeLayer::GameScore(CCObject *pSender)
{
	char str_score[256];
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_score++;
	sprintf(str_score,"%d:",m_score);

	CCLabelAtlas *scorecount=CCLabelAtlas::create(str_score,"ui/digit.png",20,25,'1');
	scorecount->setPosition(ccp(size.width/2,size.height-50));
	addChild(scorecount,5);


	
}