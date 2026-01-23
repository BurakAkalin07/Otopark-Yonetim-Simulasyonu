#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "arac.hpp"
#include "otopark.hpp"

using namespace std;

string rastgelePlakaUret()
{
    int sehirKodu = rand() % 81 + 1;
    
    string harfler = "";
    int harfSayisi = rand() % 2 + 2;
    for(int i=0; i<harfSayisi; i++) {
        harfler += (char)('A' + rand() % 26);
    }

    int sonRakamlar = rand() % 9000 + 100;

    string plaka = to_string(sehirKodu) + " " + harfler + " " + to_string(sonRakamlar);
    
    if(sehirKodu < 10) plaka = "0" + plaka;

    return plaka;
}

int main()
{
    srand(time(0));

    int kapasite;
    cout << "OTOPARK YONETIM SISTEMI" << endl;
    cout << "Kapasite giriniz: ";
    cin >> kapasite;

    Otopark otoparkim(kapasite);
    otoparkim.saatlikUcret = 50;

    int secim;
    while(true)
    {
        cout << "\n1. Manuel Giris" << endl;
        cout << "2. Rastgele Giris" << endl;
        cout << "3. Cikis Yap" << endl;
        cout << "4. Durum Goster" << endl;
        cout << "0. Cikis" << endl;
        cout << "Secim: ";
        cin >> secim;

        if(secim == 0) break;
        
        else if(secim == 1)
        {
            string plaka;
            int saat;
            
            cout << "Plaka: ";
            
            cin.ignore(); 
            
            getline(cin, plaka); 

            cout << "Saat: ";
            cin >> saat;

            
            if(cin.fail()) 
            {
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cout << "HATA: Saat icin gecerli bir sayi girmediniz!" << endl;
            }
            else
            {
                otoparkim.aracGiris(plaka, saat);
            }
        }
        else if(secim == 2)
        {
            int saat;
            cout << "Saat: ";
            cin >> saat;
            string rstPlaka = rastgelePlakaUret();
            cout << "Uretilen Plaka: " << rstPlaka << endl;
            otoparkim.aracGiris(rstPlaka, saat);
        }
        else if(secim == 3)
        {
            otoparkim.durumGoster();
            string plaka;
            int saat;
            cout << "\nCikis Plakasi: ";
            cin.ignore();
            getline(cin, plaka);
            cout << "Saat: ";
            cin >> saat;
            otoparkim.aracCikis(plaka, saat);
        }
        else if(secim == 4)
        {
            otoparkim.durumGoster();
        }
    }

    return 0;
}