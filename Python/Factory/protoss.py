from units import Units


class Protoss(Units):
    def __init__(self):
        file = 'img/p1.gif'
        super().__init__(file)
        self.pos = self.get_pos()
