import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;

public class Problema_1 {

    static class Tuple {
        int weight;
        int profit;

        Tuple(int weight, int profit) {
            this.weight = weight;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        String[] files = {"Problema-1/Resources/exemplo_01.txt", "Problema-1/Resources/exemplo_02.txt", "Problema-1/Resources/exemplo_03.txt"};

        for (String fileName : files) {
            try {
                File file = new File(fileName);
                Scanner scanner = new Scanner(file);

                int n = scanner.nextInt(); 
                int s = scanner.nextInt(); 
                Tuple[] tuples = new Tuple[n];

                for (int i = 0; i < n; i++) {
                    int weight = scanner.nextInt();
                    int profit = scanner.nextInt();
                    tuples[i] = new Tuple(weight, profit);
                }

                Arrays.sort(tuples, (a, b) -> Double.compare((double) b.profit / b.weight, (double) a.profit / a.weight));
                tuples = Arrays.stream(tuples).filter(tup -> tup.weight <= s).toArray(Tuple[]::new);

                long startTime = System.nanoTime();
                int result = calcProfit(tuples, n, s, new HashMap<>());
                long endTime = System.nanoTime();

                long durationInMillis = (endTime - startTime) / 1_000_000;
                System.out.println("Resultado para " + fileName + ": " + result);
                System.out.println("Tempo de execução de " + fileName + " " + durationInMillis + " ms");

                scanner.close();
            } catch (FileNotFoundException e) {
                System.out.println("Arquivo não encontrado: " + fileName);
                e.printStackTrace();
            }
        }
    }

    private static int calcProfit(Tuple[] tuples, int n, int s, HashMap<String, Integer> memorization) {
        String key = n + "," + s;
        if (memorization.containsKey(key)) {
            return memorization.get(key);
        }

        if (n == 0 || s == 0) {
            return 0;
        }

        if (tuples[n - 1].weight > s) {
            memorization.put(key, calcProfit(tuples, n - 1, s, memorization));
        } else {
            int profit1 = tuples[n - 1].profit + calcProfit(tuples, n - 1, s - tuples[n - 1].weight, memorization);
            int profit2 = calcProfit(tuples, n - 1, s, memorization);
            memorization.put(key, Math.max(profit1, profit2));
        }

        return memorization.get(key);
    }
}