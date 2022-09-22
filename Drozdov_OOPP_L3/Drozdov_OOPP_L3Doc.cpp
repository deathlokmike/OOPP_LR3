
// Drozdov_OOPP_L3Doc.cpp: реализация класса CDrozdovOOPPL3Doc 
//

#include "pch.h"
#include "framework.h"

// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Drozdov_OOPP_L3.h"
#endif

#include "Drozdov_OOPP_L3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrozdovOOPPL3Doc

IMPLEMENT_DYNCREATE(CDrozdovOOPPL3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDrozdovOOPPL3Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CDrozdovOOPPL3Doc

CDrozdovOOPPL3Doc::CDrozdovOOPPL3Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CDrozdovOOPPL3Doc::~CDrozdovOOPPL3Doc()
{
}

BOOL CDrozdovOOPPL3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	concern.clear();
	return TRUE;
}


// при нажатии на кнопку GetDocument()->SetModifiedFlag()

// Сериализация CDrozdovOOPPL3Doc

void CDrozdovOOPPL3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		concern.to_file(ar);
	}
	else
	{
		concern.clear();
		concern.from_file(ar);
		AfxGetMainWnd()->Invalidate();
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CDrozdovOOPPL3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CDrozdovOOPPL3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CDrozdovOOPPL3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CDrozdovOOPPL3Doc

#ifdef _DEBUG
void CDrozdovOOPPL3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrozdovOOPPL3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CDrozdovOOPPL3Doc
