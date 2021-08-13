/**
 * Игра "Муравейник"
 * Сергей Покидько
 * 12 августа ‎2021 ‎г.
 */

var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btn_play = document.getElementById('play'), btn_clear = document.getElementById('clear'),
   width, height, game = false, focus = false, speed = 200;

//Выравнивание canvas по размерам экрана
onResize();
window.addEventListener('resize', onResize);
function onResize() {
   width  = window.innerWidth;
   height = window.innerHeight;
   canvas.width  = width;
   canvas.height = height;
};

//Функция старт/пауза
function play() {
   if (game)
      btn_play.innerHTML = 'pause';
   else
      btn_play.innerHTML = 'start';
};

//Кнопка старт/пауза
btn_play.onclick=function() {
   focus = true;
   game = !game;
   play();
};

//Кнопка очистка
btn_clear.onclick=function() {
   focus = true;
   game = false;
   play();
};

//Отслеживаем клики мышкой
onclick=function(e) {
   if (!focus) {
      let x = e.clientX;
      let y = e.clientY;
   }
   focus = false;
};

//Обновление
function update() {
   //Код обновления
};

//Отрисовка
function draw() {
   ctx.beginPath();
   //Код отрисовки
   ctx.stroke();
   ctx.closePath();
};

//Аннимационный цикл
setInterval(function() {
   ctx.fillStyle='DarkGreen';
   ctx.fillRect(0, 0, width, height);
   update();
   draw();
}, speed);
