//Игра "Муравейник"

class Colony {
    fill='Black';

    //Игровой фон
    constructor(color) {
        this.color=color;
        this.pos={x: width/2, y: height/2}; //Заменить на генератор разных позиций
        this.listAnt=this.listAntFill();
    }

    //Обновление
    update() {
        ;
    }

    //Отрисовка
    draw() {
        ctx.fillStyle=this.fill;
        ctx.beginPath();
        ctx.arc(x, y, 100, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
    }
    
    //Заполнение / очистка массива муравьев
    listAntFill() {
        let listAnt=[];
        for (let i=0; i<population; i++) {
            let ant=new Ant(this.pos, this.color);
            listAnt.push(ant);
        }
        return listAnt;
    }
}
