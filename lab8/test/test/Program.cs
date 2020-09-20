using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace test
{
    class Program
    {   // ������� ���������� ����������� ����, � ��������� �������� ������� k � ������ �� ������ p
        static BigInteger Bezu(BigInteger a, BigInteger b)
        {
            BigInteger p = 1, q = 0, r = 0, s = 1, k, x, y;
            while (a!=0 && b!=0) // ���� a � b ������������ ���������
            {
                if (a >= b)
                {
                    a = a - b; //��� �� ��������� �������
                    p = p - r; // ��������� ����. ����
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
                x = p; // ���� � �� ���� �� p � q ���� ����
                y = q;
            }
            else
            {
                k = b;
                x = r; // ���� b �� ���� �� r � s ���� ����
                y = s;
            }
           // Console.WriteLine("x = " + x + " , y = " + y);
            return y; // ���������� ������ ������ ��������
        }


        // ���������� ����� ���������
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


        // ��������� ��������� �� ������ ����
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
          
            char[] mass = { '�','�', '�', '�',
                             '�', '�', '�', '�',                    // ������ ��������
                                '�', '�', '�', '�',
                                  '�', '�', '�', '�',
                                '�', '�', '�', '�',
                                   '�', '�', '�', '�',
                               '�', '�', '�', '�',
                          '�', '�', '�', '�', '�' };

            bool chet;
            int length = in_length(message); // ����� ���������
            if ((length % 2) == 0) chet = true; // ���������� ������ ��� �������� �����
            else chet = false;
            BigInteger[] mas = long_to_mas(message, length);
            int i = 0;
            int m;
            while (i <= length - 2)
            {
                if (!chet) // ���� ����� ��������, �� ������ ���� ������� �� ����� �����
                {
                    
                    result += mass[(int)mas[i] - 1];
                    i++;
                    chet = true;
                }
                else
                {
                    m = (int)mas[i] * 10 + (int)mas[i + 1]; // ���� ������ ����� � ��������� � ���������
                    result += mass[m - 1];
                    i += 2;
                }
            }
            for (int j = 0; j < result.Length; j++)
            {
                Console.Write(result[j]); // ������� �� ����� ���������
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


            // ���� ������
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
            // ����� ����: ���������� x �� 1 �� p 
            // � ���� ������� ��������� g � ������� � �� ������ p ����� �
            BigInteger sss = 1000000;
            for (BigInteger i = 0; i < p; i++)
            {
                if(i == sss)
                {
                    Console.WriteLine(sss / 1000000 + "mln");
                    sss += 1000000;
                }
                if (BigInteger.ModPow(g, i, p) == y) // ������� ���������� � ������� �� ������
                {
                    x = i;
                    Console.WriteLine("x = "+x);
                    break;
                }
            }
            BigInteger k = BigInteger.ModPow(O, x, p); // k = � � ���� � �� ��� p
            Console.WriteLine("k = " + k);
            BigInteger pt = p;
            BigInteger kmin = Bezu(pt, k); // ����� ��������� �������� � ������
            Console.WriteLine("k^(-1) = " + kmin);
            BigInteger ret = (w * kmin) % p; // ������������ �����
            Console.WriteLine("otvet = " + ret);
            finalDecoder(ret);// ������� � �����
            Console.ReadLine();
        }
    }
}
