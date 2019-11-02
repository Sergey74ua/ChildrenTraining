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

	//Переменные, массивы и объекты
	private static int block = 40, speed = 500, xForm, yForm, randForm, look, temp;
	private int ground[][][] = new int[20][10][3]; // ряды / колонки / r,g,b
	private int form[][][] = { // фигурка / блоки(4) / x,y и r,g,b
		{{1, 2}, {2, 2}, {0, 1}, {1, 1}, {255,   0,   0}}, // Z red
		{{1, 2}, {2, 2}, {1, 1}, {1, 0}, {255, 165,   0}}, // L orange
		{{1, 2}, {2, 2}, {1, 1}, {2, 1}, {255, 255,   0}}, // O yellow
		{{0, 2}, {1, 2}, {1, 1}, {2, 1}, {  0, 255,   0}}, // S green
		{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {  0, 255, 255}}, // I aqua
		{{1, 2}, {2, 2}, {2, 1}, {2, 0}, {  0,   0, 255}}, // J blue
		{{1, 2}, {0, 1}, {1, 1}, {2, 1}, {255,   0, 255}}  // T purple
	};
	private Random random = new Random();

	public static void main(String[] args) {

		//Окно приложения
		JFrame jFrame = new JFrame("Tetris");
		jFrame.setDefaultLookAndFeelDecorated(true);
		jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.setSize(block*16+17, block*20+40);
		jFrame.setResizable(false);
		jFrame.setLocationRelativeTo(null);
		jFrame.setVisible(true);

		//Объект игры
		Tetris tetris = new Tetris();
		jFrame.add(tetris);
		tetris.random();

		//Отслеживаем нажатия клавиш
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				switch(event.getKeyCode()) {
					case 37: tetris.move(-1); break; //влево
					case 38: tetris.rotation(); break; //вверх(вращение)
					case 39: tetris.move(+1); break; //вправо
					case 40: yForm++; break; //вниз
				}
			}
		});

		//Цикл анимации
		while (true) { // ***** вписать проверку на проигрыш *****
			tetris.game();
			tetris.repaint();
			try {
				Thread.sleep(speed);
			} catch (Exception e){}
		}
	}

	//Логика игры
	private void game() {
		if (yForm < 17) {
			yForm++;
		} else {
			// Добавляем фигурку в массив
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) {
					ground[form[randForm][i][1]+yForm][form[randForm][i][0]+xForm][j] = form[randForm][4][j];
				}
			}
			randForm = look;
			random();
		}
	}

	//Запуск фигурки
	private void random() {
		look = random.nextInt(7);
		xForm = random.nextInt(7);
		yForm = -2;
	}
	
	//Смещение фигурки
	private void move(int m) {
		if (xForm+m >= 0 && xForm+m <= 10-3) xForm = xForm+m;
	}
	
	//Вращение фигурки
	private void rotation() {
		for (int i = 0; i < 4; i++) {
			temp = form[randForm][i][0];
			form[randForm][i][0] = form[randForm][i][1];
			form[randForm][i][1] = -temp+3;
		}
	}

	//Отрисовка игры
	public void paint (Graphics ctx) {
		super.paint(ctx);

		//Днище
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				ctx.setColor(new Color(ground[i][j][0], ground[i][j][1], ground[i][j][2]));
				ctx.fillRect(block*j, block*i, block, block);
			}
		}

		//Предпросмотр
		ctx.setColor(Color.darkGray);
		ctx.fillRect(block*10+1, 0, block*6, block*20+1);
		ctx.setColor(new Color(form[look][4][0], form[look][4][1], form[look][4][2]));
		for (int i = 0; i < 4; i++) ctx.fillRect(block*form[look][i][0]+11*block, block*form[look][i][1]+block, block-1, block-1);

		//Фигура
		ctx.setColor(new Color(form[randForm][4][0], form[randForm][4][1], form[randForm][4][2]));
		for (int i = 0; i < 4; i++) ctx.fillRect(block*form[randForm][i][0]+xForm*block, block*form[randForm][i][1]+yForm*block, block, block);

		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(block*i, 0, block*i, block*20);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, block*10, block*i);
	}
}