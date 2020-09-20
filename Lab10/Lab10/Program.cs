using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab10
{

    class Program
    {
        static int perevod_to_win1251(char a)
        {
            return (int)a - 848;
        }
        static int[] string_to_win1251(string text)
        {
            int[] text_in_win1251 = new int[text.Length];
            for (int i = 0; i < text.Length; i++)
            {
                text_in_win1251[i] = perevod_to_win1251(text[i]);
            }
            return text_in_win1251;
        }
        static int[] list_to_mas(List<int[]> list)
        {
            int[] mas = new int[list.Count * 8];
            int k = 0;
            foreach (var m in list)
            {
                for (int i = 0; i < 8; i++)
                {
                    mas[k] = m[i];
                    // Console.Write(mas[k]);
                    k++;
                }
                // Console.WriteLine("");
            }
            return mas;
        }
        static int[] key_to_full(int[] mas)
        {
            int[] res = new int[64]; int sum = 0;
            for (int i = 0, j = 0; j < 56; i++, j++)
            {
                res[i] = mas[j];
                //  Console.Write(res[i]);
                sum += mas[j];
                if ((j + 1) % 7 == 0)
                {
                    i++;
                    if ((sum + 1) % 2 == 0)
                    {
                        res[i] = 0;
                    }
                    else res[i] = 1;
                    //   Console.WriteLine(res[i]);
                    sum = 0;
                }
            }
            return res;
        }
        static int[] sdvig_na1(int[] mas)
        {
            int[] ret = new int[mas.Length];
            for (int i = 0; i < mas.Length; i++)
            {
                if (i != mas.Length - 1) ret[i] = mas[i + 1];
                else ret[i] = mas[0];
            }
            return ret;
        }
        static int[] sdvig_na2(int[] mas)
        {
            int[] ret = new int[mas.Length];
            for (int i = 0; i < mas.Length; i++)
            {
                if (i < mas.Length - 2) ret[i] = mas[i + 2];
                else if (i == mas.Length - 2) ret[i] = mas[0];
                else ret[i] = mas[1];
            }
            return ret;
        }
        static int[] merge(int[] one, int[] two)
        {
            int[] ret = new int[one.Length * 2];
            for (int i = 0; i < one.Length * 2; i++)
            {
                if (i < one.Length) ret[i] = one[i];
                else ret[i] = two[i - one.Length];
            }
            return ret;
        }
        static void Main(string[] args)
        {
            string text = "бобоедви";
            string key = "бобоедв";
            int[] text_in_win1251 = string_to_win1251(text);
            //----------------------------------------------------
            List<int[]> text_in_binary = new List<int[]>();
            List<int[]> key_in_binary = new List<int[]>();
            for (int i = 0; i < text_in_win1251.Length; i++)
            {
                int[] mas = new int[8];
                string s = Convert.ToString(text_in_win1251[i], 2);
                for (int j = 0; j < 8; j++)
                {
                    mas[j] = (int)Char.GetNumericValue(s[j]);
                }
                text_in_binary.Add(mas);
                if (i != 7) key_in_binary.Add(mas);
            }
            //-----------------------------------------------------
            int[] mas_key_in_binary = list_to_mas(key_in_binary);
            Console.WriteLine("------------------");
            int[] full_key = key_to_full(mas_key_in_binary);
            int[] C0 = {
                57,49,41,33,25,17,9,1,58,50,42,34,26,18,
                10,2,59,51,43,35,27,19,11,3,60,52,44,36
            };
            int[] D0 = {
                63,55,47,39,31,23,15,7,62,54,46,38,30,22,
                14,6,61,53,45,37,29,21,13,5,28,20,12,4
            };
            int[] ki = {
                14,17,11,24,1,5,
                3,28,15,6,21,10,
                23,19,12,4,26,8,
                16,7,27,20,13,2,
                41,52,31,37,47,55,
                30,40,51,45,33,48,
                44,49,39,56,34,53,
                46,42,50,36,29,32
            };
            //--------
            List<int[]> block_ci = new List<int[]>();
            List<int[]> block_di = new List<int[]>();
            List<int[]> block_ki = new List<int[]>();
            block_ci.Add(C0);
            block_di.Add(D0);
            block_ki.Add(merge(C0, D0));
            for (int i = 1; i <= 16; i++)
            {
                if (i == 1 || i == 2 || i == 9 || i == 16)//сдавиг на 1
                {
                    block_ci.Add(sdvig_na1(block_ci[i - 1]));
                    block_di.Add(sdvig_na1(block_di[i - 1]));
                }
                else// сдвиг на 2
                {
                    block_ci.Add(sdvig_na2(block_ci[i - 1]));
                    block_di.Add(sdvig_na2(block_di[i - 1]));
                }
                block_ki.Add(merge(block_ci[i], block_di[i]));
            }

        }
        int[] pc = {
            58,50,42,34,26,18,10,2,
            60,52,44,36,28,20,12,4,
            62,54,46,38,30,22,14,6,
            64,56,48,40,32,24,16,8,
            57,49,41,33,25,17,9,1,
            59,51,43,35,27,19,11,3,
            61,53,45,37,29,21,13,5,
            63,55,47,39,31,23,15,7
        };
        int[] pc_m1 =
        {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9,  49, 17, 57, 25
        };

    }
}
