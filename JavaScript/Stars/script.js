const Pi2 = Math.PI*2;
var canvas = document.getElementById('start'), ctx = canvas.getContext('2d'),
    width, height, centerX, centerY,
    radius = 1, starRadius = null,
    stars = [], numStars = 2000,
    starX = null, starY = null,
    focalLength = 500,
    i, starsIndex = 0,
    img = new Image();

img.src = "stars_min.jpg";

window.addEventListener('resize', onResize);
onResize();
function onResize() {
    width = document.documentElement.clientWidth;
    height = document.documentElement.clientHeight;
    centerX = width/2;
    centerY = height/2;
    canvas.width = width;
    canvas.height = height;
}

canvas.addEventListener('mousewheel', function(e) {
    if (e.deltaY < 0) {
        focalLength *= 1.1;
    } else {
        focalLength /= 1.1;
    }
    if (focalLength >= width) {
        focalLength = width - 20;
    } else if (focalLength < 100) {
        focalLength = 100;
    }
}, false);

for (i = 0; i < numStars; i++) {
    x = Math.random() * width;
    y = Math.random() * height;
    z = Math.random() * width;
    new star(x, y, z);
}

animate();
function animate() {
    requestAnimationFrame(animate);
    ctx.fillStyle='black';
    ctx.fillRect(0, 0, width, height);
    ctx.drawImage(img, centerX-img.width/2, centerY-img.height/2, img.width, img.height);
    for(i in stars)
        stars[i].update();
}

function star(x, y, z) {
    starsIndex++;
    stars[starsIndex] = this;
    this.id = starsIndex;
    this.x = x;
    this.y = y;
    this.z = z;
    this.radius = radius;
    this.color = getRandColor();

    this.update = function() {
        starX = (this.x - centerX) * (focalLength / this.z);
        starX += centerX;
        starY = (this.y - centerY) * (focalLength / this.z);
        starY += centerY;
        starRadius = radius * (focalLength / this.z);
        this.z += -10;
        if (this.z <= 0)
            this.z = parseInt(width);
        this.draw();
    }
        
    this.draw = function() {
        ctx.beginPath();
        ctx.arc(starX, starY, starRadius, Pi2, false);
        ctx.fillStyle = this.color;
        ctx.fill();
        ctx.closePath();
    }

    function getRandColor() {
        let r, g, b;
        r = Math.floor(Math.random() * 127) + 128;
        g = Math.floor(Math.random() * 127) + 128;
        b = Math.floor(Math.random() * 127) + 128;
        return "rgb("+r+","+g+"," +b+")";
    }
}