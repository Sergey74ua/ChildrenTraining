//Симулятор колонии муравьев

class Control {

    constructor() {
        this.btnPlay=document.getElementById('play');
        this.btnClear=document.getElementById('clear');
        this.btnPlay.addEventListener('click', this.Play.bind(this));
        this.btnClear.addEventListener('click', this.Clear.bind(this));
        this.play=true;
        this.focus=false;
        this.fps=500;
        setInterval(() => this.update(), this.fps);
    }

    update() {
        if (this.play)
            view.draw();
    }

    //Отслеживае кликов мышки
    onclick=(e) => {
        if (!this.focus) {
            let pos={x: e.clientX, y: e.clientY};
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
        this.play=false;
        this.btnName();
        //Предложение сохранения
        //game=new Game(anthill);
    }

    //Функция старт/пауза
    btnName() {
        if (this.play)
            this.btnPlay.innerHTML='<i class="fa fa-pause" aria-hidden="true"></i>';
        else
            this.btnPlay.innerHTML='<i class="fa fa-play" aria-hidden="true"></i>';
    }
}