#pragma once
#include "cocos2d.h"
 
class pick_pattern :
	public cocos2d::CCScene
{
public:
	pick_pattern(void);
	~pick_pattern(void);
     CREATE_FUNC(pick_pattern);
	 virtual bool init();
	 void normal_mode(CCObject *pSender); //正常模式
	 void mirror_mode(CCObject *pSender);  //镜像模式
	 void sliding_mode(CCObject *pSender);  //滑动模式
	 void clover_mode(CCObject *pSender);   //四叶草模式
	 void anti_tradition_mode(CCObject *pSender); //反传统模式
	 void puzzle_mode(CCObject *pSender);    //拼图模式
	 void ReturnGame(CCObject *pSender);



};

