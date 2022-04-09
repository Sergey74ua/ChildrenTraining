//Симулятор колонии муравьев

class PI {
    select(ant) {
        if (ant.pose) //для примера
            ant.action=() => Action.wait(ant);
        else
            ant.action=() => Action.find(ant);
        
        ant.target=ant.getTarget(ant.pos);
        ant.angle=ant.getAngle(ant.pos, ant.target)
        ant.delay=Math.round(Math.random()*100+20);
        ant.pose=!ant.pose;
    }
}

class AI {
    select(ant) {
        ant.action=() => Action.wait(ant);
    }
}