/*
    https://stackoverflow.com/questions/28492517/write-and-load-vector-of-structs-in-a-binary-file-c?noredirect=1&lq=1
*/

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


struct Field
{
    char name[20];
    int type;
    int length;
};

struct Record
{
    vector<Field> structure;
    vector<string> info;
};

void writevecfield(ostream& os, const vector<Field>& vec)
{
    typename vector<Field>::size_type size = vec.size();
    os.write((char*)&size, sizeof(size));
    os.write((char*)&vec[0], vec.size() * sizeof(Field));
}

void readvecfield(istream& is, vector<Field>& vec)
{
    typename vector<Field>::size_type size = 0;
    is.read((char*)&size, sizeof(size));
    vec.resize(size);
    is.read((char*)&vec[0], vec.size() * sizeof(Field));
}

void writevecstring(ostream& os, const vector<string>& vec)
{
    typename vector<string>::size_type size = vec.size();
    os.write((char*)&size, sizeof(size));

    for (typename vector<string>::size_type i = 0; i < size; ++i)
    {
        typename vector<string>::size_type element_size = vec[i].size();
        os.write((char*)&element_size, sizeof(element_size));
        os.write(&vec[i][0], element_size);
    }
}

void readvecstring(istream& is, vector<string>& vec)
{
    typename vector<string>::size_type size = 0;
    is.read((char*)&size, sizeof(size));
    vec.resize(size);

    for (typename vector<string>::size_type i = 0; i < size; ++i)
    {
        typename vector<string>::size_type element_size = 0;
        is.read((char*)&element_size, sizeof(element_size));
        vec[i].resize(element_size);
        is.read(&vec[i][0], element_size);
    }
}



void WriteRecord(ostream& out, const Record& r)
{
    writevecfield(out, r.structure);
    writevecstring(out, r.info);
}

void ReadRecord(istream& in, Record& r)
{
    readvecfield(in, r.structure);
    readvecstring(in, r.info);
}


int main()
{
    Record R;

    Field first = { "HELLO", 1, 20 };
    Field second = { "WORLD", 2, 40 };
    R.structure.push_back(first);
    R.structure.push_back(second);
    R.info.push_back("INFO FOR HELLO");
    R.info.push_back("INFO FOR WORLD");

    std::ofstream out("db2.stefan", std::ios::out | std::ios::binary);
    WriteRecord(out, R);
    out.close();

    Record RR;
    std::ifstream in("db2.stefan", std::ios::in | std::ios::binary);
    ReadRecord(in, RR);
    in.close();

    for (int i = 0; i < RR.structure.size(); ++i)
    {
        std::cout << "Name:   " << RR.structure[i].name << "\n";
        std::cout << "Type:   " << RR.structure[i].type << "\n";
        std::cout << "Length: " << RR.structure[i].length << "\n";
        std::cout << "INFO:   " << RR.info[i] << "\n\n";
    }
}