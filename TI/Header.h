#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class List;

class Rud {
private:
	double Gold;
	double DragaBrokePer;
	double GoldPer;
public:
	friend class List;
	void setGold(double Gold) { this->Gold = Gold; }
	double getGold() { return this->Gold; }
	void setDragaBrokePer(double DragaBrokePer) { this->DragaBrokePer = DragaBrokePer; }
	double getDragaBrokePer() { return this->DragaBrokePer; }
	void setGoldPer(double GoldPer) { this->GoldPer = GoldPer; }
	double getGoldPer() { return this->GoldPer; }

	friend istream& operator >> (istream& in, Rud &i)
	{
		in >> i.Gold >> i.DragaBrokePer >> i.GoldPer;
		return in;
	}
	friend ostream& operator << (ostream& out, Rud &i)
	{
		out << i.Gold << endl << i.DragaBrokePer << i.GoldPer;
		return out;
	}

};

//double Function(Rud A, Rud B);
//double GoldSum(Rud A, Rud B, string all);

double Function(vector<Rud> rud, int DragK);
double GoldSum(vector<Rud> rud, vector<double> &gold, vector<int> year);