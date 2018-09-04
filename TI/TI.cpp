#pragma once
#include "stdafx.h"
#include "Header.h"


int main()
{
	Rud A, B, C;
	A.setGold(10);
	B.setGold(12);
	C.setGold(14);
	A.setDragaBrokePer(0.2);
	B.setDragaBrokePer(0.3);
	C.setDragaBrokePer(0.4);
	A.setGoldPer(0.4);
	B.setGoldPer(0.5);
	C.setGoldPer(0.6);
	vector<Rud> rud;
	rud.push_back(A);
	rud.push_back(B);
	rud.push_back(C);
	double m = Function(rud, 2);
	system("pause");
    return 0;
}

