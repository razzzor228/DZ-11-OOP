#include "Maxim.h"

Maxim::Maxim()
{

}

Maxim::~Maxim()
{
}

Maxim::Maxim(wstring s, int check1)
{
	num = 2;
	m_txt = s;
	check = check1;
}

Maxim::Maxim(const Maxim& obj)
{
	num = obj.num;
	check = obj.check;
	m_txt = obj.m_txt;
}

void Maxim::Copy(vector<Pishnyak*>& db)
{
	db.push_back(new Maxim(*this));
}

int Maxim::Get()
{
	return check;
}

int Maxim::GetNum()
{
	return num;
}

void Maxim::Print()
{
	wcout << m_txt;
}
