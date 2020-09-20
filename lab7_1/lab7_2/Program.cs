using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
namespace lab7_2
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

        static int nod(int a, int b) 
        {
            int k;
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

        static int Bezu(int a, int b) // из лабы 8
        {
            int p = 1, q = 0, r = 0, s = 1, k, x, y;
            while (a != 0 && b != 0) // пока a и b одновременно ненулевые
            {
                if (a >= b)
                {
                    a = a - b; //НОД по алгоритму Евклида
                    p = p - r; 
                    q = q - s;
                }
                else
                {
                    b = b - a;
                    r = r - p;
                    s = s - q;
                }
            }

            if (a != 0)
            {
                k = a;
                x = p; // если а не ноль то p и q коэф безу
                y = q;
            }
            else
            {
                k = b;
                x = r; // если b не ноль то r и s коэф безу
                y = s;
            }
            // Console.WriteLine("x = " + x + " , y = " + y);
            return y; // возвращаем только нужные значения
        }

        static void Main(string[] args)
        {
            int c;
            Console.WriteLine("Введите c");
            c = int.Parse(Console.ReadLine());
            int n = c + 1;
            while (true)
            {
                if (razlojenie_na_prostoe(n).Count == 2 && nod(n, c) == 1) // находим такое n, которое взаимно простое с с и имеет только два делителя
                {
                    break;
                }
                else n++;
            }
            List<int> v = razlojenie_na_prostoe(n); // делители n
            int p = v[0];
            int q = v[1];
            int f = (p - 1) * (q - 1); // функция эйлера
            int e = 2;
            while (true)
            {
                if (nod(e, f) == 1) break; // перебираем e: если e и f взимно простые то выходим из цикла
                else e++;
            }

            int crt_c1 = c % p; // представлени числа c
            int crt_c2 = c % q;
            int a = (int)BigInteger.ModPow(crt_c1, e, p); // представление шифра
            int b = (int)BigInteger.ModPow(crt_c2, e, q);
            Console.WriteLine("CRT представление c (" + crt_c1 + ", " + crt_c2 + ")\n"
                + "CRT представление шифра (" + a + ", " + b + ")");
            int q_temp = q;// q и p будут изменены в безу, поэтому сохраняем их
            int p_temp = p;
            while (q_temp > p)// пока q не будет меньше p, отнимаем p от q
            {
                q_temp -= p;
            }
            int q_vm1 = Bezu(p_temp, q_temp);// обратный для q
            int w = (((((a - b) * q_vm1)) % p) + p) % p * q + b;// по формуле из 6 лабы
            Console.WriteLine("n = " + n + " , p = " + p + " , q = " + q + "\nf = " + f + "\nе = " + e + "\nw = " + w);
        }
    }
}
