//Игра "Муравейник"

class Game {
    pallet=['SaddleBrown', 'DarkKhaki', 'Indigo', 'Salmon'];

    //Игра
    constructor() {
        this.ground=new Ground();
        this.food=new Food(); //ЗАМЕНИТЬ НА КАРТУ КОРМА И МЕТОК
        this.listColony=this.listColonyFill();
    }

    //Обновление
    update() {
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
    }

    //Заполнение массива муравейников
    listColonyFill() {
        let listColony=[];
        for (let i=0; i<numColony; i++) {
            let color;
            if (i<this.pallet.length)
                color=this.pallet[i];
            else
                color='#'+Math.floor(Math.random()*16777215).toString(16); //или 16777216
            let colony=new Colony(color)
            listColony.push(colony);
        }
        return listColony;
    }

    //Добавление муравья
    newFood(pos) {
        let crumb=new Food(pos);
        this.food.listFood.push(crumb);
    }

    //Зрение (получаем цвет пикселя)
    pixel(pos) {
        let pix=ctx.getImageData(pos.x, pos.y, 1, 1);
        //Получаем цвет пикселя
        let rgb=pix.data[0]+','+pix.data[1]+','+pix.data[2]+','+pix.data[3];
        //Меняем цвет пикселя
        pix.data[1]=255;
        ctx.putImageData(pix, pos.x, pos.y);
    }
}
