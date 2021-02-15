#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
class Client
{
public:
    int idClient;
    std::string firstName;
    std::string lastName;
    std::string email;
    bool gender;                // true:false => male:female
    bool softDel;               // true:false => hide:show
    int companyId;
    int addressId;
    Client();
};
Client::Client()
{
    idClient = 0;
    firstName = "";             // default => empty
    lastName = "";              // default => empty
    email = "";                 // default => empty
    gender = false;             // default => male
    softDel = false;            // default => show
    companyId = 0;
    addressId = 0;
};
class Company
{
public:
    int idCompany;
    std::string name;
    std::string nip;
    std::string regon;
    std::string krs;
    bool deletedFromREGON;      // true:false => yes:no
    bool softDel;               // true:false => hide:show
    int addressId;
    Company();
};
Company::Company()
{
    idCompany = 0;
    name = "";                  // default => empty
    nip = "";                   // default => empty
    regon = "";                 // default => empty
    krs = "";                   // default => empty
    deletedFromREGON = false;   // default => no
    softDel = false;            // default => show
    addressId = 0;
};
class Address
{
public:
    int idAddress;
    std::string country;
    std::string state;
    std::string county;
    std::string community;
    std::string town;
    std::string street;
    std::string propertyNo;
    std::string apartmentNo;
    std::string postCode;
    std::string postalTown;
    bool softDel;               // true:false => hide:show
    Address();
};
Address::Address()
{
    idAddress = 0;
    country = "";               // default => empty
    state = "";                 // default => empty
    county = "";                // default => empty
    community = "";             // default => empty
    town = "";                  // default => empty
    street = "";                // default => empty
    propertyNo = "";            // default => empty
    apartmentNo = "";           // default => empty
    postCode = "";              // default => empty
    postalTown = "";            // default => empty
    softDel = false;            // default => show
};
class Database
{
public:
    std::vector<Client> clients;
    std::vector<Company> companies;
    std::vector<Address> addresses;
public:
    Database();
    ~Database();
    template <typename tableName>
    void truncateTable(std::vector<tableName>& table);
    template <typename tableName>
    void updateRow(tableName& row, tableName &newValue);
    template <typename tableName>
    void insertRow(std::vector<tableName> &table, const tableName &newRow);
    template <typename tableName>
    void softDeleteRow(tableName& row);
    template <typename tableName>
    void sortTableAscBy(std::vector<tableName>& table, int columnName = 0, bool order = true);
    template <typename tableName>
    typename std::vector<tableName>::iterator findRowInTableByIndex(std::vector<tableName>& table, const int &index, std::string columnName = "idClient");
};
Database::Database()
{
    std::cout << "Baza danych została zaincjalizowana." << std::endl;
};
Database::~Database()
{
    std::cout << "Instancja klasy Database została usunięta." << std::endl;
};
template <typename tableName>
void Database::truncateTable(std::vector<tableName>& table)
{
    table.clear();
};
template <typename tableName>
void Database::updateRow(tableName& row, tableName &newValue)
{
    if constexpr(std::is_same<tableName, Client>::value)
    {
        row.firstName           = newValue.firstName;
        row.lastName            = newValue.lastName;
        row.email               = newValue.email;
        row.gender              = newValue.gender;
        row.companyId           = newValue.companyId;
        row.addressId           = newValue.addressId;
    }
    else if constexpr(std::is_same<tableName, Company>::value)
    {
        row.name                = newValue.name;
        row.nip                 = newValue.nip;
        row.regon               = newValue.regon;
        row.krs                 = newValue.krs;
        row.deletedFromREGON    = newValue.deletedFromREGON;
        row.addressId           = newValue.addressId;
    }
    else if constexpr(std::is_same<tableName, Address>::value)
    {
        row.state               = newValue.state;
        row.county              = newValue.county;
        row.community           = newValue.community;
        row.town                = newValue.town;
        row.street              = newValue.street;
        row.propertyNo          = newValue.propertyNo;
        row.apartmentNo         = newValue.apartmentNo;
        row.postCode            = newValue.postCode;
        row.postalTown          = newValue.postalTown;
    }
};
template <typename tableName>
void Database::insertRow(std::vector<tableName> &table, const tableName &newRow)
{
    table.push_back(newRow);
};
template <typename tableName>
void Database::softDeleteRow(tableName& row)
{
    if constexpr(std::is_same<tableName, Client>::value)
    {
        row.softDel = true;
    }
    else if constexpr(std::is_same<tableName, Company>::value)
    {
        row.softDel = true;
    }
    else if constexpr(std::is_same<tableName, Address>::value)
    {
        row.softDel = true;
    }
};
template <typename tableName>
void Database::sortTableAscBy(std::vector<tableName>& table, int columnName, bool order)
{
    std::sort(table.begin(), table.end(), [columnName, order](tableName const &left, tableName const &right)
    {
        bool result;
        if constexpr(std::is_same<tableName, Client>::value)
        {
            switch (columnName)
            {
                
                case 1: //firstName
                    if (order)   // true: Ascending     false: Descending  
                        result = left.firstName < right.firstName;
                    else
                        result = left.firstName > right.firstName;
                    break;
                case 2: //lastName
                    if (order)   // true: Ascending     false: Descending
                        result = left.lastName < right.lastName;
                    else
                        result = left.lastName > right.lastName;
                    break;
                case 3: //email
                    if (order)   // true: Ascending     false: Descending
                        result = left.email < right.email;
                    else
                        result = left.email > right.email;
                    break;
                case 4: //gender
                    if (order)   // true: Ascending     false: Descending
                        result = left.gender < right.gender;
                    else
                        result = left.gender > right.gender;
                    break;
                case 5: //softDel
                    if (order)   // true: Ascending     false: Descending
                        result = left.softDel < right.softDel;
                    else
                        result = left.softDel > right.softDel;
                    break;
                case 6: //companyId
                    if (order)   // true: Ascending     false: Descending
                        result = left.companyId < right.companyId;
                    else
                        result = left.companyId > right.companyId;
                    break;
                case 7: //addressId
                    if (order)   // true: Ascending     false: Descending
                        result = left.addressId < right.addressId;
                    else
                        result = left.addressId > right.addressId;
                    break;
                default:
                    if (order)   // true: Ascending     false: Descending
                        result = left.idClient < right.idClient;
                    else
                        result = left.idClient > right.idClient;
                    break;
            }
            return result;
            //return left.idClient < right.idClient;
        }
        if constexpr(std::is_same<tableName, Company>::value)
        {
            return left.idCompany < right.idCompany;
        }
        if constexpr(std::is_same<tableName, Address>::value)
        {
            return left.idAddress < right.idAddress;
        }
    });
};
template <typename tableName>
typename std::vector<tableName>::iterator Database::findRowInTableByIndex(std::vector<tableName>& table, const int &index, std::string columnName)
{
    typename std::vector<tableName>::iterator row;
    row = std::find_if(table.begin(), table.end(), [index](tableName const & result)
    {
        if constexpr(std::is_same<tableName, Client>::value)
        {
            return result.idClient == index;
        }
        if constexpr(std::is_same<tableName, Company>::value)
        {
            return result.idCompany == index;
        }
        if constexpr(std::is_same<tableName, Address>::value)
        {
            return result.idAddress == index;
        }
    });
    return row;
};
class RenderDatabaseView
{
public:
    RenderDatabaseView();
    ~RenderDatabaseView();
    template <typename tableName>
    void selectFromTable(std::vector<tableName>& table);
    template <typename tableName>
    void selectRowFromTable(const tableName& row);
};
RenderDatabaseView::RenderDatabaseView()
{
    std::cout << "Widok baza danych został zaincjalizowany." << std::endl;
};
RenderDatabaseView::~RenderDatabaseView()
{
    std::cout << "Instancja klasy RenderDatabaseView została usunięta." << std::endl;
};
template <typename tableName>
void RenderDatabaseView::selectFromTable(std::vector<tableName>& table)
{
    if constexpr(std::is_same<tableName, Client>::value)
    {
        std::cout << "====================" << std::endl;
        std::cout << "DATABASE2::TABELA: clients" << std::endl;
        std::cout << "====================" << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout << "idClient: " << table.at(i).idClient << std::endl;
            std::cout << "firstName: " << table.at(i).firstName << std::endl;
            std::cout << "lastName: " << table.at(i).lastName << std::endl;
            std::cout << "email: " << table.at(i).email << std::endl;
            std::cout << "gender: " << table.at(i).gender << std::endl;
            std::cout << "softDel: " << table.at(i).softDel << std::endl;
            std::cout << "companyId: " << table.at(i).companyId << std::endl;
            std::cout << "addressId: " << table.at(i).addressId << std::endl;
            std::cout << "--------------------" << std::endl;
        }
    }
    else if constexpr(std::is_same<tableName, Company>::value)
    {
        std::cout << "====================" << std::endl;
        std::cout << "DATABASE2::TABELA: companies" << std::endl;
        std::cout << "====================" << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout << "idCompany: " << table.at(i).idCompany << std::endl;
            std::cout << "name: " << table.at(i).name << std::endl;
            std::cout << "nip: " << table.at(i).nip << std::endl;
            std::cout << "regon: " << table.at(i).regon << std::endl;
            std::cout << "krs: " << table.at(i).krs << std::endl;
            std::cout << "deletedFromREGON: " << table.at(i).deletedFromREGON << std::endl;
            std::cout << "softDel: " << table.at(i).softDel << std::endl;
            std::cout << "addressId: " << table.at(i).addressId << std::endl;
            std::cout << "--------------------" << std::endl;
        }
    }
    else if constexpr(std::is_same<tableName, Address>::value)
    {
        std::cout << "====================" << std::endl;
        std::cout << "DATABASE2::TABELA: addresses" << std::endl;
        std::cout << "====================" << std::endl;
        for (size_t i = 0; i < table.size(); i++)
        {
            std::cout << "idAddress: " << table.at(i).idAddress << std::endl;
            std::cout << "state: " << table.at(i).state << std::endl;
            std::cout << "county: " << table.at(i).county << std::endl;
            std::cout << "community: " << table.at(i).community << std::endl;
            std::cout << "town: " << table.at(i).town << std::endl;
            std::cout << "street: " << table.at(i).street << std::endl;
            std::cout << "propertyNo: " << table.at(i).propertyNo << std::endl;
            std::cout << "apartmentNo: " << table.at(i).apartmentNo << std::endl;
            std::cout << "postCode: " << table.at(i).postCode << std::endl;
            std::cout << "postalTown: " << table.at(i).postalTown << std::endl;
            std::cout << "softDel: " << table.at(i).softDel << std::endl;
            std::cout << "--------------------" << std::endl;
        }
    }
};
template <typename tableName>
void RenderDatabaseView::selectRowFromTable(const tableName& row)
{
    if constexpr(std::is_same<tableName, Client>::value)
    {
        std::cout << "idClient: " << row.idClient << std::endl;
        std::cout << "firstName: " << row.firstName << std::endl;
        std::cout << "lastName: " << row.lastName << std::endl;
        std::cout << "email: " << row.email << std::endl;
        std::cout << "gender: " << row.gender << std::endl;
        std::cout << "softDel: " << row.softDel << std::endl;
        std::cout << "companyId: " << row.companyId << std::endl;
        std::cout << "addressId: " << row.addressId << std::endl;
    }
    else if constexpr(std::is_same<tableName, Company>::value)
    {
        std::cout << "idCompany: " << row.idCompany << std::endl;
        std::cout << "name: " << row.name << std::endl;
        std::cout << "nip: " << row.nip << std::endl;
        std::cout << "regon: " << row.regon << std::endl;
        std::cout << "krs: " << row.krs << std::endl;
        std::cout << "deletedFromREGON: " << row.deletedFromREGON << std::endl;
        std::cout << "softDel: " << row.softDel << std::endl;
        std::cout << "addressId: " << row.addressId << std::endl;

    }
    else if constexpr(std::is_same<tableName, Address>::value)
    {

        std::cout << "idAddress: " << row.idAddress << std::endl;
        std::cout << "state: " << row.state << std::endl;
        std::cout << "county: " << row.county << std::endl;
        std::cout << "community: " << row.community << std::endl;
        std::cout << "town: " << row.town << std::endl;
        std::cout << "street: " << row.street << std::endl;
        std::cout << "propertyNo: " << row.propertyNo << std::endl;
        std::cout << "apartmentNo: " << row.apartmentNo << std::endl;
        std::cout << "postCode: " << row.postCode << std::endl;
        std::cout << "postalTown: " << row.postalTown << std::endl;
        std::cout << "softDel: " << row.softDel << std::endl;

    }
};
class FileHandler
{
private:
    std::string databasePath;
public:
    FileHandler() = delete;
    ~FileHandler();
    FileHandler(std::string DBpath);
    void saveDB(const std::vector<Client>& clientsTable, const std::vector<Company>& companiesTable, const std::vector<Address>& addressesTable);
    void loadDB(std::vector<Client> &clientsTable, std::vector<Company> &companiesTable, std::vector<Address> &addressesTable);
private:
    template <typename tableName>
    void saveTable(std::ofstream& out, const std::vector<tableName>& table);
    template <typename tableName>
    void serializeTable(std::ofstream& out, const std::vector<tableName>& table, const size_t& index);
    void serializeBool(std::ofstream& out, bool value);
    void serializeInt(std::ofstream& out, int value);
    void serializeString(std::ofstream& out, std::string value);
    template <typename tableName>
    void loadTable(std::ifstream& in, std::vector<tableName>& table);
    template <typename tableName>
    void deserializeTable(std::ifstream& in, std::vector<tableName>& table, const size_t& index);
    void deserializeBool(std::ifstream& in, bool &value);
    void deserializeInt(std::ifstream& in, int &value);
    void deserializeString(std::ifstream& in, std::string &value);
};
FileHandler::FileHandler(std::string DBpath)
{
    std::cout << "Obsługa pliku bazy danych została zaincjalizowana." << std::endl;
    databasePath = DBpath;
}
FileHandler::~FileHandler()
{
    std::cout << "Instancja klasy FileHandler została usunięta" << std::endl;
}
void FileHandler::saveDB(const std::vector<Client>& clientsTable, const std::vector<Company>& companiesTable, const std::vector<Address>& addressesTable)
{
    //Zapis zawartości bazy danych do pliku binarnego
    std::ofstream out(databasePath, std::ios::out | std::ios::binary);
    std::cout << "Zapis tabeli: clients" << std::endl;
    saveTable(out, clientsTable);
    std::cout << "Zapis tabeli: companies" << std::endl;
    saveTable(out, companiesTable);
    std::cout << "Zapis tabeli: addresses" << std::endl;
    saveTable(out, addressesTable);
    out.close();
};
template <typename tableName>
void FileHandler::saveTable(std::ofstream& out, const std::vector<tableName>& table)
{
    //Zapis do pliku binarnego zawartości tabeli
    typename std::vector<tableName>::size_type size = table.size();
    std::cout << size << std::endl;
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        serializeTable(out, table, i);
    }
};
template <typename tableName>
void FileHandler::serializeTable(std::ofstream& out, const std::vector<tableName>& table, const size_t& index)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        this->serializeInt(out, table.at(index).idClient);                      //int idClient;
        this->serializeString(out, table.at(index).firstName);                  //std::string firstName;
        this->serializeString(out, table.at(index).lastName);                   //std::string lastName;
        this->serializeString(out, table.at(index).email);                      //std::string email;
        this->serializeBool(out, table.at(index).gender);                       //bool gender;
        this->serializeBool(out, table.at(index).softDel);                      //bool softDel;
        this->serializeInt(out, table.at(index).companyId);                     //int companyId;
        this->serializeInt(out, table.at(index).addressId);                     //int addressId;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        this->serializeInt(out, table.at(index).idCompany);                     //int idCompany;
        this->serializeString(out, table.at(index).name);                       //std::string name;
        this->serializeString(out, table.at(index).nip);                        //std::string nip;
        this->serializeString(out, table.at(index).regon);                      //std::string regon;
        this->serializeString(out, table.at(index).krs);                        //std::string krs;
        this->serializeBool(out, table.at(index).deletedFromREGON);             //bool deletedFromREGON;
        this->serializeBool(out, table.at(index).softDel);                      //bool softDel;
        this->serializeInt(out, table.at(index).addressId);                     //int addressId;
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        this->serializeInt(out, table.at(index).idAddress);                     //int idAddress;
        this->serializeString(out, table.at(index).country);                    //std::string country;
        this->serializeString(out, table.at(index).state);                      //std::string state;
        this->serializeString(out, table.at(index).county);                     //std::string county;
        this->serializeString(out, table.at(index).community);                  //std::string community;
        this->serializeString(out, table.at(index).town);                       //std::string town;
        this->serializeString(out, table.at(index).street);                     //std::string street;
        this->serializeString(out, table.at(index).propertyNo);                 //std::string propertyNo;
        this->serializeString(out, table.at(index).apartmentNo);                //std::string apartmentNo;
        this->serializeString(out, table.at(index).postCode);                   //std::string postCode;
        this->serializeString(out, table.at(index).postalTown);                 //std::string postalTown;
        this->serializeBool(out, table.at(index).softDel);                      //bool softDel;
    }
};
void FileHandler::serializeBool(std::ofstream& out, bool value)
{
    out.write(reinterpret_cast<const char*>((bool*)&value), sizeof(value));
};
void FileHandler::serializeInt(std::ofstream& out, int value)
{
    out.write(reinterpret_cast<const char*>((int*)&value), sizeof(value));
};
void FileHandler::serializeString(std::ofstream& out, std::string value)
{
    std::string::size_type stringSize = value.length();
    out.write(reinterpret_cast<const char*>(&stringSize), sizeof(stringSize));
    out.write(reinterpret_cast<const char*>(value.data()), stringSize);
};
void FileHandler::loadDB(std::vector<Client>& clientsTable, std::vector<Company>& companiesTable, std::vector<Address>& addressesTable)
{
    //Odczyt zawartości bazy danych z pliku binarnego
    std::ifstream in(databasePath, std::ios::in | std::ios::binary);
    std::cout << "Odczyt tabeli: clients" << std::endl;
    loadTable(in, clientsTable);
    std::cout << "Odczyt tabeli: companies" << std::endl;
    loadTable(in, companiesTable);
    std::cout << "Odczyt tabeli: addresses" << std::endl;
    loadTable(in, addressesTable);
    in.close();
};
template <typename tableName>
void FileHandler::loadTable(std::ifstream& in, std::vector<tableName>& table)
{
    //Oczyt z pliku binarnego zawartości tabeli
    typename std::vector<tableName>::size_type tableSize = 0;
    in.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    std::cout << tableSize << std::endl;
    table.resize(tableSize);
    for (size_t i = 0; i < tableSize; i++)
    {
        deserializeTable(in, table, i);
    }
};
template <typename tableName>
void FileHandler::deserializeTable(std::ifstream& in, std::vector<tableName>& table, const size_t& index)
{
    if constexpr (std::is_same<tableName, Client>::value)
    {
        this->deserializeInt(in, table.at(index).idClient);             //int idClient;
        this->deserializeString(in, table.at(index).firstName);         //std::string firstName;
        this->deserializeString(in, table.at(index).lastName);          //std::string lastName;
        this->deserializeString(in, table.at(index).email);             //std::string email;
        this->deserializeBool(in, table.at(index).gender);              //bool gender;
        this->deserializeBool(in, table.at(index).softDel);             //bool softDel;
        this->deserializeInt(in, table.at(index).companyId);            //int companyId;
        this->deserializeInt(in, table.at(index).addressId);            //int addressId;
    }
    else if constexpr (std::is_same<tableName, Company>::value)
    {
        this->deserializeInt(in, table.at(index).idCompany);            //int idCompany;
        this->deserializeString(in, table.at(index).name);              //std::string name;
        this->deserializeString(in, table.at(index).nip);               //std::string nip;
        this->deserializeString(in, table.at(index).regon);             //std::string regon;
        this->deserializeString(in, table.at(index).krs);               //std::string krs;
        this->deserializeBool(in, table.at(index).deletedFromREGON);    //bool deletedFromREGON;
        this->deserializeBool(in, table.at(index).softDel);             //bool softDel;
        this->deserializeInt(in, table.at(index).addressId);            //int addressId;
    
    }
    else if constexpr (std::is_same<tableName, Address>::value)
    {
        this->deserializeInt(in, table.at(index).idAddress);            //int idAddress;
        this->deserializeString(in, table.at(index).country);           //std::string country;
        this->deserializeString(in, table.at(index).state);             //std::string state;
        this->deserializeString(in, table.at(index).county);            //std::string county;
        this->deserializeString(in, table.at(index).community);         //std::string community;
        this->deserializeString(in, table.at(index).town);              //std::string town;
        this->deserializeString(in, table.at(index).street);            //std::string street;
        this->deserializeString(in, table.at(index).propertyNo);        //std::string propertyNo;
        this->deserializeString(in, table.at(index).apartmentNo);       //std::string apartmentNo;
        this->deserializeString(in, table.at(index).postCode);          //std::string postCode;
        this->deserializeString(in, table.at(index).postalTown);        //std::string postalTown;
        this->deserializeBool(in, table.at(index).softDel);             //bool softDel;
    }
};
void FileHandler::deserializeBool(std::ifstream& in, bool &value)
{
    in.read(reinterpret_cast<char*>((bool*)&value), sizeof(value));
};
void FileHandler::deserializeInt(std::ifstream& in, int &value)
{
    in.read(reinterpret_cast<char*>((int*)&value), sizeof(value));
};
void FileHandler::deserializeString(std::ifstream& in, std::string &value)
{
    std::string::size_type stringSize = 0;
    in.read(reinterpret_cast<char*>(&stringSize), sizeof(stringSize));
    value.resize(stringSize);
    in.read(reinterpret_cast<char*>((void*)value.data()), stringSize);
};
int main(int argc, char** argv)
{
    // Obiekt klasy: Database
    // Tabele: Clients, Companies, Addresses
    Database database1;

    // Obiekt klasy: FileHandler
    // Zastosowanie: Odczyt/Zapis zawartości bazy danych z/do pliku binarnego
    FileHandler dbFile1("projects/db/database/db.stefan");

    // Odczytanie bazy danych z pliku binarnym
    dbFile1.loadDB(database1.clients, database1.companies, database1.addresses);

    // Obiekt klasy: Client
    // Zastosowanie: wiersz w tabeli clients
    Client client1;
    client1.idClient = (database1.clients.empty()) ? 1 : database1.clients.back().idClient + 1;
    client1.firstName = "Franek";
    client1.lastName = "Kimono";
    client1.email = "franek.kimono@corp.pl";
    client1.gender = true;
    client1.companyId = (database1.companies.empty()) ? 1 : database1.companies.back().idCompany + 1;
    client1.addressId = (database1.addresses.empty()) ? 1 : database1.addresses.back().idAddress + 1;

    // Obiekt klasy: Company
    // Zastosowanie: wiersz w tabeli companies
    Company company1;
    company1.idCompany = (database1.companies.empty()) ? 1 : database1.companies.back().idCompany + 1;
    company1.name = "DUPA DUPa DUUUUPAAA MERLIN COMMERCE SPÓŁKA Z OGRANICZONĄ ODPOWIEDZIALNOŚCIĄ";
    company1.nip = "5272647706";
    company1.regon = "142799272";
    company1.krs = "0000377830";
    company1.deletedFromREGON = false;
    company1.addressId = (database1.addresses.empty()) ? 1 : database1.addresses.back().idAddress + 1;

    // Obiekt klasy: Address
    // Zastosowanie: wiersz w tabeli addresses
    Address address1;
    address1.idAddress = (database1.addresses.empty()) ? 1 : database1.addresses.back().idAddress + 1;
    address1.country = "POLSKA";
    address1.state = "MAZOWIECKIE";
    address1.county = "Warszawa";
    address1.community = "Ochota";
    address1.town = "Warszawa";
    address1.street = "Aleje Jerozolimskie";
    address1.propertyNo = "134";
    address1.apartmentNo = "";
    address1.postCode = "02-305";
    address1.postalTown = "Warszawa";

    // Umieszczenie w tabelach: clients, companies, addresses obiektów klas: Client, Company, Address
    database1.insertRow(database1.clients, client1);
    database1.insertRow(database1.companies, company1);
    database1.insertRow(database1.addresses, address1);

    // Zapisanie bazy danych w pliku binarnym
    dbFile1.saveDB(database1.clients, database1.companies, database1.addresses);

    // Wyczyszczenie zawartości tabel
    database1.truncateTable(database1.clients);
    database1.truncateTable(database1.companies);
    database1.truncateTable(database1.addresses);

    // Obiekt klasy: Database
    // Tabele: Clients, Companies, Addresses
    Database database2;

    // Odczytanie bazy danych z pliku binarnym
    dbFile1.loadDB(database2.clients, database2.companies, database2.addresses);

    // Obiekt klasy: RenderDatabaseView
    // Zastosowanie: Wyświetlanie zawartości bazy danych
    RenderDatabaseView databaseView1;

    //Wyświetlenie zawartości tabel: clients, companies, addresses
    databaseView1.selectFromTable(database2.clients);
    databaseView1.selectFromTable(database2.companies);
    databaseView1.selectFromTable(database2.addresses);
    std::cout << "====================" << std::endl;

    // Obiekt klasy: Client
    // Zastosowanie: wiersz w tabeli clients
    Client updatedClient1;
    updatedClient1.firstName = "Zbigniew";
    updatedClient1.lastName = "Andrzej";
    updatedClient1.email = "zbigniew.andrzej@corp.pl";
    updatedClient1.gender = true;
    updatedClient1.companyId = (database1.companies.empty()) ? 1 : database1.companies.back().idCompany + 1;
    updatedClient1.addressId = (database1.addresses.empty()) ? 1 : database1.addresses.back().idAddress + 1;

    // Aktualizacja tabeli: clients, aktualizacja rekordu, gdzie idClient = 17
    std::vector<Client>::iterator element1 = database2.findRowInTableByIndex(database2.clients, 17);
    if(element1 == database2.clients.cend())
    {
        std::cout << "brak wyników" << std::endl;
    }
    else
    {
        std::cout << "Element index: " << std::distance(database2.clients.begin(), element1) << std::endl;
        database2.updateRow(database2.clients.at(std::distance(database2.clients.begin(), element1)), updatedClient1);
    }

    // Aktualizacja tabeli: clients, oznaczenie rekordu jako usunięty, gdzie idClient = 17
    std::vector<Client>::iterator element2 = database2.findRowInTableByIndex(database2.clients, 17);
    if(element2 == database2.clients.cend())
    {
        std::cout << "brak wyników" << std::endl;
    }
    else
    {
        std::cout << "Element index: " << std::distance(database2.clients.begin(), element2) << std::endl;
        database2.softDeleteRow(database2.clients.at(std::distance(database2.clients.begin(), element2)));
    }

    // Wyświetlenie rekordu z tabeli: clients, gdzie idClient = 17
    std::vector<Client>::iterator element3 = database2.findRowInTableByIndex(database2.clients, 17);
    if(element3 == database2.clients.cend())
    {
        std::cout << "brak wyników" << std::endl;
    }
    else
    {
        databaseView1.selectRowFromTable(*element3);
    }

    // Sortowanie rekordów z tabeli: clients
    database2.sortTableAscBy(database2.clients, 5, true);
    
    databaseView1.selectFromTable(database2.clients);

    // Zapisanie bazy danych w pliku binarnym
    dbFile1.saveDB(database2.clients, database2.companies, database2.addresses);

    // Wyczyszczenie zawartości tabel
    database2.truncateTable(database2.clients);
    database2.truncateTable(database2.companies);
    database2.truncateTable(database2.addresses);

    return 0;
}