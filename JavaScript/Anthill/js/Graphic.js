//Игра "Муравейник"

class Graphic {


    //Рассчет координат при перемещении
    getPos(x, y, vector, speed) {
        x+=speed*Math.cos(vector);
        y+=speed*Math.sin(vector);
        return x, y;
    }
}

/*
//Движения юнита к цели **** РАЗДЕЛИТЬ НА 2 МЕТОДА ****
public void Move() {
    vector = Angle(vector, speed);
    if (vector == angle)
        position = Position(); }

//Направление юнита
public float Angle(float vector, float speed) {
    //Расстояние и угол к цели
    angle = (float)(Vector() * 180 / Math.PI + 90);
    if (angle < 0)
        angle += 360;

    //Текущий угол поворота к цели
    if (Math.Abs(vector - angle) > speed) {
        if ((vector < angle && (angle - vector) < 180) ^ (angle - vector) > -180)
            vector = (vector - speed + 360) % 360;
        else
            vector = (vector + speed) % 360;
    } else
        vector = angle;
    return vector; }

// Рассчет расстояния до цели (откуда X/Y, куда X/Y)
public float Delta(PointF position, PointF target) {
    catetX = target.X - position.X;
    catetY = target.Y - position.Y;
    return (float)Math.Sqrt(catetX * catetX + catetY * catetY); }
*/
