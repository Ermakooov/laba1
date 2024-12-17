#include "tableCipher.h"
#include "tableCipher.cpp"
using namespace std;

bool isValid(const wstring& s)
{
    for(auto c : s)
        if(!isalpha(c) || !isupper(c))
            return false;
    return true;
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout << L"Введите ключ: ";
    wcin >> key;
    if(!wcin.good()) {
        wcerr << L"Неправильный ключ\n";
        return 0;
    }
    TableCipher cipher(key);
    do {

        wcout << L"Какую операцию выберете (0-выход, 1-зашифрование, 2-расшифрование): ";
        wcin >> op;
        if(op > 2) {
            wcout << L"Ошибка\n";
        } else if(op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            if(isValid(text)) {
                if(op == 1) {
                    wcout << L"Зашифрованный текст:" << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст:" << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Неправильный текст\n";
            }
        }
    } while(op != 0);
    return 0;
}
