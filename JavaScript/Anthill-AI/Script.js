//Симулятор "Муравейник"

let listClass=['Action', 'Ant', 'Colony', 'Terrain', 'Game', 'Main', 'IntProg', 'IntArt'];
//Подключение скриптов/классов
for (let name of listClass) {
   let script=document.createElement('script');
   script.type='application/javascript';
   script.src='js/'+name+'.js';
   document.body.appendChild(script);
}

let listLib=['FileSaver'];
//Подключение библиотек
for (let name of listLib) {
   let script=document.createElement('script');
   script.type='application/javascript';
   script.src='libs/'+name+'.js';
   document.body.appendChild(script);
}
