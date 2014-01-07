#include "Mirror_ModeLayer.h"
#include "cocos2d.h"
#include  "Mirror_ModeScene.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
#include "GameScore.h"
#include "GameStore.h"
using namespace cocos2d;
Mirror_ModeLayer::Mirror_ModeLayer(void)
{
	count=0;
	m_selected1=false;
	m_selected2=false;
	m_selected3=false;
	m_selected4=false;
	m_selected5=false;
	m_selected6=false;
	m_selected7=false;
	m_selected8=false;
	m_selected9=false;
	m_haswin=false;
	m_timeleave=120;
}


Mirror_ModeLayer::~Mirror_ModeLayer(void)
{
	 
}
bool Mirror_ModeLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

	 



		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("bg_music.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("bg_music.mp3",true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bg_music.mp3",true);
		 
 
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/wrong.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.ogg");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bad.mp3");
	


		//相应触摸事件
		setTouchEnabled(true);
	    
		CCSize size=CCDirector::sharedDirector()->getWinSize();


		//倒计时
		this->schedule(schedule_selector(Mirror_ModeLayer::second),1.0f);
		CCSprite *time=CCSprite::create("ui/times.png");
		time->setPosition(ccp(80,20));
		this->addChild(time,4);

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
		this->schedule(schedule_selector(Mirror_ModeLayer::Timeout),120);

		/*
		//剩余时间
		CCSprite *time_remain=CCSprite::create("ui/time.png");
		time_remain->setPosition(ccp(150,20));
		addChild(time_remain,1,2);
*/

		//放大按钮
		CCMenuItemImage *enlarge=CCMenuItemImage::create("ui/enlarge.png","ui/enlarge.png",this,menu_selector(Mirror_ModeLayer::enlarge));
		enlarge->setPosition(ccp(250,-290));

		//商城
		CCMenuItemImage *store=CCMenuItemImage::create("ui/store.png","ui/store.png",this,menu_selector(Mirror_ModeLayer::store));
		store->setPosition(ccp(300,-290));

		CCMenu *pmenu=CCMenu::create(enlarge,store,NULL);
		this->addChild(pmenu,2);


		//标题
		CCSprite *title1=CCSprite::create("ui/title.png");
		title1->setPosition(ccp(150,size.height-20));
		this->addChild(title1,3);
		
		//张数
		CCSprite *number=CCSprite::create("ui/number.png");
		number->setPosition(ccp(size.width-330,size.height-20));
		this->addChild(number,3);



		//分数

		CCSprite *star1=CCSprite::create("ui/star2.png");
		star1->setPosition(ccp(size.width-260,size.height-20));
		this->addChild(star1,3);

		CCSprite *star2=CCSprite::create("ui/star2.png");
		star2->setPosition(ccp(size.width-230,size.height-20));
		this->addChild(star2,3);

		CCSprite *star3=CCSprite::create("ui/star2.png");
		star3->setPosition(ccp(size.width-200,size.height-20));
		this->addChild(star3,3);

		CCSprite *star4=CCSprite::create("ui/star2.png");
		star4->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star4,3);
		CCSprite *star5=CCSprite::create("ui/star2.png");
		star5->setPosition(ccp(size.width-140,size.height-20));
		this->addChild(star5,3);



		//游戏暂停
		CCMenuItemImage *GamePause=CCMenuItemImage::create("ui/pause.png","ui/pause.png",this,menu_selector(Mirror_ModeLayer::GamePause));
		//GamePause->setPosition((ccp(400,280)));

		CCMenu *pausemenu=CCMenu::create(GamePause,NULL);
		pausemenu->setPosition(ccp(size.width-30,size.height-30));
		addChild(pausemenu,4,10);






		CCSprite  *sp_mirror=CCSprite::create("pick_picture/mirror_pic2.png");
		sp_mirror->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp_mirror);

		CCSprite *pick11=CCSprite::create("number/d01.png");
		pick11->setPosition(ccp(610,234));
		pick11->setVisible(false);
	    this->addChild(pick11,1,11);
		CCSprite *pick12=CCSprite::create("number/d01.png");
		pick12->setPosition(ccp(347,412));
		pick12->setVisible(false);
		this->addChild(pick12,1,12);


		CCSprite *pick21=CCSprite::create("number/d02.png");
		pick21->setPosition(ccp( 714,265));
		pick21->setVisible(false);
		this->addChild(pick21,1,21);
		CCSprite *pick22=CCSprite::create("number/d02.png");
		pick22->setPosition(ccp(243,370));
	    pick22->setVisible(false);
		this->addChild(pick22,1,22);

		
		CCSprite *pick31=CCSprite::create("number/d03.png");
		pick31->setPosition(ccp(660,394));
	    pick31->setVisible(false);
		this->addChild(pick31,1,31);
		CCSprite *pick32=CCSprite::create("number/d03.png");
		pick32->setPosition(ccp(275,256));
	 	pick32->setVisible(false);
		this->addChild(pick32,1,32);

		CCSprite *pick41=CCSprite::create("number/d04.png");
		pick41->setPosition(ccp(523,541));
	 	pick41->setVisible(false);
		this->addChild(pick41,1,41);
		CCSprite *pick42=CCSprite::create("number/d04.png");
		pick42->setPosition(ccp(422,108));
	 	pick42->setVisible(false);
		this->addChild(pick42,1,42);

		CCSprite *pick51=CCSprite::create("number/d05.png");
		pick51->setPosition(ccp(679,98));
		pick51->setVisible(false);
		this->addChild(pick51,1,51);
		CCSprite *pick52=CCSprite::create("number/d05.png");
		pick52->setPosition(ccp(267,550));
		pick52->setVisible(false);
		this->addChild(pick52,1,52);










		
	   bRet=true;

	} while (0);
	return true;
}

void Mirror_ModeLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);


}
 
bool Mirror_ModeLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	bool IsSelected=false;
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	CCSprite *pick_sp11=(CCSprite*)this->getChildByTag(11);
	CCRect   rect_sp11=pick_sp11->boundingBox();
	if(rect_sp11.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected1)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(610,234));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(347,412));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-260,size.height-20));
		this->addChild(star1,3);

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

		if(!m_selected1)
		{

 
			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(610,234));
			this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(347,412));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-260,size.height-20));
		this->addChild(star1,3);

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
		flag_sp->setPosition(ccp(714,265));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(243,370));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-230,size.height-20));
		this->addChild(star1,3);

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

	 

			if(!m_selected3)
			{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(714,265));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(243,370));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-200,size.height-20));
		this->addChild(star1,3);

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
		flag_sp->setPosition(ccp(660,394));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(275,256));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star1,3);

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
			flag_sp->setPosition(ccp(660,394));
			this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(275,256));
		this->addChild(flag_sp2,2);
		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star1,3);


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
		flag_sp->setPosition(ccp(523,541));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(422,108));
		this->addChild(flag_sp2,2);
		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-140,size.height-20));
		this->addChild(star1,3);

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

		if(m_selected4)
		{
			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(523,541));
			this->addChild(flag_sp,2);

	 
		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(422,108));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-140,size.height-20));
		this->addChild(star1,3);


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
		flag_sp->setPosition(ccp(679,98));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(267,550));
		this->addChild(flag_sp2,2);
		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-110,size.height-20));
		this->addChild(star1,3);


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
			flag_sp->setPosition(ccp(679,98));
			this->addChild(flag_sp,2);


		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(267,550));
		this->addChild(flag_sp2,2);
		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-110,size.height-20));
		this->addChild(star1,3);


		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		  count++;
		  m_selected5=true;
		}
	}



	if(IsSelected==false)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");

	}


	if(m_selected1&&m_selected2&&m_selected3&&m_selected4&&m_selected5)
	{
		if(m_haswin)
		{
		CCSprite *success_sp=CCSprite::create("tongguan.png");
		success_sp->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(success_sp,2);
		CCActionInterval *pass_jump=CCJumpTo::create(3,CCPointMake(size.width/2,size.height/2),100,5);
		success_sp->runAction(pass_jump);

		m_haswin=true;
		this->schedule(schedule_selector(Mirror_ModeLayer::display_score),4);

		}
		}



	

	return true;
}
void Mirror_ModeLayer::ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent)
{

}
void Mirror_ModeLayer::ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent)
{

}
void Mirror_ModeLayer::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}
void Mirror_ModeLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();

}
void Mirror_ModeLayer::Timeout(float dt)
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


void Mirror_ModeLayer::GamePause(CCObject *pSender)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pausebg=CCSprite::create("pausebg.png");
	m_pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(m_pausebg,20,20);

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(false);
	//重新开始
	//	CCMenuItemFont *ResumeItem=CCMenuItemFont::create("resume",this,menu_selector(Anti_TraditionModeLayer::GameResume));
	CCMenuItemImage *resumeItem=CCMenuItemImage::create("ui/resume.png","ui/resume.png",this,menu_selector(Mirror_ModeLayer::GameResume));

	CCMenu *ResumeMenu=CCMenu::create(resumeItem,NULL);
	ResumeMenu->setPosition(ccp(size.width/2,size.height/2));
	m_pausebg->addChild(ResumeMenu,1,11);

	//暂停游戏
	CCDirector::sharedDirector()->pause();

}
void Mirror_ModeLayer::GameResume(CCObject *pSender)
{

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(true);
	//恢复游戏

	CCSprite *pausebg_sp=(CCSprite*)this->getChildByTag(20);
	this->removeChild(m_pausebg);
	CCDirector::sharedDirector()->resume();

}
void Mirror_ModeLayer::enlarge(CCObject *pSender)
{

}
void Mirror_ModeLayer::store(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameStore::create();
	float t=1.5f;
	rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}
void Mirror_ModeLayer::display_score(float dt)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameScore::create();
	float t=1.5f;
	rescene=CCTransitionProgressHorizontal::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}
void Mirror_ModeLayer::second(float dt)
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