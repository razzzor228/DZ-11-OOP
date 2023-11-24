#include "Pishnyak.h"

Pishnyak::Pishnyak()
{
}

Pishnyak::~Pishnyak()
{
}

Pishnyak::Pishnyak(wstring s,int check1)
{
	num = 1;
	m_txt = s;
	check = check1;
}

Pishnyak::Pishnyak(const Pishnyak& obj)
{
	num = obj.num;
	check = obj.check;
	m_txt = obj.m_txt;
}

void Pishnyak::Copy(vector<Pishnyak*>& db)
{
	db.push_back(new Pishnyak(*this));
}

int Pishnyak::Get() 
{
	return check;
}

int Pishnyak::GetNum()
{
	return num;
}

void Pishnyak::Print()
{
	wcout << m_txt;
}

