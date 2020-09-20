using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace test
{
    class Program
    {   // функция составляет соотношение Безу, и возращает обратный элемент k в кольце по модулю p
        static BigInteger Bezu(BigInteger a, BigInteger b)
        {
            BigInteger p = 1, q = 0, r = 0, s = 1, k, x, y;
            while (a!=0 && b!=0) // пока a и b одновременно ненулевые
            {
                if (a >= b)
                {
                    a = a - b; //НОД по алгоритму Евклида
                    p = p - r; // возможные коэф. безу
                    q = q - s;
                }
                else
                {
                    b = b - a; 
                    r = r - p;
                    s = s - q;
                }
            }

            if (a!=0)
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


        // возвращает длину сообщения
        static int in_length(BigInteger m)
        {
            int n = 0;
            while (m != 0)
            {
                m /= 10;
                n++;
            }
            return n;
        }


        // разбивает сообщение на массив цифр
        static BigInteger[] long_to_mas(BigInteger m, int length)
        {
            BigInteger[] mas = new BigInteger[length];
            for (int i = length - 1; i >= 0; i--)
            {
                mas[i] = BigInteger.Remainder(m, 10);
                m /= 10;
            }
            
            return mas;
        }

        static void finalDecoder(BigInteger message)
        { 
            string result = "";
          
            char[] mass = { 'а','б', 'в', 'г',
                             'д', 'е', 'ё', 'ж',                    // массив алфавита
                                'з', 'и', 'й', 'к',
                                  'л', 'м', 'н', 'о',
                                'п', 'р', 'с', 'т',
                                   'у', 'ф', 'х', 'ц',
                               'ч', 'ш', 'щ', 'ъ',
                          'ы', 'ь', 'э', 'ю', 'я' };

            bool chet;
            int length = in_length(message); // длина сообщения
            if ((length % 2) == 0) chet = true; // определяем четная или нечетная длина
            else chet = false;
            BigInteger[] mas = long_to_mas(message, length);
            int i = 0;
            int m;
            while (i <= length - 2)
            {
                if (!chet) // если длина нечетная, то первый блок состоит из одной цифры
                {
                    
                    result += mass[(int)mas[i] - 1];
                    i++;
                    chet = true;
                }
                else
                {
                    m = (int)mas[i] * 10 + (int)mas[i + 1]; // берём нужную цифру и добавляем в результат
                    result += mass[m - 1];
                    i += 2;
                }
            }
            for (int j = 0; j < result.Length; j++)
            {
                Console.Write(result[j]); // выводим на экран результат
            }
            Console.WriteLine();
        }


        static void Main(string[] args)
        {
            /*BigInteger p = 127;
            BigInteger g = 3;
            BigInteger y = 48;
            BigInteger w = 122;
            BigInteger O = 22;
            BigInteger x = 0;*/
            /*  BigInteger p = 211;
              BigInteger g = 2;
              BigInteger y = 8;
              BigInteger w = 170;
              BigInteger O = 64;
              BigInteger x = 0;*/
            /* BigInteger p = 218012117;
              BigInteger g = 2;
              BigInteger y = 44618890;
              BigInteger w = 125176846;
              BigInteger O = 93916858;
              BigInteger x = 0;*/
            /*BigInteger p = 719;
            BigInteger g = 11;
            BigInteger y = 612;
            BigInteger w = 270;
            BigInteger O = 664;
            BigInteger x = 0;*/


            // Ввод данных
            BigInteger p, g, y, w, O, x=0;
            Console.WriteLine("p = ");
            p = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("g = ");
            g = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("y = ");
            y = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("o = ");
            O = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("w = ");
            w = BigInteger.Parse(Console.ReadLine());
            // поиск икса: перебираем x от 1 до p 
            // и ждем верного равенства g в степени х по модулю p равно у
            BigInteger sss = 1000000;
            for (BigInteger i = 0; i < p; i++)
            {
                if(i == sss)
                {
                    Console.WriteLine(sss / 1000000 + "mln");
                    sss += 1000000;
                }
                if (BigInteger.ModPow(g, i, p) == y) // функция возведения в степень по модулю
                {
                    x = i;
                    Console.WriteLine("x = "+x);
                    break;
                }
            }
            BigInteger k = BigInteger.ModPow(O, x, p); // k = О в степ у по мод p
            Console.WriteLine("k = " + k);
            BigInteger pt = p;
            BigInteger kmin = Bezu(pt, k); // поиск обратного элемента в кольце
            Console.WriteLine("k^(-1) = " + kmin);
            BigInteger ret = (w * kmin) % p; // возвращаемый ответ
            Console.WriteLine("otvet = " + ret);
            finalDecoder(ret);// перевод в буквы
            Console.ReadLine();
        }
    }
}
