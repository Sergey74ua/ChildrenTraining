//Симулятор колонии муравьев

class Action {

    static wait(ant) {
        console.log('... wait', ant.target);
        //список целей{...}=vision(ant.pos)
        //выбор action и target из списка{...}

        ant.target=ant.getTarget(ant.pos);
        ant.angle=ant.getAngle(ant.pos, ant.target)
        ant.delay=Math.round(Math.random()*100+20);
        ant.action=() => Action.find(ant);
    }

    static find(ant) {
        console.log('->? find', ant.target);

        let angle=ant.angle-Math.PI/2;
        ant.pos.x+=ant.speed*Math.cos(angle);
        ant.pos.y+=ant.speed*Math.sin(angle);
    }

    static move(ant) {
        console.log('--> move', ant.color);
    }

    static kick(ant) {
        console.log('->* kick', ant.color);
    }

    static grab(ant) {
        console.log('.~. grab', ant.color);
    }

    static quit(ant) {
        console.log('*_* quit', ant.color);
    }

    static dead(ant) {
        console.log('xxx dead', ant.color);
    }
}