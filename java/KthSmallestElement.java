import java.util.Collections;
import java.util.PriorityQueue;

public class KthSmallestElement {
    public static int findKthSmallestElement(final int[] arr, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < arr.length; ++i) {
            if (i < k) {
                queue.add(arr[i]);
                continue;
            }
            if (queue.peek() > arr[i]) {
                queue.poll();
                queue.add(arr[i]);
            }
        }
        return queue.peek();
    }

    public static String suffix(int number) {
        return switch (number % 10) {
            case 1 -> "st";
            case 2 -> "nd";
            case 3 -> "rd";
            default -> "th";
        };
    }

    public static void main(String[] args) {
        int[] arr = {7, 10, 4, 3, 20, 15};
        int k = 6;
        int ans = findKthSmallestElement(arr, k);
        System.out.printf("%d%s smallest element: %d", k, suffix(k), ans);
    }
}
