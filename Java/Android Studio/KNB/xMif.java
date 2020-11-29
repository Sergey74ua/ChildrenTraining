package com.example.spacezombie;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class xMif extends AppCompatActivity {

    private WebView xMif;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_x_mif);

        xMif = (WebView)findViewById(R.id.xMif);
        WebSettings web = xMif.getSettings();
        web.setJavaScriptEnabled(true);
        xMif.loadUrl("https://xmif.ru");
        xMif.setWebViewClient(new WebViewClient());
    }

    @Override
    public void onBackPressed() {
        if (xMif.canGoBack()) {
            xMif.goBack();
        } else {
            super.onBackPressed();
        }
    }
}
