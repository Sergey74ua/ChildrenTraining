//Симулятор "Муравейник"

class Action {

    //Конструктор
    constructor() {
    }

    //Поведение
    behavior() {
    }

    //Осмотреться и выбрать цель
    vision() {
    }

    //Поворот на цель
    vector(pos, target) {
        return Math.atan2(target.y-pos.y, target.x-pos.x)+Math.PI/2;
    }

    //Расстояние до цели
    delta(pos, target) {
        return Math.sqrt(Math.pow(target.y-pos.y, 2)+Math.pow(target.y-pos.y, 2));
    }
}
