package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TaskA {
    public static int solve(String s, int n) {
        int count = 0;
        int[] arr = s.chars().toArray();
        int[] arr2 = Arrays.copyOf(arr, arr.length);
        Arrays.sort(arr2);
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] != arr2[i]) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int cases = Integer.parseInt(br.readLine());
            for (int i = 0; i < cases; ++i) {
                int n = Integer.parseInt(br.readLine());
                String s = br.readLine();
                System.out.println(solve(s, n));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
