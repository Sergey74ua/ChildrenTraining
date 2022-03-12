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


//Вывод FPS
/*
let fps=document.getElementById('fps');
let frameCount = function _fc(fastTimeStart, preciseTimeStart){
    let now = performance.now();
    let fastDuration = now - (fastTimeStart || _fc.startTime);
    let preciseDuration = now - (preciseTimeStart || _fc.startTime);
    if(fastDuration < 100)
        _fc.fastCounter++;
    else {
        _fc.fastFPS = _fc.fastCounter * 10;
        _fc.fastCounter = 0;
        fastTimeStart = now;
        //console.log(_fc.fastFPS);
    }
    if(preciseDuration < 1000)
        _fc.preciseCounter++;
    else {   
        _fc.preciseFPS = _fc.preciseCounter;
        _fc.preciseCounter = 0;
        preciseTimeStart = now; 
        //console.log(_fc.preciseFPS);
    }
    fps.innerHTML='fps: ' + _fc.fastFPS + ' - ' + _fc.preciseFPS;
    requestAnimationFrame(() => frameCount(fastTimeStart, preciseTimeStart)); 
}
frameCount.fastCounter = 0;
frameCount.fastFPS = 0;
frameCount.preciseCounter = 0;
frameCount.preciseFPS = 0;
frameCount.startTime = performance.now();
frameCount();
*/
