import java.io.IOException;
import java.io.InputStreamReader;

public class GivenLengthAndSumOfDigits {
	static class GivenLengthAndSumOfDigitsResult {
		String small, large;

		public GivenLengthAndSumOfDigitsResult(String small, String large) {
			this.small = small;
			this.large = large;
		}
	}

	public static GivenLengthAndSumOfDigitsResult findGivenLengthAndSumOfDigits(int length, int sum) {
		if (sum > length * 9 || (length == 1 && sum < 0) || (length > 1 && sum < 1)) {
			return new GivenLengthAndSumOfDigitsResult("-1", "-1");
		}
		if (length == 1 && sum == 0) {
			return new GivenLengthAndSumOfDigitsResult("0", "0");
		}
		int small, large;
		int sumLeftSmall = sum, sumLeftLarge = sum;
		StringBuilder smallString = new StringBuilder(), largeString = new StringBuilder();
		for (int i = 0; i < length; ++i) {
			small = Math.max(i == 0 ? 1 : 0, sumLeftSmall - (length - i - 1) * 9);
			large = Math.min(9, sumLeftLarge);
			smallString.append(small);
			largeString.append(large);
			sumLeftSmall -= small;
			sumLeftLarge -= large;
		}
		return new GivenLengthAndSumOfDigitsResult(smallString.toString(), largeString.toString());
	}

	public static void main(String[] args) throws IOException {
		FastReader fastReader = new FastReader(new InputStreamReader(System.in));
		int length = fastReader.nextInt();
		int sum = fastReader.nextInt();
		GivenLengthAndSumOfDigitsResult givenLengthAndSumOfDigitsResult = findGivenLengthAndSumOfDigits(length, sum);
		System.out.println(givenLengthAndSumOfDigitsResult.small + " " + givenLengthAndSumOfDigitsResult.large);
	}
}
