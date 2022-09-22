#pragma once
#include "Car.h"
#include "SportCar.h"

class ConcernDrozdov
{
	vector<shared_ptr<vehicleDrozdov>> motorshow;
public:
	virtual void to_file(CArchive& ar);
	virtual void from_file(CArchive& ar);
	virtual void clear();
	virtual ~ConcernDrozdov()
	{
		motorshow.clear();
	}
	CSize out(CDC* pDC);
};