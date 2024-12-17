#pragma once
#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>
#include <map>
#include <string>
#include <vector>
class TableCipher
{
private:
    int stolb;
public:
    TableCipher() = delete; // запрет на конструктор по умолчанию
    TableCipher(const int& key): stolb(key){};
    std::wstring encrypt(const std::wstring& encrypt_text);
    std::wstring decrypt(const std::wstring& decrypt_text);
};
