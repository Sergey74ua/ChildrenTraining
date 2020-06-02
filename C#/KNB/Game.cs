namespace KNB
{
    class Game
    {
        public int win, lose, draw;

        private Comp comp = new Comp();
        public string resGame;
        public byte compHand;

        public void StepGame(byte playerHand)
        {
            compHand = comp.StepComp();

            if (playerHand == compHand)
            {
                resGame = "НИЧЬЯ";
                draw++;
            }
            else if ((playerHand == 0 && compHand == 1) ||
                (playerHand == 1 && compHand == 2) ||
                (playerHand == 2 && compHand == 0))
            {
                resGame = "ПОБЕДА";
                win++;
            }
            else
            {
                resGame = "ПРОИГРЫШ";
                lose++;
            }
        }
    }
}