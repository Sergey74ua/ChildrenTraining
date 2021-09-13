//Игра "Муравейник"

class Colony {
    pallet=['SaddleBrown', 'DarkKhaki', 'DimGrey', 'Maroon'];
    duration=32;
    rad=size*12;
    life=64;

    //Игровой фон
    constructor(i, family) {
        this.clan=this.getColor(i);
        this.listAnt=[];
        this.pioner=Math.round(family/4);
        this.food=(family-this.pioner)*this.life;
        this.timer=this.duration/2;
        this.pos={
            x: Math.round(Math.random()*width*0.8+width/10),
            y: Math.round(Math.random()*height*0.8+height/10)
        };
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
        let grad=ctx.createRadialGradient(this.pos.x, this.pos.y,
            size*2, this.pos.x, this.pos.y, this.rad);
        grad.addColorStop(0, this.clan);
        grad.addColorStop(1, 'transparent');
        ctx.fillStyle = grad;
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
    
    //Цвет колонии
    getColor(i) {
        if (i<this.pallet.length)
            return this.pallet[i];
        else
            return '#'+Math.floor(Math.random()*16777216).toString(16).padStart(6, '0');
    }
}
