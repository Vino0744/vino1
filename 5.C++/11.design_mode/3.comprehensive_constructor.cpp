/*************************************************************************
	> File Name: 3.comprehension_construct.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Nov 2024 10:31:53 AM CST
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

class PersonElement;
class PersonBuilder;
class PersonBaseInfoBuilder;
class PersonWorkInfoBuilder;

class PersonElement {
public:
    // base info
    string name;
    int    age;
    double height;
    // work info
    string company;
    int level;

    static PersonBuilder *build();
};

class PersonBuilder {
public :
    PersonElement person;
    operator PersonElement() const { return person; }
    PersonBaseInfoBuilder BaseInfo();
    PersonWorkInfoBuilder WorkInfo();
};

class PersonBaseInfoBuilder : public PersonBuilder {
public:
    typedef PersonBaseInfoBuilder &Self;
    PersonElement person;
    PersonBaseInfoBuilder(PersonElement &&person) : person(std::move(person)) {}
    Self name(string n) { person.name = n; return *this; }
    Self age(int a) { person.age = a; return *this; }
    Self height(double h) { person.height = h; return *this; }
};

class PersonWorkInfoBuilder : public PersonBuilder {
public:
    typedef PersonWorkInfoBuilder &Self;
    PersonElement person;
    PersonWorkInfoBuilder(PersonElement &&person) : person(std::move(person)) {}
    Self company(string c) { person.company = c; return *this; }
    Self level(int l) { person.level = l; return *this; }
};

PersonBuilder *PersonElement::build() { 
    return new PersonBuilder(); 
}

PersonBaseInfoBuilder PersonBuilder::BaseInfo() {
    return PersonBaseInfoBuilder(std::move(person));
}

PersonWorkInfoBuilder PersonBuilder::WorkInfo() {
    return PersonWorkInfoBuilder(std::move(person));
}

int main() {
    PersonElement person = PersonElement::build()
    ->BaseInfo().name("hug").age(56).height(2.93)
    .WorkInfo().company("huawei").level(99);


    return 0;
}
