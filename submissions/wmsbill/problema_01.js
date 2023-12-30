const fs = require("node:fs");
const args = process.argv.slice(2);

function parse(fileContent) {
  const [inputConfig, ...entries] = fileContent
    .split("\n")
    .filter((line) => line.length > 0)
    .map((line) => line.split(/\W/).map(Number));

  return [inputConfig[1], entries];
}

function main(file) {
  const fileContent = fs.readFileSync(file, "utf8");
  const [spaces, entries] = parse(fileContent);
  const table = new Map();

  entries
    .sort((a, b) => b[1] / b[0] - a[1] / a[0])
    .forEach(([size, value]) => {
      if (table.has(size)) {
        table.get(size).push(value);
        return;
      }

      table.set(size, [value]);
    });

  const pointers = Array.from({ length: table.size + 1 }, () => 0);
  const profitTable = [{ value: 0, pointers }];

  for (let i = 1; i <= spaces; i++) {
    let maxProfit = { value: 0, pointers: [] };

    for (const [size, items] of table) {
      const lastProfit = profitTable[i - size];

      if (!lastProfit) {
        break;
      }

      const value = items[lastProfit.pointers[size]] ?? 0;
      const profit = lastProfit.value + value;

      if (profit > maxProfit.value) {
        const newPointers = lastProfit.pointers.slice();
        newPointers[size]++;
        maxProfit = {
          value: profit,
          pointers: newPointers,
        };
      }
    }

    profitTable[i] = maxProfit;
  }

  return profitTable.at(-1).value;
}

const result = main(
  args[0] ?? "./resources/instances/problem_01/exemplo_03.txt"
);
console.log(result);
