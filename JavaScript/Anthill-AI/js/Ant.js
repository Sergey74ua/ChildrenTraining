//Симулятор "Муравейник"

class Ant {
    step=3;
    fast=5;
    
    //Создание муравья
    constructor(pos, clan, life) {
        this.clan=clan;
        this.life=life;
        this.pos={y: pos.y, x: pos.x};
        this.angle=Math.random()*Pi2;
        this.status='wait';
        this.pose=false;
        this.speed=0;
        this.food=0;
        this.target={y: 450, x: 800};
    }

    //Обновление
    update() {
        this.pose=!this.pose;
        this.speed=this.fast;
        
        //Рассчет координат при перемещении
        let angle=this.angle-Math.PI/2;
        this.pos.x+=this.speed*Math.cos(angle);
        //левая граница
        if (this.pos.x<0) {
            this.pos.x=0;
            this.angle=Pi2-this.angle;
        //правая граница
        } else if (this.pos.x>size.width-1) {
            this.pos.x=size.width-1;
            this.angle=Pi2-this.angle;
        }
        this.pos.y+=this.speed*Math.sin(angle);
        //верхняя граница
        if (this.pos.y<0) {
            this.pos.y=0;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        //нижняя граница
        } else if (this.pos.y>size.height-1) {
            this.pos.y=size.height-1;
            this.angle=(Math.PI-this.angle+Pi2)%Pi2;
        }
        this.pos={
            x: Math.round(this.pos.x),
            y: Math.round(this.pos.y)
        };
    }

    //Предрассчет для отрисовки
    stroke='Black';
    line=0.5;
    PI05=Math.PI/2;
    size025=this.size*0.25;
    size05=this.size*0.5;
    size125=this.size*1.25;
    size15=this.size*1.5;
    size2=this.size*2;
    size22=this.size*2.2;
    size25=this.size*2.5;
    size28=this.size*2.8;
    size3=this.size*3;
    size35=this.size*3.5;
    size4=this.size*4;
    size45=this.size*4.5;
    size6=this.size*6;
    size8=this.size*8;

    //Отрисовка
    draw() {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        let pose=this.pose*this.size05;
        //Смена координат для поворота
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(angle);
        ctx.translate(-x, -y);
        //Корм
        if (this.food>0) {
            ctx.fillStyle='DarkRed';
            ctx.beginPath();
            ctx.arc(x, y-this.size4, size, 0, Pi2);
            ctx.fill();
            ctx.closePath();
        }
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.clan;
        //Тени
        ctx.shadowBlur=3;
        ctx.shadowOffsetX=2;
        ctx.shadowOffsetY=1;
        //Лапки 1-4
        ctx.beginPath();
        ctx.moveTo(x-this.size25, y-this.size3-pose*2);
        ctx.lineTo(x-this.size2, y-this.size15-pose);
        ctx.lineTo(x+this.size28, y+this.size2+pose*2);
        ctx.lineTo(x+this.size4, y+this.size6+pose*4);
        //Лапки 2-5
        ctx.moveTo(x-this.size35, y+this.size+pose);
        ctx.lineTo(x-this.size22, y-this.size025+pose);
        ctx.lineTo(x+this.size22, y+this.size025-pose);
        ctx.lineTo(x+this.size35, y+this.size15-pose);
        //Лапки 3-6
        ctx.moveTo(x-this.size4, y+this.size8-pose*4);
        ctx.lineTo(x-this.size28, y+this.size3-pose*2);
        ctx.lineTo(x+this.size2, y-this.size2+pose);
        ctx.lineTo(x+this.size25, y-this.size4+pose*2);
        ctx.stroke();
        ctx.closePath();
        //Голова
        ctx.beginPath();
        ctx.ellipse(x, y-this.size2, this.size125, this.size, 0, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+this.size35, this.size15, this.size25, 0, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Грудь
        ctx.beginPath();
        ctx.arc(x, y, this.size, 0, Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Усики
        ctx.beginPath();
        ctx.moveTo(x-this.size05, y-this.size25);
        ctx.lineTo(x-this.size15+pose*0.5, y-this.size45);
        ctx.moveTo(x+this.size05, y-this.size25);
        ctx.lineTo(x+this.size15-pose*0.5, y-this.size45);
        ctx.stroke();
        ctx.closePath();
        //Сброс координат
        ctx.restore();
        ctx.shadowBlur=0;
        ctx.shadowOffsetX=0;
        ctx.shadowOffsetY=0;
    }
}