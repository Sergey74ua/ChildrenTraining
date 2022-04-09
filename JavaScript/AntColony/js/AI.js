//Симулятор колонии муравьев

class PI {
    select(ant) {
        ant.target=ant.getTarget(ant.pos);
        ant.angle=ant.getAngle(ant.pos, ant.target)
        ant.delay=Math.round(Math.random()*60+20);

        if (ant.action==Action.wait(ant)) //// ТАК НЕ РАБОТАЕТ
            ant.action=() => Action.find(ant);
        else
            ant.action=() => Action.wait(ant);
    }
}

class AI {
    select(ant) {
        ant.action=() => Action.wait(ant);
    }
}