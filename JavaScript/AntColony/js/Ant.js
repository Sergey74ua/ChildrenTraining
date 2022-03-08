//Симулятор колонии муравьев

class Ant {

    constructor(ctx) {
        this.ctx=ctx;
        this.ctx.fillStyle='DarkRed';
        this.ctx.strokeStyle='DarkBlue';
        this.TEST=100
    }

    draw() {
        this.TEST+=1;
        this.ctx.beginPath();
        this.ctx.moveTo(500, 500);
        this.ctx.lineTo(this.TEST, 600);
        this.ctx.arc(100, 200, 50, 0, Math.PI*2);
        this.ctx.fill();
        this.ctx.stroke();
        this.ctx.closePath();
    }
}