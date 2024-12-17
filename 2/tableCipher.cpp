#include "tableCipher.h"
using namespace std;
std::wstring TableCipher::encrypt(const std::wstring& encrypt_text)
{
    wstring table = encrypt_text; // создаем копию текста
    int len, str, index, x;
    len = encrypt_text.length(); // вычисляем длину сообщения
    str = (len - 1) / stolb + 1;
    x = 0;
    for(int i = stolb; i > 0; i--) { // проходим по столбцам в обратном порядке
        for(int j = 0; j < str; j++) {
            index = i + stolb * j; //Вычисляется индекс символа в сообщении
            if(index - 1 < len) {
                table[x] = encrypt_text[index - 1];
                x++;
            }
        }
    }
    return table;
}
std::wstring TableCipher::decrypt(const std::wstring& decrypt_text)
{
    wstring table = decrypt_text;
    int len, str, index, x;
    len = decrypt_text.length();
    str = (len - 1) / stolb + 1;
    x = 0;
    for(int i = stolb; i > 0; i--) {
        for(int j = 0; j < str; j++) {
            index = i + stolb * j;
            if(index - 1 < len) {
                table[index - 1] = decrypt_text[x];
                x++;
            }
        }
    }
    return table;
}
