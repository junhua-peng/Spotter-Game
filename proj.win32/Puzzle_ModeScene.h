#pragma once
#include "cocos2d.h"
#include "Puzzle_ModeScene.h"
#include "Puzzle_ModeLayer.h"
class Puzzle_ModeScene :
	public cocos2d::CCScene
{
public:
	Puzzle_ModeScene(void);
	~Puzzle_ModeScene(void);
	virtual bool init();
	void ReturnGame(CCObject *pSender);
	CREATE_FUNC(Puzzle_ModeScene);
	CC_SYNTHESIZE(Puzzle_ModeLayer*,_puzzle_modelayer,Puzzle_ModeLayer);


};

