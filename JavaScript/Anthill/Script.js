//Игра "Муравейник"

//Подключение скриптов/классов
var listClass=['Action', 'Ant', 'Colony', 'Ground', 'Game', 'Main'];

for (let name of listClass) {
   let script=document.createElement('script');
   script.type='application/javascript';
   script.src='js/'+name+'.js';
   document.body.appendChild(script);
}
