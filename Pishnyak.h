#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cwchar>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
class Pishnyak
{
	wstring m_txt;
	int check;
	int num;
public:
	Pishnyak();
	virtual ~Pishnyak();
	Pishnyak(wstring s, int check1);
	Pishnyak(const Pishnyak& obj);
	virtual void Copy(vector<Pishnyak*>& db);
	virtual int Get();
	virtual int GetNum();
	virtual void Print();
};

