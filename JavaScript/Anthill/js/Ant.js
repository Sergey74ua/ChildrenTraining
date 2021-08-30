//Игра "Муравейник"

class Ant {
    //Муравей
    stroke='Black';
    line=size/5;
    speed=size*2;
    
    //Создание муравья
    constructor(pos, party) {
        this.party=party;
        this.pos={x: pos.x, y: pos.y};
        this.angle=Math.random()*Pi2;
        this.pose=false;
        this.food=false;
        this.target;
    }

    //Обновление
    update() {
        let pos=this.pos;
        //Рандомное смещение
        if(Math.random() >= 0.9)
            this.angle=(this.angle+Math.random()-0.5+Pi2)%Pi2;
        //Рассчет координат при перемещении
        let angle=this.angle-Math.PI/2;
        pos.x+=this.speed*Math.cos(angle);
        //левая граница
        if (pos.x<0) {
            pos.x=0;
            this.angle=Pi2-this.angle;
        //правая граница
        } else if (pos.x>width-1) {
            pos.x=width-1;
            this.angle=Pi2-this.angle;
        }
        pos.y+=this.speed*Math.sin(angle);
        //верхняя граница
        if (pos.y<0) {
            pos.y=0;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        //нижняя граница
        } else if (pos.y>height-1) {
            pos.y=height-1;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        }
        //Замкнутый мир
        /*pos.x+=this.speed*Math.cos(angle);
        if (pos.x<0)
            pos.x=width-1;
        else if (pos.x>width-1)
            pos.x=0;
        pos.y+=this.speed*Math.sin(angle);
        if (pos.y<0)
            pos.y=height-1;
        else if (pos.y>height-1)
            pos.y=0;*/
        if (play)
            this.pose=!this.pose;
    }

    //Отрисовка
    draw() {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        let pose = this.pose*size*0.5;
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.party;
        //Тени
        ctx.shadowBlur=3;
        ctx.shadowOffsetX=2;
        ctx.shadowOffsetY=1;
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
