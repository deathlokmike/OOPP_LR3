
// Drozdov_OOPP_L3View.h: интерфейс класса CDrozdovOOPPL3View
//

#pragma once


class CDrozdovOOPPL3View : public CScrollView
{
protected: // создать только из сериализации
	CDrozdovOOPPL3View() noexcept;
	DECLARE_DYNCREATE(CDrozdovOOPPL3View)

// Атрибуты
public:
	CDrozdovOOPPL3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CDrozdovOOPPL3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в Drozdov_OOPP_L3View.cpp
inline CDrozdovOOPPL3Doc* CDrozdovOOPPL3View::GetDocument() const
   { return reinterpret_cast<CDrozdovOOPPL3Doc*>(m_pDocument); }
#endif

