from units import Units


class Terran(Units):
    def __init__(self):
        file = 'img/t1.gif'
        super().__init__(file)
        self.pos = self.get_pos()
