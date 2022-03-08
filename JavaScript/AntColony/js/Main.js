//Симулятор колонии муравьев

class Main {

    constructor() {
        this.model=new Model();
        this.view=new View(this.model);
        this.control=new Control(this.view);
    }
}

var main=new Main();