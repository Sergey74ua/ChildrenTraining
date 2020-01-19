/*
 * Обучаемся языку Java на примере Тетриса
 * Сергей. Октябрь 2019 - январь 2020 года.
 */

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.KeyListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Tetris extends JPanel {

	//Переменные, массивы и объекты
	private static boolean gameOver, gamePause;
	private static int block = 40, pause = 1, speed, score, record, line, trt, tempTRT, noTRT, step, game, look, color, temp;
	private int scores[] = {0, 100, 300, 700, 1500};
	private int form[][] = new int[4][2];          // блоки / x, y
	private int ground[][][] = new int[24][10][1]; // ряды / колонки / rgb
	private int forms[][][] = {                    // фигурка / блоки / x, y и rgb
		{{ 0,  0}, {-1,  0}, { 1,  0}, { 2,  0}, {0x00ffff}}, // I aqua
		{{ 0,  0}, { 1,  0}, { 0,  1}, { 1,  1}, {0xffff00}}, // O yellow
		{{ 0,  0}, {-1,  0}, { 1,  0}, { 0,  1}, {0xff00ff}}, // T purple
		{{ 0,  0}, { 0, -1}, {-1,  1}, { 0,  1}, {0xffa500}}, // L orange
		{{ 0,  0}, { 0, -1}, { 0,  1}, { 1,  1}, {0x0000ff}}, // J blue
		{{ 0,  0}, { 1,  0}, {-1,  1}, { 0,  1}, {0x00ff00}}, // S green
		{{ 0,  0}, {-1,  0}, { 0,  1}, { 1,  1}, {0xff0000}}, // Z red
	};
	private static Random random = new Random();
	private static Color colorBlock, colorLook;
	private static Image image = new ImageIcon("earth.png").getImage();

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

		//Отслеживаем нажатия клавиш
		jFrame.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent event) {
				tetris.anyKey(1);
				switch(event.getKeyCode()) {
					case 32: tetris.anyKey(0);	break; //пробел (пауза)
					case 37: tetris.move(-1);	break; //влево
					case 38: tetris.rotation();	break; //вверх(вращение)
					case 39: tetris.move(+1);	break; //вправо
					case 40: speed = 40;		break; //вниз (сброс)
				}
				tetris.repaint();
			}
		});

		//Поехали!
		tetris.gameMain();
	}

	//Основной цикл игры
	private void gameMain() {

		//Начальные значения
		look = random.nextInt(7);
		newBlock();
		speed = 400; score = 0; step = 0; line = 0; trt = 0; tempTRT = 0; noTRT = 0;
		gameOver = false;
		game++;
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 10; j++) {
				ground[i][j][0] = 0;
			}
		}

		//Цикл анимации
		while (!gameOver) {
			gameCycle();
			timer();
		}

		//Конец игры ******** нужно как-то зафиксировать надпись конца игры ********
		pause = 0;
		gameMain();
	}

	//Таймер игры
	private void timer() {
		try {
			Thread.sleep(speed);
		} catch (Exception e){}
		repaint();
	}

	//Пауза
	private void anyKey(int pause) {
		this.pause = pause;
		if (pause == 1) gamePause = false;
		else gamePause = true;
	}

	//Проверка падения блока вниз
	private void gameCycle() {

		//Проверка падения блока вниз
		temp = 0;
		for (int i = 0; i < 4; i++)
			if (form[i][1]+1 < 20 && ground[form[i][1]+5][form[i][0]][0] == 0)
				temp++;
		if (temp >= 4) {
			for (int i = 0; i < 4; i++)
				form[i][1]+=1*pause;
		} else {

			//Устанавливаем скорость игры
			if (step <= 280) speed = 400-step; else speed = 120;

			//Поверка на конец игры
			for (int i = 0; i < 4; i++)
				if (form[i][1] < 0) gameOver = true;

			step++;

			//Добавляем фигурку в массив
			for (int i = 0; i < 4; i++)
				ground[form[i][1]+4][form[i][0]][0] = color*2/3;

		newBlock();
		}
	}

	//Запуск фигурки
	private void newBlock() {

		//Передаем цвет из предпросмотра
		color = forms[look][4][0];
		colorBlock = new Color(color);

		if (look != 0) noTRT++;
		else noTRT = 0;

		//Передаем координаты из предпросмотра в фигурку
		temp = random.nextInt(7)+1;
		for (int i = 0; i < 4; i++) {
			form[i][0] = forms[look][i][0]+temp;
			form[i][1] = forms[look][i][1]-2;
		}

		clear();

		//Новая игурка в предпосмотр
		look = random.nextInt(7);
		colorLook = new Color(forms[look][4][0]);
	}

	//Смещение фигурки
	private void move(int move) {
		temp = 0;
		for (int i = 0; i < 4; i++)
			if (form[i][0]+move >= 0 && form[i][0]+move < 10 && ground[form[i][1]+4][form[i][0]+move][0] == 0)
				temp++;
		if (temp >= 4)
			for (int i = 0; i < 4; i++)
				form[i][0]+=move;
	}

	//Вращение фигурки
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
			if (tempBlock[i][0] >= 0 && tempBlock[i][0] < 10 && ground[tempBlock[i][1]+4][tempBlock[i][0]][0] == 0)
				temp++;

		//Поворачиваем фигурку
		if (temp >= 4 && color != 0xffff00) { //******** наговнокодил с квадратом ********
			for (int i = 0; i < 4; i++) {
				form[i][0] = tempBlock[i][0];
				form[i][1] = tempBlock[i][1];
			}
		}
	}

	//Проверка на заполнение строки
	private void clear() {

		//Проходим по всем рядам и отбеливаем
		int tempScore = 0;
		for (int i = 0; i < 24; i++) {

			//Подсчитываем число полных блоков в ряду
			temp = 0;
			for (int j = 0; j < 10; j++)
				if (ground[i][j][0] > 0)
					temp++;

			//Отбеливаем заполненный ряд
			if (temp >= 10) {
				tempScore++;
				line++;

				///Подсчитываем число процент тетриса
				if (tempScore >= 4) tempTRT++;
				trt = Math.round(tempTRT*400/line);

				for (int j = 0; j < 10; j++)
					ground[i][j][0] = 0xffffff;
			}
		}

		//Подсчитываем очки
		score+=scores[tempScore];
		if (record < score) record = score;
		timer();

		//Проходим по всем рядам и смещаем их вниз
		for (int i = 0; i < 24; i++) {

			//Подсчитываем число отбеленых блоков в ряду и очищаем
			temp = 0;
			for (int j = 0; j < 10; j++)
				if (ground[i][j][0] == 0xffffff)
					temp++;

			//Сбрасываем (копируем) верхние блоки
			if (temp >= 10)
				for (int iClear = i; iClear >= 0; iClear--)
					for (int j = 0; j < 10; j++)
						if (iClear > 0)
							ground[iClear][j][0] = ground[iClear-1][j][0];
						else
							ground[iClear][j][0] = 0;
		}
	}

	//Отрисовка игры
	@Override
	public void paint (Graphics ctx) {

		//Сайдбар
		ctx.setColor(Color.darkGray);
		ctx.fillRect(10*block+1, 0, 5*block, 20*block+1);

		//Предпросмотр блока
		for (int i = 0; i < 4; i++) {
			ctx.setColor(colorLook);
			ctx.fillRect(forms[look][i][0]*block+11*block+10, forms[look][i][1]*block+2*block, block-1, block-1);
			ctx.setColor(Color.white);
			ctx.fillRect(forms[look][i][0]*block+11*block+10+4, forms[look][i][1]*block+2*block+4, 12, 3);
			ctx.fillRect(forms[look][i][0]*block+11*block+10+4, forms[look][i][1]*block+2*block+7, 3, 10);
		}

		//Панель информации
		ctx.setFont(new Font("Courier New", Font.BOLD, 20));
		ctx.setColor(Color.white);
		ctx.drawString(("Speed: " + speed), 10*block+10, 5*block);
		ctx.setColor(Color.orange);
		ctx.drawString(("Record: " + record), 10*block+10, 6*block);
		ctx.setColor(Color.green);
		ctx.drawString(("Score: " + score), 10*block+10, 7*block);
		ctx.setColor(Color.yellow);
		ctx.drawString(("Line: " + line), 10*block+10, 8*block);
		ctx.setColor(Color.blue);
		ctx.drawString(("TRT: " + trt + "%"), 10*block+10, 9*block);
		ctx.setColor(Color.red);
		ctx.drawString(("no plank: " + noTRT), 10*block+10, 10*block);
		ctx.setColor(Color.gray);
		ctx.drawString(("Step: " + step), 10*block+10, 11*block);
		ctx.setColor(Color.cyan);
		ctx.drawString(("Game: " + game), 10*block+10, 12*block);

		//Днище
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				ctx.setColor(new Color(ground[i+4][j][0]));
				ctx.fillRect(j*block, i*block, block, block);
				if (ground[i+4][j][0] > 0 && ground[i+4][j][0] < 0xffffff) {
					ctx.setColor(Color.gray);
					ctx.fillRect(j*block+4, i*block+4, 12, 3);
					ctx.fillRect(j*block+4, i*block+7, 3, 10);
				}
			}
		}

		ctx.drawImage(image, block*2, block*2, null);

		//Фигура
		for (int i = 0; i < 4; i++) {
			ctx.setColor(colorBlock);
			ctx.fillRect(form[i][0]*block, form[i][1]*block, block, block);
			ctx.setColor(Color.white);
			ctx.fillRect(form[i][0]*block+4, form[i][1]*block+4, 12, 3);
			ctx.fillRect(form[i][0]*block+4, form[i][1]*block+7, 3, 10);
		}

		//Сетка
		ctx.setColor(Color.gray);
		for (int i = 0; i <= 10; i++) ctx.drawLine(i*block, 0, i*block, 20*block);
		for (int i = 0; i <= 20; i++) ctx.drawLine(0, block*i, 10*block, i*block);

		//Пауза
		if (gamePause) {
			ctx.setColor(new Color(128, 128, 192, 192));
			ctx.fillRect(5, 5, block*14+11, block*19+31);
			ctx.setColor(Color.white);
			ctx.setFont(new Font("Courier New", Font.BOLD, 48));
			ctx.drawString(("P A U S E"), 4*block+10, 10*block);
			ctx.setFont(new Font("Courier New", Font.BOLD, 14));
			ctx.drawString(("p r e s s   a n y   k e y"), 5*block, 11*block);
		}

		//Конец игры ******** оптимизировать бы ********
		if (gameOver) {
			ctx.setColor(new Color(192, 128, 128, 192));
			ctx.fillRect(5, 5, block*14+11, block*19+31);
			ctx.setColor(Color.white);
			ctx.setFont(new Font("Courier New", Font.BOLD, 48));
			ctx.drawString(("GAME OVER"), 4*block+10, 10*block);
			ctx.setFont(new Font("Courier New", Font.BOLD, 14));
			ctx.drawString(("p r e s s   a n y   k e y"), 5*block, 11*block);
		}
	}
}