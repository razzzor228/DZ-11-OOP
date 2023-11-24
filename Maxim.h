#pragma once
#include "Pishnyak.h"
class Maxim : public Pishnyak
{
	wstring m_txt;
	int check;
	int num;
public:
	Maxim();
	~Maxim();
	Maxim(wstring s, int check1);
	Maxim(const Maxim& obj);
	void Copy(vector<Pishnyak*>& db);
	int Get();
	int GetNum();
	void Print();
};

