using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
namespace lab6
{
    class Program
    {
        static List<int> razlojenie_na_prostoe(int n)
        {
            List<int> v = new List<int>();
            int p = n;
            int z = 2;
            Console.Write("Простые множители числа " + n + " : ");
            while (p > 1)
            {
                while (p % z == 0) // пока z - простое с p
                {
                    v.Add(z);
                    Console.Write(z + " ");
                    p /= z; // делим p на z
                }
                z++;// идем к следующему числу
            }
            return v;
        }
        static int func_eilera(List<int> v)
        {
            int res = 1;
            foreach (int n in v)// умнодаем все простые числа (p1-1)*(p2-1)*.... и т.д.
            {
                res *= (n - 1);
            }
            return res;
        }

        static int Bezu(int a, int b) // Безу как в лабораторной номер 8
        {
            int p = 1, q = 0, r = 0, s = 1, k, x, y;
            while (a != 0 && b != 0)
            {
                if (a >= b)
                {
                    a = a - b;
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
                x = p;
                y = q;
            }
            else
            {
                k = b;
                x = r;
                y = s;
            }
            // Console.WriteLine("x = " + x + " , y = " + y);
            return y;
        }


        static void Main(string[] args)
        {
            int n, e, w;
            Console.WriteLine("Введите n ");
            n = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите e ");
            e = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите w ");
            w = int.Parse(Console.ReadLine());
            List<int> prostie;
            prostie = razlojenie_na_prostoe(n); // разлаживаем n на простые
            int f = func_eilera(prostie); // функция эйлера
            Console.WriteLine("\nФункция Эйлера: " + f);
            int d = Bezu(f, e); // обратный по модулю через безу
            Console.WriteLine("Число d = " + d);
            BigInteger c = BigInteger.ModPow(w, d, n);// возведение в степень по модулю
            Console.WriteLine("c = " + c);
        }
    }
}
