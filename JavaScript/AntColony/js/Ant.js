//Симулятор колонии муравьев

class Ant {
    
    //Муравей
    constructor(colony) {
        this.color=colony.color;
        this.pos={
            x: colony.pos.x,
            y: colony.pos.y
        };
        this.target={
            x: Math.round(view.canvas.width/2),
            y: Math.round(view.canvas.height/2)
        };
        this.angle=this.getAngle(this.pos, this.target);
        this.status='wait';
        this.speed=10;
        this.pose=false;
        this.food=0;
    }

    //Обновление
    update() {
        let angle=this.angle-Math.PI/2;
        this.pos.x=Math.round(this.pos.x+this.speed*Math.cos(angle));
        this.pos.y=Math.round(this.pos.y+this.speed*Math.sin(angle));
        this.pose=!this.pose;
    }

    //Отрисовка
    draw(ctx, fw) {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        let pose=this.pose*fw.size05;
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle='Black';
        ctx.fillStyle=this.color;
        //Смена координат для поворота
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(angle);
        ctx.translate(-x, -y);
        //Корм
        if (this.food>0) {
            ctx.fillStyle='DarkRed';
            ctx.beginPath();
            ctx.arc(x, y-fw.size4, fw.size, 0, Pi2);
            ctx.fill();
            ctx.closePath();
        }
        //Тени
        ctx.shadowBlur=3;
        ctx.shadowOffsetX=2;
        ctx.shadowOffsetY=1;
        //Лапки 1-4
        ctx.beginPath();
        ctx.moveTo(x-fw.size25, y-fw.size3-pose*2);
        ctx.lineTo(x-fw.size2, y-fw.size15-pose);
        ctx.lineTo(x+fw.size28, y+fw.size2+pose*2);
        ctx.lineTo(x+fw.size4, y+fw.size6+pose*4);
        //Лапки 2-5
        ctx.moveTo(x-fw.size35, y+fw.size+pose);
        ctx.lineTo(x-fw.size22, y-fw.size025+pose);
        ctx.lineTo(x+fw.size22, y+fw.size025-pose);
        ctx.lineTo(x+fw.size35, y+fw.size15-pose);
        //Лапки 3-6
        ctx.moveTo(x-fw.size4, y+fw.size8-pose*4);
        ctx.lineTo(x-fw.size28, y+fw.size3-pose*2);
        ctx.lineTo(x+fw.size2, y-fw.size2+pose);
        ctx.lineTo(x+fw.size25, y-fw.size4+pose*2);
        ctx.stroke();
        ctx.closePath();
        //Грудь
        ctx.beginPath();
        ctx.arc(x, y, fw.size, 0, fw.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Голова
        ctx.beginPath();
        ctx.ellipse(x, y-fw.size2, fw.size125, fw.size, 0, 0, fw.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+fw.size35, fw.size15, fw.size25, 0, 0, fw.Pi2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
        //Усики
        ctx.beginPath();
        ctx.moveTo(x-fw.size05, y-fw.size22);
        ctx.lineTo(x-fw.size15+pose*0.5, y-fw.size45);
        ctx.moveTo(x+fw.size05, y-fw.size22);
        ctx.lineTo(x+fw.size15-pose*0.5, y-fw.size45);
        ctx.stroke();
        ctx.closePath();
        //Сброс координат
        ctx.restore();
        ctx.shadowBlur=0;
        ctx.shadowOffsetX=0;
        ctx.shadowOffsetY=0;
    }

    //Поворот на цель
    getAngle(pos, target) {
        return Math.atan2(target.y-pos.y, target.x-pos.x)+Math.PI/2;
    }
}


class Flyweight {
    
    //Статичные данные
    constructor() {
        this.size=2;
        this.Pi2=Math.PI*2;
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
}