//Симулятор колонии муравьев

class Model {

    //Базовая модель
    constructor() {
        this.base=4;
        this.family=3;
        this.listColony=this.fillListColony(this.base, this.family);
        
        this.block=new Block();
        this.rock=new Rock();
        this.food=new Food();
    }

    fillListColony(base, family) {
        let listColony=[];
        for (let i=0; i<base; i++) {
            let colony=new Colony(i, family);
            listColony.push(colony);
        }
        return listColony;
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