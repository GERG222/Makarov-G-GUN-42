using System;

public class Program
{
    public static void Main()
    {
        // === ЗАДАЧА А ===
        // Задание 1: Массив из 8 чисел Фибоначчи
        int[] fibonacci = new int[8];
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        for (int i = 2; i < fibonacci.Length; i++)
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        // Задание 2: Массив названий 12 месяцев
        string[] months = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        // Задание 3: Матрица 3x3 со степенями чисел 2, 3 и 4
        int[,] matrix = {
           { (int)Math.Pow(2, 1), (int)Math.Pow(3, 1), (int)Math.Pow(4, 1) },
           { (int)Math.Pow(2, 2), (int)Math.Pow(3, 2), (int)Math.Pow(4, 2) },
           { (int)Math.Pow(2, 3), (int)Math.Pow(3, 3), (int)Math.Pow(4, 3) }
        };
        // Задание 4: Ступенчатый (jagged) массив
        double[][] jaggedArray = new double[3][];
        jaggedArray[0] = new double[] { 1, 2, 3, 4, 5 };
        jaggedArray[1] = new double[] { Math.E, Math.PI };
        jaggedArray[2] = new double[] { Math.Log10(1), Math.Log10(10), Math.Log10(100), Math.Log10(1000) };
        // === ЗАДАЧА Б ===
        int[] array = { 1, 2, 3, 4, 5 };
        int[] array2 = { 7, 8, 9, 10, 11, 12, 13 };
        // Задание 5: Копирование 3-х элементов
        Array.Copy(array, array2, 3);
        // Задание 6: Изменение размера массива в 2 раза через ref
        int newSize = array.Length * 2;
        Array.Resize(ref array, newSize);
        Console.WriteLine("Все задания выполнены успешно!");
    }
}