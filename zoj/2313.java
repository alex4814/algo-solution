import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int i = 1; i <= T; ++i) {
			BigInteger n = in.nextBigInteger();
			if (!n.and(BigInteger.ONE).equals(BigInteger.ZERO)) {
				System.out.println(n.divide(BigInteger.valueOf(2)));
			} else if (n.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO)) {
				System.out.println(n.divide(BigInteger.valueOf(2)).subtract(BigInteger.ONE));
			} else {
				System.out.println(n.divide(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(2)));
			}
			if (i != T) System.out.println();
		}
	}
}
