using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab12_CS
{
    internal interface IHuman
    {
        public void UseWeapon(Weapon weapon);
        public int GetAge();
        public String GetName();
        public double GetWeight();
        public double GetHeight();
    }
}
