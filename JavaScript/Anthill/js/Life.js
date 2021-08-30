//Игра "Муравейник"

const canvas=document.getElementById('canvas'), ctx=canvas.getContext('2d'), 
   btnPlay=document.getElementById('play'), btnClear=document.getElementById('clear'),
   Pi2=2*Math.PI, fps=128, numColony=6, population=32, size=2;
var width, height, game, play=false, focus=false;

//Запускаем игру после загрузки
window.onload=() => {
   window.addEventListener('resize', onResize);
   onResize();
   game=new Game();
}

//Выравнивание canvas по размерам экрана
function onResize() {
   width=window.innerWidth;
   height=window.innerHeight;
   canvas.width=width;
   canvas.height=height;
   ctx.shadowColor='Black';
}

//Аннимационный цикл
setInterval(() => {
   if (play)
      game.update();
   game.draw();
}, fps)

//Отслеживае кликов мышки
onclick=(e) => {
   if (!focus) {
      let pos={x: e.clientX, y: e.clientY};
      game.ground.newFood(pos);
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
   game=new Game();
}

//Функция старт/пауза
function btnName() {
   if (play)
      btnPlay.innerHTML='ΙΙ';
   else
      btnPlay.innerHTML='►';
}
