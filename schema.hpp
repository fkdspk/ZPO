struct Addresses
{
    int id_address;
    char country[8+1];
    char state[19+1];
    char city[10+1];
    char address[18+1];
    int is_deleted;
};
struct Client
{
    int id_client;
    char first_name[10+1];
    char last_name[10+1];
    char email[18+1];
    int is_deleted;
    int company_id;
    int address_id;
};
struct Company
{
    int id_company;
    char name[24+1];
    char nip[10+1];
    char regon[14+1];
    int is_deleted;
    int address_id;
};