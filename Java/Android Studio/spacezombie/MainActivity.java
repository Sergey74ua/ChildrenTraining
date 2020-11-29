package com.hikkicoders.spacezombie;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void start(View view) {
        Intent intent = new Intent(MainActivity.this, Level_01.class);
        startActivity(intent);
    }

    public void exit(View view) {
        finish();
        System.exit(0);
    }

    public void startFS(View view) {
        Intent intent = new Intent(MainActivity.this, Level_02.class);
        startActivity(intent);
    }

}
