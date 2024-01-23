import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class problema1 {

    public static void main(String[] args) {
        try {
            solve(args);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void solve(String[] args) throws IOException {
        String fileName = null;
        
        for(String arg : args){
            if(arg.startsWith("-file=")){
                fileName = arg.substring(6);
            } 
        }
        if(fileName == null)
            return;
        
        List<String> lines = new ArrayList<String>();

        BufferedReader input =  new BufferedReader(new FileReader(fileName));
        try {
            String line = null;
            while (( line = input.readLine()) != null){
                lines.add(line);
            }
        }
        finally {
            input.close();
        }
        
        String[] firstLine = lines.get(0).split("\\s+");
        int items = Integer.parseInt(firstLine[0]);
        int capacity = Integer.parseInt(firstLine[1]);

        int[] values = new int[items];
        int[] weights = new int[items];

        for(int i=1; i < items+1; i++){
          String line = lines.get(i);
          String[] parts = line.split("\\s+");

          weights[i-1] = Integer.parseInt(parts[0]);
          values[i-1] = Integer.parseInt(parts[1]);
        }

        int value = 0;
        int weight = 0;
        
        int[][] dp = new int[2][capacity + 1];
        String[][] takenList = new String[2][capacity + 1];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < capacity + 1; j++) {
                takenList[i][j] = "";
            }
        }

        for (int i = 1; i < items + 1; i++){
            
            if (i > 1){
                for (int j = 0; j < capacity + 1; j++){
                    dp[0][j]= dp[1][j];
                    takenList[0][j] = takenList[1][j];
                }
            }

            for (int j = 0; j < capacity + 1; j++){
                if (weights[i-1] <= j){

                    int h = values[i-1] + (int) dp[0][j-weights[i-1]];
                    dp[1][j]= dp[0][j];

                    if (h > (int) dp[0][j]) {
                        dp[1][j] = h;
                        takenList[1][j] = takenList[0][j-weights[i-1]] + (i) + ",";
                    }
                }
                else{
                    dp[1][j] = dp[0][j];
                    takenList[1][j] = takenList[0][j];
                }
            }
        }

        value = (int) dp[1][capacity];

        int valueFinalTakenList = 0;

        String[] parts = takenList[1][capacity].replaceAll(",+$", "").split(",");
        int[] finalTakenList = new int[parts.length];

        int[] submitFinalTakenList = new int[items + 1];

        for (int i = 0; i < parts.length; i++) {
            finalTakenList[i] = Integer.parseInt(parts[i]);
            valueFinalTakenList += values[finalTakenList[i]-1];
        }
        
        for (int i = 0; i < items + 1; i++){
            submitFinalTakenList[i] = 0;
        }

        for (int i = 0; i < finalTakenList.length; i++){
            submitFinalTakenList[finalTakenList[i]-1] = 1;
        }

        System.out.println(value + " 0");

        for (int i = 0; i < items; i++){
            System.out.print(submitFinalTakenList[i] + " ");
        }
    }
}