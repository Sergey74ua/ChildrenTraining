//Игра "Муравейник"

class Ground {
    colFill='DarkGreen';
    colLabel='Yellow';
    colFood='DarkRed';

    //Игровой фон
    constructor() {
        this.listFood=this.listFoodFill(4);
        this.listLabel=[];
    }

    //Обновление
    update() {
        //Испарение меток
        let buffer=[];
        for (let label of this.listLabel) {
            if (label.value > 0) {
                label.value--;
                buffer.push(label);
            }
        }
        this.listLabel=buffer;
    }

    //Отрисовка
    draw() {
        //Заливка фона
        ctx.fillStyle=this.colFill;
        ctx.fillRect(0, 0, width, height);
        //Отрисовка меток
        for (let label of this.listLabel) {
            ctx.fillRect(label.pos.x, label.pos.y, 1, 1);
        }
        //Отрисовка корма
        for (let food of this.listFood) {
            ctx.fillStyle=this.colFood;
            ctx.beginPath();
            ctx.arc(food.pos.x, food.pos.y, food.value*size/128, 0, Pi2);
            ctx.fill();
            ctx.closePath();
        }
    }

    //Начальный корм
    listFoodFill(multi) {
        let listFood=[];
        let numFood=numColony*population*multi;
        for (let i=0; i<numFood; i++) {
            let pos={
                x: Math.round(Math.random()*width),
                y: Math.round(Math.random()*height)
            };
            let food={pos: pos, value: 255};
            listFood.push(food);
        }
        return listFood;
    }
}
