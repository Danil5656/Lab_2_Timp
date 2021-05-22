#include <UnitTest++/UnitTest++.h>
#include "/home/kali/Pract_1/2/Cipher.h"
#include "/home/kali/Pract_1/2/Cipher.cpp"
#include "/home/kali/Pract_1/2/Exception.h"
#include "/home/kali/Pract_1/2/Exception.cpp"
SUITE(EncodeCipher)
{
    const int key = 4;
    Cipher test(key);
    TEST(BOLSHIE_BUKV) {
        wstring open_text = L"ЗДАРОВА";
        wstring result_correct = L"ЗОДВААР";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(mahonkie_bukovki) {
        wstring open_text = L"здарова";
        wstring result_correct = L"зодваар";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(BIG_L) {
        wstring open_text = L"FASFAFAFDFSA";
        wstring result_correct = L"FADAFFSASFFA";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(mini_l) {
        wstring open_text = L"gsdgsdgqgqrgqgq";
        wstring result_correct = L"gsgqsdqgdgrqgqg";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(mix_bukv_an_letters) {
        wstring open_text = L"здаfeafsa";
        wstring result_correct = L"зeaдa аf fs";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(special) {
        wstring open_text = L"*&$@$$@$%!";
        wstring result_correct = L"*$%&$!$@ @$";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(cifri) {
        wstring open_text = L"532145321421";
        wstring result_correct = L"541354232121";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(all_simbols) {
        wstring open_text = L"Gs rwq13$@37ауф";
        wstring result_correct = L"Gw$аsq@у 13фr37";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
}
SUITE(decshifr)
{
    const int key = 4;
    Cipher test(key);
    TEST(B) {
        wstring cipher_text = L"ЗОДВААР";
        wstring result_correct = L"ЗДАРОВА";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(m) {
        wstring cipher_text = L"зодваар";
        wstring result_correct = L"здарова";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(Eng) {
        wstring cipher_text = L"FASFAFAFDFSA";
        wstring result_correct = L"FADAFFSASFFA";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(min) {
        wstring cipher_text = L"gsdgsdgqgqrgqgq";
        wstring result_correct = L"gsgqsdqgdgrqgqg";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(mix) {
        wstring cipher_text = L"здаfeafsa";
        wstring result_correct = L"зeaдa аf fs";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(simvol) {
        wstring cipher_text = L"*&$@$$@$%!";
        wstring result_correct = L"*$%&$!$@ @$ ";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(cifr) {
        wstring cipher_text = L"532145321421";
        wstring result_correct = L"541354232121";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(all) {
        wstring cipher_text = L"Gs rwq13$@37ауф";
        wstring result_correct = L"Gw$аsq@у 13фr37";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
}
SUITE(excst)
{
    TEST(st_rus) {
        CHECK_EQUAL(7, Error::Check_s("русский"));
    }
    TEST(st_eng) {
        CHECK_EQUAL(7, Error::Check_s("english"));
      
    }
    TEST(mix_st_rus_eng) {
        CHECK_EQUAL(7, Error::Check_s("Русский english"));
        
    }
    TEST(all_simbols) {
        CHECK_EQUAL(7, Error::Check_s("gdsgds_22амвымвы?21"));
        
    }
    TEST(pustota) {
        CHECK_THROW(Error::Check_s(""),Error);
    }
}

SUITE(exckl)
{
    wstring test = L"client";
    TEST(praviln_kl) {
        CHECK_EQUAL(7, Error::Check_k (test,"3"));
    }
    TEST(non_nature_kl) {
        CHECK_THROW(Error::Check_k (test,"-2"),Error);
    }
    TEST(mix_kl) {
        CHECK_THROW(Error::Check_k (test,"sdfsdfss2312"),Error);
    }
    TEST(pustota_kl) {
        CHECK_THROW(Error::Check_k (test,""),Error);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
