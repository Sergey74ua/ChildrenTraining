/**
 * Игра "Муравейник"
 * Сергей Покидько
 * 12 августа ‎2021 ‎г.
 */

//Подключение скриптов/классов
var listClass=['Action', 'Graphic', 'Ant', 'Game', 'Life'];

for (let name of listClass) {
   let script=document.createElement('script');
   script.type='application/javascript';
   script.src='js/'+name+'.js';
   document.body.appendChild(script);
}
