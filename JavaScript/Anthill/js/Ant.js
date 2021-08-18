//Игра "Муравейник"

class Ant {
    Pi2=2*Math.PI;
    stroke='black';
    fill='saddleBrown';
    size=2;
    line=this.size/5;
    
    //Создание муравья
    constructor(pos) {
        this.pos = {x: pos.x, y: pos.y};
        this.angle=Math.random()*this.Pi2;
        this.pose=true;
        this.food=true;
    }

    //Обновление
    update() {
        //Рассчет координат при перемещении
        if(Math.random() >= 0.9)
            this.angle+=Math.random()-0.5;
        let angle=this.angle-Math.PI/2;
        this.pos.x+=this.size*Math.cos(angle);
        this.pos.y+=this.size*Math.sin(angle);
        // ВРЕМЕННО ///////////////////////////////////////////////////////////////
        if (this.pos.x<3 || this.pos.y<3 || this.pos.x>1917 || this.pos.y>1077)
            this.angle-=Math.PI;
    }

    //Отрисовка
    draw() {
        let Pi2=this.Pi2, size=this.size;
        let x=this.pos.x, y=this.pos.y;
        let angle=this.angle;
        if (play)
            this.pose=!this.pose;
        let pose = this.pose*size*0.5;
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.fill;
        //Смена координат для поворота
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(angle);
        ctx.translate(-x, -y);
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
        ctx.ellipse(x, y-size*2, size*1.25, size, 0, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+size*3.5, size*1.5, size*2.5, 0, 0, Pi2);
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
        //Сброс координат
        ctx.restore();
    }
 }