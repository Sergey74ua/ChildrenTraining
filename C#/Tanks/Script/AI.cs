using System;

namespace Tanks
{
    class AI
    {
        private Random random = new Random();
        private byte ai;

        public byte StepFind()
        {
            ai = (byte)random.Next(byte.MaxValue);

            return ai;
        }
    }
}
