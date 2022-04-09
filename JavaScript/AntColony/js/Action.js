//Симулятор колонии муравьев

class Action {
    //Действия муравья
    static wait(ant) { /////////
        ant.target=ant.getTarget(ant.pos);
        ant.angle=ant.getAngle(ant.pos, ant.target)
        ant.delay=Math.round(Math.random()*100+20);
        ant.action=() => Action.find(ant);
        console.log(ant.color, ' - сменил режим', ant.pos);
    }

    static find(ant) {
        if (Math.sqrt(Math.pow(ant.target.y-ant.pos.y, 2)+Math.pow(ant.target.y-ant.pos.y, 2))<=ant.speed)
            ant.action=() => Action.wait(ant);
        else
            ant.getStep();
    }

    static move(ant) {
        if (Math.sqrt(Math.pow(ant.target.y-ant.pos.y, 2)+Math.pow(ant.target.y-ant.pos.y, 2))<=ant.speed)
            ant.action=() => Action.grab(ant);
        else
            ant.getStep();
    }

    static kick(ant) {
        ;
    }

    static grab(ant) {
        ;
    }

    static quit(ant) {
        ;
    }

    static info(ant) {
        ;
    }

    static dead(ant) {
        if (ant.delay<0) {
            console.log(ant.color, ' - умер');
            //удалить из массива;
            //удалить объект муравья;
            new Food(ant.pos);
        }
    }
}