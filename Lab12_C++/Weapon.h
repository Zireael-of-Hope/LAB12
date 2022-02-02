#pragma once
#include <iostream>
#include <Color.h>
using namespace std;

enum class Rarity {
	FOR_EXAMPLE, //присвоится при вызове повышения уровня из дочернего класса AssaultRifle
	Standard,
	Advanced,
	High_End,
	Elite
};

enum class AmmoType {
	AMMO_45,
	AMMO_9,
	AMMO_5_56,
	AMMO_7_62
};

class Weapon
{
protected:
	Rarity rare;
	int id;
	int damage;
	string skin;
	Weapon();
	Weapon(Rarity rare, string skin);
	virtual void InspectWeapon() = 0;
	virtual void UpdateDueToRarity() = 0;
public:
	~Weapon();    
	virtual void Attack() = 0;
	void SetSkin(string skin_name);
	bool LevelUp();
	void GetStatus();
};

class Knife : public Weapon
{
private:
	virtual void UpdateDueToRarity() override final;
public:
	Knife(Rarity rare, string skin);
	using Weapon::SetSkin;
	void SetSkin(string skin_name, int special_skin);
	virtual void Attack() override final;
	virtual void InspectWeapon() override final;
};

class Firearm : public Weapon
{
protected:
	Firearm(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type);
	int effective_range;
	int fire_rate;
	int magazine;
	double reload_time;
	AmmoType ammo_type;
	void FirearmMechanic(AmmoType ammo_type, int effective_range);
};

class Handgun final : public Firearm
{
private:
	virtual void UpdateDueToRarity() override final;
public:
	Handgun(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type);
	virtual void Attack() override;
	virtual void InspectWeapon() override;
};

class AssaultRifle final : public Firearm
{
private:
	virtual void UpdateDueToRarity() override final;
public:
	AssaultRifle(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type);
	virtual void Attack() override;
	virtual void InspectWeapon() override;
	bool LevelUp();
};