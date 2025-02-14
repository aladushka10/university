#include "Person.h"
int Person::NextID_ = 0;
Person::Person() : ID_(++NextID_) {
	Name_ = new char;
}
Person::Person(const char* name, Gender gen, Person* Mother, Person* Father) : ID_(++NextID_) {
	Name_ = new char[strlen(name) + 1];
	strcpy(Name_, name);
	if (name == nullptr) {
		throw  std::logic_error("Person must have a name");
	}
	Gender_ = gen;
	if (Father != nullptr) {
		Father_ = Father;
	}
	Mother_ = Mother;
	Father_ = Father;
	if (ID_ > 2 && Mother == nullptr) {
		throw std::logic_error("You can`t create new person this way");
	}
	if (Mother != nullptr && Mother->Gender_ == Gender::male) {
		throw  std::logic_error("Mother's gender must be female");
	}
	if (Father != nullptr && Father->Gender_ == Gender::female) {
		throw  std::logic_error("Father's gender must be male");
	}
}
Person *Person::GiveBirth(const char* name, Gender gen, Person* father) {
	if (Gender_ == Gender::male) {
		throw  std::logic_error("GiveBirth: gender error");
	}
	const char* AddName = " ";
	if (name != nullptr)
		AddName = name;
	else {
		throw  std::logic_error("Baby must have a name");
	}
	auto child = new Person(AddName, gen, this, father);
	return child;
}
Person Person::operator=(const Person per) {
	return Person(Name_, Gender_, Mother_, Father_);
}
void Person::Print() const {
	std::cout << "Name: " << GetName() << std::endl;
	std::cout << "ID: " << GetID() << std::endl;
	std::cout << "Gender: " << GetGender() << std::endl;
	if (Mother_ != nullptr) {
		std::cout << "Mother Name: " << GetMother() << std::endl;
	}
	else {
		std::cout << "This Person has no mother" << std::endl;
	}
	if (Father_ != nullptr) {
		std::cout << "Father Name: " << GetFather() << std::endl;
	}
	else {
		std::cout << "This Person has no father" << std::endl;
	}
}
char* Person::GetName() const {
	return Name_;
}
const char* Person::GetGender() const {
	return this->Gender_==Gender::male ? "male" : "Female";
}
char* Person::GetMother() const {
	return Mother_->GetName();
}
char* Person::GetFather() const {
	return Father_->GetName();
}
int Person::GetID() const {
	return ID_;
}
void Person::Erase() {
	delete[] Name_;
}

