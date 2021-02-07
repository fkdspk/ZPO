#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class Klient {
private:
    int id;
    string imie;
    string nazwisko;
    string ulica;
    string miasto;
    int firma_id;

public:
    void set(string a, string b, string c, string d, string e, string f) {
        id = stoi(a);
        imie = b;
        nazwisko = c;
        ulica = d;
        miasto = e;
        firma_id = stoi(f);
    }
    
    void wyswietl(){
        cout << id << " " << imie << " " << nazwisko << " " << ulica << " " << miasto << " " << firma_id << endl;
    }

};

class File {
private:
    fstream plik;
    string linia;
    int count;
    Klient* bazka = new Klient[count];

public:
   
    File(string x) {
        plik.open(x);
        getline(plik, linia);
        count = stoi(linia);
    }

    int ile() {
        return count;
    }
        
    Klient* wczytaj() {
        Klient* db = new Klient[count];
        for (int i = 0; i < count; i++)
        {
            getline(plik, linia);
            vector<string> result;
            stringstream ss(linia);

            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                result.push_back(substr);
            }
            db[i].set(result[0], result[1], result[2], result[3], result[4], result[5]);
        }
        bazka = db;
        return db;
    }
};

class Database:public File {
private:
    

};

int main()
{
    int z;
  
  
    string nazwa = "plik.stefan";
    File otworz(nazwa);
    Klient* baza_danych = otworz.wczytaj();
    int wiersze = otworz.ile();
    cout << "BAZA DANYCH: " << endl << endl;
    for (int i = 0; i < wiersze; i++)
        baza_danych[i].wyswietl();


 
    return 0;
}
