#include "Puzzle_ModeLayer.h"
#include "cocos2d.h"
#include "Puzzle_ModeLayer.h"
#include "SimpleAudioEngine.h"
#include "pick_pattern.h"
#include "GameStore.h"
#include "GameScore.h"
#include "cocos-ext.h"

#pragma comment(lib, "libextensions.lib")  
USING_NS_CC_EXT;
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocos2d::extension;
Puzzle_ModeLayer::Puzzle_ModeLayer(void)
{

	count=0;
	m_bMoveLayer=false;
	m_timeleave=120;
}


Puzzle_ModeLayer::~Puzzle_ModeLayer(void)
{
}
bool Puzzle_ModeLayer::init()
{
	bool bRet=false;
	do 
	{

		CC_BREAK_IF(!CCLayer::init());

     	CCSize  size=CCDirector::sharedDirector()->getWinSize();


		 CCSprite *spbg=CCSprite::create("ui/bg.png");
	 	spbg->setPosition(ccp(size.width/2,size.height/2));
		 this->addChild(spbg);



		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/wrong.mp3");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/right.ogg");
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("music/bad.mp3");
  
		

		//线条
		CCSprite *line_sp1=CCSprite::create("ui/line2.png");
		line_sp1->setPosition(ccp(size.width/2,580));
		this->addChild(line_sp1,2);
		CCSprite *line_sp2=CCSprite::create("ui/line2.png");
		line_sp2->setPosition(ccp(size.width/2,165));
		this->addChild(line_sp2,2);
		CCSprite *line_sp3=CCSprite::create("ui/line2.png");
		line_sp3->setPosition(ccp(size.width/2,46));
		this->addChild(line_sp3,2);


		//倒计时
		this->schedule(schedule_selector(Puzzle_ModeLayer::second),1.0f);
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
		this->schedule(schedule_selector(Puzzle_ModeLayer::Timeout),120);

		/*
		//剩余时间
		CCSprite *time_remain=CCSprite::create("ui/time.png");
		time_remain->setPosition(ccp(150,20));
		addChild(time_remain,1,2);
		*/

		//放大按钮
		CCMenuItemImage *enlarge=CCMenuItemImage::create("ui/enlarge.png","ui/enlarge.png",this,menu_selector(Puzzle_ModeLayer::enlarge));
		enlarge->setPosition(ccp(250,-300));

		//商城
		CCMenuItemImage *store=CCMenuItemImage::create("ui/store.png","ui/store.png",this,menu_selector(Puzzle_ModeLayer::store));
		store->setPosition(ccp(350,-300));

		CCMenu *pmenu=CCMenu::create(enlarge,store,NULL);
		this->addChild(pmenu,2);


		//标题
		CCSprite *title1=CCSprite::create("ui/title.png");
		title1->setPosition(ccp(150,size.height-20));
		this->addChild(title1);
		//张数
		CCSprite *number=CCSprite::create("ui/number.png");
		number->setPosition(ccp(size.width-330,size.height-20));
		this->addChild(number,3);



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
		CCMenuItemImage *GamePause=CCMenuItemImage::create("ui/pause.png","ui/pause.png",this,menu_selector(Puzzle_ModeLayer::GamePause));
		//GamePause->setPosition((ccp(400,280)));

		CCMenu *pausemenu=CCMenu::create(GamePause,NULL);
		pausemenu->setPosition(ccp(size.width-30,size.height-30));
		addChild(pausemenu,4,10);



		//滚动视图
		 scroolviewlayer=CCLayer::create();
		  scrollView = CCScrollView::create(); 



		CCSprite *sp1=CCSprite::create("pick_picture/nine/2.png");
		sp1->setPosition(ccp(100,100));

		CCSprite *sp2=CCSprite::create("pick_picture/nine/4.png");
		sp2->setPosition(ccp(250,100));

		CCSprite *sp3=CCSprite::create("pick_picture/nine/5.png");
		sp3->setPosition(ccp(400,100));

		CCSprite *sp4=CCSprite::create("pick_picture/nine/6.png");
		sp4->setPosition(ccp(550,100));

		CCSprite *sp5=CCSprite::create("pick_picture/nine/10.png");
		sp5->setPosition(ccp(700,100));

		CCSprite *sp6=CCSprite::create("pick_picture/nine/12.png");
		sp6->setPosition(ccp(850,100));

		CCSprite *sp7=CCSprite::create("pick_picture/nine/13.png");
		sp7->setPosition(ccp(1000,100));

		CCSprite *sp8=CCSprite::create("pick_picture/nine/15.png");
		sp8->setPosition(ccp(1150,100));

		CCSprite *sp9=CCSprite::create("pick_picture/nine/19.png");
		sp9->setPosition(ccp(1300,100));

        scroolviewlayer->addChild(sp1,1,100);
		scroolviewlayer->addChild(sp2,1,101);
		scroolviewlayer->addChild(sp3,1,102);
		scroolviewlayer->addChild(sp4,1,103);
		scroolviewlayer->addChild(sp5,1,104);
		scroolviewlayer->addChild(sp6,1,105);
		scroolviewlayer->addChild(sp7,1,106);
		scroolviewlayer->addChild(sp8,1,107);
		scroolviewlayer->addChild(sp9,0,108);




		scrollView->setAnchorPoint(CCPointZero);
		scrollView->setPosition(CCPointZero);
		//显示的区域
		scrollView->setViewSize(CCSizeMake(20000, 320));
		scrollView->setContentOffset(CCPointZero);

	    //scrollView->setPosition(CCPointZero);
	 


		//显示滑动的区域大小 scrollview的实际大小

		scrollView->setContentSize(CCSizeMake(20000, 320));
		scrollView->setContainer(scroolviewlayer);

		scroolviewlayer->setContentSize(CCSizeMake(20000,320));

		//因为要自己实现触摸消息，所以这里设为false ，设置需要滚动的内容
		scrollView->setTouchEnabled(true);
		scrollView->setDirection(kCCScrollViewDirectionHorizontal);
		scrollView->setDelegate(this);
		this->addChild(scrollView);

		/*
		scroolviewlayer->setContentSize(CCSizeMake(size.width*2,size.height/2));
		scrollView->setContentSize(CCSizeMake(size.width*2,size.height/2));
		scrollView->setPosition(ccp(size.width/2,size.height/2));
		
		
		CCScrollView *myscroll=CCScrollView::create(CCSizeMake(size.width/2,size.height/2),scroolviewlayer);
		myscroll->setBounceable(false);
		this->addChild(scroolviewlayer);
		 
		 */
		/*
		CCControlSlider *myslider=CCControlSlider::create("slider/bg.png","jd.png","hk.png");
		myslider->setPosition(ccp(size.width/2,size.height/2));
		myslider->setMaximumAllowedValue(50);
		myslider->setMinimumValue(0);
		this->addChild(myslider,0,111);
		
		myslider->addTargetWithActionForControlEvents(this,cccontrol_selector(Controlslider::SliderChangedCCControlEventValueChanged));
		CCLabelTTF *numttf=CCLabelTTF::create("","Arial",15);
	 
		numttf->setPosition(ccp(size.width/2,size.height/2));
		numttf->setString(CCString::createWithFormat("%.02f",myslider->getValue())->getCString());
		this->addChild(nullptr,0,112);

		*/








		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("music/bg_music.mp3",true);

		/*

		//从左到右
		CCSprite *banner=CCSprite::create("banner2.png");
		banner->setPosition(ccp(size.width/2,size.height-10));
		this->addChild(banner,6);
		CCProgressTo *toHorizontalBar1 = CCProgressTo::create(120, 100);
		CCProgressTimer *leftHorizontalBar = CCProgressTimer::create(CCSprite::create("banner.png"));
		leftHorizontalBar->setType( kCCProgressTimerTypeBar );
		leftHorizontalBar->setBarChangeRate(ccp(1,0));
		leftHorizontalBar->setMidpoint(ccp(0,0));
		addChild(leftHorizontalBar,6);
		leftHorizontalBar->setPosition(CCPointMake(size.width/2, size.height-10));
		leftHorizontalBar->runAction( CCRepeatForever::create(toHorizontalBar1));
		this->schedule(schedule_selector(Puzzle_ModeLayer::Timeout),120);
		*/



		setTouchEnabled(true);

		//随机产生三个图片
	    cc_timeval tv;
		CCTime::gettimeofdayCocos2d(&tv,NULL);
		unsigned long int seed=tv.tv_sec*1000+tv.tv_usec/1000;
		srand(seed);

		 m_num=this->random(1,3);
		char str[100];
		int m_num2=3;
		sprintf(str,"pick_picture/puzzle_pic/%d.png",m_num);

		CCSprite *sp_select=CCSprite::create(str);
		sp_select->setPosition(ccp(size.width/2,size.height/2+50));
		this->addChild(sp_select,1);






		/*
		 
		//几个选择图片
		 
		CCSprite *pick1=CCSprite::create("pick_picture/nine/2.png");
		pick1->setPosition(ccp(50,60));
		this->addChild(pick1,1,11);
		 
		CCSprite *pick2=CCSprite::create("pick_picture/nine/4.png");
		pick2->setPosition(ccp(170,60));
		this->addChild(pick2,1,12);

		CCSprite *pick3=CCSprite::create("pick_picture/nine/5.png");
		pick3->setPosition(ccp(290,60));
		this->addChild(pick3,1,13);

		CCSprite *pick4=CCSprite::create("pick_picture/nine/6.png");
		pick4->setPosition(ccp(410,60));
		this->addChild(pick4,1,14);

		CCSprite *pick5=CCSprite::create("pick_picture/nine/10.png");
		pick5->setPosition(ccp(530,60));
		this->addChild(pick5,1,15);

		CCSprite *pick6=CCSprite::create("pick_picture/nine/12.png");
		pick6->setPosition(ccp(650,60));
		this->addChild(pick6,1,16);

		CCSprite *pick7=CCSprite::create("pick_picture/nine/13.png");
		pick7->setPosition(ccp(770,60));
		this->addChild(pick7,1,17);

		CCSprite *pick8=CCSprite::create("pick_picture/nine/15.png");
		pick8->setPosition(ccp(890,60));
		this->addChild(pick8,1,18);

		CCSprite *pick9=CCSprite::create("pick_picture/nine/19.png");
		pick9->setPosition(ccp(1010,60));
		this->addChild(pick9,1,19);

	     
		 */


		/*
		CCSprite *Puzzle_sp=CCSprite::create("pick_picture/puzzle_pic1.png");
		Puzzle_sp->setPosition(ccp(size.width/2,size.height*3/4));
		this->addChild(Puzzle_sp);

		CCSprite *puzzle_pic1=CCSprite::create("pick_picture/puz_pic1.png");
		puzzle_pic1->setPosition(ccp(800,50));
		this->addChild(puzzle_pic1,1,10);

		CCActionInterval * move11 = CCMoveTo::create(6, CCPointMake(0, 50));
		CCActionInterval * move12 = CCMoveTo::create(6, ccp(900,50));
		CCFiniteTimeAction* seq1 = CCSequence::create(move11,move12,NULL);
		CCActionInterval * repeatForever1 =CCRepeatForever::create((CCActionInterval* )seq1);
		repeatForever1->setTag(01);
		puzzle_pic1->runAction(repeatForever1);

		CCSprite *puzzle_pic2=CCSprite::create("pick_picture/puz_pic2.png");
		puzzle_pic2->setPosition(ccp(0,50));
		this->addChild(puzzle_pic2,1,20);


	      CCActionInterval * move21 = CCMoveTo::create(6, CCPointMake(0, 50));
		   CCActionInterval * move22 = CCMoveTo::create(6, ccp(900,50));
		   CCFiniteTimeAction* seq2 = CCSequence::create(move21,move22,NULL);
		   CCActionInterval * repeatForever2 =CCRepeatForever::create((CCActionInterval* )seq2);
		   repeatForever2->setTag(02);
		   puzzle_pic2->runAction(repeatForever2);

	 

		CCSprite *pick11=CCSprite::create("number/d01.png");
		pick11->setPosition(ccp(155,389));
		pick11->setVisible(false);
		this->addChild(pick11,1,11);
		CCSprite *pick12=CCSprite::create("number/d01.png");
		pick12->setPosition(ccp( 624,396));
		pick12->setVisible(false);
		this->addChild(pick12,1,12);
		*/
		 

		bRet=true;
	} while (0);
	return true;
}


void Puzzle_ModeLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}



bool Puzzle_ModeLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
//void Normal_ModeLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
//void Normal_ModeLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	// bool IsSelected=false;
	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	m_ptTouchDown=point;//记下按下触摸点

	/*
	CCSize size=CCDirector::sharedDirector()->getWinSize();

	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	m_ptTouchDown=point;//记下按下触摸点
	
	//test
	CCSprite *sp1=(CCSprite*)scroolviewlayer->getChildByTag(100);
	CCRect   rect_ret1=sp1->boundingBox();
	if(rect_ret1.containsPoint(point))
	{
		sp1->setPosition(pTouch->getLocation());
		//Puzzle_ModeLayer->addChild(sp1,2);
	
	}
	 
	 
		CCSprite *pick1=(CCSprite*)this->getChildByTag(11);
		CCRect   rect_sp1=pick1->boundingBox();
		if(rect_sp1.containsPoint(point))
		{
			pick1->setPosition(pTouch->getLocation());
		}

		CCSprite *pick2=(CCSprite*)this->getChildByTag(12);
		CCRect   rect_sp2=pick2->boundingBox();
		if(rect_sp2.containsPoint(point))
		{
			pick2->setPosition(pTouch->getLocation());
		}
		CCSprite *pick3=(CCSprite*)this->getChildByTag(13);
		CCRect   rect_sp3=pick3->boundingBox();
		if(rect_sp3.containsPoint(point))
		{
			pick3->setPosition(pTouch->getLocation());
		}

		CCSprite *pick4=(CCSprite*)this->getChildByTag(14);
		CCRect   rect_sp4=pick4->boundingBox();
		if(rect_sp4.containsPoint(point))
		{
			pick4->setPosition(pTouch->getLocation());
		}

		CCSprite *pick5=(CCSprite*)this->getChildByTag(15);
		CCRect   rect_sp5=pick5->boundingBox();
		if(rect_sp5.containsPoint(point))
		{
			pick5->setPosition(pTouch->getLocation());
		}
		CCSprite *pick6=(CCSprite*)this->getChildByTag(16);
		CCRect   rect_sp6=pick6->boundingBox();
		if(rect_sp6.containsPoint(point))
		{
			pick6->setPosition(pTouch->getLocation());
		}
		CCSprite *pick7=(CCSprite*)this->getChildByTag(17);
		CCRect   rect_sp7=pick7->boundingBox();
		if(rect_sp7.containsPoint(point))
		{
			pick7->setPosition(pTouch->getLocation());
		}
		CCSprite *pick8=(CCSprite*)this->getChildByTag(18);
		CCRect   rect_sp8=pick8->boundingBox();
		if(rect_sp8.containsPoint(point))
		{
			pick8->setPosition(pTouch->getLocation());
		}
		CCSprite *pick9=(CCSprite*)this->getChildByTag(19);
		CCRect   rect_sp9=pick9->boundingBox();
		if(rect_sp9.containsPoint(point))
		{
			pick9->setPosition(pTouch->getLocation());
		}
	 
	 
	 */

 return true;
}
 
void Puzzle_ModeLayer::ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent)
{

	/*
	CCSize size=CCDirector::sharedDirector()->getWinSize();

	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	CCPoint ptTouch=point;
	int x_range=ptTouch.x-m_ptTouchDown.x;
	int y_range=ptTouch.y-m_ptTouchDown.y;
	 


	//test
	CCSprite *sp1=(CCSprite*)scroolviewlayer->getChildByTag(100);
	CCRect   rect_ret1=sp1->boundingBox();
	if(rect_ret1.containsPoint(point))
	{
		sp1->setPosition(pTouch->getLocation());
		//this->addChild(sp1,2);
	//	Puzzle_ModeLayer.addChild(sp1,2);

	}


	CCSprite *pick1=(CCSprite*)this->getChildByTag(11);
	CCRect   rect_sp1=pick1->boundingBox();
	if(rect_sp1.containsPoint(point))
	{
		if(y_range<20)
		{
         pick1->setPosition(ccp(ptTouch.x,60));
		}
		pick1->setPosition(pTouch->getLocation());
	}

	CCSprite *pick2=(CCSprite*)this->getChildByTag(12);
	CCRect   rect_sp2=pick2->boundingBox();
	if(rect_sp2.containsPoint(point))
	{
		pick2->setPosition(pTouch->getLocation());
	}
	CCSprite *pick3=(CCSprite*)this->getChildByTag(13);
	CCRect   rect_sp3=pick3->boundingBox();
	if(rect_sp3.containsPoint(point))
	{
		pick3->setPosition(pTouch->getLocation());
	}

	CCSprite *pick4=(CCSprite*)this->getChildByTag(14);
	CCRect   rect_sp4=pick4->boundingBox();
	if(rect_sp4.containsPoint(point))
	{
		pick4->setPosition(pTouch->getLocation());
	}

	CCSprite *pick5=(CCSprite*)this->getChildByTag(15);
	CCRect   rect_sp5=pick5->boundingBox();
	if(rect_sp5.containsPoint(point))
	{
		pick5->setPosition(pTouch->getLocation());
	}
	CCSprite *pick6=(CCSprite*)this->getChildByTag(16);
	CCRect   rect_sp6=pick6->boundingBox();
	if(rect_sp6.containsPoint(point))
	{
		pick6->setPosition(pTouch->getLocation());
	}
	CCSprite *pick7=(CCSprite*)this->getChildByTag(17);
	CCRect   rect_sp7=pick7->boundingBox();
	if(rect_sp7.containsPoint(point))
	{
		pick7->setPosition(pTouch->getLocation());
	}
	CCSprite *pick8=(CCSprite*)this->getChildByTag(18);
	CCRect   rect_sp8=pick8->boundingBox();
	if(rect_sp8.containsPoint(point))
	{
		pick8->setPosition(pTouch->getLocation());
	}
	CCSprite *pick9=(CCSprite*)this->getChildByTag(19);
	CCRect   rect_sp9=pick9->boundingBox();
	if(rect_sp9.containsPoint(point))
	{
		pick9->setPosition(pTouch->getLocation());
	}
	*/

}
void Puzzle_ModeLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

	/*
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCPoint point=CCDirector::sharedDirector()->convertToGL(pTouch->getLocation());



	 if(m_num==1)
	 {

		 //三个选择的图片
		 CCSprite *pick1=(CCSprite*)this->getChildByTag(12);
	     CCRect   rect_sp1=pick1->boundingBox();
		 if(rect_sp1.containsPoint(point))
		 {

			 pick1->setPosition(ccp(281,520));
		 }
		 CCSprite *pick2=(CCSprite*)this->getChildByTag(14);
		 CCRect   rect_sp2=pick2->boundingBox();
		 if(rect_sp2.containsPoint(point))
		 {

			 pick2->setPosition(ccp(382,323));
		 }
		 CCSprite *pick3=(CCSprite*)this->getChildByTag(18);
		 CCRect   rect_sp3=pick3->boundingBox();
		 if(rect_sp3.containsPoint(point))
		 {

			 pick3->setPosition(ccp(578,420));
		 }

		 //其余的图片
		 CCSprite *pick4=(CCSprite*)this->getChildByTag(11);
		 CCRect   rect_sp4=pick4->boundingBox();
		 if(rect_sp4.containsPoint(point))
		 {
			 pick4->setPosition(ccp(50,60));
		 }

		 CCSprite *pick5=(CCSprite*)this->getChildByTag(13);
		 CCRect   rect_sp5=pick5->boundingBox();
		 if(rect_sp5.containsPoint(point))
		 {
			 pick5->setPosition(ccp(290,60));
		 }
		 CCSprite *pick6=(CCSprite*)this->getChildByTag(15);
		 CCRect   rect_sp6=pick6->boundingBox();
		 if(rect_sp6.containsPoint(point))
		 {
			 pick6->setPosition(ccp(530,60));
		 }
		 CCSprite *pick7=(CCSprite*)this->getChildByTag(16);
		 CCRect   rect_sp7=pick7->boundingBox();
		 if(rect_sp7.containsPoint(point))
		 {
			 pick7->setPosition(ccp(650,60));
		 }
		 CCSprite *pick8=(CCSprite*)this->getChildByTag(17);
		 CCRect   rect_sp8=pick8->boundingBox();
		 if(rect_sp8.containsPoint(point))
		 {
			 pick8->setPosition(ccp(770,60));
		 }
		 CCSprite *pick9=(CCSprite*)this->getChildByTag(19);
		 CCRect   rect_sp9=pick9->boundingBox();
		 if(rect_sp9.containsPoint(point))
		 {
			 pick9->setPosition(ccp(1010,60));
		 }


	 }





	 if(m_num==2)
	 {
		 CCSprite *pick1=(CCSprite*)this->getChildByTag(13);
		 CCRect   rect_sp1=pick1->boundingBox();
		 if(rect_sp1.containsPoint(point))
		 {

			 pick1->setPosition(ccp(380,219));
		 }
		 CCSprite *pick2=(CCSprite*)this->getChildByTag(16);
		 CCRect   rect_sp2=pick2->boundingBox();
		 if(rect_sp2.containsPoint(point))
		 {

			 pick2->setPosition(ccp(484,509));
		 }
		 CCSprite *pick3=(CCSprite*)this->getChildByTag(19);
		 CCRect   rect_sp3=pick3->boundingBox();
		 if(rect_sp3.containsPoint(point))
		 {

			 pick3->setPosition(ccp(682,412));
		 }


		 //其余的图片
		 CCSprite *pick4=(CCSprite*)this->getChildByTag(11);
		 CCRect   rect_sp4=pick4->boundingBox();
		 if(rect_sp4.containsPoint(point))
		 {
			 pick4->setPosition(ccp(50,60));
		 }

		 CCSprite *pick5=(CCSprite*)this->getChildByTag(12);
		 CCRect   rect_sp5=pick5->boundingBox();
		 if(rect_sp5.containsPoint(point))
		 {
			 pick5->setPosition(ccp(170,60));
		 }
		 CCSprite *pick6=(CCSprite*)this->getChildByTag(15);
		 CCRect   rect_sp6=pick6->boundingBox();
		 if(rect_sp6.containsPoint(point))
		 {
			 pick6->setPosition(ccp(530,60));
		 }
		 CCSprite *pick7=(CCSprite*)this->getChildByTag(17);
		 CCRect   rect_sp7=pick7->boundingBox();
		 if(rect_sp7.containsPoint(point))
		 {
			 pick7->setPosition(ccp(770,60));
		 }
		 CCSprite *pick8=(CCSprite*)this->getChildByTag(18);
		 CCRect   rect_sp8=pick8->boundingBox();
		 if(rect_sp8.containsPoint(point))
		 {
			 pick8->setPosition(ccp(890,60));
		 }
		 CCSprite *pick9=(CCSprite*)this->getChildByTag(19);
		 CCRect   rect_sp9=pick9->boundingBox();
		 if(rect_sp9.containsPoint(point))
		 {
			 pick9->setPosition(ccp(1010,60));
		 }


	 }

	 if(m_num==3)
	 {
		 CCSprite *pick1=(CCSprite*)this->getChildByTag(11);
		 CCRect   rect_sp1=pick1->boundingBox();
		 if(rect_sp1.containsPoint(point))
		 {

			 pick1->setPosition(ccp(280,316));
		 }
		 CCSprite *pick2=(CCSprite*)this->getChildByTag(16);
		 CCRect   rect_sp2=pick2->boundingBox();
		 if(rect_sp2.containsPoint(point))
		 {

			 pick2->setPosition(ccp(482,516));
		 }
		 CCSprite *pick3=(CCSprite*)this->getChildByTag(17);
		 CCRect   rect_sp3=pick3->boundingBox();
		 if(rect_sp3.containsPoint(point))
		 {

			 pick3->setPosition(ccp(580,217));
		 }


		 //其余的图片
		 CCSprite *pick4=(CCSprite*)this->getChildByTag(12);
		 CCRect   rect_sp4=pick4->boundingBox();
		 if(rect_sp4.containsPoint(point))
		 {
			 pick4->setPosition(pTouch->getLocation());
		 }

		 CCSprite *pick5=(CCSprite*)this->getChildByTag(13);
		 CCRect   rect_sp5=pick5->boundingBox();
		 if(rect_sp5.containsPoint(point))
		 {
			 pick5->setPosition(ccp(170,60));
		 }
		 CCSprite *pick6=(CCSprite*)this->getChildByTag(14);
		 CCRect   rect_sp6=pick6->boundingBox();
		 if(rect_sp6.containsPoint(point))
		 {
			 pick6->setPosition(ccp(410,60));
		 }
		 CCSprite *pick7=(CCSprite*)this->getChildByTag(15);
		 CCRect   rect_sp7=pick7->boundingBox();
		 if(rect_sp7.containsPoint(point))
		 {
			 pick7->setPosition(ccp(530,60));
		 }
		 CCSprite *pick8=(CCSprite*)this->getChildByTag(18);
		 CCRect   rect_sp8=pick8->boundingBox();
		 if(rect_sp8.containsPoint(point))
		 {
			 pick8->setPosition(ccp(890,60));
		 }
		 CCSprite *pick9=(CCSprite*)this->getChildByTag(19);
		 CCRect   rect_sp9=pick9->boundingBox();
		 if(rect_sp9.containsPoint(point))
		 {
			 pick9->setPosition(ccp(1010,60));
		 }


	 }
	 */
}
	
	void Puzzle_ModeLayer::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}
void Puzzle_ModeLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}
int Puzzle_ModeLayer::random(int start,int end)
{
	float i=CCRANDOM_0_1()*(end-start+1)+start;
	return (int)i;
}
 
void Puzzle_ModeLayer::Timeout(float dt)
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
void Puzzle_ModeLayer::SliderChange(CCObject *sender,CCControlEvent)
{
	CCControlSlider *myslider=(CCControlSlider*)sender;
	CCLabelTTF *numttf=(CCLabelTTF*)this->getChildByTag(112);
	numttf->setString(CCString::createWithFormat("%.02f",myslider->getValue())->getCString());



}
void Puzzle_ModeLayer::scrollViewDidScroll(CCScrollView *view)
{
	CCSprite *sp1=(CCSprite*)scroolviewlayer->getChildByTag(100);
	//sp1->setVisible(false);

}
void Puzzle_ModeLayer::scrollViewDidZoom(CCScrollView *view)
{

}


void Puzzle_ModeLayer::enlarge(CCObject *pSender)
{

}
void Puzzle_ModeLayer::store(CCObject *pSender)
{
	CCTransitionScene *rescene=NULL;
	CCScene  *replacescene=GameStore::create();
	float t=1.5f;
	rescene=CCTransitionZoomFlipY::create(t,replacescene);
	CCDirector::sharedDirector()->replaceScene(rescene);
}

void Puzzle_ModeLayer::GamePause(CCObject *pSender)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	m_pausebg=CCSprite::create("pausebg.png");
	m_pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(m_pausebg,20,20);

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(false);
	//重新开始
	//	CCMenuItemFont *ResumeItem=CCMenuItemFont::create("resume",this,menu_selector(Anti_TraditionModeLayer::GameResume));
	CCMenuItemImage *resumeItem=CCMenuItemImage::create("ui/resume.png","ui/resume.png",this,menu_selector(Puzzle_ModeLayer::GameResume));

	CCMenu *ResumeMenu=CCMenu::create(resumeItem,NULL);
	ResumeMenu->setPosition(ccp(size.width/2,size.height/2));
	m_pausebg->addChild(ResumeMenu,1,11);

	//暂停游戏
	CCDirector::sharedDirector()->pause();

}
void Puzzle_ModeLayer::GameResume(CCObject *pSender)
{

	CCMenu *menu=(CCMenu*)this->getChildByTag(10);
	menu->setEnabled(true);
	//恢复游戏

	CCSprite *pausebg_sp=(CCSprite*)this->getChildByTag(20);
	this->removeChild(m_pausebg);
	CCDirector::sharedDirector()->resume();

}

void Puzzle_ModeLayer::second(float dt)
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
void Puzzle_ModeLayer::draw()
{
	//线条
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	ccDrawColor4B(200,180,80,130);
	glLineWidth(4);
	ccDrawLine(ccp(0,600),ccp(size.width,600));

	CCSize mysize=CCDirector::sharedDirector()->getWinSize();

	 

	ccDrawColor4B(255,255,255,130);

	glLineWidth(3);

	ccDrawLine(ccp(100,200),ccp(mysize.width-100,200));

}