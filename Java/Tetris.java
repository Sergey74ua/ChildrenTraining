/*
 * Обучаемся языку Java на примере Тетриса
 * Сергей. Октябрь 2019 года.
 */

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.event.KeyListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Tetris extends JPanel {

	//Переменные, массивы и объекты
	private static int block = 40, speed = 400, xForm, yForm, randForm, look, step, test;
	private int ground[][][] = new int[20][10][1]; // ряды / колонки / rgb
	private int form[][][] = { // фигурка / блоки(4) / x,y и rgb
		{{1, 2}, {2, 2}, {0, 1}, {1, 1}, {0xff0000}}, // Z red
		{{1, 2}, {2, 2}, {1, 1}, {1, 0}, {0xffa500}}, // L orange
		{{1, 2}, {2, 2}, {1, 1}, {2, 1}, {0xffff00}}, // O yellow
		{{0, 2}, {1, 2}, {1, 1}, {2, 1}, {0x00ff00}}, // S green
		{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {0x00ffff}}, // I aqua
		{{1, 2}, {2, 2}, {2, 1}, {2, 0}, {0x0000ff}}, // J blue
		{{1, 2}, {0, 1}, {1, 1}, {2, 1}, {0xff00ff}}  // T purple
	};
	private Random random = new Random();

	public static void main(String[] args) {

		//Окно приложения
		JFrame jFrame = new JFrame("Tetris");
		jFrame.setDefaultLookAndFeelDecorated(true);
		jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.setSize(block*14+20+17, block*20+40);
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
				tetris.repaint();
				switch(event.getKeyCode()) {
					case 37: tetris.move(-1); break; //влево
					case 38: tetris.rotation(); break; //вверх(вращение)
					case 39: tetris.move(+1); break; //вправо
					case 40: speed = 40; break; //вниз
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

		//Проверка падения блока вниз
		test = 0;
		for (int i = 0; i < 4; i++)
			if (form[randForm][i][1]+yForm+1 < 20 &&
				ground[form[randForm][i][1]+yForm+1][form[randForm][i][0]+xForm][0] == 0) test++;
		
		if (test >= 4) {
			yForm++;
		} else {
			
			// Добавляем фигурку в массив
			for (int i = 0; i < 4; i++)
				ground[form[randForm][i][1]+yForm][form[randForm][i][0]+xForm][0] = form[randForm][4][0]*2/3;
			randForm = look; //замена предпросмотр на блок
			clear(); //удаляем заполненные ряды
			random(); //запускаем новую фигурку
		}
	}

	//Запуск фигурки
	private void random() {
		speed = 400;
		look = random.nextInt(7);
		xForm = random.nextInt(7);
		yForm = -1; //надо -2, но не влазит в проверяемый массив
		step++;
	}

	//Смещение фигурки
	private void move(int move) {
		test = 0;
		for (int i = 0; i < 4; i++)
			if (form[randForm][i][0]+xForm+move >= 0 && form[randForm][i][0]+xForm+move < 10) test++;
		if (test >= 4) xForm = xForm+move;
	}

	//Вращение фигурки
	private void rotation() {
		for (int i = 0; i < 4; i++) {
			int temp = form[randForm][i][0];
			form[randForm][i][0] = form[randForm][i][1];
			form[randForm][i][1] = -temp+3;
		}
	}
	
	//Проверка на заполнение строки
	private void clear() {
		for (int i = 0; i < 20; i++) {

			//Подсчитываем число полных блоков в ряду
			test = 0;
			for (int j = 0; j < 10; j++) if (ground[i][j][0] > 0) test++;

			//Удаляем заполненный ряд
			if (test >= 10) {
				for (int j = 0; j < 10; j++) ground[i][j][0] = 0;
				clear2();
			}
		}
	}
	
	//Опускаем верхние ряды
	private void clear2() {
		for (int i = 19; i > 0; i--) {

			//Подсчитываем число пустых блоков в ряду
			test = 0;
			for (int j = 0; j < 10; j++) if (ground[i][j][0] == 0) test++;
			
			//Смещаем вехние блоки (System.arraycopy(array1, 1, array2, 2, 3);)
			if (test >= 10) {
				for (int j = i; j > 0; j--) {
					for (int n = 0; n < 10; n++) ground[j][n][0] = ground[j-1][n][0];
				}
			}
		}
	}
	
	//Отрисовка игры
	@Override
	public void paint (Graphics ctx) {
		super.paint(ctx);
		
		//Сайдбар
		ctx.setColor(Color.darkGray);
		ctx.fillRect(block*10+1, 0, block*5, block*20+1);
		
		//Предпросмотр блока
		ctx.setColor(new Color(form[look][4][0]));
		for (int i = 0; i < 4; i++)
			ctx.fillRect(block*form[look][i][0]+block*10+10, block*form[look][i][1]+block, block-1, block-1);
		
		//Панель информации
		ctx.setFont(new Font("Courier New", Font.BOLD, 24));
		ctx.setColor(Color.white);
		ctx.drawString(("Speed: " + speed), block*10+10, block*6);
		ctx.setColor(Color.yellow);
		ctx.drawString(("Step: " + step), block*10+10, block*7);
		
		//Днище
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				ctx.setColor(new Color(ground[i][j][0]));
				ctx.fillRect(block*j, block*i, block, block);
			}
		}
		
		//Фигура
		ctx.setColor(new Color(form[randForm][4][0]));
		for (int i = 0; i < 4; i++)
			ctx.fillRect(block*form[randForm][i][0]+xForm*block, block*form[randForm][i][1]+yForm*block, block, block);

		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(block*i, 0, block*i, block*20);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, block*10, block*i);
	}
}