package com.hikkicoders.spacezombie;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;

public class Level_01 extends AppCompatActivity {

    // Элементы экрана
    private ImageView imageViewL1Window, imageViewL1Door, imageViewL1Cupboard,
            imageViewL1ZombieW, imageViewL1ZombieD, imageViewL1ZombieR,
            imageViewHero0, imageViewHero1, imageViewHero2,
            imageViewHero3, imageViewHero4, imageViewHero5;

    // Сценарии анимации
    protected Animation zombwinleft, zombwinright, zombroom, alpha, combo;

    // Звуки событий
    protected MediaPlayer zombw, zombd, zombr, zombh;

    // Переменные логики

    private String step;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.level_01);

        // Прописываем ID-шники переменным элементов
        imageViewL1Window = findViewById(R.id.imageViewL1Window);
        imageViewL1Door = findViewById(R.id.imageViewL1Door);
        imageViewL1Cupboard = findViewById(R.id.imageViewL1Cupboard);
        imageViewL1ZombieW = findViewById(R.id.imageViewL1ZombieW);
        imageViewL1ZombieD = findViewById(R.id.imageViewL1ZombieD);
        imageViewL1ZombieR = findViewById(R.id.imageViewL1ZombieR);
        imageViewHero0 = findViewById(R.id.imageViewHero0);
        imageViewHero1 = findViewById(R.id.imageViewHero1);
        imageViewHero2 = findViewById(R.id.imageViewHero2);
        imageViewHero3 = findViewById(R.id.imageViewHero3);
        imageViewHero4 = findViewById(R.id.imageViewHero4);
        imageViewHero5 = findViewById(R.id.imageViewHero5);

        // Прописываем пути доступа переменным анимации
        zombwinleft = AnimationUtils.loadAnimation(this, R.anim.zombwinleft);
        zombwinright = AnimationUtils.loadAnimation(this, R.anim.zombwinright);
        zombroom = AnimationUtils.loadAnimation(this, R.anim.zombroom);
        alpha = AnimationUtils.loadAnimation(this, R.anim.alpha);
        combo = AnimationUtils.loadAnimation(this, R.anim.combo);

        // Прописываем пути доступа переменным звука
        zombw = MediaPlayer.create(this, R.raw.zombw);
        zombd = MediaPlayer.create(this, R.raw.zombd);
        zombr = MediaPlayer.create(this, R.raw.zombr);
        zombh = MediaPlayer.create(this, R.raw.zombh);

        //Оператор выбора действия при нажатой кнопке
        View.OnClickListener onClickListener = new View.OnClickListener() {

            @Override
            public void onClick(View view) {

            // Обновление невидимости для всех картинок персонажей
            imageViewL1ZombieW.setVisibility(View.INVISIBLE);
            imageViewL1ZombieD.setVisibility(View.INVISIBLE);
            imageViewL1ZombieR.setVisibility(View.INVISIBLE);
            imageViewHero0.setVisibility(View.INVISIBLE);
            imageViewHero1.setVisibility(View.INVISIBLE);
            imageViewHero2.setVisibility(View.INVISIBLE);
            imageViewHero3.setVisibility(View.INVISIBLE);
            imageViewHero4.setVisibility(View.INVISIBLE);
            imageViewHero5.setVisibility(View.INVISIBLE);

            if (step == "finish") {
                Intent intent = new Intent(Level_01.this, Level_03.class);
                startActivity(intent);
                finish();
                System.exit(0);
            }

            //Картинка при выборе игрока и эффект нажатия картинки
            switch (view.getId()){

                case R.id.imageViewL1Window:
                    step = "window";
                    stepWindow ();
                    break;

                case R.id.imageViewL1Door:
                    if (step == "window") {
                        step = "door";
                        stepDoor();
                    }
                    break;

                case R.id.imageViewL1Cupboard:
                    if (step == "door") {
                        step = "cupboard";
                        stepCupboard ();
                    }
                    break;

                case R.id.imageViewHero3:
                    if (step == "cupboard") {
                        step = "finish";
                        stepHero3 ();
                    }
                    break;
            }
            }
        };

        // Назначаем обработчик (слушатель) картинок-кнопок
        imageViewL1Window.setOnClickListener(onClickListener);
        imageViewL1Door.setOnClickListener(onClickListener);
        imageViewL1Cupboard.setOnClickListener(onClickListener);
        imageViewHero3.setOnClickListener(onClickListener);
    }

    // Функция при клике на окно
    private void stepWindow () {
        imageViewHero1.setVisibility(View.VISIBLE);
        imageViewL1ZombieW.startAnimation(zombwinleft);
        imageViewL1ZombieW.setVisibility(View.VISIBLE);
        zombw.start();
    }

    // Функция при клике на дверь
    private void stepDoor () {
        imageViewHero2.setVisibility(View.VISIBLE);
        imageViewL1ZombieW.startAnimation(zombwinright);
        imageViewL1ZombieD.startAnimation(zombwinleft);
        imageViewL1ZombieD.setVisibility(View.VISIBLE);
        zombd.start();
    }

    // Функция при клике на дверь
    private void stepCupboard () {
        imageViewHero3.setVisibility(View.VISIBLE);
        imageViewHero3.startAnimation(alpha);
        imageViewL1ZombieR.startAnimation(zombroom);
        imageViewL1ZombieR.setVisibility(View.VISIBLE);
        zombr.start();
    }

    // Функция при клике на дверь
    private void stepHero3 () {
        imageViewL1ZombieR.startAnimation(combo);
        imageViewL1ZombieR.setVisibility(View.VISIBLE);
        imageViewHero5.setVisibility(View.VISIBLE);
        zombh.start();
    }

    // Функция кнопки-выхода
    private void exit(View view) {
        finish();
        System.exit(0);
    }
}
