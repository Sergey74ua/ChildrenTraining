//Симулятор колонии муравьев

class Ant {
    
    //Муравей
    constructor(pos={y: window.innerHeight/2, x: window.innerWidth/2}) {
        this.size=15;
        this.clan='DarkRed';
        this.pos=pos;
        this.angle=Math.random()*Math.PI*2;
        this.status='wait';
        this.pose=false;
        this.food=0;
        this.markup();
    }

    //Предрассчет для отрисовки
    markup() {
        this.Pi2=Math.PI*2;
        this.stroke='Black';
        this.line=this.size*0.2;
        this.size025=this.size*0.25;
        this.size05=this.size*0.5;
        this.size125=this.size*1.25;
        this.size15=this.size*1.5;
        this.size2=this.size*2;
        this.size22=this.size*2.2;
        this.size25=this.size*2.5;
        this.size28=this.size*2.8;
        this.size3=this.size*3;
        this.size35=this.size*3.5;
        this.size4=this.size*4;
        this.size45=this.size*4.5;
        this.size6=this.size*6;
        this.size8=this.size*8;
    }

    //Отрисовка
    draw(ctx) {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        this.pose=!this.pose;
        let pose=this.pose*this.size05;
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle=this.stroke;
        ctx.fillStyle=this.clan;
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
        //Грудь
        ctx.beginPath();
        ctx.arc(x, y, this.size, 0, this.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Голова
        ctx.beginPath();
        ctx.ellipse(x, y-this.size2, this.size125, this.size, 0, 0, this.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+this.size35, this.size15, this.size25, 0, 0, this.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Усики
        ctx.beginPath();
        ctx.moveTo(x-this.size05, y-this.size22);
        ctx.lineTo(x-this.size15+pose*0.5, y-this.size45);
        ctx.moveTo(x+this.size05, y-this.size22);
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