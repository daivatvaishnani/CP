import java.io.BufferedReader;

class Task {
	static BufferedReader br = new BufferedReader(System.in);

	public static void main(String[] args) {
		int n = br.nextInt();
		for(int i = 0; i < n; ++i) {
			int a = br.nextInt();
			System.out.print(a + " ");	
		}
		System.out.println();
	}
}	
