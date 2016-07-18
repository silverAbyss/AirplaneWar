
// MFCApplication3View.h : CMFCApplication3View 类的接口
//
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")
#include "Animation.h"
#include "PlaneSelf.h"
#include "BulletGeneral.h"
#include "PlaneEmenyGeneral.h"
#include "Explosion.h"
#include "PlaneBoss.h"
//#pragma comment( lib, "json.lib" )
#include "json.hpp"
#include <string>
#include <fstream>
#include <streambuf>
#include "DSBuffer.h"
#include "DSList.h"
#pragma once
using namespace Gdiplus;

struct gamesetting {
	int mission_present=0;//当前关卡
	bool bossmode = 0;//boss模式
	int mission_level[4] = { 5,50,90,140 };//升级杀敌数要求
	int bossid [4] = {16,17,18,19};//bossid
	int mission_killed = 0;//已杀普通敌机数目
	int cooldown_plane_generate[2] = {0,2000};//第一值为状态量，第二个值为目标量



};

class CMFCApplication3View : public CView
{
public:
	int music_explosion_index = 1;
	int music_fire_index = 31;
	int key_space = 0;//1
public:
	CDSList DSlist1;
	void LoadImageFromFile();
	void InitalizeAirplane();
	void InitializeEquation();
public:
	PlaneSelf plane_self;
	PlaneBoss *plane_boss=NULL;

protected: // 仅从序列化创建
	CMFCApplication3View();
	DECLARE_DYNCREATE(CMFCApplication3View)

	

public:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR   gdiplusToken;
public://双缓冲
	CBitmap MemBitmap;//双缓存
	CDC MemDC;//双缓存、
	CBrush m_brush;//刷背景

public:
	//游戏控制
	void JudgeFlyingObject();//判断飞行目标
	void JudgeSetting();//剧情检测
	void FireSetting();//子弹发射剧情

public:
	gamesetting mgamesetting;
// 特性
public:
	CMFCApplication3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnInitialUpdate();
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCApplication3View.cpp 中的调试版本
inline CMFCApplication3Doc* CMFCApplication3View::GetDocument() const
   { return reinterpret_cast<CMFCApplication3Doc*>(m_pDocument); }
#endif

