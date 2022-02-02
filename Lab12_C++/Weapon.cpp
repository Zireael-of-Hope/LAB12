#include "Weapon.h"

Weapon::Weapon()
{
	rare = Rarity::Standard;
	skin = "Standard";
}

Weapon::Weapon(Rarity rare, string skin)
{
	this->rare = rare;
	this->skin = skin;
}

Weapon::~Weapon()
{
}

void Weapon::SetSkin(string skin_name)
{
	skin = skin_name;
}

void Knife::Attack()
{
	cout << "*cutting stuff*" << endl;
}

bool Weapon::LevelUp()
{
	switch (rare) {
	case Rarity::Standard:
		rare = Rarity::Advanced;
		UpdateDueToRarity();
		return true;
	case Rarity::Advanced:
		rare = Rarity::High_End;
		UpdateDueToRarity();
		return true;
	case Rarity::High_End:
		rare = Rarity::Elite;
		UpdateDueToRarity();
		return true;
	default: return false;
	}
}

void Knife::InspectWeapon()
{
	cout << "*inspecting knife*" << endl;
}

void Weapon::GetStatus()
{ 
	switch (rare) {
	case Rarity::FOR_EXAMPLE:
		SetColor(4, 0);
		break;
	case Rarity::Standard:
		SetColor(2, 0);
		break;
	case Rarity::Advanced:
		SetColor(9, 0);
		break;
	case Rarity::High_End:
		SetColor(5, 0);
		break;
	case Rarity::Elite:
		SetColor(10, 0);
		break;
	}

	switch (id) {
	case 0:
		cout << "Knife: ";
		break;
	case 1:
		cout << "Handgun: ";
		break;
	case 2:
		cout << "Assault Rifle: ";
		break;
	case 3:
		cout << "Sniper Rifles: ";
		break;
	}

	SetColor(15, 0);

	cout << "Damage: " << damage << " | Skin: " << skin << endl;
}

Knife::Knife(Rarity rare, string skin) : Weapon(rare, skin)
{
	id = 0;
	damage = 55;
	UpdateDueToRarity();
}

void Knife::SetSkin(string skin_name, int special_skin)
{
	skin = skin_name + "_KNIFE";
}

void Knife::UpdateDueToRarity()
{
	switch (rare) {
	case Rarity::FOR_EXAMPLE:
		cout << "\n\nAssaultRifle LevelUp methos has been called!\n" << endl;
		break;
	case Rarity::Standard:
		damage += 0;
		break;
	case Rarity::Advanced:
		damage += 5;
		break;
	case Rarity::High_End:
		damage += 10;
		break;
	case Rarity::Elite:
		damage += 15;
		break;
	}
}

Handgun::Handgun(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type) 
	: Firearm(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type)
{
}

void Handgun::Attack()
{
	cout << "*shooting with pistol: ";
	FirearmMechanic(ammo_type, effective_range);
	cout << "*";
}

void  Firearm::FirearmMechanic(AmmoType ammo_type, int effective_range)
{
	cout << "BANG with ";
	switch (ammo_type) {
	case AmmoType::AMMO_9:
		cout << "9mm ";
		break;
	case AmmoType::AMMO_45:
		cout << "45.ACP ";
		break;
	case AmmoType::AMMO_5_56:
		cout << "5.56 ";
		break;
	case AmmoType::AMMO_7_62:
		cout << "7.62 ";
		break;
	}	
	cout << "at " << effective_range << " meters";
}

void Handgun::InspectWeapon()
{
	cout << "*inspecting handgun*" << endl;
}

void Handgun::UpdateDueToRarity()
{
	switch (rare) {
	case Rarity::Standard:
		damage += 0;
		effective_range += 0;
		reload_time = reload_time - 0;
		break;
	case Rarity::Advanced:
		damage += 4;
		effective_range += 10;
		reload_time = reload_time - 0.3;	
		break;
	case Rarity::High_End:
		damage += 8;
		effective_range += 20;
		reload_time = reload_time - 0.6;		
		break;
	case Rarity::Elite:
		damage += 12;
		effective_range += 30;
		reload_time = reload_time - 0.9;			
		break;
	}
}

AssaultRifle::AssaultRifle(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type)
	: Firearm(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type)
{
}

void AssaultRifle::Attack()
{
	cout << "*automatic shooting with assault rifle: ";
	FirearmMechanic(ammo_type, effective_range);
	cout << "*";
}

void AssaultRifle::InspectWeapon()
{
	cout << "*inspecting assault rifle*" << endl;
}

bool AssaultRifle::LevelUp()
{
	rare = Rarity::FOR_EXAMPLE;
	return true;
}

void AssaultRifle::UpdateDueToRarity()
{
	switch (rare) {
	case Rarity::Standard:
		break;
	case Rarity::Advanced:
		damage += 5;
		effective_range += 13;
		reload_time = reload_time - 0.3;
		break;
	case Rarity::High_End:
		damage += 10;
		effective_range += 26;
		reload_time = reload_time - 0.6;
		break;
	case Rarity::Elite:
		damage += 15;
		effective_range += 39;
		reload_time = reload_time - 0.9;
		break;
	}
}

Firearm::Firearm(Rarity rare, string skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type)
	: Weapon(rare, skin)
{
	id = 2;
	this->effective_range = effective_range;
	this->fire_rate = fire_rate;
	this->damage = damage;
	this->magazine = magazine;
	this->reload_time = reload_time;
	this->ammo_type = ammo_type;
}
