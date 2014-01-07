#pragma once
#include "cocos2d.h"
#include "Mirror_ModeLayer.h"
class Mirror_ModeScene :
	public cocos2d::CCScene
{
public:
	Mirror_ModeScene(void);
	~Mirror_ModeScene(void);
	virtual bool init();
	void ReturnGame(CCObject *pSender);
	CREATE_FUNC(Mirror_ModeScene);
	CC_SYNTHESIZE(Mirror_ModeLayer*,_mirror_modelayer,Mirror_ModeLayer);

};

