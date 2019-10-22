/*
 * Обучаемся языку Java на примере Тетриса
 * Сергей. Октябрь 2019 года.
 */
 
import java.awt.*;
import javax.swing.*;


public class Tetris extends JFrame {

  public static void main(String[] args) {
    Tetris tetris = new Tetris();
    tetris.window();
  }

  public void window() {
    JFrame.setDefaultLookAndFeelDecorated(true);
    setTitle("Tetris");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocation(200, 100);
    setSize(800, 600);
    setResizable(false);
    setVisible(true);
  }
}
