class Ant {
    Pi2=2*Math.PI;
    stroke='black';
    fill='saddleBrown';
    size=5;
    line=this.size/5;
    
    //Создание муравья
    constructor(x, y) {
        this.x=x;
        this.y=y;
        this.angle=0.0;
        this.pose=true;
        this.food=true;
    }

    //Обновление
    update() {
        this.x+=Math.random() * this.size-this.size/2;
        this.y-=this.size;
        if (this.y<0)
            this.y=1000;
    }

    //Отрисовка
    draw() {
        let Pi2=this.Pi2, size=this.size;
        let x=this.x, y=this.y, angle=this.angle;
        if (game)
            this.pose=!this.pose;
        let pose = this.pose*size*0.5;
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.fill;
        //Лапки 1-4
        ctx.beginPath();
        ctx.moveTo(x-size*2.5, y-size*3-pose*2);
        ctx.lineTo(x-size*2, y-size*1.5-pose);
        ctx.lineTo(x+size*2.8, y+size*2+pose*2);
        ctx.lineTo(x+size*4, y+size*6+pose);
        //Лапки 2-5
        ctx.moveTo(x-size*3.5, y+size*1+pose);
        ctx.lineTo(x-size*2.2, y-size*0.25+pose);
        ctx.lineTo(x+size*2.2, y+size*0.25-pose);
        ctx.lineTo(x+size*3.5, y+size*1.5-pose);
        //Лапки 3-6
        ctx.moveTo(x-size*4, y+size*7-pose);
        ctx.lineTo(x-size*2.8, y+size*3-pose*2);
        ctx.lineTo(x+size*2, y-size*2+pose);
        ctx.lineTo(x+size*2.5, y-size*4+pose*2);
        ctx.stroke();
        ctx.closePath();
        //Голова
        ctx.beginPath();
        ctx.ellipse(x, y-size*2, size*1.25, size, angle, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+size*3.5, size*1.5, size*2.5, angle, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Грудь
        ctx.beginPath();
        ctx.arc(x, y, size, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Усики
        ctx.beginPath();
        ctx.moveTo(x-size*0.5, y-size*2.5);
        ctx.lineTo(x-size*1.5+pose*0.5, y-size*4.5);
        ctx.moveTo(x+size*0.5, y-size*2.5);
        ctx.lineTo(x+size*1.5-pose*0.5, y-size*4.5);
        ctx.stroke();
        ctx.closePath();
    }
 }