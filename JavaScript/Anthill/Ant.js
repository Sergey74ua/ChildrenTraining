class Ant {
    //Создание муравья
    constructor(x, y) {
        this.size = 3;
        this.x = x;
        this.y = y;
        this.pose = true;
        this.stat = true;
    }

    //Обновление
    update() {
        this.x += 0.5;
        this.y -= 4;
        if (this.y < -10)
            this.y = 1000;
    }

    //Отрисовка
    draw() {
        let size = this.size, x = this.x, y = this.y;
        if (game)
        this.pose = !this.pose;
        let pose = this.pose * size;
        let Pi2 = 2*Math.PI, angle = 0;

        ctx.lineWidth = size/5;
        ctx.strokeStyle = 'black';
        ctx.fillStyle = 'saddleBrown';

        //Лапки
        ctx.beginPath();
        //1-4
        ctx.moveTo(x-size*2.5, y-size*3-pose*0.5);
        ctx.lineTo(x-size*2, y-size*1.5-pose*0.5);
        ctx.lineTo(x+size*2.8, y+size*1.75+pose*0.75);
        ctx.lineTo(x+size*4, y+size*6+pose);
        //2-5
        ctx.moveTo(x-size*3.5, y+size*1+pose*0.5);
        ctx.lineTo(x-size*2.2, y-size*0.5+pose);
        ctx.lineTo(x+size*2.2, y+size*0.5-pose);
        ctx.lineTo(x+size*3.5, y+size*1.5-pose*0.5);
        //3-6
        ctx.moveTo(x-size*4, y+size*7-pose);
        ctx.lineTo(x-size*2.8, y+size*2.5-pose*0.75);
        ctx.lineTo(x+size*2, y-size*2+pose*0.5);
        ctx.lineTo(x+size*2.5, y-size*3.5+pose*0.5);
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