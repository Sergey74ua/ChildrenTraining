//Игра "Муравейник"

var canvas=document.getElementById('canvas'), ctx=canvas.getContext("2d"), 
   btnPlay=document.getElementById('play'), btnClear=document.getElementById('clear'),
   width, height, play=false, focus=false, speed=40,
   game=new Game();
// ВРЕМЕННО /////////////////////////////////////////
document.addEventListener("DOMContentLoaded", () => {
   game=new Game();
});

//Аннимационный цикл
setInterval(function() {
   ctx.fillStyle='DarkGreen';
   ctx.fillRect(0, 0, width, height);
   if (play)
      game.update();
   game.draw();
}, speed)

//Выравнивание canvas по размерам экрана
onResize();
window.addEventListener('resize', onResize);
function onResize() {
   width=window.innerWidth;
   height=window.innerHeight;
   canvas.width=width;
   canvas.height=height;

   //Настройка тени
   ctx.shadowColor='black';
   ctx.shadowBlur=3;
   ctx.shadowOffsetX=2;
   ctx.shadowOffsetY=1;
}

//Отслеживае кликов мышки
onclick=(e) => {
   if (!focus) {
      let pos = {x: e.clientX, y: e.clientY};
      let ant=new Ant(pos);
      game.listAnt.push(ant);  //Заменить на функции в Game
   }
   focus=false;
}

//Кнопка старт/пауза
btnPlay.onclick=() => {
   focus=true;
   play=!play;
   btnName();
}

//Кнопка очистка
btnClear.onclick=() => {
   focus=true;
   play=false;
   btnName();
   game.listAnt=game.listFill();  //Может лучше простой вызов функции в Game
}

//Функция старт/пауза
function btnName() {
   if (play)
      btnPlay.innerHTML='pause';
   else
      btnPlay.innerHTML='start';
}
