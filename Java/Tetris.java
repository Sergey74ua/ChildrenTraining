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
	private static boolean gameOver;
	private static int block = 40, speed, step, look, color, temp;
	private int form[][] = new int[4][2];                     // блоки / x, y
	private int ground[][][] = new int[20][10][1];            // ряды / колонки / rgb
	private int forms[][][] = {                               // фигурка / блоки / x, y и rgb
		{{ 0,  0}, {-1,  0}, { 0,  1}, { 1,  1}, {0xff0000}}, // Z red
		{{ 0,  0}, { 0, -1}, {-1,  1}, { 0,  1}, {0xffa500}}, // L orange
		{{ 0,  0}, { 1,  0}, { 0,  1}, { 1,  1}, {0xffff00}}, // O yellow
		{{ 0,  0}, { 1,  0}, {-1,  1}, { 0,  1}, {0x00ff00}}, // S green
		{{ 0,  0}, {-1,  0}, { 1,  0}, { 2,  0}, {0x00ffff}}, // I aqua
		{{ 0,  0}, { 0, -1}, { 0,  1}, { 1,  1}, {0x0000ff}}, // J blue
		{{ 0,  0}, {-1,  0}, { 1,  0}, { 0,  1}, {0xff00ff}}  // T purple
	};
	private static Random random = new Random();
	private static Color colorBlock, colorLook;

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

		//Начальные значения
		look = random.nextInt(7);
		tetris.newBlock();

		//Отслеживаем нажатия клавиш
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				tetris.repaint();
				switch(event.getKeyCode()) {
					case 37: tetris.move(-1); break;   //влево
					case 38: tetris.rotation(); break; //вверх(вращение)
					case 39: tetris.move(+1); break;   //вправо
					case 40: speed = 40; break;        //вниз (сброс)
				}
			}
		});

		//Цикл анимации
		do {
			tetris.game();
			tetris.repaint();
			try {
				Thread.sleep(speed);
			} catch (Exception e){}
		} while (!gameOver);

		//Конец игры
		tetris.gameFinish();
	}

	//Логика игры
	private void game() {

		//Проверка падения блока вниз
		temp = 0;
		for (int i = 0; i < 4; i++)
			if (form[i][1]+1 < 20 &&
				ground[form[i][1]+1][form[i][0]][0] == 0) temp++; // ******** тут вызывается выход за массив ********
		if (temp >= 4) {
			for (int i = 0; i < 4; i++)
				form[i][1]++;
		} else {

			//Поверка на конец игры ******** переделать ********
			for (int i = 0; i < 4; i++)
				if (form[i][1] < 1) gameOver = true;

			// Добавляем фигурку в массив
			for (int i = 0; i < 4; i++)
				ground[form[i][1]][form[i][0]][0] = color*2/3;

			newBlock();
		}
	}

	//Запуск фигурки
	private void newBlock() {
		speed = 400;
		clear();
		step++;

		//Передаем координаты в блок
		temp = random.nextInt(7)+1;
		for (int i = 0; i < 4; i++) {
			form[i][0] = forms[look][i][0]+temp;
			form[i][1] = forms[look][i][1]; //надо -1, но не влазит в проверяемый массив по стр.87
		}

		color = forms[look][4][0];
		colorBlock = new Color(color);
		look = random.nextInt(7);
		colorLook = new Color(forms[look][4][0]);
	}

	//Смещение фигурки
	private void move(int move) {
		temp = 0;
		for (int i = 0; i < 4; i++)
			if (form[i][0]+move >= 0 && form[i][0]+move < 10 && ground[form[i][1]][form[i][0]+move][0] == 0) temp++;
		if (temp >= 4)
			for (int i = 0; i < 4; i++)
				form[i][0]+=move;
	}

	//Вращение фигурки ******** надо как-то переделать вращение "0"(квадрата) ********
	private void rotation() {

		//Копируем фигурку с поворотом
		int tempBlock[][] = new int[4][2];
		for (int i = 0; i < 4; i++) {
			tempBlock[i][0] = -form[i][1]+form[0][1]+form[0][0];
			tempBlock[i][1] = form[i][0]-form[0][0]+form[0][1];
		}

		//Проверяем на наложение повернутую копию фигурки
		temp = 0;
		for (int i = 0; i < 4; i++)
			if (tempBlock[i][0] >= 0 && tempBlock[i][0] < 10 && ground[tempBlock[i][1]][tempBlock[i][0]][0] == 0) temp++;

		//Поворачиваем фигурку
		if (temp >= 4) {
			for (int i = 0; i < 4; i++) {
				form[i][0] = tempBlock[i][0];
				form[i][1] = tempBlock[i][1];
			}
		}
	}

	//Проверка на заполнение строки
	private void clear() {
		for (int i = 0; i < 20; i++) {

			//Подсчитываем число полных блоков в ряду
			temp = 0;
			for (int j = 0; j < 10; j++) if (ground[i][j][0] > 0) temp++;

			//Удаляем заполненный ряд ******** надо переделать на отбеливание ряда перед удалением ********
			if (temp >= 10) {
				for (int j = 0; j < 10; j++) ground[i][j][0] = 0;
				drop();
			}
		}
	}

	//Опускаем верхние ряды
	private void drop() {
		for (int i = 19; i > 0; i--) {

			//Подсчитываем число пустых блоков в ряду
			temp = 0;
			for (int j = 0; j < 10; j++) if (ground[i][j][0] == 0) temp++;

			//Смещаем вехние блоки
			if (temp >= 10) {
				for (int j = i; j > 0; j--) {
					for (int n = 0; n < 10; n++) ground[j][n][0] = ground[j-1][n][0];
				}
			}
		}
	}

	//Конец игры ******** переделать ********
	private void gameFinish() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) ground[i][j][0] = 0xffffff;
		}
	}

	//Отрисовка игры
	@Override
	public void paint (Graphics ctx) {

		//Сайдбар
		ctx.setColor(Color.darkGray);
		ctx.fillRect(10*block+1, 0, 5*block, 20*block+1);

		//Предпросмотр блока
		ctx.setColor(colorLook);
		for (int i = 0; i < 4; i++)
			ctx.fillRect(forms[look][i][0]*block+11*block+10, forms[look][i][1]*block+2*block, block-1, block-1);

		//Панель информации
		ctx.setFont(new Font("Courier New", Font.BOLD, 24));
		ctx.setColor(Color.white);
		ctx.drawString(("Speed: " + speed), 10*block+10, 6*block);
		ctx.setColor(Color.yellow);
		ctx.drawString(("Step: " + step), 10*block+10, 7*block);

		//******** убрать или заменить ********
		ctx.setFont(new Font("Courier New", Font.BOLD, 20));
		ctx.setColor(colorBlock);
		ctx.drawString(("X: " +form[0][0]+" "+form[1][0]+" "+form[2][0]+" "+form[3][0]), 10*block+10, 13*block);
		ctx.drawString(("Y: " +form[0][1]+" "+form[1][1]+" "+form[2][1]+" "+form[3][1]), 10*block+10, 14*block);
		ctx.drawString(("gameOver: " + gameOver), 10*block+10, 15*block);

		//Днище
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				ctx.setColor(new Color(ground[i][j][0]));
				ctx.fillRect(j*block, i*block, block, block);
			}
		}

		//Фигура
		ctx.setColor(colorBlock);
		for (int i = 0; i < 4; i++)
			ctx.fillRect(form[i][0]*block, form[i][1]*block, block, block);

		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(i*block, 0, i*block, 20*block);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, 10*block, i*block);
	}
}