//Симулятор "Муравейник"

class Game {
    
    //Игра
    constructor(anthill) {
        this.size={width: canvas.width, height: canvas.height};
        this.terrain=new Terrain(this.size);
        this.listColony=[];
        //Распределение интелекта (нужна визуализация)
        for (let i=0; i<anthill; i++) {
            if (i%2==0)
                this.logic=new IntProg();
            else
                this.logic=new IntArt();
            this.listColony.push(new Colony(i, this.logic, this.size));
        }
        this.colFill='DarkGreen';
        this.colFood='DarkRed';
        ////////////////
        this.terrain.map[100][200]=new Block();
        this.pos={y: 100, x: 200};
        this.pos=this.terrain.getPos(this.pos);
        console.log('Game', this.pos, typeof(this.pos));
        ////////////////
    }

    //Обновление игры
    update() {
        this.terrain.update;
        for (let colony in this.listColony)
            colony.update();
    }

    //Обновление экрана
    draw() {
        ctx.fillStyle=this.colFill;
        ctx.fillRect(0, 0, this.size.width, this.size.height);
        for (let y in this.terrain.map)
            for (let x in this.terrain.map[y])
                switch (this.terrain.map[y][x].constructor.name) {
                    case 'Block':
                        ctx.fillStyle='Orange';
                        this.terrain.drawPixel(y, x);
                        break;
                    case 'Rock':
                        ctx.fillStyle='Black';
                        this.terrain.drawPixel(y, x);
                        break;
                    case 'Food':
                        ctx.fillStyle='Yellow';
                        this.terrain.drawPixel(y, x);
                        break;
                    case 'Label':
                        ctx.fillStyle='White';
                        this.terrain.drawPixel(y, x);
                        break;
                    case 'Ant':
                        this.terrain.map[y][x].update();
                        break;
                    case 'Colony':
                        this.colony.map[y][x].update();
                        break;
                    default:
                        continue;
                }

        //Отрисовка муравьев
        for (let colony of this.listColony)
            for (let ant of colony.listAnt)
                ant.draw();
        
        //Отрисовка муравейников
        for (let colony of this.listColony)
            colony.draw();
    }

    //Размер игровой карты
    resize() {
        if (this.size.width<=canvas.width)
            this.size.width=canvas.width;
        else
            this.size.width=this.size.width; //Проверка на наличие объектов
        if (this.size.height<=canvas.height)
            this.size.height=canvas.height;
        else
            this.size.height=this.size.height; //Проверка на наличие объектов
        ctx.shadowColor='Black';
        this.terrain.reload(this.size); //а что там делается?
    }

    //Сохранение игры (ДОРАБОТАТЬ)
    save() {
        var blob=new Blob(["Тестовый текст ..."],
            {type: "text/plain; charset=utf-8"});
        saveAs(blob, "save_"+new Date().toJSON().slice(0,10)+".txt");
    }

    //Загрузка игры (ДОРАБОТАТЬ)
    load() {
        ;
    }
}
