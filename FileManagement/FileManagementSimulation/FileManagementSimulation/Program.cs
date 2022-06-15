using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Experiment 1
            ExperimentOne();
            //Experiment 2
            Console.WriteLine("Second Experiment START...");

            var sequentialFile = @"D:\OSCO\FileManagement\SequentialFile.txt";
            var pileFile = File.ReadAllText(@"D:\OSCO\FileManagement\PileFile.txt");


            var pileFileLength = pileFile.Length;

            var bytesLength = File.ReadAllBytes(sequentialFile).Length;
            Console.WriteLine($"count the number of byte accesses needed {bytesLength}");
            var allBytes = File.ReadAllBytes(sequentialFile);
            decimal averageAccessTime = File.GetLastAccessTime(sequentialFile).Second;
            Console.WriteLine(averageAccessTime / pileFileLength);
            File.ReadLines(@"D:\OSCO\FileManagement\TransactionFile.txt").SkipWhile(line => !line.Contains("CustomerEN"))
                .TakeWhile(line => !line.Contains('\n'));
            //ratio
            decimal ratio = (decimal)sequentialFile.Length / (decimal)allBytes.Length;
            Console.WriteLine($"Ratio: {ratio}");
            Console.WriteLine("Second Experiment END..." + Environment.NewLine);

        }

        private static void ExperimentOne()
        {
            Console.WriteLine("First Experiment START...");
            var transactionFile = @"D:\OSCO\FileManagement\TransactionFile.txt";
            var pileFile = File.ReadAllText(@"D:\OSCO\FileManagement\PileFile.txt");
            var pileFileLength = pileFile.Length;

            var bytesLength = File.ReadAllBytes(transactionFile).Length;
            Console.WriteLine($"count the number of byte accesses needed {bytesLength}");
            var allBytes = File.ReadAllBytes(transactionFile);
            decimal averageAccessTime = File.GetLastAccessTime(transactionFile).Second;
            Console.WriteLine(averageAccessTime / pileFileLength);
            File.ReadLines(@"D:\OSCO\FileManagement\TransactionFile.txt").SkipWhile(line => !line.Contains("CustomerEN"))
                .TakeWhile(line => !line.Contains('\n'));
            Console.WriteLine("First Experiment END...\n");
        }
    }
}