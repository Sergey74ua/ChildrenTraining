using System.Drawing;

namespace Tanks
{
    abstract class AObject
    {
        public Color party;     //команда
        public PointF position; //позиция
        public PointF target;   //цель
        public float vector;    //вектор
        public float speed;     //скорость
    }
}