#include<iostream>
#include<fstream>
#include<vector>
struct Student
{
	char name[50];
	int age;
	float gpa;
};
std::ostream& operator<<(std::ostream& stream, const Student& student)
{
	stream << student.name << ", " << student.age << ", " << student.gpa;
	return stream;
}
int maaaaaaain()
{

	/*
	std::vector<Student> olds;
	olds.push_back({ "Hank", 48, 3.58 });
	olds.push_back({ "Tom", 25, 2.58 });
	for (int i = 0; i < olds.size(); i++)
		std::cout << olds[i] << std::endl;
	olds.erase(olds.begin() + 1);
	for (Student& s : olds)
		std::cout << s << std::endl;
	*/
	/*
	const int SIZE = 3;
	Student old_students[SIZE] = {
		{ "Hank", 48, 3.58 },
		{"Tom", 25, 2.58},
		{"Rick", 22, 3.98}
	};

	std::fstream db;
	db.open("db2.stefan", std::ios::out | std::ios::binary);
	if (db.is_open())
	{
		db.write(reinterpret_cast<char*>(old_students), SIZE * sizeof(Student));
		db.close();
	}
	else {
		std::cout << "Nie udalo sie Write" << std::endl;
	}

	Student new_students[SIZE];
	db.open("db2.stefan", std::ios::in | std::ios::binary);
	if (db.is_open())
	{
		db.read(reinterpret_cast<char*>(new_students), SIZE * sizeof(Student));
		db.close();
	}
	else {
		std::cout << "Nie udalo sie Write" << std::endl;
	}
	for (Student& s : new_students)
	{
		std::cout << s.name << std::endl;
		std::cout << s.age << std::endl;
		std::cout << s.gpa << std::endl;
	}
	*/

	/*
	Student stu = { "Hank", 48, 3.58 };

	std::fstream db;
	db.open("db2.stefan", std::ios::out | std::ios::binary);
	if (db.is_open())
	{
		db.write(reinterpret_cast<char*>(&stu), sizeof(Student));
		db.close();
	}
	else {
		std::cout << "Nie udalo sie Write" << std::endl;
	}

	Student newStu;

	db.open("db2.stefan", std::ios::in | std::ios::binary);
	if (db.is_open())
	{
		db.read(reinterpret_cast<char*>(&newStu), sizeof(Student));
		db.close();
	}
	else {
		std::cout << "Nie udalo sie Read" << std::endl;
	}

	std::cout << newStu.name << std::endl;
	std::cout << newStu.age << std::endl;
	std::cout << newStu.gpa << std::endl;
	*/

	return 0;
};