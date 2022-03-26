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

        for (let colony of model.listColony)
            for (let ant of colony.listAnt)
                ant.draw(this.ctx, this.fw);
        
        for (let colony of model.listColony)
            colony.draw(this.ctx)
        
        for (let food of model.listFood)
            food.draw(this.ctx);
            
        model.block.draw(this.ctx);
        model.rock.draw(this.ctx);
    }

    //Выравнивание экрана по размерам окна
    onResize() {
        this.canvas.width=window.innerWidth;
        this.canvas.height=window.innerHeight;
        this.ctx=this.canvas.getContext('2d');
        this.ctx.shadowColor='Black';
        this.fw=new Flyweight();
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