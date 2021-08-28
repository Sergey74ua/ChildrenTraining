//Игра "Муравейник"

class Food {
    fill='DarkRed';

    //Корм
    constructor() {
        this.listFood=this.listFoodFill();
    }

    //Обновление
    update() {
        ; //перерасчет корма
    }

    //Отрисовка
    draw() {
        ctx.fillStyle=this.fill;
        ctx.beginPath();
        ctx.arc(x, y, 2, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
    }

    //Заполнение массива корма
    listFoodFill() {
        let listFood=[];
        for (let i=0; i<height; i++)
            for (let i=0; i<width; i++) {
                let chit=0;
                listFood.push(chit);
        }
        return listFood;
    }
}
