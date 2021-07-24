import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

class FindTwoMaximums {
    private static final String INPUT_TEXT_FILE = "/Users/dvaishnani/dev/codes/java/FindTwoMaximums_input.txt";

    private static int numComparisonsLinear = 0;
    private static int numComparisonsDC = 0;

    static class TwoMax {
        int firstMax, secondMax;

        public TwoMax(final int firstMax, final int secondMax) {
            this.firstMax = firstMax;
            this.secondMax = secondMax;
        }

        @Override
        public String toString() {
            return String.format("TwoMax { firstMax = %d, secondMax= %d }", firstMax, secondMax);
        }
    }

    public static TwoMax findTwoMaxLinear(final int[] arr) {
        numComparisonsLinear = 0;
        TwoMax twoMax = new TwoMax(-1, -1);
        for (int i = 0; i < arr.length; ++i) {
            if (i == 0) {
                twoMax.firstMax = arr[i];
                twoMax.secondMax = Integer.MIN_VALUE;
                continue;
            }

            int minFirstMax = Math.min(twoMax.firstMax, arr[i]);
            twoMax.firstMax = Math.max(twoMax.firstMax, arr[i]);
            twoMax.secondMax = Math.max(twoMax.secondMax, minFirstMax);
            numComparisonsLinear += 2;
        }
        return twoMax;
    }

    private static int[] findMaxDC(final int[] arr, final int l, final int r, final int d) {
        if (l >= r) {
            int[] path = new int[d + 2];
            path[d] = arr[r];
            path[d + 1] = Integer.MIN_VALUE;
            return path;
        }

        int m = l + (r - l) / 2;
        int[] pathLeft = findMaxDC(arr, l, m, d + 1);
        int[] pathRight = findMaxDC(arr, m + 1, r, d + 1);

        if (pathLeft[d + 1] >= pathRight[d + 1]) {
            pathLeft[d] = pathLeft[d + 1];
            pathLeft[d + 1] = pathRight[d + 1];
            numComparisonsDC++;
            return pathLeft;
        } else {
            pathRight[d] = pathRight[d + 1];
            pathRight[d + 1] = pathLeft[d + 1];
            numComparisonsDC++;
            return pathRight;
        }
    }

    public static TwoMax findTwoMaxDC(final int[] arr) {
        numComparisonsDC = 0;
        int[] path = findMaxDC(arr, 0, arr.length - 1, 0);
        int firstMax = path[0];
        int secondMax = Integer.MIN_VALUE;
        for (int i = 1; i < path.length; ++i) {
            secondMax = Math.max(secondMax, path[i]);
            numComparisonsDC++;
        }
        return new TwoMax(firstMax, secondMax);
    }

    public static void main(final String[] args) {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(INPUT_TEXT_FILE))) {
            int[] arr = Arrays.stream(bufferedReader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            TwoMax ansLinear = findTwoMaxLinear(arr);
            TwoMax ansDC = findTwoMaxDC(arr);

            System.out.println(ansLinear);
            System.out.println("numComparisonsLinear: " + numComparisonsLinear);
            System.out.println(ansDC);
            System.out.println("numComparisonsDC: " + numComparisonsDC);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
