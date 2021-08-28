//Игра "Муравейник"

class Game {
    //Игра
    constructor() {
        this.ground=new Ground();
        this.listColony=this.listColonyFill();
    }

    //Обновление
    update() {
        this.ground.update();
        for (let colony of this.listColony)
            for (let ant of colony.listAnt) {
                //Осмотреться - Ant
                this.pixel(ant.pos);  ////////////////////////////
                //Выбрать дейтвие - Actions
                //Совершить действие - Ant
                ant.update(); /////
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

    //Добавление корма
    newFood(pos) {
        let food={pos: pos, value: 255};
        this.ground.listFood.push(food);
    }

    //Зрение (получаем цвет пикселя) ///////////////////////////////////////
    pixel(pos) {
        let pix=ctx.getImageData(pos.x, pos.y, 1, 1);
        //Получаем цвет пикселя
        let rgb=pix.data[0]+','+pix.data[1]+','+pix.data[2]+','+pix.data[3];
        //Меняем цвет пикселя
        pix.data[1]=255;
        ctx.putImageData(pix, pos.x, pos.y);
    }
}
