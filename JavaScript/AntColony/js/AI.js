//Симулятор колонии муравьев

class PI {
    choice(ant) {
        //Ожидание
        if (ant.target==undefined)
            return Action.wait(this);
        //Поиск
        if (true)
            return Action.find(this);
    }
}

class AI {
    choice() {
        ;
    }
}