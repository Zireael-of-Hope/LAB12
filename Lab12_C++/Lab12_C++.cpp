#include <iostream>
#include <conio.h>
#include <Color.h>
#include <Weapon.h>
#include <Human.h>

int main()
{
    Weapon* M4A1;
    M4A1 = new AssaultRifle(Rarity::Standard, "TOP", 100, 800, 40, 30, 1.5, AmmoType::AMMO_5_56);
    AssaultRifle AK_105(Rarity::Advanced, "Peacemaker", 100, 800, 40, 30, 1.5, AmmoType::AMMO_7_62);
    Handgun Glock17(Rarity::High_End, "CrappyThing", 55, 350, 40, 17, 2.5, AmmoType::AMMO_9);
    
    Knife Bayonet(Rarity::Elite, "");

    Bayonet.SetSkin("Bloody Moon");
    Bayonet.GetStatus();
    Bayonet.SetSkin("Green Sky", 1);
    Bayonet.GetStatus();
    //Если не использовать using Class::Method в Knife
    //То будет доступен лишь один методов SetSkin()
    //Какой из методов доступен - определяет Тип Bayonet

    Human MyBuddy("Hamilton", 78, 180, 37);
    SWAT_Operator Operator("Johnson", 87, 190, 27, Rank::LIEUTENANT);

    Operator = MyBuddy;
    cout << Operator;
    Operator.UseWeapon(*M4A1);

    cout << "\n"; Operator.ExampleCallVirtualMethod();
    cout << endl;

    Human *Buddy, *Buddy2;

    Buddy = new SWAT_Operator("Bottas", 76, 174, 2, Rank::DEPUTY);
    Buddy2 = new Human("Norris", 81, 185, 24);

    Buddy->UseWeapon(*M4A1);
    cout << endl;
    Buddy2->UseWeapon(Glock17);
    cout << endl;

    //Не виртуальная функция
    AK_105.LevelUp(); //AssaultRifle::LevelUp();
    AK_105.GetStatus();
    M4A1->LevelUp(); //Weapon::LevelUp();
    M4A1->GetStatus();

    M4A1->LevelUp();
    M4A1->GetStatus();

    Glock17.Weapon::LevelUp();
    Glock17.GetStatus();

}