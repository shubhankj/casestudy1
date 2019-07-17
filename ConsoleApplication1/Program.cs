using System;

namespace ConsoleApplication1
{
    public class Program
    {
        public bool SamplePrint()
        {
            Console.WriteLine("Hello");
            return true;
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.SamplePrint();
        }
    }
}