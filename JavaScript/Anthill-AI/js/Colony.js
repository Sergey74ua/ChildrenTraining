//Симулятор "Муравейник"

class Colony {
    pallet=['SaddleBrown', 'DarkKhaki', 'DimGrey', 'Maroon'];
    duration=32;
    rad=2*12;
    life=64;

    //Игровой фон
    constructor(i, logic, size) {
        this.clan=this.getColor(i);
        this.pos=this.getPos(size);
        this.logic=logic;
        this.listAnt=[];
        this.food=100;
        this.timer=this.duration/2;
        this.listAntFill(this.pioner);
    }

    //Обновление
    update() {
        if (this.food>=this.life) {
            if (this.timer>0)
                this.timer--;
            else {
                this.timer=this.duration;
                this.food-=this.life;
                this.newAnt();
            }
        }
    }

    //Отрисовка муравейника
    draw() {
        let grad=ctx.createRadialGradient(this.pos.x, this.pos.y, 5,
            this.pos.x, this.pos.y, this.rad);
        grad.addColorStop(0, this.clan);
        grad.addColorStop(1, 'transparent');
        ctx.fillStyle=grad;
        ctx.beginPath();
        ctx.arc(this.pos.x, this.pos.y, this.rad, 0, Pi2);
        ctx.fill();
        ctx.closePath();
    }
    
    //Начальное заполнение колонии
    listAntFill(pioner) {
        for (let i=0; i<pioner; i++)
            this.newAnt();
    }

    //Создание муравья
    newAnt() {
        this.listAnt.push(new Ant(this.pos, this.clan, this.life));
    }

    //Выбор позиции колонии
    getPos(size) {
        let pos = {
            y: Math.round(Math.random()*size.height*0.8+size.height/10),
            x: Math.round(Math.random()*size.width*0.8+size.width/10)
        };
        return pos
    }
    
    //Цвет колонии
    getColor(i) {
        if (i<this.pallet.length)
            return this.pallet[i];
        else
            return '#'+Math.floor(Math.random()*16777216).toString(16).padStart(6, '0');
    }
}

//Метки - запах корма и муравьев
class Label {
    constructor(aroma, weight=128) {
        this.color=aroma;
        this.weight=weight;
    }
    update() { // Учесть наложение меток
        if (this.weight>0)
            this.weight--;
        else
            delete this;
    }
}
