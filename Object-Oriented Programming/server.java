import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;


public class server {

    static ServerSocket ss;
    static Socket s;
    static DataInputStream dinput;
    static DataOutputStream dout;
}

public static void main(String args[]) {
    java.awt.EventQueue.invokeLater(new Runnable() {
        @Override
        public void run() {
            new server().setVisible(true);
        }
    });

    String msgin = "";
    try{

        ss = new ServerSocket(1201);
       s = ss.accept();
     dinput = new DataInputStream(s.getInputStream());
     dout = new DataOutputStream(s.getOutputStream());

     while (!msgin.equals("exit")){

         msgin = dinput.readUTF();
         msg
     }

    }

}

    private void setVisible(boolean b) {
    }
