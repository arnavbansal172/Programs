import java.util.Arrays;

public class simplesieve {

    public static void main(String[] args) {
        int n = 20;
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                System.out.println(i);
            }
        }
    }
}
