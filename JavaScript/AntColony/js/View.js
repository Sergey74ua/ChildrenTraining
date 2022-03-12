//Симулятор колонии муравьев

class View {

    //Представление
    constructor() {
        this.canvas=document.getElementById('canvas');
        this.onResize();
        window.addEventListener('resize', this.onResize);
    }

    //Отрисовка экрана
    draw() {
        this.ctx.fillStyle='DarkGreen';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
        
        model.ant.draw(this.ctx);
        model.antHill.draw(this.ctx);
        model.block.draw(this.ctx);
        model.rock.draw(this.ctx);
        model.food.draw(this.ctx);
    }

    //Выравнивание экрана по размерам окна
    onResize() {
        this.canvas.width=window.innerWidth;
        this.canvas.height=window.innerHeight;
        this.ctx=this.canvas.getContext('2d');
        this.ctx.shadowColor='Black';
    }
}

/*
ЗАГРУЗКА
- инициализация базовых данных для отрисовки

СТАРТ/РЕСТАРТ
- перерисовка

ШАГ ИГРЫ
- отрисовка фона
- отрисовка предметов
- отрисовка меток
- отрисовка муравьев
- отрисовка интерфейса
*/