/**
Локальный месседжер
Студенты:
- Максим Покидько
18 марта 2024 г.
*/

// Скрипты...
var description=document.getElementById("description");
var download=document.getElementById("download");
var about=document.getElementById("about");
var up=document.getElementById("up");

up.style.visibility = "hidden";

// Загрузка файла
function downloadFile() {
    const file = "file/hub.exe";
    // Создание ссылки на скачивание файла
    const link = document.createElement("a");
    link.href = file;
  
    // Установка атрибута загрузки
    link.setAttribute("download", "");
  
    // Добавление ссылки на страницу и эмуляция клика для скачивания файла
    document.body.appendChild(link);
    link.click();
  
    // Удаление ссылки из DOM после скачивания
    document.body.removeChild(link);
  }

// Плавная прокрутка
document.getElementById('description').addEventListener('click', function() {
    var section1 = document.getElementById('section1');
    var topPos = section1.offsetTop; // Получаем верхнюю позицию раздела 1
    window.scrollTo({
    top: topPos,
    behavior: 'smooth' // Делаем прокрутку плавной
    });
});

document.getElementById('download').addEventListener('click', function() {
    var section2 = document.getElementById('section2');
    var topPos = section2.offsetTop; // Получаем верхнюю позицию раздела 2
    window.scrollTo({
    top: topPos,
    behavior: 'smooth' // Делаем прокрутку плавной
    });
});

document.getElementById('about').addEventListener('click', function() {
    var section3 = document.getElementById('section3');
    var topPos = section3.offsetTop; // Получаем верхнюю позицию раздела 3
    window.scrollTo({
    top: topPos,
    behavior: 'smooth' // Делаем прокрутку плавной
    });
});


// Прыжок на вверх
up.onclick=()=> {
    document.body.scrollTop=0;
    document.documentElement.scrollTop=0;
}

window.onscroll=()=> {
    if(document.body.scrollTop>200 || document.documentElement.scrollTop>200)
        up.style.visibility = "visible";
    else
        up.style.visibility = "hidden";
}

// Можно добавить слайдер

// Можно добавить темную/светлую тему

