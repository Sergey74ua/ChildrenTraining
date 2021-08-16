/**
 * Игра "Муравейник"
 * Сергей Покидько
 * 12 августа ‎2021 ‎г.
 */

var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btnPlay = document.getElementById('play'), btnClear = document.getElementById('clear'),
   width, height, game = false, focus = false, speed = 40, size = 20,
   posX = 300, posY = 200;

//Выравнивание canvas по размерам экрана
onResize();
window.addEventListener('resize', onResize);
function onResize() {
   width  = window.innerWidth;
   height = window.innerHeight;
   canvas.width  = width;
   canvas.height = height;
}

//Отслеживаем клики мышкой
onclick=function(e) {
   if (!focus) {
      let x = e.clientX;
      let y = e.clientY;
   }
   focus = false;
}

//Кнопка старт/пауза
btnPlay.onclick = () => {
   focus = true;
   game = !game;
   btnName();
}

//Кнопка очистка
btnClear.onclick = () => {
   focus = true;
   game = false;
   btnName();
   arr = arrNew();
}

//Функция старт/пауза
function btnName() {
   if (game)
      btnPlay.innerHTML = 'pause';
   else
      btnPlay.innerHTML = 'start';
}

//Заполнение / очистка массива объектов
arr = arrNew();
function arrNew() {
   let arr = [];
   for (let i = 0; i < 10; i++) {
      let ant = new Ant(300 + i * 50, 200 + i * 30);
      arr[i] = ant;
   }
   return arr;
}

//Аннимационный цикл
setInterval(function() {
   if (game)
      update();
   draw();
}, speed)

//Обновление
function update() {
   for (let ant of arr) {
      ant.x += 3;
      ant.y += 2;
   }
}

//Настройка линий и тени
ctx.lineWidth = size/5;
/*ctx.shadowColor = 'black';
ctx.shadowBlur = 10;
ctx.shadowOffsetX = 3;
ctx.shadowOffsetY = 2;*/

//Отрисовка
function draw() {
   ctx.fillStyle = 'darkGreen';
   ctx.fillRect(0, 0, width, height);
   for (let ant of arr)
      ant.drawAnt();
}
