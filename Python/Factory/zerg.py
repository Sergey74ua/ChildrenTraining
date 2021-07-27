from units import Units


class Zerg(Units):
    def __init__(self):
        file = 'img/z1.gif'
        super().__init__(file)
        self.pos = self.get_pos()
