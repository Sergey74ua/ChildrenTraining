//Игра "Муравейник"

class Ground {
    fill='DarkGreen';

    //Игровой фон
    constructor() {
        ; //Массив с метками
    }

    //Обновление
    update() {
        ; //перерасчет меток
    }

    //Отрисовка
    draw() {
        ctx.fillStyle=this.fill;
        ctx.fillRect(0, 0, width, height);
        //переносим метки на фон
    }
}
