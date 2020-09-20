using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace lab9_
{
    class Program
    {

        static bool is_prime(BigInteger c)
        {
            for (BigInteger d = 2; d * d <= c; d++)
            {
                // если разделилось нацело, то составное
                if (c % d == 0)
                    return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            BigInteger c;
            c = BigInteger.Parse(Console.ReadLine()); // считываем c
            BigInteger p; // p - ближайшее простое
            BigInteger ct = c;
            while (true) // вычисляем следующее простое число после с
            {
                ct++;
                if (is_prime(ct))
                    break;
            }
            p = ct;
            Random rnd = new Random();
            BigInteger g = 1, x, k;// рандомно генерируем x,k


            bool b;

            while (true)//ищем g
            {
                b = true;
                if (BigInteger.ModPow(g, p - 1, p) == 1)
                {
                    for (int i = 1; i < p - 1; i++)
                    {
                        if (BigInteger.ModPow(g, i, p) == 1)
                        {
                            b = false;
                            break;
                        }
                    }
                    if (b)
                    {
                        break;
                    }

                }
                g++;
            }

            try
            {
                x = rnd.Next(2, (int)p);//генерируем от 2 до p
                k = rnd.Next(2, (int)p);
            }
            catch
            {
                x = rnd.Next(2, Int32.MaxValue);
                k = rnd.Next(2, Int32.MaxValue);
            }
            BigInteger y = BigInteger.ModPow(g, x, p); // вычисляем y и k
            BigInteger K = BigInteger.ModPow(y, k, p);

            BigInteger w = (K * c) % p; // вычисляем w
            BigInteger O = BigInteger.ModPow(g, k, p); // вычисляем O
            Console.WriteLine("p = " + p + " , g = " + g + " , y = " + y + " , w = " + w + " , O = " + O);
            Console.ReadLine();
        }
    }
}
