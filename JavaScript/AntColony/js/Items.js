//Симулятор колонии муравьев

class Items {
    //Абстрактный класс для объектов
    constructor() {
        this.pos={
            y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10),
            x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10)
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
    constructor() {
        super();
        this.color='Black';
    }
}

class Rock extends Items {
    //Камни - непроходимые, переносимые
    constructor() {
        super();
        this.color='Lime';
        this.weight=Math.round(Math.random()*16)+240;
    }
}

class Food extends Items {
    //Корм - непроходим, переносим и съедобен
    constructor() {
        super();
        this.color='Brown';
        this.weight=Math.round(Math.random()*128)+128;
    }
}