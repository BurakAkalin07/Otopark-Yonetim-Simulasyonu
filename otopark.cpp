#include "otopark.hpp"
#include <iostream>

using namespace std;

Otopark::Otopark(int kapasite)
{
    this->otoparkKapasitesi = kapasite;
    parkYerleri = new Arac[kapasite];
    aracSayisi = 0;
    saatlikUcret = 50;
}

Otopark::~Otopark()
{
    delete[] parkYerleri;
}

void Otopark::aracGiris(string plaka, int saat)
{
    if(aracSayisi >= otoparkKapasitesi)
    {
        cout << "Otopark dolu!" << endl;
        return;
    }

    for(int i = 0; i < otoparkKapasitesi; i++)
    {
        if(parkYerleri[i].doluMu == false)
        {
            parkYerleri[i].plaka = plaka;
            parkYerleri[i].girisSaati = saat;
            parkYerleri[i].doluMu = true;
            aracSayisi++;
            cout << "Arac park edildi. Park No: " << i << endl;
            break;
        }
    }
}

void Otopark::aracCikis(string plaka, int saat)
{
    bool aracBulundu = false;

    for(int i = 0; i < otoparkKapasitesi; i++)
    {
        if(parkYerleri[i].doluMu == true && parkYerleri[i].plaka == plaka)
        {
            
            int sure = saat - parkYerleri[i].girisSaati;
            if(sure <= 0) sure = 1;

            int ucret = sure * saatlikUcret;

            cout << endl;
            cout << "==================================" << endl;
            cout << "      ODEME EKRANI (" << plaka << ")" << endl;
            cout << "==================================" << endl;
            cout << "Sure: " << sure << " Saat" << endl;
            cout << "ODENMESI GEREKEN TUTAR: " << ucret << " TL" << endl;
            cout << "----------------------------------" << endl;

            
            int alinanPara;
            while(true)
            {
                cout << "Odemeyi Giriniz (TL): ";
                cin >> alinanPara;

                if(alinanPara >= ucret)
                {
                    int paraUstu = alinanPara - ucret;
                    cout << "\n>> Odeme Onaylandi. Para Ustu: " << paraUstu << " TL" << endl;
                    cout << ">> Iyi yolculuklar dileriz..." << endl;
                    cout << "==================================\n" << endl;
                    break; 
                }
                else
                {
                    cout << "! Yetersiz Bakiye !" << endl;
                    cout << "Eksik Tutar: " << ucret - alinanPara << " TL. Lutfen tam tutari giriniz." << endl;
                }
            }

           
            parkYerleri[i].doluMu = false;
            parkYerleri[i].plaka = "";
            aracSayisi--;
            aracBulundu = true;
            break;
        }
    }

    if(aracBulundu == false)
    {
        cout << "Hata: " << plaka << " plakali arac otoparkta bulunamadi!" << endl;
    }
}

void Otopark::durumGoster()
{
    cout << endl;
    for(int i = 0; i < otoparkKapasitesi; i++)
    {
        if(i != 0 && i % 5 == 0) cout << endl;

        if(parkYerleri[i].doluMu)
        {
            cout << "[" << parkYerleri[i].plaka << "]\t";
        }
        else
        {
            cout << "[ BOS ]\t";
        }
    }
    cout << endl;
}