#include<iostream>
#include <cstdlib>    //knihovna pro pause
using namespace std;
int main()
{
    setlocale(LC_ALL, ""); //čeština - psal jsem to ve visual studiu
    int pocet_sirek = 0;
    int hrac1 = 0;
    int hrac2 = 0;
    int x = 0;
    bool status_hrace = false;   //pomocí true a false později rozlišíme kdy hraje hráč 1 a hráč 2

    if (pocet_sirek == 0) {    //dokud není zapsaný počet sirek, bude program vyzívat uživatele k zadání výchozího počtu pro hru
        cout << "První hráči, zadej výchozí počet sirek (celé číslo): \n";
        cin >> pocet_sirek;  //nastaví defaultní počet sirek
        cout << "Děkuji, hra může začít! \n";
    }
    while (pocet_sirek >= 2) {   //dokud zbude 2 nebo více sirek, hra pokračuje

        cout << (status_hrace ? "Hraje první hráč:\n" : "Hraje druhý hráč:\n"); //pokud je status hráče true - hraje první, pokud false hraje druhý
        cout << " Kolik si bereš sirek?\n";
        cin >> x;
        //zapíšeme do proměnné x, od té se bude potom odvíjet odčítaní sirek a sčítat počet odebraných sirek hráčem v hrac1 a hrac2
        if (x > pocet_sirek) {
            cout << "ERROR: Snažíš se odebrat více sirek než jich máš :D, zkus to znovu!" << endl;
            x = 0; //když hráč zadá špatně, nebude se s zapsanou hodnotou nic dělat - vynuluje se input

        }
        else if (x <= 0) {
            cout << "ERROR: Zadal jsi neplatný počet sirek k odebrání :/, zkus to znovu!" << endl;
            x = 0;  //když hráč zadá špatně, nebude se s zapsanou hodnotou nic dělat - vynuluje se input
        }
        else if (x == pocet_sirek) {
            cout << "ERROR: Zadal jsi počet sirek shodný s celkovým počtem sirek :P, zkus to znovu!" << endl;
            x = 0;
        }
        pocet_sirek -= x;  //odečteme zadaný počet sirek od námi zadané výchozí hodnoty
        cout << "Máš ještě " << pocet_sirek << " sirek!" << endl;

        if (status_hrace == false) {
            hrac2 += x;   //hráči 2 dám do statistik počet zadaných sirek
            status_hrace = true;  //přehodíme status hráče, aby mohl teď hrát první hráč (pokud true - hraje první, pokud false hraje druhý - pod. operator na zacatku)
            x = 0; //vynulujeme vstup pro jiného hráče (aby se mu nepřičítala hodnota minulého hráče | neodčítala hodnota sirek + jiný hráč)
        }
        else {
            hrac1 += x;                //to stejné jak s hráčem 2, akorát teď pro 1. hráče
            status_hrace = false;
            x = 0;
        }
    }
    cout << "\n Výsledky:" << endl;
    cout << "Hráč1: " << hrac1 << " sirek" << endl;   //vypíše počet sirek z proměnných pro hráče
    cout << "hráč2: " << hrac2 << " sirek" << endl;
    cout << endl;
    if (hrac1 > hrac2) {                                      //výpis kdo vyhrál podle podmínek
        cout << "Vyhrává první hráč! Gratuluji! ;)" << endl;   //pokud měl hráč 1 větší skóre, pogratulujeme mu
    }
    else if (hrac1 < hrac2) {   //pokud měl 2. hráč větší skóre (víc odebraných sirek) - pogratulujeme mu
        cout << "Vyhrává druhý hráč! Gratuluji! ;)" << endl;
    }
    else if (hrac1 == hrac2) {   //Pokud mají hráč1 a hráč 2 stejný počet bodů - Vypíše se remíza
        cout << "Remíza!" << endl;
    }
    system("pause");
}