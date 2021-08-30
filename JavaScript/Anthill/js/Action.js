//Игра "Муравейник"

class Action {
    rad=size*8;

    //Осмотреться
    vision(map, pos) {
        let target, startX, finishX, startY, finishY, maxSmell=0;
        //Левый край
        startX=pos.x-this.rad;
        if (startX<0)
            startX=0;
        //Правый край
        finishX=pos.x+this.rad;
        if (finishX>width-1)
            finishX=width;
        //Верхний край
        startY=pos.y-this.rad;
        if (startY<0)
            startY=0;
        //Нижний край
        finishY=pos.y+this.rad;
        if (finishY>height-1)
            finishY=height;
        //Выбор цели
        for (let y=startY; y<finishY; y++)
            for (let x=startX; x<finishX; x++) {
                if (map[y][x].food>0) {
                    target={x: x, y: y};
                    break;
                } else if (map[y][x].smell>maxSmell) {
                    maxSmell=map[y][x].smell;
                    //target={x: x, y: y};
                }
            }
        return target;
    }

    //Поворот на цель
    vector (pos, target) {
        return Math.atan2(target.y-pos.y, target.x-pos.x)+Math.PI/2;
    }

    //Двигаться к цели
    delta(pos, target) {
        return Math.sqrt(Math.pow(target.y-pos.y, 2)+Math.pow(target.y-pos.y, 2));
    }

    //Питаться

    //Взять корм

    //Складировать корм

    //Атаковать

    //Сдохнуть
}
