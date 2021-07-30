import java.util.Arrays;

public class DutchNationalFlagSort {
    // sort array with 0s, 1s and 2s
    private static void swap(int[] arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }

    public static void sort(int[] arr) {
        int end0s = -1, end1s = -1;
        for (int i = 0; i < arr.length; ) {
            switch (arr[i]) {
                case 0 -> {
                    end0s++;
                    if (end0s == i) {
                        i++;
                        continue;
                    }
                    swap(arr, end0s, i);
                }
                case 1 -> {
                    if (end1s == -1) {
                        end1s = end0s;
                    }
                    end1s++;
                    if (end1s == i) {
                        i++;
                        continue;
                    }
                    swap(arr, end1s, i);
                }
                case 2 -> i++;
            }
        }
    }

    public static void main(String[] args) {
//        int[] arr = {0, 2, 2, 2, 1, 2};
        int[] arr = {2, 2, 1, 2, 0, 0, 0, 2, 1, 1, 1, 1, 0, 2, 1, 2, 2};
        sort(arr);
        Arrays.stream(arr).mapToObj(it -> it + " ").forEach(System.out::printf);
    }
}
