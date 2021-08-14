/**
 * Игра "Жизнь"
 * Сергей Покидько
 * 04 августа ‎2021 ‎г.
 */

var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btnPlay = document.getElementById('play'), btnClear = document.getElementById('clear'),
   btnRand = document.getElementById('rand'),
   game = false, focus = false, speed = 200, size = 16, rnd = 0.61803,
   center = size/2, radius = center*0.95, arch = 2*Math.PI,
   width, height, row, col;

//Аннимационный цикл
setInterval(() => {
   ctx.fillStyle = 'PapayaWhip';
   ctx.fillRect(0, 0, width, height);
   drawLines();
   if (game)
      updateCell();
   drawCell();
}, speed)

//Выравнивание canvas по размерам экрана
window.addEventListener('resize', onResize);
onResize();
function onResize() {
   width  = window.innerWidth;
   height = window.innerHeight;
   canvas.width  = width;
   canvas.height = height;
   row = Math.ceil(height / size);
   col = Math.ceil(width / size);
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

//Кнопка рандом
btnRand.onclick = () => {
   focus = true;
   btnName();
   arr = arrRand();
}

//Функция старт/пауза
function btnName() {
   if (game)
      btnPlay.innerHTML = 'pause';
   else
      btnPlay.innerHTML = 'start';
}

//Очистка массива клеток
arr = arrNew();
function arrNew() {
   let arr = [];
   for (let i = 0; i < row; i++) {
      arr[i] = [];
      for (let j = 0; j < col; j++) {
         arr[i][j] = false;
      }
   }
   return arr;
}

//Рандомное заполнение массива клеток
function arrRand() {
   arr = arrNew();
   for (let i = 1; i < row-1; i++) {
      arr[i] = [];
      for (let j = 1; j < col-1; j++) {
         arr[i][j] = Math.random() >= rnd;
      }
   }
   return arr;
}

//Отслеживаем клики мышкой
onclick = (e) => {
   if (!focus) {
      let x = Math.floor(e.clientX / size);
      let y = Math.floor(e.clientY / size);
      arr[y][x] = !arr[y][x];
   }
   focus = false;
}

//Отрисовка сетки
function drawLines() {
   ctx.lineWidth = 0.5;
   ctx.strokeStyle='LightBlue';
   //Горизонтальные линии
   ctx.beginPath();
   for (let i = 0; i < height; i+=size) {
      ctx.moveTo(0, i);
      ctx.lineTo(width, i);
   }
   ctx.stroke();
   ctx.closePath();
   //Вертикальные линии
   ctx.beginPath();
   for (let i = 0; i < width; i+=size) {
      ctx.moveTo(i, 0);
      ctx.lineTo(i, height);
   }
   ctx.stroke();
   ctx.closePath();
}

//Отрисовка клеток
function drawCell() {
   ctx.fillStyle='Black';
   for (let i = 0; i < row; i++) {
      for (let j = 0; j < col; j++) {
         if (arr[i][j]) {
            ctx.beginPath();
            ctx.arc(j*size+center, i*size+center, radius, 0, arch, true);
            ctx.fill();
            ctx.closePath();
         };
		}
	}
}

//Перерасчет клеток
function updateCell() {
   buffer = arrCopy(arr);
   let empty = false;
   for (let i = 1; i < row-1; i++) {
      for (let j = 1; j < col-1; j++) {
         let near = nearCell(i, j);
         if (arr[i][j] && near >= 2 && near <= 3) {
            buffer[i][j] = true;
            empty = true;
         } else if (!arr[i][j] && near == 3)
            buffer[i][j] = true;
         else
            buffer[i][j] = false;
         //printNear(near, i, j);  //Для тестирования
      }
   }
   //Проверка на отсутствие клеток
   arr = arrCopy(buffer);
   if (empty == false) {
      game = false;
      btnName();
   }
}

//Копирование клеток
function arrCopy(arr) {
   let buffer = []
   for (let i = 0; i < row; i++) {
      buffer[i] = [];
      for (let j = 0; j < col; j++) {
         buffer[i][j] = arr[i][j];
      }
   }
   return buffer;
}

//Проверка окружения
function nearCell(pos_i, pos_j) {
   let near = 0;
   for (let i = pos_i-1; i < pos_i+2; i++) {
      for (let j = pos_j-1; j < pos_j+2; j++)
         near+=arr[i][j];
   }
   if (arr[pos_i][pos_j] && near)
      near-=1;
   return near;
}

//Вывод счетчика клеток
ctx.font = "8pt Arial";
function printNear(near, i, j) {
   ctx.beginPath();
   if (near == 0)
      ctx.fillStyle = "White";
   else if (near > 0 && near < 3)
      ctx.fillStyle = "Blue";
   else if (near > 2 && near < 5)
      ctx.fillStyle = "Green";
   else
      ctx.fillStyle = "Red";
   ctx.fillText(near, j*size+size*0.5-4, i*size+size*0.5+4);
   ctx.closePath();
}