//Игра "Муравейник"

class Game {
    //Игра
    constructor() {
        this.ground=new Ground();
        this.action=new Action();
        this.listColony=this.listColonyFill();
    }

    //Обновление
    update() {
        this.ground.update();
        for (let colony of this.listColony)
            for (let ant of colony.listAnt) {
                let pos={x: Math.round(ant.pos.x), y: Math.round(ant.pos.y)};
                //Муравьиные метки
                this.ground.newLabel(pos);
                //Высматриваем цель (корм или метку)
                if (ant.target===undefined) {
                    ant.target=this.action.vision(this.ground.map, pos);
                    ant.update();
                //Поворачиваемся и подбираемся к цели
                } else {
                    ant.angle=this.action.vector(pos, ant.target);
                    if (this.action.delta(pos, ant.target)>ant.speed) {
                        ant.update();
                        ant.food=true;
                    }
                }
                //
            }
    }

    //Отрисовка
    draw() {
        this.ground.draw();
        for (let colony of this.listColony)
            for (let ant of colony.listAnt)
                ant.draw();
        for (let colony of this.listColony)
            colony.draw();
    }

    //Заполнение массива муравейников
    listColonyFill() {
        let listColony=[];
        for (let i=0; i<numColony; i++) {
            let colony=new Colony(i)
            listColony.push(colony);
        }
        return listColony;
    }
}
