package com.company;

public class Main {

    public static void main(String[] args) {
        Weapon M4A1 = new AssaultRifle(Rarity.Elite, "TOP", 100, 800, 40, 30, 1.5, AmmoType.AMMO_5_56);
        AssaultRifle AK_105 = new AssaultRifle(Rarity.Advanced, "Peacemaker", 100, 800, 40, 30, 1.5, AmmoType.AMMO_7_62);
        Handgun Glock17 = new Handgun(Rarity.High_End, "CrappyThing", 55, 350, 40, 17, 2.5, AmmoType.AMMO_9);

        Knife Bayonet = new Knife(Rarity.Elite, "");

        Bayonet.SetSkin("Bloody Moon");
        Bayonet.GetStatus();
        Bayonet.SetSkin("Green Sky", 1);
        Bayonet.GetStatus();

        Human MyBuddy = new Human("Hamilton", 78, 180, 37);
        Human MuBuddyCopy = new Human(MyBuddy);
        SWAT_Operator Operator = new SWAT_Operator("Johnson", 87, 190, 27, Rank.LIEUTENANT);

        System.out.println(MyBuddy.toString());
        System.out.println(MuBuddyCopy.toString());
        System.out.println(Operator.toString());

        Operator.UseWeapon(M4A1);

        System.out.println(""); Operator.ExampleCallVirtualMethod();
        System.out.println("");

        Human Buddy, Buddy2;

        Buddy = new SWAT_Operator("Bottas", 76, 174, 2, Rank.DEPUTY);
        Buddy2 = new Human("Norris", 81, 185, 24);

        Buddy.UseWeapon(M4A1);
        System.out.println("");
        Buddy2.UseWeapon(Glock17);
        System.out.println("");

    }
}
