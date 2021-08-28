//Игра "Муравейник"

class Game {
    //Игра
    constructor() {
        this.posHill={x: 200, y: 300, f: 255};
        this.listAnt=[];
        this.listFill(256);
    }

    //Обновление
    update() {
        for (let ant of this.listAnt) {
            //Осмотреться - Ant
            this.pixel(ant.pos);  ////////////////////////////
            //Выбрать дейтвие - Actions
            //Совершить действие - Ant
            ant.update();
        }
    }

    //Отрисовка
    draw() {
        ctx.fillStyle='DarkGreen'; //ПОПРОБЫВАТЬ сохранять метки в фоновом массиве
        ctx.fillRect(0, 0, width, height);
        for (let ant of this.listAnt)
            ant.draw();
    }

    //Заполнение / очистка массива объектов
    listFill(n) {
        for (let i=0; i<n; i++) {
            let rndX = width/3,  //ВРЕМЕННАЯ СТАРТОВАЯ ПОЗИЦИЯ
                rndY = height/3;
            let pos = {
                x: rndX+Math.random()*rndX,
                y: rndY+Math.random()*rndY
            };
            this.newAnt(pos);
        }
    }

    //Добавление муравья
    newAnt(pos) {
        let ant=new Ant(pos);
        this.listAnt.push(ant);
    }

    //Зрение (получаем цвет пикселя)
    pixel(pos) {
        let pix=ctx.getImageData(pos.x, pos.y, 1, 1);
        //Получаем цвет пикселя
        let rgb=pix.data[0]+','+pix.data[1]+','+pix.data[2]+','+pix.data[3];
        //console.log(rgb);  //ВРЕМЕННО
        //Меняем цвет пикселя
        pix.data[1]=255;
        ctx.putImageData(pix, pos.x, pos.y);
    }
}
