package com.example.spacezombie;

import android.content.Intent;
import android.graphics.Color;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;


public class KNB extends AppCompatActivity {

    //Объявляем элементы XML (для доступа из всего документа)
    ImageView imageKam, imageNoj, imageBum, imageViewUser, imageViewComp;
    TextView textViewKNB, textViewGame, textViewWin, textViewLose, textViewDraw;

    //Переменные и счетчики
    int scoreGame, scoreWin, scoreLose, scoreDraw;

    //Звук кнопки
    private SoundPool soundPool = new SoundPool(3, AudioManager.STREAM_MUSIC, 0);

    //Основной метод при загрузке экрана
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_knb);

        //Присваиваем значения объектам кнопок
        imageKam = findViewById(R.id.imageKam);
        imageNoj = findViewById(R.id.imageNoj);
        imageBum = findViewById(R.id.imageBum);

        //Присваиваем значения объектам картинок выбора и результата
        imageViewUser = findViewById(R.id.imageViewUser);
        imageViewComp = findViewById(R.id.imageViewComp);
        textViewKNB = findViewById(R.id.textViewKNB);

        //Присваиваем значения объектам счетчиков
        textViewGame = findViewById(R.id.textViewGame);
        textViewWin = findViewById(R.id.textViewWin);
        textViewLose = findViewById(R.id.textViewLose);
        textViewDraw = findViewById(R.id.textViewDraw);

        //Загружаем файл звука
        soundPool.load(this, R.raw.sound, 1);

        //Создаем объекты для игры
        final Player user = new Player();
        final Player comp = new Player();

        //Оператор выбора действия при нажатой кнопке
        View.OnClickListener onClickListener = new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                //Воспроизводим звук
                soundPool.play(1,1,1,1,0,1);

                //Картинка при выборе игрока и эффект нажатия картинки
                switch (view.getId()){
                    case R.id.imageKam:
                        user.hand = Player.Hands.KAM;
                        imageDefault();
                        imageKam.setImageResource(R.drawable.kamen_click);
                        imageViewUser.setImageResource(R.drawable.kamen);
                        break;
                    case R.id.imageNoj:
                        user.hand = Player.Hands.NOJ;
                        imageDefault();
                        imageNoj.setImageResource(R.drawable.nojnici_click);
                        imageViewUser.setImageResource(R.drawable.nojnici);
                        break;
                    case R.id.imageBum:
                        user.hand = Player.Hands.BUM;
                        imageDefault();
                        imageBum.setImageResource(R.drawable.bumaga_click);
                        imageViewUser.setImageResource(R.drawable.bumaga);
                        break;
                }

                //Картинка выбора компьютера
                comp.hand = Player.randomMetod();
                switch (comp.hand){
                    case KAM:
                        imageViewComp.setImageResource(R.drawable.kamen);
                        break;
                    case NOJ:
                        imageViewComp.setImageResource(R.drawable.nojnici);
                        break;
                    case BUM:
                        imageViewComp.setImageResource(R.drawable.bumaga);
                        break;
                    default: finish();
                }

                //Сравнение результатов
                if (user.hand == comp.hand) {
                    drawKNB();
                } else if ((user.hand == Player.Hands.KAM && comp.hand == Player.Hands.NOJ) ||
                           (user.hand == Player.Hands.NOJ && comp.hand == Player.Hands.BUM) ||
                           (user.hand == Player.Hands.BUM && comp.hand == Player.Hands.KAM)) {
                    winKNB();
                } else {
                    loseKNB();
                }

                //Обновление счетчиков
                scoreKNB();
            }
        };

        //Назначаем обработчик (слушатель) картинок-кнопок
        imageKam.setOnClickListener(onClickListener);
        imageNoj.setOnClickListener(onClickListener);
        imageBum.setOnClickListener(onClickListener);
    }

    //Восстанавливаем стандартные картинки кнопок после нажатия
    private void imageDefault() {
        imageKam.setImageResource(R.drawable.kamen);
        imageNoj.setImageResource(R.drawable.nojnici);
        imageBum.setImageResource(R.drawable.bumaga);
    }

    //Метод в случае победы
    private void winKNB() {
        scoreWin++;
        textViewKNB.setText(getString(R.string.win));
        textViewKNB.setTextColor(Color.GREEN);
    }

    //Метод в случае поражения
    private void loseKNB() {
        scoreLose++;
        textViewKNB.setText(getString(R.string.lose));
        textViewKNB.setTextColor(Color.RED);
    }

    //Метод в случае ничьи
    private void drawKNB() {
        scoreDraw++;
        textViewKNB.setText(getString(R.string.draw));
        textViewKNB.setTextColor(Color.BLUE);
    }

    //Обновление счетчиков
    private void scoreKNB() {
        textViewGame.setText(String.valueOf(++scoreGame));
        textViewWin.setText(String.valueOf(scoreWin));
        textViewLose.setText(String.valueOf(scoreLose));
        textViewDraw.setText(String.valueOf(scoreDraw));
    }

    //Нажатие кнопки возврат в меню
    public void Click_2(View view) {
        Intent intent = new Intent(KNB.this, MainActivity.class);
        startActivity(intent);
        finish();
        System.exit(0);
    }

    //Кнопка выхода
    public void Click_Exit(View view) {
        finish();
        System.exit(0);
    }
}