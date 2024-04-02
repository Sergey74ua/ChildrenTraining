//Размер окна
w=1918*0.6; h=956;
width=window.innerWidth;
height=window.innerHeight;

//Масштаб
zoom=Math.min(width/w, height/h);
stepX=zoom;
stepY=zoom;
x=w/2;
y=h/2;

//Радар
radar=document.getElementById('radar');
ctxRad=radar.getContext('2d');

//Горизонт
horizon=document.getElementById('horizon');
ctxHor=horizon.getContext('2d');
img=new Image();
img.src="photo.png";

//Фото
photo=document.getElementById('photo');
url='drone.jpg';
image=new Image();
image.src=url;

//Выравнивание canvas по размерам экрана
window.addEventListener('resize', onResize);
onResize();
function onResize() {
    //Размер окна
	width=window.innerWidth;
	height=window.innerHeight;
    //Масштаб
	zoom=Math.min(width/w, height/h);
    //Размер радара
    radar.width=width*0.6*zoom;
    radar.height=height*zoom;
    //Размер горизонта
    horizon.width=width*0.4*zoom;
    horizon.height=height*0.6*zoom;
    //Размер изображения
    photo.width=width*zoom;
	photo.height=height*0.4*zoom;
};

//Control
setInterval(()=>{
    update();
    drawRadar();
    drawHorizon();
}, 40);

//Model
function update() {
    if (x<0)
        stepX=zoom*2;
    else if (x>w)
        stepX=-zoom*2;
    x+=stepX;

    if (y<0)
        stepY=zoom*3;
    else if (y>h)
        stepY=-zoom*0.5;
    y+=stepY;
};

//Радар
function drawRadar() {
    ctxRad.lineWidth=zoom*5;
    //Заливка
    ctxRad.beginPath();
    ctxRad.fillStyle='lightskyblue';
	ctxRad.fillRect(0, 0, radar.width, radar.height);
    //Рамка радара
    ctxRad.strokeStyle='black';
    ctxRad.strokeRect(50*zoom, 50*zoom, radar.width-100*zoom, radar.height-100*zoom);
    //Кружек
    ctxRad.fillStyle='red';
    ctxRad.arc(x, y, 50*zoom, 0, Math.PI * 2, true);
    ctxRad.fill();
    ctxRad.stroke();
};

//Горизонт
function drawHorizon() {
    ctxHor.lineWidth=zoom*3;
    //Рамка горизонта
    ctxHor.beginPath();
    ctxHor.fillStyle = ctxHor.createPattern(img, "repeat");
    ctxHor.fillRect(0, 0, horizon.width, horizon.height);
    //Рамка горизонта
    ctxHor.strokeStyle='black';
    ctxHor.strokeRect(50*zoom, 50*zoom, horizon.width-100*zoom, horizon.height-100*zoom);
    //Кружек
    ctxHor.fillStyle='blue';
    ctxHor.arc(x, y, 50*zoom, 0, Math.PI * 2, true);
    ctxHor.fill();
    ctxHor.stroke();
};