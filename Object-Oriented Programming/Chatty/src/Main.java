//Dylan Messerly
import java.util.Scanner;

public class Main {

    public static void main( String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Number of users? ");

        int num = scanner.nextInt();
        String[] names = new String[num];

            for (int i= 0; i< num; i++){
                System.out.println("User "+ (i+1) + "'s name?");
                names[i] = scanner.next();
            }

        new chatServer(num, names);

    }

}
