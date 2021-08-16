class Ant {

    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.pose = true;
        this.stat = true;
    }
 
 //Отрисовка муравья
    drawAnt() {
        let x = this.x, y = this.y,
        pi = 2*Math.PI, angle = 0;

        ctx.strokeStyle = 'black';
        ctx.fillStyle = 'saddleBrown';

        //Лапки
        ctx.beginPath();
        //1-4
        ctx.moveTo(x-size*4, y-size*4);
        ctx.lineTo(x-size*3, y-size*1.5);
        ctx.lineTo(x+size*3, y+size*1.5);
        ctx.lineTo(x+size*4, y+size*6);
        //2-5
        ctx.moveTo(x-size*4, y-size*1.5);
        ctx.lineTo(x-size*3, y+size*0.1);
        ctx.lineTo(x+size*3, y-size*0.1);
        ctx.lineTo(x+size*4, y+size*3);
        //3-6
        ctx.moveTo(x+size*4, y-size*4);
        ctx.lineTo(x+size*3, y-size*1.5);
        ctx.lineTo(x-size*3, y+size*1.5);
        ctx.lineTo(x-size*4, y+size*6);
        ctx.stroke();
        ctx.closePath();

        //Голова
        ctx.beginPath();
        ctx.ellipse(x, y-size*2, size*1.2, size, angle, 0, pi);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();

        //Брюшко
        ctx.beginPath();
        ctx.ellipse(x, y+size*4, size*1.5, size*3, angle, 0, pi);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();

        //Грудь
        ctx.beginPath();
        ctx.arc(x, y, size, 0, pi);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();

        //Усики
        ctx.beginPath();
        ctx.moveTo(x-size*0.5, y-size*2.5);
        ctx.lineTo(x-size*2, y-size*5);
        ctx.moveTo(x+size*0.5, y-size*2.5);
        ctx.lineTo(x+size*2, y-size*5);
        ctx.stroke();
        ctx.closePath();
    }
 }