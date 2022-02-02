using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab12_CS
{
    enum Rarity
    {
        FOR_EXAMPLE, //присвоится при вызове повышения уровня из дочернего класса AssaultRifle
        Standard,
        Advanced,
        High_End,
        Elite
    };

    enum AmmoType
    {
        AMMO_45,
        AMMO_9,
        AMMO_5_56,
        AMMO_7_62
    };

    internal abstract class Weapon
    {
        protected Rarity rare;
        protected int id;
        protected int damage;
        protected String skin;
        protected Weapon()
        {
            rare = Rarity.Standard;
            skin = "Standard";
        }
        protected Weapon(Rarity rare, String skin)
        {
            this.rare = rare;
            this.skin = skin;
        }
        protected abstract void UpdateDueToRarity();
        public abstract void InspectWeapon();

        public abstract void Attack();
        public void SetSkin(String skin_name)
        {
            skin = skin_name;
        }
        public bool LevelUp()
        {
            switch (rare)
            {
                case Rarity.Standard:
                    rare = Rarity.Advanced;
                    UpdateDueToRarity();
                    return true;
                case Rarity.Advanced:
                    rare = Rarity.High_End;
                    UpdateDueToRarity();
                    return true;
                case Rarity.High_End:
                    rare = Rarity.Elite;
                    UpdateDueToRarity();
                    return true;
                default: return false;
            }
        }
        public void GetStatus()
        {
            switch (rare)
            {
                case Rarity.Standard:
                    Console.Write("Standard: ");
                    break;
                case Rarity.Advanced:
                    Console.Write("Advanced: ");
                    break;
                case Rarity.High_End:
                    Console.Write("High_End: ");
                    break;
                case Rarity.Elite:
                    Console.Write("Elite: ");
                    break;
            }

            switch (id)
            {
                case 0:
                    Console.Write("Knife: ");
                    break;
                case 1:
                    Console.Write("Handgun: ");
                    break;
                case 2:
                    Console.Write("Assault Rifle: ");
                    break;
                case 3:
                    Console.Write("Sniper Rifles: ");
                    break;
            }

            Console.WriteLine("Damage: " + damage + " | Skin: " + skin);
        }
    }

    class Knife : Weapon
    {
        protected override void UpdateDueToRarity()
        {
            switch (rare)
            {
                case Rarity.FOR_EXAMPLE:
                    Console.WriteLine("\n\nAssaultRifle LevelUp methos has been called!\n");
                    break;
                case Rarity.Standard:
                    break;
                case Rarity.Advanced:
                    damage += 5;
                    break;
                case Rarity.High_End:
                    damage += 10;
                    break;
                case Rarity.Elite:
                    damage += 15;
                    break;
            }
        }
        public Knife(Rarity rare, String skin)
                : base(rare, skin)
        {
            id = 0;
            damage = 55;
            UpdateDueToRarity();
        }
        public void SetSkin(String skin_name, int special_skin)
        {
            skin = skin_name + "_KNIFE";
        }
        public override void Attack()
        {
            Console.WriteLine("*cutting stuff*");
        }
        public override void InspectWeapon()
        {
            Console.WriteLine("*inspecting knife*");
        }
    };

    abstract class Firearm : Weapon
    {
        protected Firearm(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type)
            : base(rare, skin)
        {
            id = 2;
            this.effective_range = effective_range;
            this.fire_rate = fire_rate;
            this.damage = damage;
            this.magazine = magazine;
            this.reload_time = reload_time;
            this.ammo_type = ammo_type;
        }
        protected int effective_range;
        protected int fire_rate;
        protected int magazine;
        protected double reload_time;
        protected AmmoType ammo_type;
        protected void FirearmMechanic(AmmoType ammo_type, int effective_range)
        {
            Console.Write("BANG with ");
            switch (ammo_type)
            {
                case AmmoType.AMMO_9:
                    Console.Write("9mm ");
                    break;
                case AmmoType.AMMO_45:
                    Console.Write("45.ACP ");
                    break;
                case AmmoType.AMMO_5_56:
                    Console.Write("5.56 ");
                    break;
                case AmmoType.AMMO_7_62:
                    Console.Write("7.62 ");
                    break;
            }
            Console.Write("at " + effective_range + " meters");
        }
    };

    class Handgun : Firearm
    {
        protected override void UpdateDueToRarity()
        {
            switch (rare)
            {
                case Rarity.Standard:
                    reload_time = reload_time - 0;
                    break;
                case Rarity.Advanced:
                    damage += 4;
                    effective_range += 10;
                    reload_time = reload_time - 0.3;
                    break;
                case Rarity.High_End:
                    damage += 8;
                    effective_range += 20;
                    reload_time = reload_time - 0.6;
                    break;
                case Rarity.Elite:
                    damage += 12;
                    effective_range += 30;
                    reload_time = reload_time - 0.9;
                    break;
            }
        }
        public Handgun(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type)
            : base(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type)
        {
        }

        public override void Attack()
        {
            Console.Write("*shooting with pistol: ");
            FirearmMechanic(ammo_type, effective_range);
            Console.Write("*");
        }
        public override void InspectWeapon()
        {
            Console.WriteLine("*inspecting handgun*");
        }
    };

class AssaultRifle : Firearm
{
        protected override void UpdateDueToRarity()
        {
            switch (rare)
            {
                case Rarity.Standard:
                    break;
                case Rarity.Advanced:
                    damage += 5;
                    effective_range += 13;
                    reload_time = reload_time - 0.3;
                    break;
                case Rarity.High_End:
                    damage += 10;
                    effective_range += 26;
                    reload_time = reload_time - 0.6;
                    break;
                case Rarity.Elite:
                    damage += 15;
                    effective_range += 39;
                    reload_time = reload_time - 0.9;
                    break;
            }
        }
        public AssaultRifle(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type)
            : base(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type)
        { 
        }

        public override void Attack()
        {
            Console.Write("*automatic shooting with assault rifle: ");
            FirearmMechanic(ammo_type, effective_range);
            Console.Write("*");
        }
        public override void InspectWeapon()
        {
            Console.WriteLine("*inspecting assault rifle*");
        }
    }
}
