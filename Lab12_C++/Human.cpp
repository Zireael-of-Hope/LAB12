#include "Human.h"

SWAT_Operator::SWAT_Operator(string name, double weight, double height, int age, Rank rank)
	: Human(name, weight, height, age)
{
	this->rank = rank;
}

void SWAT_Operator::UseWeapon(Weapon& weapon)
{
	cout << "Officer using deadly force! ";
	weapon.Attack();
}

SWAT_Operator& SWAT_Operator::operator=(Human& other)
{
	if (this == &other)
		return *this;

	age = other.GetAge();
	height = other.GetHeight();
	name = other.GetName();
	weight = other.GetWeight();
}

Human::Human(string name, double weight, double height, int age)
{
	this->age = age;
	this->height = height;
	this->name = name;
	this->weight = weight;
}

string Human::GetName()
{
	return name;
}

double Human::GetWeight()
{
	return weight;
}

double Human::GetHeight()
{
	return height;
}

int Human::GetAge()
{
	return age;
}

void Human::UseWeapon(Weapon& weapon)
{
	cout << "Suspect using deadly force! ";
	weapon.Attack();
}

void Human::ExampleCallVirtualMethod()
{
	cout << ExampleVirtualMethod();
}

string Human::ExampleVirtualMethod()
{
	return "Hello World";
}

ostream& operator<<(ostream& out, const Human& human)
{
	out << "Info: " << human.name << " Age " << human.age << " Weight " << human.weight << " Height " << human.height << endl;

	return out;
}
