
// Drozdov_OOPP_L3Doc.h: интерфейс класса CDrozdovOOPPL3Doc 
//


#pragma once
#include "Concern.h"

class CDrozdovOOPPL3Doc : public CDocument
{
protected: // создать только из сериализации
	CDrozdovOOPPL3Doc() noexcept;
	DECLARE_DYNCREATE(CDrozdovOOPPL3Doc)

// Атрибуты
public:
	ConcernDrozdov concern;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CDrozdovOOPPL3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
