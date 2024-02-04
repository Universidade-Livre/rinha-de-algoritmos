using System.Diagnostics;

namespace madebyluque;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length < 1)
        {

            Console.WriteLine("Informe o caminho do arquivo.");
            return;
        }

        var sw = new Stopwatch();
        sw.Start();

        var filePath = args[0];
        var text = File.ReadAllLines(filePath);
        string[] firstLine = text[0].Split(" ");
        int n = int.Parse(firstLine[0]);
        int W = int.Parse(firstLine[1]);

        int[] weights = new int[n];
        int[] profits = new int[n];

        for (var i = 1; i <= n; i++)
        {
            string[] values = text[i].Split('\t');
            weights[i - 1] = int.Parse(values[0]);
            profits[i - 1] = int.Parse(values[1]);
        }

        Console.WriteLine("Resultado: " + KnapSack(W, weights, profits, n));
        sw.Stop();
        Console.WriteLine("Tempo gasto: " + sw.Elapsed);
    }

    static int KnapSack(int W, int[] weights, int[] profits, int n)
    {
        int[] maxValues = new int[W + 1];

        for (int currentItem = 1; currentItem <= n; currentItem++)
        {
            for (int currentCapacity = W; currentCapacity >= 0; currentCapacity--)
            {
                if (weights[currentItem - 1] <= currentCapacity)
                {
                    maxValues[currentCapacity] = Math.Max(maxValues[currentCapacity],
                        maxValues[currentCapacity - weights[currentItem - 1]] + profits[currentItem - 1]);
                }
            }
        }

        return maxValues[W];
    }
}
