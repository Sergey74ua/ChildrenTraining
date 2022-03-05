//Симулятор "Муравейник"

const canvas=document.getElementById('canvas'), ctx=canvas.getContext('2d'), 
   btnPlay=document.getElementById('play'), btnClear=document.getElementById('clear'),
   Pi2=Math.PI*2, fps=128;
var game, play=false, focus=false, anthill=4;

//Запускаем игру после загрузки
window.onload=() => {
   window.addEventListener('resize', onResize);
   onResize();
   //Предложение загрузки сохранения
   game=new Game(anthill);
}

//Выравнивание canvas по размерам экрана
function onResize() {
   canvas.width=window.innerWidth;
   canvas.height=window.innerHeight;
   if (game)
      game.resize();
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
   //Предложение сохранения
   game=new Game(anthill);
}

//Функция старт/пауза
function btnName() {
   if (play)
      btnPlay.innerHTML='ΙΙ';
   else
      btnPlay.innerHTML='►';
}

//Синхронизация canvas с кадрами экрана
/*
window.requestAnimationFrame=( function() {
	return	window.requestAnimationFrame     ||
			window.webkitRequestAnimationFrame  ||
			window.mozRequestAnimationFrame     ||
			window.oRequestAnimationFrame       ||
			window.msRequestAnimationFrame      ||
			function (callback) {
				window.setTimeout(callback, 1000/60);
			}
})();
*/
