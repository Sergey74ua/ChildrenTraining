/**
 * Игра "Жизнь"
 * Сергей Покидько
 * 04 августа ‎2021 ‎г.
 */

var canvas = document.getElementById('canvas'), ctx = canvas.getContext("2d"),
   btnPlay = document.getElementById('play'), btnClear = document.getElementById('clear'), btnRand = document.getElementById('rand'),
   game = false, focus = false, speed = 120, size = 16, rnd = 0.61803, center = size/2, arch = 2*Math.PI, radius = center*0.95,
   colBG = 'PapayaWhip', colLine = 'LightBlue', colCell = 'Black',
   //colBG = 'Black', colLine = 'YellowGreen', colCell = 'Lime',
   width, height, row, col;

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

//Аннимационный цикл
setInterval(() => {
   ctx.fillStyle = colBG;
   ctx.fillRect(0, 0, width, height);
   drawLines();
   if (game)
      updateCell();
   drawCell();
}, speed)

//Заполнение / очистка массива клеток
arr = arrNew();
function arrNew() {
   let arr = [];
   for (let i = 0; i < row; i++) {
      arr[i] = [];
      for (let j = 0; j < col; j++)
         arr[i][j] = false;
   }
   return arr;
}

//Рандомное заполнение массива клеток
function arrRand() {
   arr = arrNew();
   for (let i = 0; i < row; i++) {
      arr[i] = [];
      for (let j = 0; j < col; j++)
         arr[i][j] = Math.random() >= rnd;
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
   ctx.strokeStyle=colLine;
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
   ctx.fillStyle = colCell;
   for (let i = 0; i < row; i++)
      for (let j = 0; j < col; j++)
         if (arr[i][j]) {
            ctx.beginPath();
            ctx.arc(j*size+center, i*size+center, radius, 0, arch);
            ctx.fill();
            ctx.closePath();
         }
}

//Перерасчет клеток
function updateCell() {
   buffer = arrCopy(arr);
   let empty = false;
   //Перерасчет середины
   for (let i = 1; i < row-1; i++) {
      for (let j = 1; j < col-1; j++) {
         buffer[i][j] = nearCell(i, j);
         if (!empty)
            empty = buffer[i][j];
      }
   }
   //Перерасчет крайних рядов, левый, правый, верхний, нижний
   for (let i = 0; i < row; i++)
      buffer[i][0] = nearCellBorder(i, 0);
   for (let i = 0; i < row; i++)
      buffer[i][col-1] = nearCellBorder(i, col-1);
   for (let j = 1; j < col-1; j++)
      buffer[0][j] = nearCellBorder(0, j);
   for (let j = 1; j < col-1; j++)
      buffer[row-1][j] = nearCellBorder(row-1, j);
   //Проверка на отсутствие клеток
   arr = arrCopy(buffer);
   if (!empty) {
      game = false;
      btnName();
   }
}

//Копирование клеток
function arrCopy(arr) {
   let buffer = [];
   for (let i = 0; i < row; i++) {
      buffer[i] = [];
      for (let j = 0; j < col; j++)
         buffer[i][j] = arr[i][j];
   }
   return buffer;
}

//Проверка окружения
function nearCell(i, j) {
   let near = 0;
   for (let iNear = i-1; iNear < i+2; iNear++) {
      for (let jNear = j-1; jNear < j+2; jNear++)
         near+=arr[iNear][jNear];
   }
   if (arr[i][j] && near)
      near-=1;
   life = getLife(i, j, near);
   return life;
}

//Проверка окружения по краям
function nearCellBorder(i, j) {
   let near = 0;
   for (let iNear = i-1; iNear < i+2; iNear++) {
      for (let jNear = j-1; jNear < j+2; jNear++) {
         iBorder = iNear;
         jBorder = jNear;
         if (iNear < 0)
            iBorder = row-1;
         else if (iNear > row-1)
            iBorder = 0;
         if (jNear < 0)
            jBorder = col-1;
         else if (jNear > col-1)
            jBorder = 0;
         near+=arr[iBorder][jBorder];
      }
   }
   if (arr[i][j] && near)
      near-=1;
   life = getLife(i, j, near);
   return life;
}

//Логика жизни
function getLife(i, j, near) {
   let life = false;
   if (arr[i][j] && near >= 2 && near <= 3 || !arr[i][j] && near == 3)
      life = true;
   return life;
}
