//Симулятор колонии муравьев

class Model {
    //Базовая модель
    constructor() {
        this.base=1;
        this.food=1;
        
        this.map=[];
        this.air=[];
        this.listBlock=[];
        this.listColony=[];
        this.listRock=[];
        this.listFood=[];
    }

    //Обновление
    update() {
        for (let colony of this.listColony) {
            for (let ant of colony.listAnt)
                ant.update();
            colony.update();
        }
    }

    //Инициализация карты
    init() {
        let w=window.innerWidth,
            h=window.innerHeight;
        //Карта
        for (let x=0; x<w; x++) {
            this.map[x]=[];
            this.air[x]=[];
            for (let y=0; y<h; y++) {
                this.map[x][y]={};
                this.air[x][y]={};
                this.newBlock({x: x, y: y});
            }
        }
        //Колонии
        for (let i=0; i<this.base; i++) {
            let pos=this.randPos();
            let colony=new Colony(i, this.food);
            this.listColony.push(colony);
            this.map[colony.pos.x][colony.pos.y]=colony;
        }
        //Камни
        for (let i=0; i<this.base*this.food*10; i++) {
            let pos=this.randPos();
            let rock=new Rock(pos);
            this.listRock.push(rock);
            this.map[rock.pos.x][rock.pos.y]=rock;
        }
        //Корм
        for (let i=0; i<this.base*this.food*10; i++) {
            let pos=this.randPos();
            this.newFood(pos);
        }
    }

    //Обзор юнита
    vision(pos, range=0) {
        let listTarget=[];
        for (let x=Math.round(pos.x-range); x<Math.round(pos.x+range); x++)
            for (let y=Math.round(pos.y-range); y<Math.round(pos.y+range); y++)
                if (Object.keys(this.map[x][y]).length!==0)
                    listTarget.push(this.map[x][y]);
        return listTarget;
    }

    //Добавление блоков
    newBlock(pos) {
        let w=window.innerWidth,
            h=window.innerHeight,
            b=3;
        if ((pos.y<b || pos.y>=(h-b)) || (pos.x<b || pos.x>=(w-b))) {
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

    //Случайная позиция
    randPos() {
        let collision=true;
        let pos={};
        while (collision) {
            pos={
                x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10),
                y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10)
            };
            if (Object.keys(this.map[pos.x][pos.y]).length===0)
                collision=false;
        }
        return pos
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
