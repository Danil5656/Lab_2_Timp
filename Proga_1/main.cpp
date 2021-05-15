#include <iostream>
#include "modAlphaCipher.h"
#include <codecvt>
using namespace std;

int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool Check = true;
    wstring regime,Neregime,wstr,wstr_key;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "Cправка о работе программы:" << endl;
    cout << "1 - режим шифрования шифром  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "2 - режим расшифрования шифра  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "0 - завершить работу программы.\n";
    do {
        cout << "Укажите режим работы:";
        wcin >> regime;
        if (regime == L"1") {
            cout << "Введите строку для шифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring cipherText = cipher.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(cipherText)<<endl;
            } catch (Error & ex) {
                cout << "Описание ошибки: "<<ex.what() << endl;

            }
        }
        if (regime == L"2") {
            cout << "Введите строку для расшифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring OpenText = cipher.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(OpenText)<<endl;
            } catch (Error & ex) {
                cout << "Описание ошибки: "<<ex.what() << endl;
            }
        }
        if (regime == L"0") {
            cout << "Программа завершила работу." << endl;
            Check = false;
            break;
        }

    } while (Check != false);
    return 0;

}
