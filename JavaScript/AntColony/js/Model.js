//Симулятор колонии муравьев

class Model {
    //Базовая модель
    constructor() {
        this.base=1;
        this.food=1;
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
                this.map[x][y]={};
                this.air[x][y]={};
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

    //Обзор юнита
    vision(pos, range=0) {
        let listTarget=[];
        let left=Math.max(Math.round(pos.x-range), 0);
        let right=Math.min(Math.round(pos.x+range), this.size.width);
        let top=Math.max(Math.round(pos.y-range), 0);
        let bottom=Math.min(Math.round(pos.y+range), this.size.height);
        for (let x=left; x<right; x++)
            for (let y=top; y<bottom; y++)
                if (Object.keys(this.map[x][y]).length!=0)
                    listTarget.push(this.map[x][y]);
        return listTarget;
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
    newRock(pos) {
        let rock=new Rock(pos);
        this.listRock.push(rock);
        this.map[rock.pos.x][rock.pos.y]=rock;
    }

    //Случайная позиция
    rndPos() {
        let collision=true;
        let pos={};
        while (collision) {
            pos={
                x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10),
                y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10)
            };
            if (Object.keys(this.map[pos.x][pos.y]).length==0)
                collision=false;
        }
        return pos;
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
