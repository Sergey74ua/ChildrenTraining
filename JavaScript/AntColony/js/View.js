//Симулятор колонии муравьев

class View {

    constructor(model) {
        this.canvas=document.getElementById('canvas');
        this.canvas.width=window.innerWidth;
        this.canvas.height=window.innerHeight;
        this.ctx=this.canvas.getContext('2d');
        this.ant=new Ant(this.ctx);
    }

    draw() {
        this.ant.draw();
    }
}