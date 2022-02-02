package com.company;

enum Rarity {
    FOR_EXAMPLE, //присвоится при вызове повышения уровня из дочернего класса AssaultRifle
    Standard,
    Advanced,
    High_End,
    Elite
};

enum AmmoType {
    AMMO_45,
    AMMO_9,
    AMMO_5_56,
    AMMO_7_62
};

public abstract class Weapon {
    protected Rarity rare;
    protected int id;
    protected int damage;
    protected String skin;
    protected Weapon() {
        rare = Rarity.Standard;
        skin = "Standard";
    }
    protected Weapon(Rarity rare, String skin) {
        this.rare = rare;
        this.skin = skin;
    }
    protected abstract void UpdateDueToRarity();
    public abstract void InspectWeapon();
    public abstract void Attack();
    public void SetSkin(String skin_name) {
        skin = skin_name;
    }
    public boolean LevelUp() {
        switch (rare) {
            case Standard:
                rare = Rarity.Advanced;
                UpdateDueToRarity();
                return true;
            case Advanced:
                rare = Rarity.High_End;
                UpdateDueToRarity();
                return true;
            case High_End:
                rare = Rarity.Elite;
                UpdateDueToRarity();
                return true;
            default: return false;
        }
    }
    public void GetStatus() {
        switch (rare) {
            case Standard:
                System.out.print("Standard: ");
                break;
            case Advanced:
                System.out.print("Advanced: ");
                break;
            case High_End:
                System.out.print("High_End: ");
                break;
            case Elite:
                System.out.print("Elite: ");
                break;
        }

        switch (id) {
            case 0:
                System.out.print("Knife: ");
                break;
            case 1:
                System.out.print("Handgun: ");
                break;
            case 2:
                System.out.print("Assault Rifle: ");
                break;
            case 3:
                System.out.print("Sniper Rifles: ");
                break;
        }

        System.out.println("Damage: " + damage + " | Skin: " + skin);
    }
};

class Knife extends Weapon {
    @Override
    protected void UpdateDueToRarity() {
        switch (rare) {
            case FOR_EXAMPLE:
                System.out.println("\n\nAssaultRifle LevelUp methos has been called!\n");
                break;
            case Standard:
                break;
            case Advanced:
                damage += 5;
                break;
            case High_End:
                damage += 10;
                break;
            case Elite:
                damage += 15;
                break;
        }
    }
    public Knife(Rarity rare, String skin) {
        super(rare, skin);
        id = 0;
        damage = 55;
        UpdateDueToRarity();
    }
    public void SetSkin(String skin_name, int special_skin) {
        skin = skin_name + "_KNIFE";
    }
    @Override
    public void Attack() {
        System.out.println("*cutting stuff*");
    }
    @Override
    public void InspectWeapon() {
        System.out.println("*inspecting knife*");
    }
};

abstract class Firearm extends Weapon {
    protected Firearm(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type) {
        super(rare, skin);
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
    protected void FirearmMechanic(AmmoType ammo_type, int effective_range) {
        System.out.print("BANG with ");
        switch (ammo_type) {
            case AMMO_9:
                System.out.print("9mm ");
                break;
            case AMMO_45:
                System.out.print("45.ACP ");
                break;
            case AMMO_5_56:
                System.out.print("5.56 ");
                break;
            case AMMO_7_62:
                System.out.print("7.62 ");
                break;
        }
        System.out.print("at " + effective_range + " meters");
    }
};

class Handgun extends Firearm {
    @Override
    protected void UpdateDueToRarity() {
        switch (rare) {
            case Standard:
                reload_time = reload_time - 0;
                break;
            case Advanced:
                damage += 4;
                effective_range += 10;
                reload_time = reload_time - 0.3;
                break;
            case High_End:
                damage += 8;
                effective_range += 20;
                reload_time = reload_time - 0.6;
                break;
            case Elite:
                damage += 12;
                effective_range += 30;
                reload_time = reload_time - 0.9;
                break;
        }
    }
    public Handgun(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type) {
        super(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type);
    }
    @Override
    public void Attack() {
        System.out.print("*shooting with pistol: ");
        FirearmMechanic(ammo_type, effective_range);
        System.out.print("*");
    }
    @Override
    public void InspectWeapon() {
        System.out.println("*inspecting handgun*");
    }
};

class AssaultRifle extends Firearm {
    @Override
    protected void UpdateDueToRarity() {
        switch (rare) {
            case Standard:
                break;
            case Advanced:
                damage += 5;
                effective_range += 13;
                reload_time = reload_time - 0.3;
                break;
            case High_End:
                damage += 10;
                effective_range += 26;
                reload_time = reload_time - 0.6;
                break;
            case Elite:
                damage += 15;
                effective_range += 39;
                reload_time = reload_time - 0.9;
                break;
        }
    }
    public AssaultRifle(Rarity rare, String skin, int effective_range, int fire_rate, int damage, int magazine, double reload_time, AmmoType ammo_type) {
        super(rare, skin, effective_range, fire_rate, damage, magazine, reload_time, ammo_type);
    }
    @Override
    public void Attack() {
        System.out.print("*automatic shooting with assault rifle: ");
        FirearmMechanic(ammo_type, effective_range);
        System.out.print("*");
    }
    @Override
    public void InspectWeapon() {
        System.out.println("*inspecting assault rifle*");
    }
}


