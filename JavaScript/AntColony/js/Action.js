//Симулятор колонии муравьев

class Action {
    static x = 0;

    static wait(ant) {
        console.log('функция wait', this.x);
        this.x++;
        if (this.x>10) {
            ant.action = () => this.find(ant);
            this.x=0;
        }
    }

    static find(ant) {
        console.log('функция find', this.x);
        this.x++;
        if (this.x>10) {
            ant.action = () => this.wait(ant);
            this.x=0;
        }
    }
}