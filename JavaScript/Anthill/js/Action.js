//Игра "Муравейник"

class Action {
    rad=size*8;

    constructor(map, listColony) {
        this.map=map;
        this.listColony=listColony;
    }

    behavior(ant) {
        //Смерть
        if (ant.status=='dead') {
            if (ant.timer<=0) {
                this.map[ant.pos.y][ant.pos.x].food=ant.power;
                //delete ant;
            }
        
        //Атака
        } else if (ant.status=='kick') {
            if (ant.target.life>0)
                ant.target.life--;
            else
                ant.status=='wait';
        
        //Загрузка
        } else if (ant.status=='load') {
            if (ant.food<ant.power && this.map[ant.target.y][ant.target.x].food>0) {
                this.map[ant.target.y][ant.target.x].food--;
                ant.food++;
            } else {
                ant.status='back';
                ant.angle=ant.angle+Math.PI;
            }
        
        //Разгрузка
        } else if (ant.status=='free') {
            if (ant.food>0) {
                ant.food--;
                this.map[ant.target.y][ant.target.x].food++;
            } else
                ant.status='find';
        
        //Сближение
        } else if (ant.status=='move') {
            ant.angle=this.vector(ant.pos, ant.target);
            if (this.delta(ant.pos, ant.target)<=ant.speed)
                ant.status='load';
        
        //Возврат
        } else if (ant.status=='back') {
            ant.target=this.vision(ant);
            ant.target={x: width/2, y: height/2}; //Заменить на поиск меток и муравейника
        
        //Поиск корма
        } else if (ant.status=='find') {
            ant.target=this.vision(ant);
            if (ant.target===undefined) {
                if(Math.random()>=0.9)
                    ant.angle=(ant.angle+Math.random()-0.5+Pi2)%Pi2;
            } else
                ant.status='move';
        
        //Ожидание
        } else
            this.select(ant);
    }

    //Выбор действия
    select(ant) {
        //Смерть
        if (ant.life<1) {
            ant.status='dead';
        } else {
            //Осмотр окресности
            ant.target=this.vision(ant);

            //Если есть цель
            if (ant.target) {
                //Атака
                if (ant.life<ant.life) //если атакуют или нет корма, но чужак с кормом
                    ant.status='kick';
                //Разгрузка
                else if (ant.life<ant.life) //если атакуют или в таргете свой муравейник
                    ant.status='free';
                //Загрузка
                else if (ant.food<ant.power && ant.status=='move')
                    ant.status='load';
                //Сближение
                else if (!ant.target===undefined)
                    ant.status='move';
            
            //Если цели нет
            } else {
                //Возврат
                if (ant.food>0)
                    ant.status='back';
                //Поиск корма
                else if (ant.food<1 && ant.target===undefined)
                    ant.status='find';
                //По умолчанию
                else
                    ant.status='wait';
            }
        }
    }

    //Осмотреться и выбрать цель
    vision(ant) {
        let target, startX, finishX, startY, finishY;
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
        //Выбор цели (атакующий - дом - корм - жертва - аромат - метка) ////
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
    vector(pos, target) {
        return Math.atan2(target.y-pos.y, target.x-pos.x)+Math.PI/2;
    }

    //Расстояние до цели
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