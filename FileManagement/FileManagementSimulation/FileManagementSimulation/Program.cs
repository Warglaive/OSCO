﻿using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Experiment 1
            var keys = File.ReadAllText(@"D:\OSCO\FileManagement\TransactionFile.txt").Split(
             new string[] { Environment.NewLine },
                 StringSplitOptions.None);

            var pileFile = File.ReadAllText(@"D:\OSCO\FileManagement\PileFile.txt").Split(
             new string[] { Environment.NewLine },
                 StringSplitOptions.None);



        }
    }
}