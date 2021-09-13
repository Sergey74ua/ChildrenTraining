//Игра "Муравейник"

class Game {
    anthill=4;
    family=16;

    //Игра
    constructor() {
        //Карта игры (количество корма)
        this.ground=new Ground(this.anthill*this.family);
        //Список колоний -> заполняем
        this.listColony=[];
        for (let i=0; i<this.anthill; i++) {
            let colony=new Colony(i, this.family);
            this.listColony.push(colony);
            this.ground.map[colony.pos.y][colony.pos.x].busy=colony.clan;
        }
        //Набор действий (карта)
        this.action=new Action(this.ground.map);
    }

    //Обновление игры
    update() {
        //Обновление юнитов в колониях
        for (let colony of this.listColony) {
            for (let ant of colony.listAnt) {
                //Обновление поведения муравьев
                this.action.behavior(ant, colony);
                //Обновление меток муравьев на карте
                this.ground.update(ant);
                //Обновление состояния муравьев
                ant.update();
            }
            //Обновление муравейников
            colony.update();
        }
    }

    //Отрисовка игры
    draw() {
        //Отрисовка карты
        this.ground.draw();
        //Отрисовка юнитов
        for (let colony of this.listColony)
            for (let ant of colony.listAnt)
                ant.draw();
        //Отрисовка муравейников
        for (let colony of this.listColony)
            colony.draw();
    }
}
