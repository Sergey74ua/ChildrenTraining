package com.example.spacezombie;

import java.util.Random;

//Класс игроков в КНБ
public class Hands {

    //Пользовательский тип для выбора игрока
    enum Form { KAM, NOJ, BUM }

    //Значение выбора объекта
    Form hand;

    //Рандомный выбор компьютера
    public static Form randomMetod() {
        Form[] randomMetod = Form.values();
        Random random = new Random();
        int i = random.nextInt(randomMetod.length);
        return randomMetod[i];
    }

}