const args = process.argv.slice(2);
const arg = args[0];

// ALGORITMO DE PROGRAMAÇÃO DINÂMICA PARA
// RESOLVER O PROBLEMA DA PLANTAÇÃO DE SEMENTES
function maxCoins(seeds, W) {
  const n = seeds.length;

  const mtz = Array.from({ length: n + 1 }, () => Array(W + 1).fill(0));

  for (let i = 1; i <= n; i++) {
    const { spaceRequired: wi, coins: vi } = seeds[i - 1];

    for (let j = 1; j <= W; j++) {
      mtz[i][j] = Math.max(
        mtz[i - 1][j],
        wi <= j ? mtz[i - 1][j - wi] + vi : 0
      );
    }
  }

  const selectedSeeds = [];
  for (let ni = n, Wj = W; ni > 0 && Wj > 0; ni--) {
    if (mtz[ni][Wj] !== mtz[ni - 1][Wj]) {
      selectedSeeds.push(seeds[ni - 1].seed);
      Wj -= seeds[ni - 1].spaceRequired;
    }
  }

  return { maxValue: mtz[n][W], selectedSeeds };
}

//CONSTRUÇÃO DOS ARQUIVOS PARA TESTES
const fs = require("fs");

function buildInventory(filename) {
  const content = fs.readFileSync(filename, "utf-8");

  const lines = content.trim().split("\n");

  const [totalSeeds, availableSpace] = lines[0].split(/\s+/).map(Number);

  const seeds = lines.slice(1).map((line, index) => {
    const [spaceRequired, coins] = line.split(/\s+/).map(Number);
    return { seed: `${index + 1}`, coins, spaceRequired };
  });

  return { totalSeeds, availableSpace, seeds };
}

const filename01 = "../../resources/instances/problem_01/exemplo_01.txt";
const inventory01 = buildInventory(filename01);

//DEBUG
// console.log("Total de sementes na array:", result01.totalSeeds);
// console.log("Total de espaços disponíveis:", result01.availableSpace);
// console.log("Sementes:", result01.seeds);

const result01 = maxCoins(inventory01.seeds, inventory01.availableSpace);

const filename02 = "../../resources/instances/problem_01/exemplo_02.txt";
const inventory02 = buildInventory(filename02);
const result02 = maxCoins(inventory02.seeds, inventory02.availableSpace);

const filename03 = "../../resources/instances/problem_01/exemplo_03.txt";
const inventory03 = buildInventory(filename03);
const result03 = maxCoins(inventory03.seeds, inventory03.availableSpace);

//IMPRIMIR O RESULTADO
// # Organizar as sementes em ordem crescente
const sortSeeds = (seeds) => {
  seeds.sort((a, b) => {
    if (!isNaN(a) && !isNaN(b)) {
      return parseInt(a, 10) - parseInt(b, 10);
    }
    if (!isNaN(a)) {
      return -1;
    }
    if (!isNaN(b)) {
      return 1;
    }
    return a.localeCompare(b);
  });
  return seeds;
};
// # Console log
const echoResult = (filename, result) => {
  const seedLabel =
    result.selectedSeeds.length > 1 ? "Sementes plantadas" : "Semente plantada";

  console.log(filename);
  if (arg?.toLowerCase() === "-s")
    console.log(
      `🌱 ${seedLabel}: ${sortSeeds(result.selectedSeeds).join(", ")}.`
    );
  console.log(`🟡 Valor máximo obtido: ${result.maxValue}`);
};

echoResult("../exemplo_01.txt", result01);
echoResult("../exemplo_02.txt", result02);
echoResult("../exemplo_03.txt", result03);
