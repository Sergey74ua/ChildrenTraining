package com.example.spacezombie;

import java.util.Random;

//Класс игроков в КНБ
public class Player {

    //Пользовательский тип для выбора игрока
    enum Hands { KAM, NOJ, BUM }

    //Значение выбора объекта
    public Hands hand;

    //Рандомный выбор компьютера
    public static Hands randomMetod() {
        Hands[] values = Hands.values();
        Random random = new Random();
        int i = random.nextInt(values.length);
        return values[i];
    }

}