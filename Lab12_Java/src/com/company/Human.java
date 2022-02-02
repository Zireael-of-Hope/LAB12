package com.company;

enum Rank {
    DEPUTY,
    SUPERVISOR,
    SERGEANT,
    LIEUTENANT
};

public class Human implements IHuman {
    protected String name;
    protected double weight;
    protected double height;
    protected int age;

    public Human(String name, double weight, double height, int age) {
        this.age = age;
        this.height = height;
        this.name = name;
        this.weight = weight;
    }
    public Human(Human other) {
        name = other.name;
        weight = other.weight;
        height = other.height;
        age = other.age;
    }
    @Override
    public String GetName() {
        return name;
    }
    @Override
    public double GetWeight() {
        return weight;
    }
    @Override
    public double GetHeight() {
        return height;
    }
    @Override
    public int GetAge() {
        return age;
    }
    @Override
    public void UseWeapon(Weapon weapon) {
        System.out.print("Suspect using deadly force! ");
        weapon.Attack();
    }

    public String toString() {
        return ("Info: " + name + " Age " + age + " Weight " + weight + " Height " + height);

    }

    public void ExampleCallVirtualMethod() {
        System.out.print(ExampleVirtualMethod());
    }
    private String ExampleVirtualMethod() {
        return "Hello World";
    }
};

class SWAT_Operator extends Human {
    private Rank rank;
    public SWAT_Operator(String name, double weight, double height, int age, Rank rank) {
        super(name, weight, height, age);
        this.rank = rank;
    }
    @Override
    public void UseWeapon(Weapon weapon) {
        System.out.print("Officer using deadly force! ");
        weapon.Attack();
    }
}
