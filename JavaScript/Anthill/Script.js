/**
 * Игра "Муравейник"
 * Сергей Покидько
 * 12 августа ‎2021 ‎г.
 */

var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btnPlay = document.getElementById('play'), btnClear = document.getElementById('clear'),
   width, height, game = false, focus = false, speed = 100;

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
      let ant = new Ant(x, y);
      arr.push(ant);
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
   for (let i = 0; i < 20; i++) {
      let ant = new Ant(200+i*75, 800);
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
      ant.update();
   }
}

//Настройка тени
/*ctx.shadowColor = 'black';
ctx.shadowBlur = 10;
ctx.shadowOffsetX = 3;
ctx.shadowOffsetY = 2;*/

//Отрисовка
function draw() {
   ctx.fillStyle = 'darkGreen';
   ctx.fillRect(0, 0, width, height);
   for (let ant of arr)
      ant.draw();
}
