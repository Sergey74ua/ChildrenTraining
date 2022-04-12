//Симулятор колонии муравьев

class Ant {
    //Муравей
    constructor(colony) {
        this.color=colony.color;
        this.pos=this.getPos(colony.pos, 2);
        this.ai=colony.ai;
        this.listTarget=[];
        this.contact={}; ////////
        this.score=0; ////////
        this.life=100;
        this.food=0;
        this.speed=1.0;
        this.range=32;
        this.step=5;
        this.run=false;
        this.pose=false;
        this.delay=30;
        this.timer=0;
        this.target=this.getPos(this.pos, this.range);
        this.angle=this.getAngle(this.pos, this.target);
        this.action=Action.wait;
    }

    //Обновление
    update() {
        this.timer--;
        if (this.timer<0)
            if (this.life<=0)
                this.action=Action.dead;
            else {
                this.listTarget=model.vision(this.pos, this.range);
                this.ai.select(this);
                this.action(this);
            }
        if (this.run)
            this.getStep();
    }

    //Отрисовка
    draw(ctx, fw) {
        let x=this.pos.x, y=this.pos.y, angle=this.angle;
        let pose=this.pose*.5;
        //Смена координат для поворота
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(angle);
        ctx.translate(-x, -y);
        //Корм
        if (this.food>0) {
            ctx.fillStyle=Food.color;
            ctx.beginPath();
            ctx.arc(x, y-fw.size4, fw.size15, 0, fw.Pi2);
            ctx.fill();
            ctx.closePath();
        }
        //Цвета и линии
        ctx.lineWidth=this.line;
        ctx.strokeStyle='Black';
        ctx.fillStyle=this.color;
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

        //ВРЕМЕННО - ОБЗОР //////////////////////////////////////////////////
        ctx.strokeStyle='Yellow';
        ctx.lineWidth=0.5;
        ctx.strokeRect(x-this.range, y-this.range, this.range*2, this.range*2)
    }

    //Смена шагов
    getStep() {
        let angle=this.angle-Math.PI/2;
        this.pos.x+=this.speed*Math.cos(angle);
        this.pos.y+=this.speed*Math.sin(angle);
        if (this.step<=0) {
            this.pose=!this.pose;
            this.step=5;
        } else
            this.step--;
    }

    //Рандомная цель
    getPos(pos, range) {
        let collision=true;
        let target={};
        while (collision) {
            target={
                x: Math.round(pos.x+Math.random()*range*2-range),
                y: Math.round(pos.y+Math.random()*range*2-range)
            };
            if (Object.keys(model.map[target.x][target.y]).length==0)
                collision=false;
        }
        return target;
    }

    //Поворот на цель
    getAngle(pos, target) {
        return Math.atan2(target.y-pos.y, target.x-pos.x)+Math.PI/2*0;
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