//Игра "Муравейник"

class Ground {
    colFill='DarkGreen';
    colFood='DarkRed';

    //Игровой фон
    constructor(resources) {
        this.map=[];
        this.startMap(resources);
    }

    //Обновление
    update(ant) { ////Ломается при изменении размера экрана
        this.map[ant.pos.y][ant.pos.x].busy=1;
        //Добавление метки на карту
        if (this.map[ant.pos.y][ant.pos.x].label<=0)
            this.map[ant.pos.y][ant.pos.x].label=128;
        else if (this.map[ant.pos.y][ant.pos.x].label>128)
            this.map[ant.pos.y][ant.pos.x].label=255;
        else
            this.map[ant.pos.y][ant.pos.x].label+=128;
        //Добавление аромата на карту
        if (ant.food>0) {
            if (this.map[ant.pos.y][ant.pos.x].aroma<=0)
                this.map[ant.pos.y][ant.pos.x].aroma=128;
            else if (this.map[ant.pos.y][ant.pos.x].aroma>128)
                this.map[ant.pos.y][ant.pos.x].aroma=255;
            else
                this.map[ant.pos.y][ant.pos.x].aroma+=128;
        }
    }

    //Отрисовка
    draw() {
        //Заливка фона
        ctx.fillStyle=this.colFill;
        ctx.fillRect(0, 0, width, height);
        //Отрисовка карты на холсте
        for (let y=0; y<height; y++) {
            for (let x=0; x<width; x++) {
                //Препятствие
                this.map[y][x].busy=0; ////
                //Отрисовка аромата или метки
                if (this.map[y][x].aroma>0) {
                    ctx.fillStyle='rgba(255, 192, 0,'+(this.map[y][x].aroma/256)+')';
                    this.drawPixel(x, y);
                } else if (this.map[y][x].label>0) {
                    ctx.fillStyle='rgba(64, 0, 128,'+(this.map[y][x].label/256)+')';
                    this.drawPixel(x, y);
                }
                //Отрисовка корма
                if (this.map[y][x].food>0) {
                    ctx.fillStyle=this.colFood;
                    ctx.beginPath();
                    ctx.arc(x, y, this.map[y][x].food*size/128, 0, Pi2);
                    ctx.fill();
                    ctx.closePath();
                }
            }
        }
    }

    //Отрисовка пикселя аромата или метки
    drawPixel(x, y) {
        ctx.beginPath();
        ctx.fillRect(x, y, 1, 1);
        ctx.fill();
        ctx.closePath();
        //Испарение аромата или метки
        this.map[y][x].aroma--;
        this.map[y][x].label--;
    }

    //Начальный корм
    startMap(resources) {
        //Заполняем массив объектов
        for (let y=0; y<height; y++) {
            this.map[y]=[];
            for (let x=0; x<width; x++)
                this.map[y][x]={busy: 0, food: 0, label: 0, aroma: 0};
        }
        //Случайный корм
        for (let i=0; i<resources; i++) {
            let x=Math.round(Math.random()*width*0.9+width/20),
                y=Math.round(Math.random()*height*0.9+height/20);
            this.map[y][x].food=Math.round(Math.random()*128)+128;
        }
    }

    //Добавление корма по клику
    newFood(pos) {
        this.map[pos.y][pos.x].food=255;
    }
}
