/*
 * Обучаемся языку Java на примере Тетриса
 * Сергей. Октябрь 2019 года.
 */

import java.awt.Color;
import java.awt.Graphics;
import java.util.Timer;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Tetris {
	
	protected static int block = 40;
	
	public static void main(String[] args) {
		
		//Окно программы
		JFrame jFrame = new JFrame("Tetris");
        JFrame.setDefaultLookAndFeelDecorated(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.pack();
        jFrame.setSize(block*10+17, block*20+40);
		jFrame.setResizable(false);
		jFrame.setLocationRelativeTo(null);
		
		//Отслеживаем нажатия клавиш
		
		//Отрисовка в окне
		int rect = block/5;
		JPanel panel = new JPanel() {
            @Override
            public void paint(Graphics ctx) {
				setBackground(Color.black);
                super.paint(ctx);
				
				//Сетка
				ctx.setColor(Color.gray);
				for (byte i = 0; i <= 10; i++) ctx.drawLine(block*i, 0, block*i, block*20);
				for (byte i = 0; i <= 20; i++) ctx.drawLine(0, block*i, block*10, block*i);
				
				//Тестовые блоки
				ctx.setColor(Color.green);
				ctx.drawRoundRect(block*0+1, block*0+1, block-2, block-2, rect, rect);
				ctx.drawRoundRect(block*1+1, block*1+1, block-2, block-2, rect, rect);
				ctx.drawRoundRect(block*5+1, block*10+1, block-2, block-2, rect, rect);
				ctx.drawRoundRect(block*9+1, block*19+1, block-2, block-2, rect, rect);
            }
        };
		jFrame.add(panel);
		jFrame.setVisible(true);
    }
}

