//Игра "Муравейник"

class Ground {
    colFill='DarkGreen';
    colFood='DarkRed';

    //Игровой фон
    constructor() {
        this.map=this.startMap();
    }

    //Обновление
    update() {
        ;
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
                //Отрисовка меток
                if (this.map[y][x].smell>0) {
                    ctx.fillStyle='rgba(127, 0, 127,'+(this.map[y][x].smell/256)+')';
                    ctx.beginPath();
                    ctx.fillRect(x, y, 1, 1);
                    ctx.fill();
                    ctx.closePath();
                    //Испарение меток
                    this.map[y][x].smell--;
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

    //Начальный корм
    startMap() {
        let map=[];
        for (let y=0; y<height; y++) {
            map[y]=[];
            for (let x=0; x<width; x++) {
                map[y][x]={busy: 0, food: 0, smell: 0};
            }
        }
        //Случайный корм
        let numFood=numColony*population;
        for (let i=0; i<numFood; i++) {
            let x=Math.round(Math.random()*width*0.9+width/20),
                y=Math.round(Math.random()*height*0.9+height/20);
            map[y][x].food=Math.round(Math.random()*128)+128;
        }
        return map;
    }

    //Добавление метки
    newLabel(pos) { //Ломается при изменении размера экрана
        if (this.map[pos.y][pos.x].smell<=0)
            this.map[pos.y][pos.x].smell=128;
        else if (this.map[pos.y][pos.x].smell>128)
            this.map[pos.y][pos.x].smell=255;
        else
            this.map[pos.y][pos.x].smell+=128;
    }

    //Добавление корма по клику
    newFood(pos) {
        this.map[pos.y][pos.x].food=255;
    }
}
