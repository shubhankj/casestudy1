using System;

namespace ConsoleApplication1
{
    class Program
    {
        void SamplePrint()
        {
            Console.WriteLine("Hello");
            Console.ReadKey();
            Console.ReadKey();
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.SamplePrint();
        }
    }
}
