//Симулятор колонии муравьев

class Action {
    static x = 0;

    static wait(ant) {
        console.log('функция wait', this.x);
        this.x++;
        if (this.x>50)
            ant.action = () => this.find();
    }

    static find() {
        console.log('функция find', this.x);
    }
}