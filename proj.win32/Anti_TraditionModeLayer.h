#pragma once
#include "cocos2d.h"
 
using namespace  cocos2d;
class Anti_TraditionModeLayer :
	public cocos2d::CCLayer
{
public:
	Anti_TraditionModeLayer(void);
	~Anti_TraditionModeLayer(void);
	CREATE_FUNC(Anti_TraditionModeLayer);
	virtual bool init();
 
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void registerwithTouchDispather();
	virtual void onEnter();
	virtual void onExit();

	void Update(float dt);
	void Timeout(float dt);

	void enlarge(CCObject *pSender);
	void store(CCObject *pSender);

	void GamePause(CCObject *pSender);
	void GameResume(CCObject *pSender);

	//计分
	void GameScore(CCObject *pSender);



    //显示剩余时间

	 void second(float dt);

	 int m_timeleave;

public:
	CCSprite *m_pausebg;
	long m_score; //实时分数
	long m_maxscore;
	long m_rank;

	//找茬点标记
	bool m_find1;
	bool m_find2;
	bool m_find3;
	bool m_find4;
	bool m_find5;
	bool m_selected1;
	bool m_selected2;
	bool m_selected3;
	bool m_selected4;
	bool m_selected5;
	bool m_selected6;
	bool m_selected7;
	bool m_selected8;
	bool m_selected9;




	/*
	virtual bool CCTouchBegan(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCSet *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCSet *pTouch,cocos2d::CCEvent *pEvent);
	virtual void onEnter();
	virtual void onExit();
	*/
private:
	int count;
};

