from units import Units


class Terran(Units):
    def __init__(self):
        super().__init__('Земля')
        self.file = 'img/t1.gif'
        self.pos = 100, 100
