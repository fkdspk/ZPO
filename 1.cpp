// ZPO_DB.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>

class Hello
{
public:
    std::string name;
    std::string get()
    {
        return name;
    }
    Hello()
    {
        name = "ALBO NIE";
    };
    Hello(std::string nameValue)
    {
        name = nameValue;
    };
};

/*
obiekt =
typy odpowiadaj¹ce kolumnom + schema tego obiektu cont nazwy kolumn, ilosc kolumn, array z rekordami

tablica obiektow:
schema tego obiektu cont nazwy kolumn, ilosc kolumn, array z rekordami
--
obiekt_rekordu1
obiekt rekordu2

obiekt->edycja->rekord(id)
*/
/*

=====
@TABELANAZWA
=====
id;ime;nazwisko;tralalala
=====
1;franek;zbigniewski;arsobajestlysyxD
2;trevor;jakistam;arsobajestjegoidolem
3;ryszard;rumun;jebacpis
=====
@TABELAINNANAZWA
=====
id;miasto;kod;adres;
*/
/*
Class DBHanSolo
{
public:
    std::string dbname = ""
    std::string path = "C:\hui-wi-dzie\";
    load(nazwa pliku)
    save()
private:
    DBHanSolo clientSchema;
    clientTable;
    companySchema;
    companyTable;
    addressesSchema;
    addressesTable;
};

class Client
{

};

Client::zaprzyja¿nisz siê Z DBHanSolo??
*/


std::string
getFileContent(const std::string& path)
{
    std::ifstream file(path);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return content;
}

int main_test()
{
    Hello* hjjey = new Hello();
    hjjey->name = "JEBAC PIS";
    std::cout << "Hello " << hjjey->name << std::endl;
    delete hjjey;

    Hello* hey = new Hello("JEBAC PO");
    std::cout << "Hello " << hey->name << std::endl;
    delete hey;

    Hello hello2;
    hello2.name = "Hiujk";
    std::cout << "Hello " << hello2.name << std::endl;
    /*DBHanSolo addressesSchema = new DBHanSolo.addressesSchema;???*/

    //std::cout << getFileContent("C:\\Users\\dariu\\source\\repos\\ZPO_DB\\database.stefan");


    /*
    *
    * https://medium.com/@zekumorudoragonhatto/how-to-work-with-binary-files-in-c-520a852ee04a
    *
    * ios::in means that we’ll be handling input to this file such as writing data.
    * ios::out means that we’ll be taking or reading the contents of this file.
    * ios::binary means that we specifically tell that we’ll be working with binaries, why? Because, by default, fstream object works with text.
    * ios::trunc means that we want this file to be empty, if the file sample.bin already exists, ios::trunc will discard everything inside the file. You can think of ios::trunc like the clear() function of a string object.
    *
    */

    std::string pathDB = "C:\\Users\\dariu\\source\\repos\\ZPO_DB\\db.stefan";
    std::fstream db(pathDB, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (db.is_open()) {
        // some code...
        db.close();
    }
    else {
        std::cout << "Error! File cannot be opened!" << std::endl;
    }


    /*
    *
    * https://medium.com/@zekumorudoragonhatto/how-to-work-with-binary-files-in-c-520a852ee04a
    *
    * seekp(x) moves our put/reading cursor by x. It can be negative.
    * tellp() tells the current position of our reading cursor.
    * seekg(x) moves our get/writing cursor by x. It can be negative.
    * tellg() tells the current position of our writing cursor.
    *
    */
    char str[20] = "Hello world!";
    db.write(str, 20);
    // sample.bin:
    // Hello world!\0\0\0\0\0\0\0\0

    char str2[20];
    db.seekp(0, std::ios_base::beg);
    db.read(str2, 20);
    std::cout << str2 << std::endl;
    // console:
    // Hello Everyone!
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz¹ce rozpoczynania pracy:
//   1. U¿yj okna Eksploratora rozwi¹zañ, aby dodaæ pliki i zarz¹dzaæ nimi
//   2. U¿yj okna programu Team Explorer, aby nawi¹zaæ po³¹czenie z kontrol¹ Ÿród³a
//   3. U¿yj okna Dane wyjœciowe, aby sprawdziæ dane wyjœciowe kompilacji i inne komunikaty
//   4. U¿yj okna Lista b³êdów, aby zobaczyæ b³êdy
//   5. Wybierz pozycjê Projekt > Dodaj nowy element, aby utworzyæ nowe pliki kodu, lub wybierz pozycjê Projekt > Dodaj istniej¹cy element, aby dodaæ istniej¹ce pliku kodu do projektu
//   6. Aby w przysz³oœci ponownie otworzyæ ten projekt, przejdŸ do pozycji Plik > Otwórz > Projekt i wybierz plik sln
