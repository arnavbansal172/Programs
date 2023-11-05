import java.util.*;
public class cc3 {
}



class GFG{


    static int distinctSubString(String P, String Q,
                                 int K, int N)
    {

        // Hashmap to store all subStrings
        HashSet<String> S = new HashSet<String>();

        // Iterate over all subStrings
        for (int i = 0; i < N; ++i) {

            // Maintain the sum of all characters
            // encountered so far
            int sum = 0;

            String s = "";

            for (int j = i; j < N; ++j) {

                int pos = P.charAt(j) - 'a';

                sum += Q.charAt(pos) - '0';


                s += P.charAt(j);

                if (sum <= K) {
                    S.add(s);
                }

                else {
                    break;
                }
            }
        }


        return S.size();
    }

    public static void main(String[] args)
    {
        String P = "abcde";
        String Q = "12345678912345678912345678";
        int K = 5;
        int N = P.length();

        System.out.print(distinctSubString(P, Q, K, N));
    }
}
// time complexity O(N^2)
