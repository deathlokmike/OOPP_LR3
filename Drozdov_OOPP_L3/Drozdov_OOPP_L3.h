
// Drozdov_OOPP_L3.h: основной файл заголовка для приложения Drozdov_OOPP_L3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CDrozdovOOPPL3App:
// Сведения о реализации этого класса: Drozdov_OOPP_L3.cpp
//

class CDrozdovOOPPL3App : public CWinApp
{
public:
	CDrozdovOOPPL3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrozdovOOPPL3App theApp;
