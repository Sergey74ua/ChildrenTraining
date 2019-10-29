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
	static int block = 40, xForm, yForm, randForm, temp;
	public int form[][][] = { // фигурка / блоки / x,y или r,g,b
		{{1, 2}, {2, 2}, {0, 1}, {1, 1}, {255, 0, 0}}, // Z red
		{{1, 2}, {2, 2}, {1, 1}, {1, 0}, {255, 165, 0}}, // L orange
		{{1, 2}, {2, 2}, {1, 1}, {2, 1}, {255, 255, 0}}, // O yellow
		{{0, 2}, {1, 2}, {1, 1}, {2, 1}, {0, 255, 0}}, // S green
		{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {0, 255, 255}}, // I aqua
		{{1, 2}, {2, 2}, {2, 1}, {2, 0}, {0, 0, 255}}, // J blue
		{{1, 2}, {0, 1}, {1, 1}, {2, 1}, {255, 0, 255}}  // T purple
	};
	Random random = new Random();

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
		tetris.random();

		//Отслеживаем нажатия клавиш
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				switch(event.getKeyCode()) {
					case 37: xForm--; break; //влево
					case 38: tetris.rotation(); break; //вниз
					case 39: xForm++; break; //вправо
					case 40: yForm++; break; //вверх(вращение)
				}
			}
		});

		//Цикл анимации
		while (true) { //вписать проверку на проигрыш
			tetris.game();
			tetris.repaint();
			try {
				Thread.sleep(200);
			} catch (Exception e){}
		}
	}

	//Логика игры
	private void game() {
		yForm++;
		if (yForm == 20) random(); //заменить на сложение с массивом днища
	}

	//Запуск фигурки
	private void random() {
		randForm = random.nextInt(7);
		xForm = random.nextInt(7);
		yForm = -2;
	}

	//Вращение блока
	private void rotation() {
		for (int i = 0; i < 4; i++) {
			temp = form[randForm][i][0];
			form[randForm][i][0] = form[randForm][i][1];
			form[randForm][i][1] = -temp+4;
		}
	}

	//Отрисовка игры
	public void paint (Graphics ctx) {
		super.paint(ctx);
		setBackground(Color.black);

		//Фигура
		for (int i = 0; i < 4; i++) {
			ctx.setColor(new Color(form[randForm][4][0], form[randForm][4][1], form[randForm][4][2]));
			ctx.fillRect(block*form[randForm][i][0]+xForm*block, block*form[randForm][i][1]+yForm*block, block, block);
		}

		//Днище


		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(block*i, 0, block*i, block*20);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, block*10, block*i);
	}
}