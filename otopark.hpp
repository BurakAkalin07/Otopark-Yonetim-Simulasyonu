#ifndef OTOPARK_HPP
#define OTOPARK_HPP

#include <string>
#include "arac.hpp"

using namespace std;

class Otopark
{
    private:
        Arac* parkYerleri;
        int otoparkKapasitesi;
        int aracSayisi;

    public:
        int saatlikUcret;

        Otopark(int kapasite);
        ~Otopark();

        void aracGiris(string plaka, int saat);
        void aracCikis(string plaka, int saat);
        void durumGoster();
};

#endif