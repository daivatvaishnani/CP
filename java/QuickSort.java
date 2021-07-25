import java.util.Arrays;

interface PivotSelector {
    int select(int[] arr, int l, int r);
}

class LastElementSelector implements PivotSelector {
    @Override
    public int select(int[] arr, int l, int r) {
        return r;
    }
}

class RandomSelector implements PivotSelector {
    @Override
    public int select(int[] arr, int l, int r) {
        return l + (int) (Math.random() * (r - l + 1));
    }
}

public class QuickSort {
    private static void swap(int[] arr, int i, int j) {
        if (i == j) return;
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }

    private static int partition(int[] arr, int l, int r, PivotSelector pivotSelector) {
        if (l >= r) return l;
        int pivotIndex = pivotSelector.select(arr, l, r);
        int pivot = arr[pivotIndex];
        swap(arr, pivotIndex, r);
        int partitionIndex = l - 1;
        for (int i = l; i < r; ++i) {
            if (arr[i] <= pivot) {
                partitionIndex++;
                swap(arr, partitionIndex, i);
            }
        }
        partitionIndex++;
        swap(arr, partitionIndex, r);
        return partitionIndex;
    }

    public static void sort(int[] arr, int l, int r, PivotSelector pivotSelector) {
        if (l >= r) return;
        int partitionIndex = partition(arr, l, r, pivotSelector);
        sort(arr, l, partitionIndex - 1, pivotSelector);
        sort(arr, partitionIndex + 1, r, pivotSelector);
    }

    public static void sort(int[] arr, PivotSelector pivotSelector) {
        sort(arr, 0, arr.length - 1, pivotSelector);
    }

    public static void main(String[] args) {
        int[] arr = {7, 2, 1, 6, 8, 5, 3, 4};
        sort(arr, new RandomSelector());
        Arrays.stream(arr).mapToObj(it -> it + " ").forEach(System.out::print);
    }
}
