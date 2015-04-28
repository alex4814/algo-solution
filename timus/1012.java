import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
    private static final int MAX_LENS = 178;
    private static final int MAX_BASE = 10;

    public static void main(String[] args) {
        BigInteger[][] f = new BigInteger[MAX_LENS + 1][MAX_BASE];
        for (int i = 0; i < MAX_LENS + 1; ++i) {
            f[i] = new BigInteger[MAX_BASE];
            for (int j = 0; j < MAX_BASE; ++j) {
                f[i][j] = BigInteger.ZERO;
            }
        }

        Scanner in = new Scanner(new BufferedInputStream(System.in));

        for (int i = 0; i < MAX_BASE; ++i) {
            f[1][i] = BigInteger.ONE;
        }

        int n = in.nextInt();
        int k = in.nextInt();
        for (int len = 2; len <= n; ++len) {
            for (int d = 0; d < k; ++d) {
                for (int _d = 0; _d < k; ++_d) {
                    if (len - 1 == 1 && _d == 0) continue;
                    if (d == 0 && _d == 0) continue;
                    f[len][d] = f[len][d].add(f[len - 1][_d]);
                }
            }
        }

        BigInteger sum = BigInteger.ZERO;
        for (int i = 0; i < k; ++i) {
            sum = sum.add(f[n][i]);
        }
        System.out.println(sum);
    }
}
