namespace Tanks
{
    public enum A : byte //********  В О Т   О Н О   Н А Д О  ?  ********
    {
        WAIT,       //ожидание
        LOOC,       //осмотр    ********
        FIND,       //разветка
        ROTATE,     //поворот   ********
        RUN,        //движение  ********
        LOAD,       //зарядка   ********
        FIRE,       //выстрел
        BACK,       //отъезд
        REPAIR,     //ремонт    ********
        LEAVE       //смерть
    }

    class Actions
    {
        //Выбор действия
        public A ChoiseActions(dynamic unit) //******** Д О В Е С Т И   Д О   У М А ********
        {
            //Танк уничтожен
            if (unit.life <= 0)
                return A.LEAVE;

            //Отсупление
            if (unit.life < 5)
                return A.BACK;

            //Атака цели
            if (unit.target != null)
                return A.FIRE;

            //Поиск цели
            if (unit.target == null)
                return A.FIND;

            return A.WAIT; //******** У Б Р А Т Ь   В   К О Н Е Ц   Ф У Н К И Й ********
        }
    }
}