package com.uva.contest.theseusII;

import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class Main {
	
	boolean bug = false;
	
	class Cave {

		String name;
		boolean T_mark = false;
		boolean M_mark = false;
		boolean lighted = false;

		List<Cave> reached = new ArrayList<Cave>();

		Cave(String name) {
			this.name = name;
		}
		
	}

	List<Object[]> read() {
		BufferedReader br = null;
		List<Object[]> list = new ArrayList<Object[]>();
		Map<String, Cave> caves = new HashMap<String, Cave>();
		Map<String, List<String>> caves_reached = new HashMap<>();
		try {

			br = new BufferedReader(new InputStreamReader(System.in));

			String input;
			while (!(input = br.readLine()).equals("#")) {
				if (input.contains("@")) {
					String start = input.split("@")[1];
					for (Entry<String, Cave> entry : caves.entrySet()) {
						Cave cave = entry.getValue();
						List<String> list2 = caves_reached.get(entry.getKey());
						for (String n : list2) {
							cave.reached.add(caves.get(n));
						}
					}

					char[] charArray = start.toCharArray();
					Cave T_prev = caves.get(String.valueOf(charArray[0]));
					Cave T_start = caves.get(String.valueOf(charArray[1]));
					Cave M_prev = caves.get(String.valueOf(charArray[2]));
					Cave M_start = caves.get(String.valueOf(charArray[3]));

					list.add(new Object[] { T_prev, T_start, M_prev, M_start });
				} else {
					String[] split = input.split(":");
					caves.put(split[0], new Cave(split[0]));
					String string = split[1];
					List<String> l = new ArrayList<String>();
					for (char c : string.toCharArray()) {
						l.add(String.valueOf(c));
					}
					caves_reached.put(split[0], l);
				}
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

		return list;
	}

	// entry point from OS
	public static void main(String args[]) {
		Main myWork = new Main(); // create a dinamic instance
		myWork.Begin(); // the true entry point
	}

	int searchIndex(Cave prev, Cave next) {
		for(int i = 0; i < next.reached.size(); i++) {
			if(next.reached.get(i).name.equals(prev.name)) {
				return i;
			}
		}
		return -1;
	}
	
	void Begin() {
		List<Object[]> lines = read();
		for (int j = 0; j < lines.size(); j++) {
			Object[] o = lines.get(j);
			Cave T_prev = (Cave) o[0];
			Cave T_next = (Cave) o[1];
			T_next.T_mark=true;
			Cave M_prev = (Cave) o[2];
			Cave M_next = (Cave) o[3];
			M_next.M_mark=true;
			
			if(bug) {
				System.out.println("T starts bween " + T_prev.name + ", and " + T_next.name);
				System.out.println("M starts bween " + M_prev.name + ", and " + M_next.name);				
			}
			
			while (true) {
				//FIXME Theseus move's
				if(T_next.M_mark) {//If is prev visited by M
					if(bug) {
						System.out.println(T_next.name + " prev visited by M ");						
					}
					T_next.lighted = true; //light it
					int k = searchIndex(T_prev, T_next);
					for(int count = 1; count < T_next.reached.size(); count++) {
						Cave cave = T_next.reached.get((k + count) % T_next.reached.size());
						if(cave.M_mark) {//Take the M exit
							cave.T_mark = true;
							T_prev = T_next;
							T_next = cave;
							if(bug) {
								System.out.println("T takes the M exit " + cave.name + " visited by the M");								
							}
							break;
						}
					}
				} else {//If not visited by M
					int k = searchIndex(T_prev, T_next);
					for(int count = 1; count < T_next.reached.size(); count++) {
						Cave cave = T_next.reached.get((k+count) % T_next.reached.size());
						if(!cave.T_mark) {//Take unmarked exit
							cave.T_mark = true;
							T_prev = T_next;
							T_next = cave;
							if(bug) {
								System.out.println("T takes the exit " + cave.name);								
							}
							break;
						}
					}
				}
				
				//FIXME Minotaur move's
				int k = searchIndex(M_prev, M_next);
				for(int count = 1; count < M_next.reached.size(); count++) {
					Cave cave = M_next.reached.get((k-count + M_next.reached.size()) % M_next.reached.size());
					if(cave.lighted) {
						if(bug) {
							System.out.println("M backs to " + M_next.name);							
						}
						break;
					}
					if(!cave.M_mark) {//Take unmarked exit
						cave.M_mark = true;
						M_prev = M_next;
						M_next = cave;
						if(bug) {
							System.out.println("M takes the exit " + cave.name);							
						}
						break;
					}
				}
				
				if(T_next.name.equals(M_next.name)) {
					System.out.println("The Minotaur is slain in " + T_next.name);
					break;
				}
				
				if(T_next.name.equals(M_prev.name) && M_next.name.equals(T_prev.name)) {
					System.out.println("Theseus is killed between " + T_prev.name + " and " + T_next.name);
					break;
				}
			}
		}
	}
}