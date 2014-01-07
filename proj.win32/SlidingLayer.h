#ifndef _SLIDING_LAYER_H_
#define _SLIDING_LAYER_H_
#include "cocos2d.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace  cocos2d;

//////////////////////////////////////////////////////////////////////////
class CSlidingLayer : public cocos2d::CCLayer
{
public:
	CSlidingLayer();
	~CSlidingLayer();

public:
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); // 手指触碰时
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent); // 手指移动时
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); // 手指放开时

public:
	void AddSprite(CCSprite* pSprite); // 添加用于滑屏显示的精灵
	bool IsMoveLayer() { return m_bMoveLayer; } // 用于判断是否手指滑动了

private:
	CCPoint m_ptTouchDown; // 首次按下的触摸点

	typedef vector<CCSprite*> VEC_SPRITE;
	VEC_SPRITE m_vecSprite; // 精灵集合
	int m_nCurSprite; // 当前显示的精灵

	bool m_bMoveLayer; // 移动层
};
#endif