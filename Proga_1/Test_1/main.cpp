#include <UnitTest++/UnitTest++.h>
#include "/home/kali/Pract_1/1//modAlphaCipher.h"
#include "/home/kali/Pract_1/1/modAlphaCipher.cpp"
#include "/home/kali/Pract_1/1//Exception.h"

SUITE(kl_tst)
{
    TEST(B) {
        modAlphaCipher test(L"АФЫАФЫАФЫ");
        CHECK(true);
    }

    TEST(mal) {
        modAlphaCipher test(L"паыпвпыавав");
        CHECK(true);
    }

    TEST(B_mal) {
        modAlphaCipher test(L"паарЕЦаВаВЫ");
        CHECK(true);
    }
    TEST(num) {
        CHECK_THROW(modAlphaCipher test(L"аы33пвы"),Error);
    }
    TEST(probel) {
        CHECK_THROW(modAlphaCipher test(L"а в"), Error);
    }
    TEST(simbol) {
        CHECK_THROW(modAlphaCipher test(L")паыв.(аы"),Error);
    }
    TEST(pusto) {
        CHECK_THROW(modAlphaCipher test(L""), Error);
    }



}

struct KeyAB_fixture { // Для тестов шифрования и расшифрования
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"АВД");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(enshifr)
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV ) {
        wstring open_text = L"ЗДАРОВА";
        wstring result_correct = L"ЗЁДРРЁА";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki ) {
        wstring open_text = L"здарова";
        wstring result_correct = L"ЗЁДРРЁА";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig ) {
        wstring open_text = L"ЗдАОРОваПацаНы";
        wstring result_correct = L"ЗЁДОТТВВУАШДНЭ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota ) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num) {
        wstring open_text = L"ЗДАРОВА123";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring open_text = L"ЗДАРО*ВА";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring open_text = L"ЗДА РОВА";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }

}
SUITE(decshifr)
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV) {
        wstring cipher_text = L"ЗЁДРРЁА";
        wstring result_correct = L"ЗДАРОВА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki) {
        wstring cipher_text = L"ЗЁДРРЁА";
        wstring result_correct = L"здарова";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig) {
        wstring cipher_text = L"ЗЁДОТТВВУАШДНЭ";
        wstring result_correct = L"ЗдАОРОваПацаНы";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num ) {
        wstring cipher_text = L"ЗДАРОВА123";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring cipher_text = L"ЗДАРО*ВА";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring cipher_text = L"ЗДА РОВА";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
