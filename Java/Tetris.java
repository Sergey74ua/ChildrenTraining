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

public class Tetris extends JPanel {

	//Переменные
	static int block = 40, x = 0, y = 0, r;
	public int form[][][] = {
		{{0, 0, 0, 0}, { 1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {255, 0, 0}}, // Z red
		{{0, 1, 0, 0}, { 0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {255, 165, 0}}, // L orange
		{{0, 0, 0, 0}, { 0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {255, 255, 0}}, // O yellow
		{{0, 0, 0, 0}, { 0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 255, 0}}, // S green
		{{0, 0, 0, 0}, { 1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 255, 255}}, // I aqua
		{{0, 0, 1, 0}, { 0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 255}}, // J blue
		{{0, 0, 0, 0}, { 1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {255, 0, 255}}  // T purple
	};

	public static void main(String[] args) {

		//Окно приложения
		JFrame jFrame = new JFrame("Tetris");
		jFrame.setDefaultLookAndFeelDecorated(true);
		jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.setSize(block*10+17, block*20+40);
		jFrame.setResizable(false);
		jFrame.setLocationRelativeTo(null);
		jFrame.setVisible(true);

		//Объект игры
		Tetris tetris = new Tetris();
		jFrame.add(tetris);

		//Отслеживаем нажатия клавиш
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				switch(event.getKeyCode()) {
					case 37: x--; break; //влево
					case 38: y--; break; //вниз
					case 39: x++; break; //вправо
					case 40: y++; break; //вверх
				}
			}
		});

		//Цикл анимации
		while (true) {
			tetris.game();
			tetris.repaint();
			System.out.print(" " + r);
			try {
				Thread.sleep(500);
			} catch (Exception e){}
		}
	}

	//Логика игры
	private void game() {
		Random random = new Random();
		r = random.nextInt(7);
		//y++;
	}

	//Отрисовка игры
	public void paint (Graphics ctx) {
		super.paint(ctx);
		setBackground(Color.black);

		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(block*i, 0, block*i, block*20);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, block*10, block*i);

		//Фигура
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				ctx.setColor(Color.green);
				if (form[r][i][j] > 0) {
					ctx.fillRect(block*3+j*block+1+x*block, block*i+y*block+1, block-1, block-1);
				}
			}
		}
	}
}