using System;

class Program
{
    static void Main(string[] args)
    {
        if (!Int32.TryParse(Console.ReadLine(), out var a) || !Int32.TryParse(Console.ReadLine(), out var b))
        {
            Console.WriteLine("Not a number");
            return;
        }

        var s = Console.ReadLine();
        if (string.IsNullOrEmpty(s))
        {
            Console.WriteLine("Wrong sign");
            return;
        }

        int result;
        switch (s[0])
        {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) { Console.WriteLine("Division by zero"); return; }
                result = a / b;
                break;
            default:
                Console.WriteLine("Wrong sign");
                return;
        }

        Console.WriteLine($"Decimal:     {result}");
        Console.WriteLine($"Hexadecimal: {Convert.ToString(result, 16).ToUpper()}");
        Console.WriteLine($"Binary:      {Convert.ToString(result, 2)}");
    }
}
