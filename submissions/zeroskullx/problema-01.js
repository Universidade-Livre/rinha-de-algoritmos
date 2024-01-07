const args = process.argv.slice(2);
const arg0 = args[0];
const arg1 = args[1];

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
  if (!fs.existsSync(filename)) {
    console.error(`Arquivo ${filename} não encontrado.`);
    return;
  }

  const content = fs.readFileSync(filename, "utf-8");

  const lines = content.trim().split("\n");

  const [totalSeeds, availableSpace] = lines[0].split(/\s+/).map(Number);

  //Escolhas, pqn?! Mesmo diminuindo o desempenho,
  //coloquei uma validação aqui.
  const seeds = lines.slice(1).map((line, index) => {
    const [spaceRequired, coins] = line.split(/\s+/).map(Number);
    if (isNaN(spaceRequired) || isNaN(coins)) {
      return null
    }

    return { seed: `${index + 1}`, coins, spaceRequired };
  }).filter(seed => seed !== null);

  const results = maxCoins(seeds, availableSpace);

  echoResult(results);
  //return { totalSeeds, availableSpace, seeds };
}

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

const echoResult = (result) => {

  const seedLabel =
    result.selectedSeeds.length > 1 ? "Sementes plantadas" : "Semente plantada";


  if (arg1?.toLowerCase() === "-s")
    console.log(
      `🌱 ${seedLabel}: [${sortSeeds(result.selectedSeeds).join(", ")}].`
    );
  console.log(`◽ Solução: ${result.maxValue}`);
};

//EXEC
buildInventory(arg0);
