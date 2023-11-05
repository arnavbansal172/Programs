import java.util.Arrays;

public class CheckArrayEquality {

    public static void main(String[] args) {

        // declare two arrays
        int[] array1 = {1, 2, 3, 4, 5};
        int[] array2 = {1, 2, 3, 4, 5};

        // check if the arrays are equal using Arrays.equals()
        boolean isEqual = Arrays.equals(array1, array2);

        // print the result
        if (isEqual) {
            System.out.println("The arrays are equal");
        } else {
            System.out.println("The arrays are not equal");
        }
    }
}
