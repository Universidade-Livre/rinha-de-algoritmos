const fs = require("node:fs");
const args = process.argv.slice(2);

function* range(start, end) {
  for (let i = start; i <= end; i++) {
    yield i;
  }
}

function parse(fileContent) {
  const [inputConfig, ...entries] = fileContent
    .split("\n")
    .filter((line) => line.length > 0)
    .map((line) => line.split(/\W/).map(Number));

  return [inputConfig, entries];
}

function buildGraph(graphConfig, nodeLength) {
  const graph = new Map(
    [...range(1, nodeLength)].map((node) => [node, new Set()])
  );

  for (const [from, to] of graphConfig) {
    graph.get(from).add(to);
    graph.get(to).add(from);
  }

  return graph;
}

function removeCycle(graph, root) {
  const tree = new Map(
    [...range(1, graph.size)].map((node) => [node, new Set()])
  );
  const visited = new Set([root]);
  const queue = [root];

  while (queue.length > 0) {
    const current = queue.shift();

    for (const neighbor of graph.get(current)) {
      if (visited.has(neighbor)) {
        continue;
      }

      tree.get(current).add(neighbor);
      tree.get(neighbor).add(current);
      visited.add(neighbor);
      queue.push(neighbor);
    }
  }

  return tree;
}

function main(file) {
  const fileContent = fs.readFileSync(file, "utf8");
  const [[nodeLength], graphConfig] = parse(fileContent);
  const graph = buildGraph(graphConfig, nodeLength);

  const sizes = [...range(1, nodeLength)]
    .map((node) => removeCycle(new Map(graph), node))
    .map((tree) => {
      let leaves = 0;

      tree.forEach((neighbors) => {
        leaves += neighbors.size === 1 ? 1 : 0;
      });

      return leaves;
    });

  return Math.max(...sizes);
}

const result = main(
  args[0] ?? "./resources/instances/problem_02/exemplo_01.txt"
);

console.log(result);
