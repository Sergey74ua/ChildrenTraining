//Симулятор колонии муравьев

class PI { //////////////////////////////
    select(ant) {
        if (ant.pose) {
            ant.action=Action.wait;
            ant.delay=Math.round(Math.random()*40+20);
            ant.pose=!ant.pose;
        } else {
            ant.action=Action.find;
            ant.target=ant.getPos(ant.pos, ant.range);
            ant.angle=ant.getAngle(ant.pos, ant.target)
            ant.delay=Math.round(Math.random()*100+20);
        }
    }
}

class AI { //////////////////////////////
    select(ant) {
        //Сброс - если есть корм и (рядом свой муравейник или тебя атакуют)
        if (ant.food>0 && (false || ant.life<100)) //урон-?
            ant.action=Action.drop;
        //Атака - если тебя атакуют и рядом чужой муравей
        else if (ant.life<100)  //урон-?
            ant.action=Action.kick;
        //Сбор - если нет корма и рядом корм
        else if (ant.food<=0 && typeof(ant.contact)==Food)
            ant.action=Action.grab;
        //Подход - если виден корм или муравейник
        else if (ant.listTarget.includes(Food))
            ant.action=Action.move;
        //Поиск - если нет корма и корм не виден
        else if (ant.food<=0)
            ant.action=Action.find;
        //Обучение - если в контакте с союзником
        else if (typeof(ant.contact)==Ant && ant.contact.score>ant.score)
            ant.action=Action.info;
        //Смерть - если жизни нет
        else if (ant.life<0)
            ant.action=Action.dead;
        //Ожидание - все прочее
        else
            ant.action=Action.wait;
    }
}

class RI { //////////////////////////////
    listAction=[
        Action.drop,
        Action.kick,
        Action.grab,
        Action.move,
        Action.find,
        Action.info,
        Action.dead,
        Action.wait
    ];

    select(ant) {
        ant.action=this.listAction[Math.floor(Math.random()*this.listAction.length)];
    }
}