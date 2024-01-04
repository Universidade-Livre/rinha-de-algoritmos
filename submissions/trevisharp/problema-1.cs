using System;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;

Stopwatch sw = new Stopwatch();
sw.Start();

if (args.Length < 1)
{

	Console.WriteLine("Envie o caminho da instância ao executar a aplicação 'dotnet run caminho'");
	return;
}

var path = args[0];
var ndata = read(path);
if (ndata is null)
	return;
var data = ndata.Value;

int gold = 0;
int size = data.w;
int lastIndex = data.seeds.Count - 1;
int dumbLimit = 2 * data.seeds.Max(s => s.w) - 1;
int total = data.seeds.Sum(s => s.w);
if (total <= size)
	dumbLimit = 0;

while (size > dumbLimit)
{
	if (lastIndex < 0)
		break;

	var best = data.seeds[lastIndex];	
	lastIndex--;
	
	if (size < best.w)
		continue;

	size -= best.w;
	gold += best.v;
}

int[] limits = new int[] { 0, 
	size / 1, size / 2,
	size / 3, size / 4,
	size / 5, size / 6,
	size / 7
};
int breakCond = limits.Sum();
var finalSeeds = new List<(int w, int v, float r)>();
for (int i = lastIndex; i > -1; i--)
{
	var s = data.seeds[i];
	if (limits[s.w] == 0)
		continue;
	
	finalSeeds.Add(s);
	limits[s.w]--;
	breakCond--;

	if (breakCond == 0)
		break;
}

int N = finalSeeds.Count + 1;
int W = size + 1;
int[] table = new int[N * W];

for (int i = 1; i < N; i++)
{
	for (int j = 1; j < W; j++)
	{
		var wi = finalSeeds[i - 1].w;
		var vi = finalSeeds[i - 1].v;
		table[i + N * j] = wi > j ? 
			table[i - 1 + N * j] : 
			int.Max(table[i - 1 + N * j], table[i - 1 + N * (j - wi)] + vi);
	}
}
gold += table[^1];

sw.Stop();

Console.WriteLine(sw.Elapsed.TotalSeconds);
Console.WriteLine(gold);

(int w, List<(int w, int v, float r)> seeds)? read(string path)
{
	if (!File.Exists(path))
	{
		Console.WriteLine("Arquivo não encontrado");
		return null;
	}

	var data = File.ReadAllLines(path);
	var baseInfo = data[0].Split('\t', ' ');

	int n = int.Parse(baseInfo[0]);
	int w = int.Parse(baseInfo[1]);
	var list = new List<(int w, int v, float r)>();

	for (int i = 1; i < n + 1; i++)
	{
		var info = data[i].Split('\t', ' ');
		int wi = int.Parse(info[0]);
		int vi = int.Parse(info[1]);
		list.Add((wi, vi, vi / (float)wi));
	}
	list = list
		.OrderBy(x => x.r)
		.ToList();

	return (w, list);
}
