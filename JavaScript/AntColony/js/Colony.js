//Симулятор колонии муравьев

class Colony {
    
    pallet=['SaddleBrown', 'DarkKhaki', 'DimGrey', 'Maroon'];

    constructor(i, family) {
        this.clan=this.getColor(i);
        this.listAnt=[];
        this.fillListAnt(family);
        this.pos={
            y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10),
            x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10)
        };
    }

    //Обновление
    update() {
        if (this.food>=this.life) {
            if (this.timer>0)
                this.timer--;
            else {
                this.timer=this.duration;
                this.food-=this.life;
                this.newAnt();
            }
        }
    }
    
    //Начальное заполнение колонии
    fillListAnt(family) {
        for (let i=0; i<family; i++)
            this.newAnt();
    }

    //Создание муравья
    newAnt() {
        let pos={
            y: Math.round(Math.random()*window.innerHeight*0.8+window.innerHeight/10),
            x: Math.round(Math.random()*window.innerWidth*0.8+window.innerWidth/10)
        };
        let ant=new Ant(pos);
        this.listAnt.push(ant);
    }
    
    //Цвет колонии
    getColor(i) {
        if (i<this.pallet.length)
            return this.pallet[i];
        else
            return '#'+Math.floor(Math.random()*16777216).toString(16).padStart(6, '0');
    }
}