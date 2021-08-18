//Игра "Муравейник"

class Game {
    constructor() {
        //вход в муравейник
        //список корма
        this.listAnt=this.listFill();
        //список меток поиска
        //список меток доставки
    }
    
    //Заполнение / очистка массива объектов
    listFill() {
        let listAnt=[];
        for (let i=0; i<200; i++) {
            let pos = {x: 950+Math.random()*400-200, y: 500+Math.random()*300-150};
            let ant=new Ant(pos);
            listAnt[i]=ant;
        }
        return listAnt;
    }

    //Обновление
    update() {
        for (let ant of this.listAnt) {
            //Осмотреться
                
            //Выбрать дейтвие
        
            //Совершить действие
            ant.update();
        }
    }

    //Отрисовка
    draw() {
        for (let ant of this.listAnt)
            ant.draw();
    }
}
