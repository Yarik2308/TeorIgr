#pragma once
#include "Header.h"


double GoldSum(vector<Rud> rud, vector<double> &gold, vector<int> year)
{
	double m = 0;
	for (int i : year)
	{
		m = m + gold[i-1] * rud[i-1].getGoldPer();
		gold[i-1] = gold[i-1] - gold[i-1] * rud[i-1].getGoldPer();
	}
	return m;
}

