/**
 * Игра "Жизнь"
 * Автор: Сергей Покидько
 * 04 августа ‎2021 ‎г.
 */


var canvas=document.getElementById('life'), ctx=canvas.getContext("2d"), width, height, row, col, life;
var game = true, speed = 250, size = 16;

//Выравнивание canvas по размерам экрана
onResize();
window.addEventListener('resize', onResize);
function onResize() {
   width  = window.innerWidth;
   height = window.innerHeight;
   canvas.width  = width;
   canvas.height = height;
   row = Math.ceil(height / size);
   col = Math.ceil(width / size);
};

//Очистка массива клеток
function new_arr() {
   let _arr = [];
   for (let i = 0; i < row; i++) {
      _arr[i] = [];
      for (let j = 0; j < col; j++) {
         _arr[i][j] = false;
      }
   }
   return _arr;
};
arr = new_arr();

//Перерасчет окружения
function copy_arr(arr) {
   let buffer = []
   for (let i = 0; i < row; i++) {
      buffer[i] = [];
      for (let j = 0; j < col; j++) {
         buffer[i][j] = arr[i][j];
      }
   }
   return buffer;
}
buffer = copy_arr(arr);

//Отслеживаем клики мышкой
onclick=function(e) {
   game = false;
   let x = Math.floor(e.clientX / size);
   let y = Math.floor(e.clientY / size);
   arr[y][x] = !arr[y][x];
};

//Отслеживаем клавиатуру
onkeyup=function(){
   game = !game;
};

//Перерасчет окружения
function life_ceil(loc_i, loc_j) {
   life = 0;
   for (let i = loc_i-1; i < loc_i+2; i++) {
      for (let j = loc_j-1; j < loc_j+2; j++) {
         if (arr[i][j])
            life++;
      }
   }
   if (arr[loc_i][loc_j] && life > 0)
      life-=1;
   return life;
};

//Перерасчет клеток
function update_ceil() {
   buffer = copy_arr(arr);

   for (let i = 1; i < row-1; i++) {
      for (let j = 1; j < col-1; j++) {
         life = life_ceil(i, j);
         if (arr[i][j] && life >= 2 && life <= 3)
            buffer[i][j] = true;
         else if (!arr[i][j] && life == 3)
            buffer[i][j] = true;
         else
            buffer[i][j] = false;
         
         /*ctx.beginPath();
         ctx.fillStyle="Red";
         ctx.font="12pt Arial";
         ctx.fillText(life, j*size+12, i*size+24);
         ctx.closePath();*/
      }
   }
   
   arr = copy_arr(buffer);
};

//Отрисовка сетки
function draw_lines() {
   ctx.lineWidth = 0.25;
   ctx.strokeStyle='Grey';
   //Вертикальные линии
   ctx.beginPath();
   for (let i = 0; i < height; i+=size) {
      ctx.moveTo(0, i);
      ctx.lineTo(width, i);
   }
   ctx.stroke();
   ctx.closePath();
   //Горизонтальные линии
   ctx.beginPath();
   for (let i = 0; i < width; i+=size) {
      ctx.moveTo(i, 0);
      ctx.lineTo(i, height);
   }
   ctx.stroke();
   ctx.closePath();
};

//Отрисовка клеток
function draw_ceil() {
   let centre = size/2;
   ctx.fillStyle='Black';
   for (let i = 0; i < row; i++) {
      for (let j = 0; j < col; j++) {
         if (arr[i][j]) {
            ctx.beginPath();
            ctx.arc(j*size+centre, i*size+centre, centre-1, 0, 2*Math.PI, true);
            ctx.fill();
            ctx.closePath();
         };
		}
	}
};

//Аннимационный цикл
setInterval(function() {
   ctx.fillStyle='PapayaWhip';
   ctx.fillRect(0, 0, width, height);
   draw_lines();
   if (game)
      update_ceil();
   draw_ceil();
}, speed);
