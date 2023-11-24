#include "DB.h"

struct Leaks {
    ~Leaks() {
        _CrtDumpMemoryLeaks();
    }
};

Leaks _l;

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    wifstream in("text.txt");
    in.imbue(locale(in.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>));
    DB<Pishnyak*> db1;
    DB<Pishnyak*> db2;
    int counter = 0;
    wchar_t c;
    wstring s;
    for (; in; ) {
        in.get(c);
        if (in.eof()) break;
        s = s + c;
        if (c == L'\n')counter++;
    }
    int counter2 = 0;
    wstring s1, s2;
    int ii;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == L'\n')counter2++;
        s1 = s1 + s[i];
        ii = i;
        if (counter2 == counter / 2)break;
    }
    for (int i = ii + 1; i < s.size(); i++) {
        if (s[i] == L'\n')counter2++;
        s2 = s2 + s[i];
    }
    wcout << s1 << s2;
    db1.Random(s1, s2);
    db2 = db1;
    db2.Delete();
    db2.Swap();
    wcout << endl;
    wcout << endl;
    db2.Print();
}
//Приняли - ура!