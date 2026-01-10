import java.util.Random;

public class AliceAppleTree {

    private int numberOfApples;

    public AliceAppleTree() {
        this.numberOfApples = new Random().nextInt(100);
    }

    public int getNumberOfApples() {
        return this.numberOfApples;
    }

    public void pickAnApple() {
        this.numberOfApples--;
    }

    public boolean hasApples() {
        return this.numberOfApples > 0;
    }

    public static void main(String[] args) {
        AliceAppleTree tree = new AliceAppleTree();
        System.out.println("The tree has " + tree.getNumberOfApples() + " apples.");
        tree.pickAnApple();
        System.out.println("The tree now has " + tree.getNumberOfApples() + " apples.");
        System.out.println("Does the tree have apples? " + tree.hasApples());
    }
}
