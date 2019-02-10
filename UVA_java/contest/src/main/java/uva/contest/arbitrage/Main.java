package uva.contest.arbitrage;

import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

class Main {

	void build_paths(double[][][] best, int[][][] path, int n) {
		for (int steps = 1; steps < n; steps++) {
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						double tmp = best[i][k][steps - 1] * best[k][j][0];
						if (best[i][j][steps] < tmp) {
							best[i][j][steps] = tmp;
							path[i][j][steps] = k;
						}
					}
				}
			}
		}
	}

	void print_result(double[][][] best, int[][][] path, int n) {
		boolean sequence = false;
		for (int steps = 1; steps < n; steps++) {
			if (sequence) {
				break;
			}
			for (int i = 0; i < n; i++) {
				if (best[i][i][steps] > 1.01) {
					int index = i;
					int[] pp = new int[steps + 2];
					pp[steps + 1] = index + 1;

					for (int j = steps; j >= 0; j--) {
						int v = path[i][index][j];
						pp[j] = v + 1;
						index = v;
					}
					String aux = "";
					for(int k = 0; k < steps+2; k++) {
						if(k > 0) {
							aux += " ";
						}
						aux += pp[k];
					}
					System.out.println(aux);
					sequence = true;
					break;
				}
			}
		}

		if (!sequence) {
			System.out.println("no arbitrage sequence exists");
		}
	}

	void main() throws IOException {

		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
		while (sc.hasNext()) {
			int n = sc.nextInt();
			double[][][] best = new double[n][n][n];
			int[][][] path = new int[n][n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j) {
						best[i][j][0] = sc.nextDouble();
					} else {
						best[i][j][0] = 1;
					}
					path[i][j][0] = i;
				}
			}

			arbitrage(best, path, n);

		}
		
		sc.close();

	}

	void arbitrage(double[][][] best, int[][][] path, int n) {
		build_paths(best, path, n);

		print_result(best, path, n);
	}

	public static void main(String[] args) throws IOException {
		new Main().main();
	}

}
