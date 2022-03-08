//Симулятор колонии муравьев

class View {

    constructor() {
        this.canvas=document.getElementById('canvas');
        this.canvas.width=window.innerWidth;
        this.canvas.height=window.innerHeight;
        this.ctx=this.canvas.getContext('2d');
        this.ctx.shadowColor='Black';
    }

    draw() {
        this.ctx.fillStyle='DarkGreen';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
        model.ant.draw(this.ctx);
    }
}