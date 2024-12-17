#include "modAlphaCipher.h"
#include "modAlphaCipher.cpp"

#include <cctype>
#include <iostream>
#include <locale>
using namespace std;

bool isValid(const wstring& s)
{
    for(auto c : s)
        if(!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char** argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    wcout << L"Введите ключ: ";
    wcin >> key;
    if(!isValid(key)) {
        cerr << L"Неправильный ключ\n";
        return 1;
    }
    wcout << L"Ключ принят\n";
    modAlphaCipher cipher(key);
    do {
        wcout << L"Выберете операцию (0-выход, 1-зашифровка, 2-расшифровка): ";
        wcin >> op;
        if(op > 2) {
            wcout << L"Ошибка\n";
        } else if(op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            if(isValid(text)) {
                if(op == 1) {
                    wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Неверный текст\n";
            }
        }
    } while(op != 0);
    return 0;
}
