//Dylan Messerly
import java.io.*;
import java.io.File;
import java.io.FileReader;

public class Main {

    public static void main(String[] args) throws Exception {

        File file = new File("src/Start.txt");

        FileReader fr = new FileReader(file);

        BufferedReader br = new BufferedReader(new FileReader("src/Start.txt"));

        char[] chars = new char[(char) file.length()];

        fr.read(chars);

        String lastLine = "0";
        String line;
        int numGens;

        while ((line = br.readLine()) != null) {
            lastLine = line;
        }

        numGens = Integer.parseInt(lastLine);

        Life lifeBoard = new Life(chars, numGens);

        for(int i = 0; i < numGens; i++)
            lifeBoard.startThreads();

        lifeBoard.print();
    }
}
