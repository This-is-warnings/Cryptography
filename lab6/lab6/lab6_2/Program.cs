using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
namespace lab6_2
{
    class Program
    {

        static BigInteger Bezu(BigInteger a, BigInteger b) // Безу как в лабораторной номер 8
        {
            BigInteger p = 1, q = 0, r = 0, s = 1, k, x, y;
            while (a != 0 && b != 0)
            {
                if (a >= b * 100000000)             // только здесь изменения: когда а было намного больше чем b, алгоритм считался очень долго
                {                                   // и я добавил чтобы отнималось по разрядам сразу 100 млн, если а больше чем b*100 млн и т. д.
                    a = a - b * 100000000;
                    p = p - r * 100000000;
                    q = q - s * 100000000;
                }
                else if (a >= b*10000000)
                {
                    a = a - b*10000000;
                    p = p - r*10000000;
                    q = q - s*10000000;
                }
                else if (a >= b * 1000000)
                {
                    a = a - b * 1000000;
                    p = p - r * 1000000;
                    q = q - s * 1000000;
                }
                else if (a >= b * 100000)
                {
                    a = a - b * 100000;
                    p = p - r * 100000;
                    q = q - s * 100000;
                }
                else if (a >= b * 10000)
                {
                    a = a - b * 10000;
                    p = p - r * 10000;
                    q = q - s * 10000;
                }
                else if(a>=b)
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
               // Console.WriteLine("f = " + a + " e = " + b);
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



        // здесь вывод как в 8 лабораторной
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
           
            if(length==1)
            {
                Console.WriteLine(mass[(int)message - 1]);
                return;

            }
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
            // BigInteger p = 2038074761, q = 2038074769, e = 1299709, w = 591405405315775798,n; // условие по заданию
            BigInteger n, e, w, p, q;
            Console.WriteLine("Введите p ");
            p = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("Введите q ");
            q = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("Введите e ");
            e = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("Введите шифр ");
            w = BigInteger.Parse(Console.ReadLine());
            n = p * q;

            BigInteger f = (p - 1) * (q - 1); // функция эйлера
            
            BigInteger d = Bezu(f, e); // высчитываем d по безу
           
            BigInteger a = w % p; // шифр текст
            BigInteger b = w % q;


            BigInteger a_a = BigInteger.ModPow(a, d, p);// открытый текст
            BigInteger b_b = BigInteger.ModPow(b, d, q);
            Console.WriteLine("f = " + f + "\n" +
                "d = " + d + "\n" +
                "Шифрр текст(" + a + "," + b+ ")\n" +
                //"b = " + b + "\n" +
                "Откр. текст (" + a_a + "," + b_b + ")\n");
                
            // формула гарнера (((a-b)(q^(-1)modp)modp)q+b
            BigInteger q_temp = q;// q и p будут изменены в безу, поэтому сохраняем их
            BigInteger p_temp = p;
            while(q_temp>p)// пока q не будет меньше p, отнимаем p от q
            {
                q_temp -= p;
            }
            BigInteger q_vm1 = Bezu(p_temp, q_temp); // обратный элемент по модулю через безу
            Console.WriteLine("q^(-1)modp = " + q_vm1);
            //BigInteger c = ((a - b) * (q_vm1) % p) * q + b; // эта формула не всегда работала, и я поинтересовалсяя у одногруппника, почему так
            BigInteger c = (((((a_a - b_b) * q_vm1)) % p) + p) % p * q + b_b; // он сказал что вы дали вот эту формулу, которая обходит отрицательный результат
            Console.WriteLine(c);
            finalDecoder(c);
        }
    }
}
