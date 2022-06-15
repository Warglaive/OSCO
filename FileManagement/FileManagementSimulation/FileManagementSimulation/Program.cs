using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Experiment 1
            //var keys = File.ReadAllText(@"D:\OSCO\FileManagement\TransactionFile.txt").Split(
            //new string[] { Environment.NewLine },
            //StringSplitOptions.None);

            //var pileFile = File.ReadAllText(@"D:\OSCO\FileManagement\PileFile.txt").Split(
            //new string[] { Environment.NewLine },
            //StringSplitOptions.None);

            var path = "D:\\OSCO\\FileManagement\\TransactionFile.txt";
            var bytesLength = File.ReadAllBytes(path).Length;
            Console.WriteLine($"count the number of byte accesses needed {bytesLength}");
            var averageAccessTime = File.ReadAllBytes(path);
            var current = File.GetLastAccessTime(path).Second;
            Console.WriteLine(current);
            File.ReadLines(@"D:\OSCO\FileManagement\TransactionFile.txt").SkipWhile(line => !line.Contains("CustomerEN"))
                .TakeWhile(line => !line.Contains('\n'));
        }
    }
}