//Симулятор колонии муравьев

class Model {
    //Базовая модель
    constructor() {
        this.base=4;
        this.food=10;
        this.size={
            width: window.innerWidth,
            height: window.innerHeight
        };
        this.map=[];
        this.air=[];
        this.listBlock=[];
        this.listColony=[];
        this.listRock=[];
        this.listFood=[];
        this.init();
    }

    //Инициализация карты
    init() {
        //Карта
        for (let x=0; x<this.size.width; x++) {
            this.map[x]=[];
            this.air[x]=[];
            for (let y=0; y<this.size.height; y++) {
                this.map[x][y]=false;
                this.air[x][y]=false;
                this.newBlock({x: x, y: y});
            }
        }
        //Колонии
        for (let i=0; i<this.base; i++) {
            let pos=this.rndPos();
            let colony=new Colony(i, pos, this.food);
            this.listColony.push(colony);
            this.map[pos.x][pos.y]=colony;
        }
        //Камни
        for (let i=0; i<this.base*this.food*10; i++) {
            let pos=this.rndPos();
            this.newRock(pos);
        }
        //Корм
        for (let i=0; i<this.base*this.food*10; i++) {
            let pos=this.rndPos();
            this.newFood(pos);
        }
    }

    //Обновление
    update() {
        for (let colony of this.listColony) {
            for (let ant of colony.listAnt)
                ant.update();
            colony.update();
        }
    }

    //Добавление блоков
    newBlock(pos) {
        let border=1;
        if ((pos.x<border || pos.x>=(this.size.width-border)) ||
            (pos.y<border || pos.y>=(this.size.height-border))) {
            let block=new Block({x: pos.x, y: pos.y});
            this.listBlock.push(block);
            this.map[pos.x][pos.y]=block;
        }
    }

    //Добавление корма
    newFood(pos) {
        let food=new Food(pos);
        this.listFood.push(food);
        this.map[food.pos.x][food.pos.y]=food;
    }

    //Добавление камня
    newRock(pos) { //Отдельная функция может и не нужна.
        let rock=new Rock(pos);
        this.listRock.push(rock);
        this.map[rock.pos.x][rock.pos.y]=rock;
    }

    //Случайная позиция
    rndPos(_pos={x: 0, y: 0}, _range=0) { //возможно совмещение с vision
        let collision=true;
        let pos={};
        let range={};
        if (!_range) { //Объединить в одно с min/max и учетом границ
            range={
                left: this.size.width*.05,
                right: this.size.width*.95,
                top: this.size.height*.05,
                bottom: this.size.height*.95
            };
        } else {
            range={
                left: Math.max(_pos.x-_range, 0),
                right: Math.min(_pos.x+_range, this.size.width),
                top: Math.max(_pos.y-_range, 0),
                bottom: Math.min(_pos.y+_range, this.size.height)
            };
        }
        while (collision) {
            pos={
                x: Math.round(Math.random()*(range.right-range.left)+range.left),
                y: Math.round(Math.random()*(range.bottom-range.top)+range.top)
            };
            if (this.map[pos.x][pos.y]===false)
                collision=false;
        }
        return pos;
    }
    
    //Обзор юнита
    vision(pos, range=0) { //возможно совмещение с randPos
        let listTarget=[];
        let left=Math.max(pos.x-range, 0);
        let right=Math.min(pos.x+range, this.size.width);
        let top=Math.max(pos.y-range, 0);
        let bottom=Math.min(pos.y+range, this.size.height);
        for (let x=left; x<right; x++)
            for (let y=top; y<bottom; y++)
                if (this.map[x][y]!==false)
                    listTarget.push(this.map[x][y]);
        return listTarget;
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
