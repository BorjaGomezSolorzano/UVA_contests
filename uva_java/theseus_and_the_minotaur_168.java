import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		int n = 26;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while (!(line = br.readLine()).equals("#")) {
			int[][] adjacency_list = new int[n][n];
			int[] adjacency_list_count = new int[n];
			boolean[] candle = new boolean[n];

			String[] vector_1 = line.split("\\.");
			String[] vector_2 = vector_1[0].split(";");
			for (String v2 : vector_2) {
				String[] vector_3 = v2.split(":");
				if (vector_3.length > 1) {
					int src = vector_3[0].charAt(0) - 'A';
					for (int i = 0; i < vector_3[1].length(); i++) {
						adjacency_list[src][adjacency_list_count[src]] = vector_3[1].charAt(i) - 'A';
						adjacency_list_count[src] += 1;
					}

				}
			}

			String[] vector_4 = vector_1[1].split(" ");
			int mStart = vector_4[1].charAt(0) - 'A';
			int tStart = vector_4[2].charAt(0) - 'A';
			int k = Integer.parseInt(vector_4[3]);

			int count = 0;
			StringBuilder candles_left = new StringBuilder();
			while (true) {
				// Minotaur moves
				int temp = mStart;
				for (int i = 0; i < adjacency_list_count[temp]; i++) {
					int c = adjacency_list[temp][i];
					if (!candle[c] && c != tStart) {
						mStart = c;
						break;
					}
				}

				// Theseus moves
				tStart = temp;

				if (tStart == mStart) {
					if (candles_left.length() > 0) {
						candles_left.append(" /");
						candles_left.append((char) (tStart + 'A'));
					} else {
						candles_left.append("/");
						candles_left.append((char) (tStart + 'A'));
					}
					System.out.println(candles_left.toString());
					break;
				}

				if ((count + 1) % k == 0) {
					candle[tStart] = true;
					if (candles_left.length() > 0) {
						candles_left.append(" ");
					}
					candles_left.append((char) (tStart + 'A'));
				}
				count += 1;
			}
		}

	}

}
