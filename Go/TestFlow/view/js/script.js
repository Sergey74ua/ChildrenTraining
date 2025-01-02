// Скрипты...
var up=document.getElementById("up");
var footer = document.querySelector("footer");
var footerHeight = footer.offsetHeight;

up.style.visibility = "hidden";

window.addEventListener("load", updateScrollPosition);
window.addEventListener("scroll", updateScrollPosition);

// Прыжок на вверх
up.onclick=()=> {
    document.body.scrollTop=0;
    document.documentElement.scrollTop=0;
}

// Что бы кнопка на вверх не залазила на футер
function updateScrollPosition() {
    var windowHeight = window.innerHeight;
    var scrollPosition = window.scrollY;

    if ((scrollPosition + windowHeight) >= (footer.offsetTop - footerHeight)) {
        up.style.bottom = (scrollPosition + windowHeight - footer.offsetTop + footerHeight-30) + "px";
    } else {
        up.style.bottom = "20px";
    }
}

// Параллакс эффект для фона
document.addEventListener("DOMContentLoaded", function() {
    var header = document.querySelector('header');
    var headerContent = document.querySelector('.header-content');
    var speed = 0.45; // Установите скорость прокрутки (чем меньше значение, тем медленнее)

    window.onscroll = function() {
        var yOffset = window.scrollY;
        header.style.backgroundPositionY = -yOffset * speed + 'px';
        headerContent.style.transform = 'translateY(' + yOffset * speed + 'px)';

        if(document.body.scrollTop>200 || document.documentElement.scrollTop>200)
            up.style.visibility = "visible";
        else
            up.style.visibility = "hidden";
    }
});