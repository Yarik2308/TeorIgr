#pragma once
#include "Header.h"

double Fun(vector<Rud> rud, vector<double> gold, vector<int> &year, vector<vector<int>> yearA, int k, int DragC)
{
	vector<double> Max(rud.size());
	vector<vector<int>> yearN(size(rud));
	vector<int> used(DragC);
	if (DragC != 0 && k > 0)
	{
		for (int i = 0; i < yearA.size();i++)
			if (yearA[i].size()>0)
				used[i] = yearA[i][k-1];
	}

	for (int i = 0; i < size(rud); i++)
	{
		if(k>0)
		{
			if (gold[i] > 0)
			{
				if (DragC != 0)
				{
					for (int j : used)
						if (i != j-1)
						{
							Max[i] = (1 - rud[i].getDragaBrokePer())*rud[i].getGoldPer()*gold[i];
							gold[i] = gold[i] - (gold[i] * rud[i].getGoldPer());
							Max[i] = Max[i] + (1 - rud[i].getDragaBrokePer())*Fun(rud, gold, yearN[i], yearA, k - 1, DragC);
						}
				}
				else
				{
					Max[i] = (1 - rud[i].getDragaBrokePer())*rud[i].getGoldPer()*gold[i];
					gold[i] = gold[i] - (gold[i] * rud[i].getGoldPer());
					Max[i] = Max[i] + (1 - rud[i].getDragaBrokePer())*Fun(rud, gold, yearN[i], yearA, k - 1, DragC);
				}
			}
		}
	}

	double m = 0;
	double j = 0;
	for (int i = 0; i < size(Max); i++)
	{
		if (Max[i] > m)
		{
			m = Max[i];
			j = i;
		}
	}

	yearN[j].push_back(j+1);
	year = yearN[j];
	return Max[j];
}

double Function(vector<Rud> rud, int DragK)
{
	ofstream F("Test.txt", ios_base::trunc);
	vector<vector<int>> yearA(DragK);

	vector<double> gold;
	for (int i = 0; i < size(rud); i++)
		gold.push_back(rud[i].getGold());

	double p = 1;
	for (int i = 0; i < size(rud); i++)
		if (rud[i].getDragaBrokePer() < p)
			p = rud[i].getDragaBrokePer();

	if (p >= 1 || DragK >= rud.size())
	{
		cout << "Something wrong" << endl;
		return 0;
	}
	int kol = 0;
	while (pow((1 - p), kol) > 0.1)
		kol = kol + 1;
	vector<int> year1(kol);
	cout << kol << endl;
	for (int i = 0; i < DragK; i++)
	{
		double m = Fun(rud, gold, year1, yearA, kol, i);
		year1.erase(year1.begin());
		yearA[i]= year1;
		F << m << endl;
		F << GoldSum(rud, gold, yearA[i]) << endl;
	}
	for (vector<int> i : yearA)
	{
		for (int j : i)
			F << j << " ";
		F << endl;
	}
	F.close();
	return 0;
}


