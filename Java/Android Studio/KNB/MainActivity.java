package com.example.spacezombie;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    //Нажатие на текст
    public void Click_xMif(View view) {
        Intent intent = new Intent(MainActivity.this, xMif.class);
        startActivity(intent);
        finish();
        System.exit(0);
    }

    //Нажатие кпопки перехода в FullScreen
    public void Click_FullScreen(View view) {
        Intent intent = new Intent(MainActivity.this, FullscreenActivity.class);
        startActivity(intent);
        finish();
        System.exit(0);
    }

    //Нажатие кнопки с главного окна
    public void Click_1(View view) {
        Intent intent = new Intent(MainActivity.this, KNB.class);
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
