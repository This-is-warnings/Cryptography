using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace lab7
{
    class Program
    {
        static List<int> razlojenie_na_prostoe(int n)
        {
            List<int> v = new List<int>();
            int p = n;
            int z = 2;
            //Console.Write("Простые множители числа " + n + " : ");
            while (p > 1)
            {
                while (p % z == 0) // пока z - простое с p
                {
                    v.Add(z);
                   // Console.Write(z + " ");
                    p /= z; // делим p на z
                }
                z++;// идем к следующему числу
            }
            return v;
        }

        static int nod(int a, int b) // Безу как в лабораторной номер 8
        {
            int  k;
            while (a != 0 && b != 0)
            {
                if (a >= b)
                {
                    a = a - b;
                }
                else
                {
                    b = b - a;
                }
            }

            if (a != 0)
            {
                k = a;
            }
            else
            {
                k = b;
            }
            // Console.WriteLine("x = " + x + " , y = " + y);
            return k;
        }

        static void Main(string[] args)
        {
            int c;
            Console.WriteLine("Введите c");
            c = int.Parse(Console.ReadLine());
            int n = c+1;
            while(true)
            {
                if (razlojenie_na_prostoe(n).Count == 2 && nod(n,c)==1) // находим такое n, которое взаимно простое с с и имеет только два делителя
                {
                    break;
                }
                else n++;
            }
            List<int> v = razlojenie_na_prostoe(n);
            int p = v[0];
            int q = v[1];
            int f = (p - 1) * (q - 1);
            int e = 2;
            while(true)
            {
                if (nod(e, f) == 1) break;
                else e++;
            }
            int w = (int)BigInteger.ModPow(c, e, n);
            Console.WriteLine("n = " + n + " , p = " + p + " , q = " + q +"\nf = " + f + "\nе = " + e + "\nw = " + w);
        }
    }
}
