//Dylan Messerly
import java.util.ArrayList;

public class Life extends Thread {

    public static int rows = 20;
    public static int columns = 20;
    int numGens;
    public int[][] currentGen, nextGen;

    public Life(char[] firstGen, int numGenerations) {
        numGens = numGenerations;

        currentGen = new int[rows][columns];

        nextGen = new int[rows][columns];

        int cntr = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {

                while(cntr < firstGen.length){
                    if (firstGen[cntr] == 'X' || firstGen[cntr] == 'O')
                        break;
                    else
                        cntr++;
                }
                if (firstGen[cntr] == 'X') {
                    currentGen[i][j] = 1;
                    cntr++;
                } else {
                    currentGen[i][j] = 0;
                    cntr++;
                }
            }
        }
    }

    public void startThreads() throws InterruptedException {

        ArrayList<Threads> threads = new ArrayList<>();

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; j++) {
                threads.add(new Threads(i, j, this.currentGen));
            }

            for (Threads t : threads)
                t.start();
            for (Threads t : threads)
                t.join();

            int cntr = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    currentGen[i][j] = threads.get(cntr).aliveOrDead;
                    cntr++;
                }
            }
        }

    public void print(){
        System.out.print("Output after " + numGens + " generations \n");

        for (int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(currentGen[i][j] == 1) {
                    System.out.print('X');
                } else
                    System.out.print('O');

                if(j == columns-1)
                    System.out.print('\n');
            }
        }
    }
}
