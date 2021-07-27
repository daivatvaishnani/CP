package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TaskB {
    private static int findSuperior(int[][] athleteStats, int i, int j) {
        int woi = 0;
        for (int k = 0; k < athleteStats[i].length; ++k) {
            if (athleteStats[i][k] < athleteStats[j][k]) {
                woi++;
            }
        }
        if (woi >= 3) {
            return i;
        }
        return j;
    }

    public static int solve(int[][] athleteStats) {
        int ans = 0;
        for (int i = 1; i < athleteStats.length; ++i) {
            int superior = findSuperior(athleteStats, ans, i);
            if (superior != ans) {
                ans = i;
            }
        }
        int infCount = 0;
        for (int i = 0; i < athleteStats.length; ++i) {
            if (i != ans && findSuperior(athleteStats, ans, i) == ans) {
                infCount++;
            }
        }
        return infCount == athleteStats.length - 1 ? ans + 1 : -1;
    }

    public static void main(String[] args) {
        try (
            InputStream is = System.in;
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr)
        ) {
            int cases = Integer.parseInt(br.readLine());
            for (int i = 0; i < cases; ++i) {
                int numAthletes = Integer.parseInt(br.readLine());
                int[][] athleteStats = new int[numAthletes][5];
                for (int j = 0; j < numAthletes; ++j) {
                    athleteStats[j] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                }
                System.out.println(solve(athleteStats));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
