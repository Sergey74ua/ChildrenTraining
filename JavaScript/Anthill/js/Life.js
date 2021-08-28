//Игра "Муравейник"

var canvas=document.getElementById('canvas'), ctx=canvas.getContext('2d'), 
   btnPlay=document.getElementById('play'), btnClear=document.getElementById('clear'),
   game, width, height, play=false, focus=false, speed=100, shadow=true;

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
      ctx.shadowColor='black';
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
}, speed)

//Отслеживае кликов мышки
onclick=(e) => {
   if (!focus) {
      let pos = {x: e.clientX, y: e.clientY};
      game.newAnt(pos);
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
