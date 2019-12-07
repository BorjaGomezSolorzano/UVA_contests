import java.io.*;
import java.util.*;

class Main {

	List<char[]> readLines() {
		List<char[]> lines = new ArrayList<char[]>();
		BufferedReader br = null;

		try {

			br = new BufferedReader(new InputStreamReader(System.in));

			String input;
			while (!(input = br.readLine()).equals("#")) {
				lines.add(input.toCharArray());
			}

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (br != null) {
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}

		return lines;
	}

	public static void main(String args[]) {
		Main myWork = new Main();
		myWork.Begin();
	}

	void Begin() {
		List<char[]> lines = readLines();
		long g = 34943L;
		for (int i = 0; i < lines.size(); i++) {
			char[] line = lines.get(i);
			long sum = 0;
			for (char c : line) {
				long aux = sum << 8;
				sum = (aux + c) % g;
			}
			long aux = sum << 16;
			sum = aux % g;
			long hexa = (g - sum) % g;
			String result = String.format("%02X %02X", hexa >> 8, hexa % 256);
			System.out.println(result);
		}
	}
}
