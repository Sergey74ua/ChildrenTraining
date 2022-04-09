//Симулятор колонии муравьев

class Model {
    //Базовая модель
    constructor() {
        this.base=1;
        this.food=1;
        
        this.map=this.initMap();
        this.listColony=this.initListColony(this.base, this.food);
        this.listFood=[];

        this.listFood.push(new Food());
        this.block=new Block();
        this.rock=new Rock();
    }

    //Обновление
    update() {
        for (let colony of model.listColony) {
            for (let ant of colony.listAnt)
                ant.update();
            colony.update();
        }
    }

    //Запуск карты
    initMap() {
        let map=[];
        for (let x=0; x<window.innerWidth; x++) {
            map[x]=[];
            for (let y=0; y<window.innerHeight; y++)
                map[x][y]=undefined;
            map.push(x);
        }
        return map;
    }

    //Запуск колоний
    initListColony(base, food) {
        let listColony=[];
        for (let i=0; i<base; i++) {
            let colony=new Colony(i, food);
            listColony.push(colony);
        }
        return listColony;
    }

    //Обзор юнита
    vision(pos) {
        let range=20;
        let listItems=[];
        for (let x=pos.x-range; x>pos.x+range; x++)
            for (let y=pos.y-range; y>pos.y+range; y++)
                if (this.map[x][y] != undefined)
                    listItems.push(this.map[x][y]);
        return listItems;
    }
}

/*
ЗАГРУЗКА
- инициализация базовых данных для рассчета
- карты:
    -- ландшафт (двумерный массив с объектами)
    -- ароматы (массив координат и вес)
        --- свой
        --- колонии
        --- общий

СТАРТ/РЕСТАРТ
- размещение колоний, корма и камней
- сохранение весов нейросети
- обнуление счетчиков

ШАГ ИГРЫ
- Обход действий муравьев
- Перерассчет ресурсов колоний
- Испарение меток
*/

/* ПРОВЕРКА ТОЧКИ НА ВХОЖДЕНИЕ В КАНВАС
if (ctx.isPointInPath(20,50)) {
    ctx.stroke();
};
*/
