//Симулятор колонии муравьев

class Action {
    //Действия муравья
    static drop(ant) {
        ;
    }

    static kick(ant) {
        ;
    }

    static grab(ant) {
        ;
    }

    static move(ant) {
        if (Math.sqrt(Math.pow(ant.target.y-ant.pos.y, 2)+Math.pow(ant.target.y-ant.pos.y, 2))<=ant.speed)
            ant.action=Action.grab;
        else {
            model.map[Math.round(ant.pos.x)][Math.round(ant.pos.y)]={};
            ant.getStep();
            model.map[Math.round(ant.pos.x)][Math.round(ant.pos.y)]=ant;
        }
    }

    static find(ant) {
        if (Math.sqrt(Math.pow(ant.target.y-ant.pos.y, 2)+Math.pow(ant.target.y-ant.pos.y, 2))<=ant.speed)
            ant.action=Action.wait;
        else {
            model.map[Math.round(ant.pos.x)][Math.round(ant.pos.y)]={};
            ant.getStep();
            model.map[Math.round(ant.pos.x)][Math.round(ant.pos.y)]=ant;
        }
    }

    static info(ant) {
        ant.action=Action.wait;
    }

    static dead(ant) {
        ant.pos.x=Math.round(ant.pos.x);
        ant.pos.y=Math.round(ant.pos.y);
        if (ant.delay<0) {
            if (ant.food>0) {
                let food=new Food(ant.pos);
                food.weight=ant.food;
                model.listFood.push(food);
                model.map[food.pos.x][food.pos.y]=food;
            }
            model.newFood(ant.pos)
            //удалить муравья с массива колонии
            model.map[ant.pos.x][ant.pos.y]={};
            //delete(ant);
        }
    }
    
    static wait(ant) {
        ant.action=Action.wait;
    }
}