//Симулятор колонии муравьев

class PI { //////////////////////////////
    //Программируемый интеллект
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
        //Возврат - если есть корм
        else if (ant.food>0)
            ant.action=Action.back;
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

class RI {
    //Рандомный интеллект
    select(ant) {
        ant.action=Action.listAction[Math.floor(Math.random()*Action.listAction.length)];
    }
}

class AI { //////////////////////////////
    //Искуственный интеллект (нейросеть)
    select(ant) {
        ant.action=Action.listAction[getAct(ant)];
    }

    getAct(ant) {
        let neron=[
            n1=ant.life,
            n2=ant.food,
            n3=ant.run,
            n4=ant.target,
            n5=ant.action,
            n6=ant.listTarget //////////////////
        ];
        return 0;
    };
}