#pragma once
#include "Maxim.h"
template <typename T>
class DB 
{
    vector<Pishnyak*> v;
public:
    DB() {}
    ~DB()
    {
        for (int i = 0; i < v.size(); i++)
        {
            delete v[i];
        }
    }
    DB(const DB& obj)
    {
        for (vector<Pishnyak*>::iterator it = obj.begin(); it != obj.end(); ++it)
        {
            (*it)->Copy(*this);
        }
    }
    DB& operator =(const DB& obj)
    {
        if (this == &obj) return *this;
        for (vector<Pishnyak*>::iterator it = v.begin(); it != v.end(); ++it)
        {
            delete(*it);
        }
        v.clear();
        for (vector<Pishnyak*>::const_iterator it = obj.v.begin(); it != obj.v.end(); ++it)
        {
            (*it)->Copy(v);
        }
        return *this;
    }
    void Random(wstring s1,wstring s2) {
        int c1 = 0, c2 = 0;
        int checker1 = 0, checker2 = 0;
        for (int i = 0; i < 6; i++) {
            if (rand() % 2 == 0) {
                c1++;
                if (c1 == 5) { 
                    v.push_back(new Maxim(s2, checker2)); 
                    break;
                }
                v.push_back(new Pishnyak(s1, checker1));
                if (checker1 == 0)checker1 = 1;
            }
            else {
                c2++;
                if (c2 == 5) { v.push_back(new Pishnyak(s1, checker1)); break; }
                v.push_back(new Maxim(s2,checker2));
                if (checker2 == 0)checker2 = 1;
            }
        }
    }
    void Delete() {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->Get() == 1)
            {
                delete v[i];
                v.erase(v.begin()+ i);
                i--;
            }
        }
    }
    void Swap()
    {
        if (v[0]->GetNum() == 2) {
            swap(v[0], v[1]);
        }
    }
    void Print() {
        for (int i = 0; i < v.size(); i++) {
            v[i]->Print();
        }
    }
};

