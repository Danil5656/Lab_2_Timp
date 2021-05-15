#include "Cipher.h"
#include <locale>
#include "Exception.h"
#include <codecvt>
int main()
{
    bool Check = true;
    string regime, str, Skey;
    cout << "Добро пожаловать в программу, которая реализует шифр табличной маршрутной перестановки." << endl;
    cout << "1 - режим шифрования шифром табличной маршрутной перестановки. \n";
    cout << "2 - режим расшифрования шифра табличной маршрутной перестановки.\n";
    cout << "Чтобы завершить работу программу, введите \"0\"." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Укажите режим работы:";
        getline(cin,regime);
        if (regime == "1") {
            cout << "Введите строку для шифрования:";
            getline(cin, str);
            try {
                Error::Check_s(str);
                cout << "Введите ключ:";
                getline(cin, Skey);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                Error::Check_k(wstren, Skey);
                int key = stoi(Skey);
                Cipher enc(key);
                cout<<codec.to_bytes(enc.EncodeCipher(enc,wstren))<<endl;
            } catch(Error & e) {
                cout<<"Описание ошибки: "<<e.what()<<endl;
            }
        }

        if (regime == "2") {
            cout << "Введите строку для расшифрования:";
            getline(cin, str);
            try {
                Error::Check_s(str);
                cout << "Введите ключ:";
                getline(cin, Skey);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                Error::Check_k(wstren, Skey);
                int key = stoi(Skey);
                Cipher dec(key);
                cout<<codec.to_bytes(dec.DecodeCipher(dec,wstren))<<endl;
            } catch(Error & e) {
                cout<<"Описание ошибки: "<<e.what()<<endl;
            }
        }
        if (regime == "0") {
            cout << "До новых встреч!." << endl;
            Check = false;
            break;
        }

    } while (Check != false);
    return 0;
}
