using System;

namespace KNB
{
    class Comp
    {
        public byte comp;

        private Random random = new Random();

        public byte StepComp()
        {
            comp = (byte)random.Next(3);

            return comp;
        }
    }
}