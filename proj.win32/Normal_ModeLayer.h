#pragma once
#include "cocos2d.h"
#include  "Normal_ModeLayer.h"
using namespace cocos2d;
class Normal_ModeLayer :
	public cocos2d::CCLayer
{
public:
	Normal_ModeLayer(void);
	~Normal_ModeLayer(void);
	virtual bool init();
	CREATE_FUNC(Normal_ModeLayer);
	void ReturnGame(CCObject *pSender);
	CC_SYNTHESIZE(Normal_ModeLayer*,_normal_modelayer,Normal_ModeLayer)




	//触屏事件
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	void registerWithTouchDispatcher(void);
	//生命周期
	virtual void onEnter();
	virtual void onExit();
    void Timeout(float dt);
	void GamePause(CCObject *pSender);
	void GameResume(CCObject *pSender);

	void enlarge(CCObject *pSender);
	void store(CCObject *pSender);
	void  display_score(float dt);
	void second(float dt);


     

public:
	CCSprite* m_pausebg;
	int count;

	bool m_selected1;
	bool m_selected2;
	bool m_selected3;
	bool m_selected4;
	bool m_selected5;
	bool m_selected6;
	bool m_selected7;
	bool m_selected8;
	bool m_selected9;

	bool m_haswin;
	long m_timeleave;

};

