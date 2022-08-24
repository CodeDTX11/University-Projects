//Dylan Messerly

public class Threads extends Thread {
    public int row;
    public int col;
    public int[][] currentGen;
    public int aliveOrDead;
    public int neighbors;

    public Threads(int rowPos, int columnPos, int[][] CurrentBoard) {
        row = rowPos;
        col = columnPos;
        currentGen = CurrentBoard.clone();
    }

    public void run() {
        neighbors = 0;
        int rows = 20;
        int columns = 20;

        for (int x = -1; x < 2; x++) {
            for (int y = -1; y < 2; y++) {

                if ((row + x) < 0 || (row + x) > (rows - 1)) {
                    neighbors += 0;
                } else if ((col + y) < 0 || (col + y) > (columns - 1)) {
                    neighbors += 0;
                } else
                    neighbors += currentGen[row + x][col + y];
            }
        }
        neighbors -= currentGen[row][col];

        if (neighbors < 2) // auto death
            aliveOrDead = 0;
        else if (currentGen[row][col] == 1 && (neighbors == 2 || neighbors == 3)) // stay alive
            aliveOrDead = 1;
        else if (neighbors > 3) // auto death
            aliveOrDead = 0;
        else if (currentGen[row][col] == 0 && neighbors == 3) // re birth
            aliveOrDead = 1;
    }
}

