
// Drozdov_OOPP_L3View.cpp: реализация класса CDrozdovOOPPL3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Drozdov_OOPP_L3.h"
#endif

#include "Drozdov_OOPP_L3Doc.h"
#include "Drozdov_OOPP_L3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrozdovOOPPL3View

IMPLEMENT_DYNCREATE(CDrozdovOOPPL3View, CScrollView)

BEGIN_MESSAGE_MAP(CDrozdovOOPPL3View, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CDrozdovOOPPL3View

CDrozdovOOPPL3View::CDrozdovOOPPL3View() noexcept
{
	// TODO: добавьте код создания

}

CDrozdovOOPPL3View::~CDrozdovOOPPL3View()
{
}

BOOL CDrozdovOOPPL3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CDrozdovOOPPL3View

void CDrozdovOOPPL3View::OnDraw(CDC* pDC)
{
	CDrozdovOOPPL3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CSize sizeTotal = pDoc->concern.out(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDrozdovOOPPL3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CDrozdovOOPPL3View

#ifdef _DEBUG
void CDrozdovOOPPL3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrozdovOOPPL3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrozdovOOPPL3Doc* CDrozdovOOPPL3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrozdovOOPPL3Doc)));
	return (CDrozdovOOPPL3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CDrozdovOOPPL3View


void CDrozdovOOPPL3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*	CWindowDC dc(this);
	CString s;
	s.Format("%s", );
	dc.TextOut(point.x, point.y, s);*/

}
