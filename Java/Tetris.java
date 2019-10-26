/*
 * Обучаемся языку Java на примере Тетриса
 * Сергей. Октябрь 2019 года.
 */

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Tetris {
	
	static byte block = 40, t = 0, y = 0;
	
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
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				switch(event.getKeyCode()) {
					case 37: y--; break; //влево
					case 38: y--; break; //вниз
					case 39: y++; break; //вправо
					case 40: y++; break; //вверх
				}
			}
		});
		
		//Отрисовка в окне
		while (true) {
			
			t++; //для теста
			JPanel jPanel = new JPanel() {
				
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
					ctx.fillRect(block*3+1+y*block, block*(-2)+1+t*block, block-1, block-1);
					ctx.fillRect(block*4+1+y*block, block*(-2)+1+t*block, block-1, block-1);
					ctx.fillRect(block*5+1+y*block, block*(-2)+1+t*block, block-1, block-1);
					ctx.fillRect(block*5+1+y*block, block*(-1)+1+t*block, block-1, block-1);
				}
			};
			jFrame.add(jPanel);
			jFrame.setVisible(true);
			
			//Пауза между кадрами
			try {
				Thread.sleep(400);
			} catch (Exception e){}
		}
	}
}