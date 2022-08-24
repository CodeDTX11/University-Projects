//Dylan Messerly
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class chatServer {
    public int number;
    public String message;
    public GUI[] GUIarray;

    public chatServer(int num, String[] users) {
        number = num;

        GUIarray = new GUI[num];

        for (int i = 0; i < number; i++) {
            GUIarray[i] = new GUI(users[i]);
        }
    }

    public class GUI implements ActionListener {
        //Creating the Frame
        public String name;
        JFrame frame = new JFrame();
        JMenuBar mb = new JMenuBar();
        JPanel panel = new JPanel();
        JLabel label = new JLabel("Enter Messages");
        JTextField tf = new JTextField(20);
        JButton send = new JButton("Send");

        JTextArea ta = new JTextArea();

        public GUI(String nme) {
            name = nme;
            frame.setTitle(name + "'s Chat Frame");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 400);

            send.addActionListener(this);
            panel.add(label);
            panel.add(tf);
            panel.add(send);

            frame.getContentPane().add(BorderLayout.SOUTH, panel);
            frame.getContentPane().add(BorderLayout.NORTH, mb);
            frame.getContentPane().add(BorderLayout.CENTER, ta);
            frame.setVisible(true);
        }

        public void actionPerformed(ActionEvent e) {
            String message = tf.getText();
            messages(name + ": " + message + "\n");
            tf.setText("");
        }
    }

    public void messages(String msg) {
        for (int i = 0; i < number; i++) {
           GUIarray[i].ta.append(msg);
        }
    }
}
