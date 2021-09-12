//Игра "Муравейник"

class Ant {
    stroke='Black';
    line=size/5;
    speed=size*2;
    power=8;
    
    //Создание муравья
    constructor(pos, party) {
        this.party=party;
        this.pos={x: pos.x, y: pos.y};
        this.angle=Math.random()*Pi2;
        this.pose=false;
        this.status='wait';
        this.food=0; //(Math.random()>0.5)*16;
        this.timer=0;
        this.target;
    }

    //Обновление
    update() {
        //Смена шагов
        if (this.timer>0)
            this.timer--;
        if (play && this.timer<=0) {
            this.pose=!this.pose;
            this.speed=size*2;
        }
        else
            this.speed=0;
        //Рандомное смещение (ПЕРЕНЕСТИ - ???)
        if(Math.random() >= 0.9)
            this.angle=(this.angle+Math.random()-0.5+Pi2)%Pi2;
        //Рассчет координат при перемещении
        let angle=this.angle-Math.PI/2;
        this.pos.x+=this.speed*Math.cos(angle);
        //левая граница
        if (this.pos.x<0) {
            this.pos.x=0;
            this.angle=Pi2-this.angle;
        //правая граница
        } else if (this.pos.x>width-1) {
            this.pos.x=width-1;
            this.angle=Pi2-this.angle;
        }
        this.pos.y+=this.speed*Math.sin(angle);
        //верхняя граница
        if (this.pos.y<0) {
            this.pos.y=0;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        //нижняя граница
        } else if (this.pos.y>height-1) {
            this.pos.y=height-1;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        }
        this.pos={x: Math.round(this.pos.x), y: Math.round(this.pos.y)};
    }

    //Отрисовка
    draw() {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        let pose = this.pose*size*0.5;
        //Смена координат для поворота
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(angle);
        ctx.translate(-x, -y);
        //Корм
        if (this.food>0) {
            ctx.fillStyle='DarkRed';
            ctx.beginPath();
            ctx.arc(x, y-size*4, size, 0, Pi2);
            ctx.fill();
            ctx.closePath();
        }
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.party;
        //Тени
        ctx.shadowBlur=3;
        ctx.shadowOffsetX=2;
        ctx.shadowOffsetY=1;
        //Лапки 1-4
        ctx.beginPath();
        ctx.moveTo(x-size*2.5, y-size*3-pose*2);
        ctx.lineTo(x-size*2, y-size*1.5-pose);
        ctx.lineTo(x+size*2.8, y+size*2+pose*2);
        ctx.lineTo(x+size*4, y+size*6+pose*4);
        //Лапки 2-5
        ctx.moveTo(x-size*3.5, y+size*1+pose);
        ctx.lineTo(x-size*2.2, y-size*0.25+pose);
        ctx.lineTo(x+size*2.2, y+size*0.25-pose);
        ctx.lineTo(x+size*3.5, y+size*1.5-pose);
        //Лапки 3-6
        ctx.moveTo(x-size*4, y+size*8-pose*4);
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
        ctx.shadowBlur=0;
        ctx.shadowOffsetX=0;
        ctx.shadowOffsetY=0;
    }
 }
