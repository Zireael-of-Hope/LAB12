#pragma once
#include <iostream>
#include <Weapon.h>
using namespace std;

enum class Rank {
	DEPUTY,
	SUPERVISOR, 
	SERGEANT,
	LIEUTENANT
};

class Human
{
protected:
	string name;
	double weight;
	double height;
	int age;
public:
	Human(string name, double weight, double height, int age);
	string GetName();
	double GetWeight();
	double GetHeight();
	int GetAge();
	virtual void UseWeapon(Weapon& weapon);

	friend ostream& operator<< (ostream& out, const Human& human);

	void ExampleCallVirtualMethod();
private:
	virtual string ExampleVirtualMethod();
};

class SWAT_Operator final : public Human
{
private:
	Rank rank;
public:
	SWAT_Operator(string name, double weight, double height, int age, Rank rank);
	void UseWeapon(Weapon& weapon) override final;
	SWAT_Operator& operator=(Human& other);
};

