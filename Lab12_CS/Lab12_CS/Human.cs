using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab12_CS
{
    enum Rank
    {
        DEPUTY,
        SUPERVISOR,
        SERGEANT,
        LIEUTENANT
    };

    internal class Human : IHuman
    {
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
        public String GetName() {
            return name;
        }
        public double GetWeight() {
            return weight;
        }
        public double GetHeight() {
            return height;
        }
        public int GetAge() {
            return age;
        }
        public virtual void UseWeapon(Weapon weapon) { 
            Console.Write("Suspect using deadly force! ");
            weapon.Attack();
        }

        public String toString() {
            return ("Info: " + name + " Age " + age + " Weight " + weight + " Height " + height);

        }

        public void ExampleCallVirtualMethod() {
            Console.Write(ExampleVirtualMethod());
        }
        private String ExampleVirtualMethod() {
            return "Hello World";
        }
    }

    class SWAT_Operator : Human
    {
    private Rank rank;
    public SWAT_Operator(String name, double weight, double height, int age, Rank rank)
            : base(name, weight, height, age)
    {
        this.rank = rank;
    }
    public override void UseWeapon(Weapon weapon) {
        Console.Write("Officer using deadly force! ");
        weapon.Attack();
    }
}
}
