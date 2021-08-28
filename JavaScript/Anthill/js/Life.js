//Игра "Муравейник"

var canvas=document.getElementById('canvas'), ctx=canvas.getContext('2d'), 
   btnPlay=document.getElementById('play'), btnClear=document.getElementById('clear'),
   width, height, play=false, focus=false, fps=100, shadow=true, Pi2=2*Math.PI,
   game, numColony=6, population=4, size=2;

//Запускаем игру после загрузки
window.onload=() => {
   game=new Game();
}

//Выравнивание canvas по размерам экрана
window.addEventListener('resize', onResize);
onResize();
function onResize() {
   width=window.innerWidth;
   height=window.innerHeight;
   canvas.width=width;
   canvas.height=height;

   //Настройка тени
   if (shadow) {
      ctx.shadowColor='Black';
      ctx.shadowBlur=3;
      ctx.shadowOffsetX=2;
      ctx.shadowOffsetY=1;
   }
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
      game.newFood(pos);
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
