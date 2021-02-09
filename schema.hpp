struct Client
{
    int id_client = 0;
    char first_name[10+1] = "";
    char last_name[10+1] = "";
    char email[18+1] = "";
    int is_deleted = 0;
    int company_id = 0;
    int address_id = 0;
};
struct Company
{
    int id_company = 0;
    char name[24+1] = "";
    char nip[10+1] = "";
    char regon[14+1] = "";
    int is_deleted = 0;
    int address_id = 0;
};
struct Addresses
{
    int id_address = 0;
    char country[8+1] = "";
    char state[19+1] = "";
    char city[10+1] = "";
    char address[18+1] = "";
    int is_deleted = 0;
};