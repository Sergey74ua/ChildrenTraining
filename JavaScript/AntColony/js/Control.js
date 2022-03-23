//Симулятор колонии муравьев

class Control {

    //Управление
    constructor() {
        this.play=true;
        this.focus=false;
        this.fps=250;
        
        this.btnPlay=document.getElementById('play');
        this.btnClear=document.getElementById('clear');
        this.btnPlay.addEventListener('click', this.Play.bind(this));
        this.btnClear.addEventListener('click', this.Clear.bind(this));

        setInterval(() => this.update(), this.fps);
        onclick=(e) => this.onClick(e);
    }

    //Обновление
    update() {
        if (this.play)
            model.update();
        view.draw();
    }

    //Отслеживае кликов мышки
    onClick=(e) => {
        if (!this.focus) {
            let pos={
                x: e.clientX,
                y: e.clientY
            };
            console.log(pos);
        }
        this.focus=false;
    };
    
    //Кнопка старт/пауза
    Play() {
        this.focus=true;
        this.play=!this.play;
        this.btnName();
    }

    //Кнопка очистка
    Clear() {
        this.focus=true;
        //this.play=false;
        this.btnName();
        //Предложение сохранения
        model=new Model();
    }

    //Функция старт/пауза
    btnName() {
        if (this.play)
            this.btnPlay.innerHTML='<i class="fa fa-pause" aria-hidden="true"></i>';
        else
            this.btnPlay.innerHTML='<i class="fa fa-play" aria-hidden="true"></i>';
    }
}

/*
ЗАГРУЗКА
- инициализация базовых данных управления:
    -- старт/пауза
    -- сохранение/загрузка
    -- рестарт (сохранение)

СТАРТ/РЕСТАРТ
- сброс базовых данных

ШАГ ИГРЫ
- игровой цикл
*/