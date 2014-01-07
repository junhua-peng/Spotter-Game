#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"


using namespace cocos2d;
using namespace cocos2d::extension;

//using namespace CocosDenshion; 

 
class Puzzle_ModeLayer : 
		public cocos2d::CCLayer,public CCScrollViewDelegate

{
public:
	Puzzle_ModeLayer(void);
	~Puzzle_ModeLayer(void);
	virtual bool init();
	CREATE_FUNC(Puzzle_ModeLayer);

    virtual  void scrollViewDidScroll(CCScrollView *view);
	virtual void scrollViewDidZoom(CCScrollView *view);
	CCScrollView *scrollView;
	CCLayer *scroolviewlayer;



	//触屏事件
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	 

	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);

	void registerWithTouchDispatcher(void);
	//生命周期
	virtual void onEnter();
	virtual void onExit();

	int random(int start,int end);
	int randomInt(int max ,int min);
    void Timeout(float dt);
	void SliderChange(CCObject *sender,CCControlEvent);

	void GamePause(CCObject *pSender);
	void GameResume(CCObject *pSender);

	void enlarge(CCObject *pSender);
	void store(CCObject *pSender);
	void second(float dt);
	virtual void draw();



public:
	CCSprite* m_pausebg;


private:
	CCPoint m_ptTouchDown;//首次按下的触摸点
	bool m_bMoveLayer;
    long m_timeleave;







	//CCSprite *m_puzzle_pic1;
	//CCSprite *m_puzzle_pic2;
private:
	int count;
	int m_num;
	int m_num1;
	int m_num2;
};

