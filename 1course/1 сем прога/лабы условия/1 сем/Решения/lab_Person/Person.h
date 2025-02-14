#pragma warning (disable:4996)
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string.h>
enum class Gender { male, female };
class Person
{
private:
	const int ID_;
	char* Name_;
	Gender Gender_;
	static int NextID_;
	Person* Mother_;
	Person* Father_;
	void Erase();
public:
	Person();
	Person(const char*, Gender, Person* = nullptr, Person* = nullptr);
	Person* GiveBirth(const char*, Gender, Person* = nullptr);
	Person operator = (const Person p);
	void Print() const;
	char* GetName() const;
	const char* GetGender() const;
	char* GetMother() const;
	char* GetFather() const;
	int GetID() const;
};
#endif
