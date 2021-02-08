#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "schema.hpp"
#include <fstream>
#include <istream>



class DB
{
    public:
    std::vector<Client> client;
    std::vector<Company> company;
    std::vector<Addresses> addresses;
    
    friend std::ostream& operator<<(std::ostream& os, const Client& clnt);
    friend std::ostream& operator<<(std::ostream& os, const Company& cmpn);
    friend std::ostream& operator<<(std::ostream& os, const Addresses& adrs);

    DB();
    ~DB();
};
DB::DB()
{
    this->client = client;
    this->company = company;
    this->addresses = addresses;
}
DB::~DB()
{
    std::cout << "Instancja klasy DB została pomyślnie wypierdolona"<<std::endl;
};
std::ostream& operator<<(std::ostream& os, const Client& clnt)
{
    // |  id | first_name |  last_name |              email | del | cmpn_id | adrs_id |
    std::cout 
    << "| " << std::setw(3) << clnt.id_client 
    << " | " << std::setw(10) << clnt.first_name 
    << " | " << std::setw(10) << clnt.last_name 
    << " | " << std::setw(18) << clnt.email 
    << " | " << std::setw(3) << clnt.is_deleted 
    << " | " << std::setw(7) << clnt.company_id 
    << " | " << std::setw(7) << clnt.address_id 
    << " |" << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Company& cmpn)
{
    // |  id |                     name |        nip |          regon | del | adrs_id |
    std::cout 
    << "| " << std::setw(3) << cmpn.id_company 
    << " | " << std::setw(24) << cmpn.name 
    << " | " << std::setw(10) << cmpn.nip 
    << " | " << std::setw(14) << cmpn.regon 
    << " | " << std::setw(3) << cmpn.is_deleted 
    << " | " << std::setw(7) << cmpn.address_id 
    << " |" << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Addresses& adrs)
{
    //|  id |  country |               state |       city |            address | del |
    std::cout 
    << "| " << std::setw(3) << adrs.id_address 
    << " | " << std::setw(8) << adrs.country 
    << " | " << std::setw(19) << adrs.state 
    << " | " << std::setw(10) << adrs.city 
    << " | " << std::setw(18) << adrs.address 
    << " | " << std::setw(3) << adrs.is_deleted 
    << " |" << std::endl;
    return os;
}



void insertClient(DB *row)
{
    Client client;
    std::cout << "Wprowadź klienta" << std::endl;
    client.id_client = row->client.size() + 1;
    std::cin.getline (client.first_name, 8);
    std::cin.getline (client.last_name, 19);
    std::cin.getline (client.email, 10);
    client.is_deleted = 0;
    client.company_id = row->company.size() + 1;
    client.address_id = row->addresses.size() + 1;
    row->client.push_back(client);
    std::cout << std::endl;
};
void insertCompany(DB *row)
{
    Company company;
    std::cout << "Wprowadź firmę" << std::endl;
    company.id_company = row->company.size() + 1;
    std::cin.getline (company.name, 8);
    std::cin.getline (company.nip, 19);
    std::cin.getline (company.regon, 10);
    company.is_deleted = 0;
    company.address_id = row->addresses.size() + 1;
    row->company.push_back(company);
    std::cout << std::endl;
};
void insertAddress(DB *row)
{
    Addresses addresses;
    std::cout << "Wprowadź adres firmy" << std::endl;
    addresses.id_address = row->addresses.size() + 1;
    std::cin.getline (addresses.country, 8);
    std::cin.getline (addresses.state, 19);
    std::cin.getline (addresses.city, 10);
    std::cin.getline (addresses.address, 18);
    addresses.is_deleted = 0;
    row->addresses.push_back(addresses);
    std::cout << std::endl;
};
void selectClient(DB *rows, size_t sizeRowsClient)
{
    std::cout << " ============================================================================== " << std::endl;
    std::cout << "| Tabela: Client                                                               |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
    std::cout 
    << "| " << std::setw(3) << "Id" 
    << " | " << std::setw(10) << "First name" 
    << " | " << std::setw(10) << "Last name" 
    << " | " << std::setw(18) << "Email" 
    << " | " << std::setw(3) << "Del" 
    << " | " << std::setw(7) << "Cmpn_id" 
    << " | " << std::setw(7) << "Adrs_id" 
    << " |" << std::endl;
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    for (Client clnt : rows->client) {
        std::cout << clnt;
    }
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    std::cout 
    << "| " << std::setw(75) <<"Ilość rekordów: "
    << " " << std::setw(3) << sizeRowsClient
    << " |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
};
void selectCompany(DB *rows, size_t sizeRowsCompany)
{
    std::cout << " ============================================================================== " << std::endl;
    std::cout << "| Tabela: Company                                                              |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
    std::cout << std::setfill (' ');
    std::cout 
    << "| " << std::setw(3) << "Id" 
    << " | " << std::setw(24) << "Name" 
    << " | " << std::setw(10) << "NIP" 
    << " | " << std::setw(14) << "REGON" 
    << " | " << std::setw(3) << "Del" 
    << " | " <<  std::setw(7) << "Addr_id"
    << " |" << std::endl;
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    for (Company cmpn : rows->company) {
        std::cout << cmpn;
    }
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    std::cout 
    << "| " << std::setw(75) <<"Ilość rekordów: "
    << " " << std::setw(3) << sizeRowsCompany
    << " |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
};
void selectAddresses(DB *rows, size_t sizeRowsAddresses)
{
    std::cout << " ============================================================================== " << std::endl;
    std::cout << "| Tabela: Addresses                                                            |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
    std::cout 
    << "| " << std::setw(3) << "Id" 
    << " | " << std::setw(8) << "Country" 
    << " | " << std::setw(19) << "State" 
    << " | " << std::setw(10) << "City" 
    << " | " << std::setw(18) << "Address" 
    << " | " << std::setw(3) << "Del" 
    << " |" << std::endl;
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    for (Addresses adrs : rows->addresses) {
        std::cout << adrs;
    }
    std::cout << " ------------------------------------------------------------------------------ " << std::endl;
    std::cout 
    << "| " << std::setw(75) <<"Ilość rekordów: "
    << " " << std::setw(3) << sizeRowsAddresses
    << " |" << std::endl;
    std::cout << " ============================================================================== " << std::endl;
};
void writeClientTable(std::ofstream* out, size_t sizeRowsClient, DB *rows)
{
    // Zapis zawartości tabeli Client; typ std::vector; instancja DB::rows
    out->write((char*)&sizeRowsClient, sizeof(sizeRowsClient));
    out->write((char*)&rows->client[0], (double)sizeRowsClient * sizeof(Client));
    
};
void writeCompanyTable(std::ofstream* out, size_t sizeRowsCompany, DB *rows)
{
    // Zapis zawartości tabeli Company; typ std::vector; instancja DB::rows
    out->write((char*)&sizeRowsCompany, sizeof(sizeRowsCompany));
    out->write((char*)&rows->company[0], (double)sizeRowsCompany * sizeof(Company));
    
};
void writeAddressesTable(std::ofstream* out, size_t sizeRowsAddresses, DB *rows)
{
    // Zapis zawartości tabeli Addresses; typ std::vector; instancja DB::rows
    out->write((char*)&sizeRowsAddresses, sizeof(sizeRowsAddresses));
    out->write((char*)&rows->addresses[0], (double)sizeRowsAddresses * sizeof(Addresses));
    
};
void writeDB(std::string databasePath, DB *rows, size_t sizeRowsClient, size_t sizeRowsCompany, size_t sizeRowsAddresses)
{
    // Otworzenie pliku w trybie binarnym i zapis danych
    std::ofstream out(databasePath, std::ios::out | std::ios::binary);
    writeClientTable(&out, sizeRowsClient, rows);
    rows->client.clear(); //Wypierdolenie wszystkich elementów z vectora
    writeCompanyTable(&out, sizeRowsCompany, rows);
    rows->company.clear(); //Wypierdolenie wszystkich elementów z vectora
    writeAddressesTable(&out, sizeRowsAddresses, rows);
    rows->addresses.clear(); //Wypierdolenie wszystkich elementów z vectora
    // Zamknięcie pliku
    out.close();
};
void readClientTable(std::ifstream *in, size_t &sizeRowsClient, DB &rows)
{
    // Odczyt zawartości tabeli Client; typ std::vector; instancja DB::rows2
    in->read((char*)&sizeRowsClient, sizeof(sizeRowsClient));
    rows.client.resize(sizeRowsClient);
    in->read((char*)&rows.client[0], (double)rows.client.size() * sizeof(Client));
}
void readCompanyTable(std::ifstream *in, size_t &sizeRowsCompany, DB &rows)
{
    // Odczyt zawartości tabeli Company; typ std::vector; instancja DB::rows2
    in->read((char*)&sizeRowsCompany, sizeof(sizeRowsCompany));
    rows.company.resize(sizeRowsCompany);
    in->read((char*)&rows.company[0], (double)rows.company.size() * sizeof(Company));
}
void readAddressesTable(std::ifstream *in, size_t &sizeRowsAddresses, DB &rows)
{
    // Odczyt zawartości tabeli Addresses; typ std::vector; instancja DB::rows2
    in->read((char*)&sizeRowsAddresses, sizeof(sizeRowsAddresses));
    rows.addresses.resize(sizeRowsAddresses);
    in->read((char*)&rows.addresses[0], (double)rows.addresses.size() * sizeof(Addresses));
}
void readDB(std::string databasePath, DB &rows, size_t &sizeRowsClient, size_t &sizeRowsCompany, size_t &sizeRowsAddresses)
{
    // Otworzenie pliku w trybie binarnym i odczyt danych
    std::ifstream in(databasePath, std::ios::in | std::ios::binary);
    readClientTable(&in, sizeRowsClient, rows);
    readCompanyTable(&in, sizeRowsCompany, rows);
    readAddressesTable(&in, sizeRowsAddresses, rows);
    // Zamknięcie pliku
    in.close();
};



int main(int argc, char** argv)
{
    std::string databasePath = "";
    // Walidacja poprawnego uruchomienia programu
    // Rozważyć/zaimplementować możliwość stworzenia nowej bazy danych dla (argc < 2)
    if (argc == 2) {
        databasePath = argv[1];
        std::cout << "Lokalizacja bazy danych: " << argv[1] << std::endl;
    } else if (argc > 2) {
        std::cout << "Wprowadzono zbyt wiele parametrów przy uruchomieniu!" << std::endl;
        return 1;
    } else if (argc < 2) {
        std::cout << "Nie wprowadzono parametru stanowiącego ścieżkę dostępu do bazy danych!" << std::endl;
        return 1;
    }

    // Utworzenie nowej instancji (rows) klasy DB:
    DB *rows = new DB();

    // Przygotowanie danych do wrzutu
    Addresses addr = {1, "Polska", "Zachodniopomorskie", "Koszalin", "Sezamkowa 1A/24", 0};
    Addresses addr2 = {2, "Polska", "Mazowieckie", "Sosnowiec", "Turkusowa 13C", 0};
    Client cli = {1, "Krzysztof", "Jarzyna", "k.jarzyna@corp.com", 0, 1, 1};
    Company com = {1, "Corp", "0123456789", "012345678", 0, 2};

    // Wrzut zawartości tabel
    rows->addresses.push_back(addr);
    rows->addresses.push_back(addr2);
    rows->client.push_back(cli);
    rows->company.push_back(com);

    // Wrzut danych od użytkownika
    insertClient(rows);
    insertCompany(rows);
    insertAddress(rows);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach przed zapisem: Addresses, Client, Company typu std::vector
    size_t sizeRowsAddresses = rows->addresses.size();
    size_t sizeRowsClient = rows->client.size();
    size_t sizeRowsCompany = rows->company.size();
    std::cout << "Ilość rekordów w tabelach przed zapisem do pliku:" << std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Addresses:" << sizeRowsAddresses <<std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Client:" << sizeRowsClient <<std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Company:" << sizeRowsCompany <<std::endl;

    // Zapis danych do pliku bazy danych
    writeDB(databasePath, rows, sizeRowsClient, sizeRowsCompany, sizeRowsAddresses);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach po zapisie: Addresses, Client, Company typu std::vector
    sizeRowsAddresses = rows->addresses.size();
    sizeRowsClient = rows->client.size();
    sizeRowsCompany = rows->company.size();
    std::cout << "Ilość rekordów w tabelach po zapisie do pliku:" << std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Addresses:" << sizeRowsAddresses <<std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Client:" << sizeRowsClient <<std::endl;
    std::cout << "DB::rows \t => Ilość rekordów w tabeli Company:" << sizeRowsCompany <<std::endl;
    // Usunięcie instancji (rows) klasy DB:
    delete rows;



    // Utworzenie nowej instancji (rows) klasy DB:
    DB *rows2 = new DB();

    // Instancja rows: Ilość rekordów w poszczególnych tablicach przed odczytem: Addresses, Client, Company typu std::vector
    size_t sizeRows2Addresses = rows2->addresses.size();
    size_t sizeRows2Client = rows2->client.size();
    size_t sizeRows2Company = rows2->company.size();
    std::cout << "Ilość rekordów w tabelach przed odczytem z pliku:" << std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Client:" << sizeRows2Client <<std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Company:" << sizeRows2Company <<std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Addresses:" << sizeRows2Addresses <<std::endl;

    // Odczyt danych z pliku bazy danych
    readDB(databasePath, *rows2, sizeRows2Client, sizeRows2Company, sizeRows2Addresses);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach po odczycie: Addresses, Client, Company typu std::vector
    selectClient(rows2, sizeRows2Client);
    selectCompany(rows2, sizeRows2Company);
    selectAddresses(rows2, sizeRows2Addresses);
    std::cout << "Ilość rekordów w tabelach po odczycie z pliku:" << std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Client:" << sizeRows2Client <<std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Company:" << sizeRows2Company <<std::endl;
    std::cout << "DB::rows2 \t => Ilość rekordów w tabeli Addresses:" << sizeRows2Addresses <<std::endl;

    // Usunięcie instancji (rows2) klasy DB:
    delete rows2;



    // Utworzenie nowej instancji (rows) klasy DB:
    DB *rows3 = new DB();

    // Przygotowanie danych do wrzutu
    Addresses addr3 = {1, "Polska", "Zachodniopomorskie", "Koszalin", "Sezamkowa 1A/24", 0};
    Addresses addr4 = {2, "Polska", "Mazowieckie", "Sosnowiec", "Turkusowa 13C", 0};
    Client cli2 = {1, "Krzysztof", "Jarzyna", "k.jarzyna@corp.com", 0, 1, 1};
    Company com2 = {1, "Corp", "0123456789", "012345678", 0, 2};

    // Wrzut zawartości tabel
    rows3->addresses.push_back(addr3);
    rows3->addresses.push_back(addr4);
    rows3->client.push_back(cli2);
    rows3->company.push_back(com2);

    // Wrzut danych od użytkownika
    insertClient(rows3);
    insertCompany(rows3);
    insertAddress(rows3);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach przed zapisem: Addresses, Client, Company typu std::vector
    size_t sizeRows3Addresses = rows3->addresses.size();
    size_t sizeRows3Client = rows3->client.size();
    size_t sizeRows3Company = rows3->company.size();
    std::cout << "Ilość rekordów w tabelach przed zapisem do pliku:" << std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Addresses:" << sizeRows3Addresses <<std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Client:" << sizeRows3Client <<std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Company:" << sizeRows3Company <<std::endl;

    // Zapis danych do pliku bazy danych
    writeDB(databasePath, rows3, sizeRows3Client, sizeRows3Company, sizeRows3Addresses);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach po zapisie: Addresses, Client, Company typu std::vector
    sizeRows3Addresses = rows3->addresses.size();
    sizeRows3Client = rows3->client.size();
    sizeRows3Company = rows3->company.size();
    std::cout << "Ilość rekordów w tabelach po zapisie do pliku:" << std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Client:" << sizeRows3Client <<std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Company:" << sizeRows3Company <<std::endl;
    std::cout << "DB::rows3 \t => Ilość rekordów w tabeli Addresses:" << sizeRows3Addresses <<std::endl;

    // Usunięcie instancji (rows) klasy DB:
    delete rows3;



    // Utworzenie nowej instancji (rows) klasy DB:
    DB *rows4 = new DB();

    // Instancja rows: Ilość rekordów w poszczególnych tablicach przed odczytem: Addresses, Client, Company typu std::vector
    size_t sizeRows4Addresses = rows4->addresses.size();
    size_t sizeRows4Client = rows4->client.size();
    size_t sizeRows4Company = rows4->company.size();
    std::cout << "Ilość rekordów w tabelach przed odczytem z pliku:" << std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Client:" << sizeRows4Client <<std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Company:" << sizeRows4Company <<std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Addresses:" << sizeRows4Addresses <<std::endl;

    // Odczyt danych z pliku bazy danych
    readDB(databasePath, *rows4, sizeRows4Client, sizeRows4Company, sizeRows4Addresses);

    // Instancja rows: Ilość rekordów w poszczególnych tablicach po odczycie: Addresses, Client, Company typu std::vector
    selectClient(rows4, sizeRows4Client);
    selectCompany(rows4, sizeRows4Company);
    selectAddresses(rows4, sizeRows4Addresses);
    std::cout << "Ilość rekordów w tabelach po odczycie z pliku:" << std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Client:" << sizeRows4Client <<std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Company:" << sizeRows4Company <<std::endl;
    std::cout << "DB::rows4 \t => Ilość rekordów w tabeli Addresses:" << sizeRows4Addresses <<std::endl;

    // Usunięcie instancji (rows2) klasy DB:
    delete rows4;

    return 0;
}