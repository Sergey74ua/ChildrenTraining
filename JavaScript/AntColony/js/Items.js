//Симулятор колонии муравьев

class Items {
    //Абстрактный класс для объектов
    constructor(pos) {
        this.pos={
            x: pos.x,
            y: pos.y
        };
    }

    draw(ctx) {
        ctx.fillStyle=this.color;
        ctx.beginPath();
        ctx.fillRect(this.pos.x, this.pos.y, 1, 1);
        ctx.fill();
        ctx.closePath();
    }
}

class Block extends Items {
    //Преграды - непроходимые, непереносимые
    constructor(pos) {
        super(pos);
        this.color='#1b2b20';
    }
}

class Rock extends Items {
    //Камни - непроходимые, переносимые
    constructor(pos) {
        super(pos);
        this.color='SteelBlue';
        this.weight=Math.round(Math.random()*16)+240;
    }
}

class Food extends Items {
    //Корм - непроходим, переносим и съедобен
    constructor(pos) {
        super(pos);
        this.color='Brown';
        this.weight=Math.round(Math.random()*128)+128;
    }
}