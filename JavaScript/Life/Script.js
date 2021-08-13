/**
 * Игра "Жизнь"
 * Сергей Покидько
 * 04 августа ‎2021 ‎г.
 */


var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btn_play = document.getElementById('play'), btn_clear = document.getElementById('clear'),
   width, height, row, col, game = false, focus = false, speed = 200, size = 16, center = size/2, arch = 2*Math.PI;

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
   arr = new_arr();
};

//Отслеживаем клики мышкой
onclick=function(e) {
   if (!focus) {
      let x = Math.floor(e.clientX / size);
      let y = Math.floor(e.clientY / size);
      arr[y][x] = !arr[y][x];
   }
   focus = false;
};

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

//Перерасчет окружения
function near_ceil(pos_i, pos_j) {
   let near = 0;
   for (let i = pos_i-1; i < pos_i+2; i++) {
      for (let j = pos_j-1; j < pos_j+2; j++) {
         if (arr[i][j])
            near++;
      }
   }
   if (arr[pos_i][pos_j] && near)
      near-=1;
   return near;
};

//Перерасчет клеток
function update_ceil() {
   buffer = copy_arr(arr);

   let empty = false;

   for (let i = 1; i < row-1; i++) {  //ОБРЕЗАННЫЙ ДИАПАЗОН :(
      for (let j = 1; j < col-1; j++) {  //ОБРЕЗАННЫЙ ДИАПАЗОН :(
         let near = near_ceil(i, j);
         if (arr[i][j] && near >= 2 && near <= 3) {
            buffer[i][j] = true;
            empty = true;
         } else if (!arr[i][j] && near == 3)
            buffer[i][j] = true;
         else
            buffer[i][j] = false;
         
         /* ctx.beginPath();
         ctx.fillStyle="Red";
         ctx.font="8pt Arial";
         ctx.fillText(near, j*size+6, i*size+12);
         ctx.closePath(); */
      }
   }

   if (empty == false) {
      game = false;
      play();
   }
   arr = copy_arr(buffer);
};

//Отрисовка сетки
function draw_lines() {
   ctx.lineWidth = 0.5;
   ctx.strokeStyle='LightBlue';
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
   ctx.fillStyle='Black';
   for (let i = 0; i < row; i++) {
      for (let j = 0; j < col; j++) {
         if (arr[i][j]) {
            ctx.beginPath();
            ctx.arc(j*size+center, i*size+center, center-1, 0, arch, true);
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
