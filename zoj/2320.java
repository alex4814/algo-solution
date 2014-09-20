import java.util.*;
import java.math.BigInteger;

class Prime {
	public static boolean is_prime(int x) {
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	}
	public static int[] gen(int size) {
		int[] p = new int[size];
		int k = 0, n = 2;
		while (k < size) {
			if (is_prime(n)) {
				p[k++] = n;
			}
			n = n + 1;
		}
		return p;
	}
}

class Matrix {
	public int[][] d;

	public Matrix(int r, int c) {
		d = new int[r][c];
	}
	public int rank(int r, int c) {
		int i = 0, j = 0;
		while (i < r && j < c) {
			int t = i;
			for (int k = i; k < r; ++k) {
				if (d[k][j] == 1) { t = k; break; }
			}
			if (d[t][j] == 1) {
				if (t != i) for (int k = 0; k < c; ++k) {
					int temp = d[t][k];
					d[t][k] = d[i][k];
					d[i][k] = temp;
				}
				for (int u = i + 1; u < r; ++u) if (d[u][j] == 1) {
					for (int k = i; k < c; ++k) {
						d[u][k] ^= d[i][k];
					}
				}
				i = i + 1;
			}
			j = j + 1;
		}
		//System.out.printf("rank = %d\n", i);
		//print(r, c);
		return i;
	}
	public void print(int r, int c) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				System.out.printf("%d ", d[i][j]);
			}
			System.out.println();
		}
	}
}

class Main {
	public static void main(String[] args) {
		int aa = 3, bb = 5;
		System.out.printf("before, %d %d\n", aa, bb);
		/*
		aa ^= bb;
		bb ^= aa;
		aa ^= bb;
		*/
		aa ^= bb ^= aa ^= bb;
		System.out.printf("after,  %d %d\n", aa, bb);
		Scanner in = new Scanner(System.in);

		int[] p = Prime.gen(100);
		int T = in.nextInt();
		while (T-- > 0) {
			int t = in.nextInt();
			int m = in.nextInt();

			Matrix a = new Matrix(t, m);
			for (int i = 0; i < m; ++i) {
				int x = in.nextInt();
				for (int k = 0; k < t; ++k) {
					if (x == 1) break;
					while (x % p[k] == 0) {
						a.d[k][i] ^= 1;
						x /= p[k];
					}
				}
			}
			//a.print(t, m);

			BigInteger ret = BigInteger.valueOf(2);
			System.out.println(ret.pow(m - a.rank(t, m)).subtract(BigInteger.ONE));
			if (T != 0) System.out.println();
		}
	}
}
