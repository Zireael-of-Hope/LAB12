using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab12_CS // Note: actual namespace depends on the project name.
{
    public class Program
    {
        public static void Main(string[] args)
        {
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

            Console.WriteLine(MyBuddy.toString());
            Console.WriteLine(MuBuddyCopy.toString());
            Console.WriteLine(Operator.toString());

            Operator.UseWeapon(M4A1);

            Console.WriteLine(""); Operator.ExampleCallVirtualMethod();
            Console.WriteLine("");

            Human Buddy, Buddy2;

            Buddy = new SWAT_Operator("Bottas", 76, 174, 2, Rank.DEPUTY);
            Buddy2 = new Human("Norris", 81, 185, 24);

            Buddy.UseWeapon(M4A1);
            Console.WriteLine("");
            Buddy2.UseWeapon(Glock17);
            Console.WriteLine("");
        }
    }
}