//Симулятор колонии муравьев

class Colony {
    
    pallet=['SaddleBrown', 'DarkKhaki', 'DimGrey', 'Maroon'];

    constructor(i, reserve) {
        this.reserve=reserve;
        this.pos=this.getPos();
        this.color=this.getColor(i);
        this.ai=new PI;
        this.listAnt=[];
        this.timer=20;
        this.delay=Math.round(this.timer*0.75);
    }

    //Обновление
    update() {
        if (this.delay>this.timer && this.reserve>0) {
            this.newAnt();
            this.reserve--;
            this.delay=0;
        } else
            this.delay++;
    }

    //Отрисовка
    draw(ctx) {
        let grad=ctx.createRadialGradient(this.pos.x, this.pos.y, 8,
            this.pos.x, this.pos.y, 32);
        grad.addColorStop(0, this.color);
        grad.addColorStop(1, 'transparent');
        ctx.fillStyle=grad;
        ctx.beginPath();
        ctx.arc(this.pos.x, this.pos.y, 32, 0, Math.PI*2);
        ctx.fill();
        ctx.closePath();
    }

    //Создание муравья
    newAnt() {
        let ant=new Ant(this);
        this.listAnt.push(ant);
    }

    //Позиция колонии
    getPos() {
        let pos={
            y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10),
            x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10)
        };
        return pos;
    }
    
    //Цвет колонии
    getColor(i) {
        if (i<this.pallet.length)
            return this.pallet[i];
        else
            return '#'+Math.floor(Math.random()*16777216).toString(16).padStart(6, '0');
    }
}