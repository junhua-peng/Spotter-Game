#include "Normal_ModeLayer.h"
#include "cocos2d.h"
#include "Normal_ModeScene.h"
#include "StartGame.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
#include "GameScore.h"
#include "GameStore.h"
using namespace cocos2d;
Normal_ModeLayer::Normal_ModeLayer(void)
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


Normal_ModeLayer::~Normal_ModeLayer(void)
{

}
bool Normal_ModeLayer::init()
{
	bool bRet=false;
	do 
	{

		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.mp3");
	    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/wrong.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.ogg");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bad.mp3");
 
	   //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);
		
		CC_BREAK_IF(!CCLayer::init());

		setTouchEnabled(true);

		CCSize  size=CCDirector::sharedDirector()->getWinSize();

		  
		//倒计时
		this->schedule(schedule_selector(Normal_ModeLayer::second),1.0f);
		CCSprite *time=CCSprite::create("ui/times.png");
		time->setPosition(ccp(80,20));
		this->addChild(time);

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
		this->schedule(schedule_selector(Normal_ModeLayer::Timeout),120);

		/*
		//剩余时间
		CCSprite *time_remain=CCSprite::create("ui/time.png");
		time_remain->setPosition(ccp(150,20));
		addChild(time_remain,1,2);
		*/

		//放大按钮
		CCMenuItemImage *enlarge=CCMenuItemImage::create("ui/enlarge.png","ui/enlarge.png",this,menu_selector(Normal_ModeLayer::enlarge));
		enlarge->setPosition(ccp(250,-280));

		//商城
		CCMenuItemImage *store=CCMenuItemImage::create("ui/store.png","ui/store.png",this,menu_selector(Normal_ModeLayer::store));
		store->setPosition(ccp(300,-280));

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
		 


		//游戏暂停
		CCMenuItemImage *GamePause=CCMenuItemImage::create("ui/pause.png","ui/pause.png",this,menu_selector(Normal_ModeLayer::GamePause));
		//GamePause->setPosition((ccp(400,280)));

		CCMenu *pausemenu=CCMenu::create(GamePause,NULL);
		pausemenu->setPosition(ccp(size.width-30,size.height-30));
		addChild(pausemenu,4,10);





        CCSprite *sp_normal=CCSprite::create("pick_picture/normal1.png");
		sp_normal->setPosition(ccp(size.width/4,size.height/2));
		this->addChild(sp_normal);

       CCSprite *sp_normal2=CCSprite::create("pick_picture/normal2.png");
	   sp_normal2->setPosition(ccp(size.width*3/4,size.height/2));
	   this->addChild(sp_normal2);


	   CCSprite *pick11=CCSprite::create("number/d01.png");
	   pick11->setPosition(ccp(155,389));
	   pick11->setVisible(false);
	   this->addChild(pick11,1,11);
	   CCSprite *pick12=CCSprite::create("number/d01.png");
	   pick12->setPosition(ccp( 624,396));
	  pick12->setVisible(false);
	   this->addChild(pick12,1,12);


	   CCSprite *pick21=CCSprite::create("number/d02.png");
	   pick21->setPosition(ccp(231, 86));
	  pick21->setVisible(false);
	   this->addChild(pick21,1,21);
	   CCSprite *pick22=CCSprite::create("number/d02.png");
	   pick22->setVisible(false);
	   pick22->setPosition(ccp(690, 92));
	   this->addChild(pick22,1,22);

	   CCSprite *pick31=CCSprite::create("number/d03.png");
	   pick31->setPosition(ccp(298 ,571));
	   pick31->setVisible(false);
	   this->addChild(pick31,1,31);
	   CCSprite *pick32=CCSprite::create("number/d03.png");
	   pick32->setVisible(false);
	   pick32->setPosition(ccp(804,558));
	   this->addChild(pick32,1,32);
	  
	   CCSprite *pick41=CCSprite::create("number/d04.png");
	  pick41->setVisible(false);
	   pick41->setPosition(ccp(152,554));
	   this->addChild(pick41,1,41);
	   CCSprite *pick42=CCSprite::create("number/d04.png");
	   pick42->setVisible(false);
	   pick42->setPosition(ccp(629,557));
	   this->addChild(pick42,1,42);


	   /*
	   CCSprite *pick5=CCSprite::create("number/d05.png");
	   pick5->setPosition(ccp(500,500));
	   this->addChild(pick5,1,5);
	   */
	    

	   /*
		CCSprite *sp2=CCSprite::create("sp1.png");
		sp1->setPosition(ccp(300,300));
		this->addChild(sp2,2,2);

		CCSprite *sp3=CCSprite::create("sp2.png");
		sp3->setPosition(ccp(400,400));
		sp3->addChild(sp3,3,3);

		CCSprite *sp4=CCSprite::create("sp3.png");
		sp4->setPosition(ccp(500,450));
		sp4->addChild(sp4,3,4);
		*/

	bRet=true;
	} while (0);
	return true;
}
 
void Normal_ModeLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}

 
bool Normal_ModeLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
//void Normal_ModeLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
//void Normal_ModeLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	
	bool IsSelected=false;
	CCSize  size=CCDirector::sharedDirector()->getWinSize();
	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	 
	CCSprite *pick_sp11=(CCSprite*)this->getChildByTag(11);
	CCRect sprect11=pick_sp11->boundingBox();
	 
	if(sprect11.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected1)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		//flag_sp->setPosition(ccp(700,500));
		flag_sp->setPosition(ccp(155 ,389));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(624 ,396));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-260,size.height-20));
		this->addChild(star1,4);


		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
	   //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;
		m_selected1=true;
		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}

	CCSprite *pick_sp12=(CCSprite*)this->getChildByTag(12);
	CCRect sp_retct12=pick_sp12->boundingBox();
	if(sp_retct12.containsPoint(point))
	{
		IsSelected=true;
		if(!m_selected1)
		{
			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			//flag_sp->setPosition(ccp(700,500));
			flag_sp->setPosition(ccp(155 ,389));
			this->addChild(flag_sp,2);
 
		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(624 ,396));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-260,size.height-20));
		this->addChild(star1,4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		 //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;

		m_selected1=true;
		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	CCSprite *pick_sp21=(CCSprite*)this->getChildByTag(21);
	CCRect sp_retct21=pick_sp21->boundingBox();
	if(sp_retct21.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected2)
		{

			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(231,86));
			this->addChild(flag_sp,2);
 
			CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
			flag_sp2->setPosition(ccp( 690,92));
			this->addChild(flag_sp2,2);

			CCSprite *star1=CCSprite::create("ui/star1.png");
			star1->setPosition(ccp(size.width-230,size.height-20));
			this->addChild(star1,4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		 // CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;


		m_selected2=true;

		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	CCSprite *pick_sp22=(CCSprite*)this->getChildByTag(22);
	CCRect sp_rect22=pick_sp22->boundingBox();
	if(sp_rect22.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected2)
		{
 


			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(231,86));
			this->addChild(flag_sp,2);


		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp( 690,92));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-230,size.height-20));
		this->addChild(star1,4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		 //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;
		m_selected2=true;
		}

	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	CCSprite *pick_sp31=(CCSprite*)this->getChildByTag(31);
	CCRect sp_rect31=pick_sp31->boundingBox();
	if(sp_rect31.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected3)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp(298 ,571));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp( 804,558));
		this->addChild(flag_sp2,2);


		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-200,size.height-20));
		this->addChild(star1,4);

		 CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		 count++;
	
		
		m_selected3=true;
		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	
	CCSprite *pick_sp32=(CCSprite*)this->getChildByTag(32);
	CCRect sp_rect32=pick_sp32->boundingBox();
	if(sp_rect32.containsPoint(point))
	{
		IsSelected=true;


		if(!m_selected3)
		{

			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp(298 ,571));
			this->addChild(flag_sp,2);

 
		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp( 804,558));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-200,size.height-20));
		this->addChild(star1,4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		 //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;

		m_selected3=true;
		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	CCSprite *pick_sp41=(CCSprite*)this->getChildByTag(41);
	CCRect sp_rect41=pick_sp41->boundingBox();
	if(sp_rect41.containsPoint(point))
	{
		IsSelected=true;

		if(!m_selected4)
		{
 
		CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
		flag_sp->setPosition(ccp( 152 ,554));
		this->addChild(flag_sp,2);

		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(629, 557));
		this->addChild(flag_sp2,2);

		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star1,4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		// CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;

		m_selected4=true;
		}
	}
	CCSprite *pick_sp42=(CCSprite*)this->getChildByTag(42);
	CCRect sp_rect42=pick_sp42->boundingBox();
	if(sp_rect42.containsPoint(point))
	{
		IsSelected=true;


		if(!m_selected4)
		{
 


			CCSprite *flag_sp=CCSprite::create("flags/flag2.png");
			flag_sp->setPosition(ccp( 152 ,554));
			this->addChild(flag_sp,2);


		CCSprite *flag_sp2=CCSprite::create("flags/flag2.png");
		flag_sp2->setPosition(ccp(629, 557));
		this->addChild(flag_sp2,2);


		CCSprite *star1=CCSprite::create("ui/star1.png");
		star1->setPosition(ccp(size.width-170,size.height-20));
		this->addChild(star1,4);


		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.mp3");
		  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/right.ogg");
		count++;
		m_selected4=true;

		}
	}
	else
	{
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");

	//IsSelect=CCRect::CCRectContainsPoint(sp1->boundingBox,)

	
	if(IsSelected==false)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");
	}
	 
	if(m_selected1&&m_selected2&&m_selected3&&m_selected4)
	{

		if(!m_haswin)
		{
 
		CCSprite *success_sp=CCSprite::create("tongguan.png");
		success_sp->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(success_sp,2);
		CCActionInterval *pass_jump=CCJumpTo::create(3,CCPointMake(size.width/2,size.height/2),100,5);
		success_sp->runAction(pass_jump);
		m_haswin=true;

		this->schedule(schedule_selector(Normal_ModeLayer::display_score),4);
	 
		}

		/* 
		CCTransitionScene *rescene=NULL;
		CCScene  *replacescene=GameScore::create();
		float t=1.5f;
		rescene=CCTransitionProgressHorizontal::create(t,replacescene);
		CCDirector::sharedDirector()->replaceScene(rescene);
		 */
	}



//	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bad.mp3");

	/*
	CCSetIterator iter=pTouches->begin();
	for(;iter!=pTouches->end();iter++)
	{
		CCTouch *pTouch=(CCTouch*)(*iter);
		CCPoint location=pTouch->getLocation();
		if(pTouch->getID()==0){
			//CCSprite *sp1=(CCSprite*)this->getChildByTag(1);
			//sp1->setPosition(location);
			CCSprite *sp_flag=CCSprite::create("flags/flag2.png");
			sp_flag->setPosition(location);
			this->addChild(sp_flag,2);
		}
		if(pTouch->getID()==1)
		{
			//CCSprite *sp2=(CCSprite*)this->getChildByTag(2);
			//sp2->setPosition(location);
			CCSprite *sp_flag=CCSprite::create("flags/flag2.png");
			sp_flag->setPosition(location);
			this->addChild(sp_flag,2);
		}
	}
	*/

	 
 return true;
}
void Normal_ModeLayer::ccTouchesMoved(CCSet *pTouches,CCEvent *pEvent)
{
	/*
	CCSprite *sp2=CCSprite::create("flags/flag1.png");
	sp2->setPosition(ccp(400,400));
	this->addChild(sp2);
	*/
}
void Normal_ModeLayer::ccTouchesEnded(CCSet *pTouches,CCEvent *pEvent)
{
	/*
	CCSprite *sp3=CCSprite::create("flags/flag1.png");
	sp3->setPosition(ccp(300,300));
	this->addChild(sp3);
	*/
}

 
void Normal_ModeLayer::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}
void Normal_ModeLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}
 

void Normal_ModeLayer::Timeout(float dt)
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
void Normal_ModeLayer::GamePause(CCObject *pSender)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pausebg=CCSprite::create("pausebg.png");
	m_pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(m_pausebg,20,20);

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(false);
	//重新开始
	//	CCMenuItemFont *ResumeItem=CCMenuItemFont::create("resume",this,menu_selector(Anti_TraditionModeLayer::GameResume));
	CCMenuItemImage *resumeItem=CCMenuItemImage::create("ui/resume.png","ui/resume.png",this,menu_selector(Normal_ModeLayer::GameResume));

	CCMenu *ResumeMenu=CCMenu::create(resumeItem,NULL);
	ResumeMenu->setPosition(ccp(size.width/2,size.height/2));
	m_pausebg->addChild(ResumeMenu,1,11);

	//暂停游戏
	CCDirector::sharedDirector()->pause();

}
void Normal_ModeLayer::GameResume(CCObject *pSender)
{

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(true);
	//恢复游戏

	CCSprite *pausebg_sp=(CCSprite*)this->getChildByTag(20);
    this->removeChild(m_pausebg);
	CCDirector::sharedDirector()->resume();

}

void Normal_ModeLayer::enlarge(CCObject *pSender)
{

}
void Normal_ModeLayer::store(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameStore::create();
	float t=1.5f;
	rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}
void Normal_ModeLayer::display_score(float dt)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameScore::create();
	float t=1.5f;
	rescene=CCTransitionProgressHorizontal::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);

}


void Normal_ModeLayer::second(float dt)
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