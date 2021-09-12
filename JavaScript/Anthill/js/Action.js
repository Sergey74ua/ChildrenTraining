//Игра "Муравейник"

class Action {
    rad=size*8;

    constructor(map) {
        this.map=map;
    }

    behavior(ant) {
        if (!ant.food && ant.target===undefined) {
            ant.target=this.vision(ant);
        //Поворачиваемся и подбираемся к цели
        } else {
            ant.angle=this.vector(ant.pos, ant.target);
            if (this.delta(ant.pos, ant.target)<=ant.speed) {
                ant.food=true;
                ant.timer=60;
                ant.target={x: width/2, y: height/2}; /////////////// НУЖЕН ПОИСК ОБРАТНОГО ПУТИ
            }
        }
    }

    //Осмотреться и выбрать цель
    vision(ant) {
        let target, startX, finishX, startY, finishY, maxSmell=0;
        //Левый край
        startX=ant.pos.x-this.rad;
        if (startX<0)
            startX=0;
        //Правый край
        finishX=ant.pos.x+this.rad;
        if (finishX>width-1)
            finishX=width;
        //Верхний край
        startY=ant.pos.y-this.rad;
        if (startY<0)
            startY=0;
        //Нижний край
        finishY=ant.pos.y+this.rad;
        if (finishY>height-1)
            finishY=height;
        //Выбор цели
        for (let y=startY; y<finishY; y++)
            for (let x=startX; x<finishX; x++) {
                if (this.map[y][x].food>0) {
                    target={x: x, y: y};
                    break;
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
}

/*
//Рассчет координат при перемещении
getPos(x, y, vector, speed) {
    x+=speed*Math.cos(vector);
    y+=speed*Math.sin(vector);
    return x, y;

C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C# C#

//Движения юнита к цели **** РАЗДЕЛИТЬ НА 2 МЕТОДА ****
public void Move() {
    vector = Angle(vector, speed);
    if (vector == angle)
        position = Position(); }

//Направление юнита
public float Angle(float vector, float speed) {
    //Расстояние и угол к цели
    angle = (float)(Vector() * 180 / Math.PI + 90);
    if (angle < 0)
        angle += 360;

    //Текущий угол поворота к цели
    if (Math.Abs(vector - angle) > speed) {
        if ((vector < angle && (angle - vector) < 180) ^ (angle - vector) > -180)
            vector = (vector - speed + 360) % 360;
        else
            vector = (vector + speed) % 360;
    } else
        vector = angle;
    return vector; }

// Рассчет расстояния до цели (откуда X/Y, куда X/Y)
public float Delta(PointF position, PointF target) {
    catetX = target.X - position.X;
    catetY = target.Y - position.Y;
    return (float)Math.Sqrt(catetX * catetX + catetY * catetY); }
*/