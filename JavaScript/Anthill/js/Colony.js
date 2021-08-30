//Игра "Муравейник"

class Colony {
    pallet=['SaddleBrown', 'DarkKhaki', 'DimGrey', 'Maroon'];
    rad=size*12;

    //Игровой фон
    constructor(i) {
        this.pos={
            x: Math.random()*width*0.8+width/10,
            y: Math.random()*height*0.8+height/10
        };
        this.color=this.getColor(i);
        this.listAnt=this.listAntFill();
    }

    //Обновление
    update() {
        ;
    }

    //Отрисовка муравейника
    draw() {
        let grad = ctx.createRadialGradient(this.pos.x, this.pos.y, size*2,
            this.pos.x, this.pos.y, this.rad);
        grad.addColorStop(0, this.color);
        grad.addColorStop(1, 'transparent');
        ctx.fillStyle = grad;
        ctx.beginPath();
        ctx.arc(this.pos.x, this.pos.y, this.rad, 0, Pi2);
        ctx.fill();
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
    
    //Цвет колонии
    getColor(i) {
        let color;
        if (i<this.pallet.length)
            color=this.pallet[i];
        else
            color='#'+Math.floor(Math.random()*16777216).toString(16).padStart(6, '0');
        return color;
    }
}
