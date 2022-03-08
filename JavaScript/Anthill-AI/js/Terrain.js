//Симулятор "Муравейник"

class Terrain {

    //Игровая карта
    constructor(size) {
        this.size=size;
        this.map={};
        this.loadBlock();
        this.loadRock(100);
        this.loadFood(100);
        this.range=1.0;
    }

    //Границы мира
    loadBlock() {
        this.map[0]={};
        this.map[this.size.height-1]={};
        for (let x=0; x<this.size.width; x++) {
            this.map[0][x]=new Block();
            this.map[this.size.height-1][x]=new Block();
        }
        for (let y=1; y<this.size.height-1; y++) {
            this.map[y]={};
            this.map[y][0]=new Block();
            this.map[y][this.size.width-1]=new Block();
        }
    }

    //Камни
    loadRock(count) {
        for (let i=0; i<count; i++) {
            let x=Math.round(Math.random()*this.size.width*0.9+this.size.width/20),
                y=Math.round(Math.random()*this.size.height*0.9+this.size.height/20);
            this.map[y][x]=new Rock();
        }
    }

    //Начальный корм
    loadFood(count) {
        for (let i=0; i<count; i++) {
            let x=Math.round(Math.random()*this.size.width*0.9+this.size.width/20),
                y=Math.round(Math.random()*this.size.height*0.9+this.size.height/20);
            this.map[y][x]=new Food();
        }
    }

    //Проверка занятости точки
    getPos(pos) {
        if (this.map[pos.y][pos.x]!=undefined && this.range<16) {
            pos.y+=(Math.floor(Math.random()*3)-1)*Math.floor(this.range);
            pos.x+=(Math.floor(Math.random()*3)-1)*Math.floor(this.range);
            this.range+=0.1;
            this.getPos(pos); // НЕ РАБОТАЕТ, НА ВЫХОДЕ - НЕОПРЕДЕЛЕННОСТЬ
        } else {
            this.range=1.0;
            return pos
        }
    }

    //Отрисовка пикселя аромата или метки
    drawPixel(y, x) {
        ctx.beginPath();
        ctx.fillRect(x, y, 1, 1);
        ctx.fill();
        ctx.closePath();
    }
}

//Преграды - непроходимые, непереносимые
class Block {
    constructor() {}
}

//Камни - непроходимые, переносимые
class Rock {
    constructor() {
        this.weight=Math.round(Math.random()*16)+240;
    }
}

//Корм - непроходим, переносим и съедобен
class Food {
    constructor() {
        this.weight=Math.round(Math.random()*128)+128;
    }

    //Добавление корма по клику (ПЕРЕДЕЛАТЬ)
    newFood(pos) {
        this.map[pos.y][pos.x].food=255;
    }
}
