from units import Units


class Zerg(Units):
    def __init__(self):
        super().__init__('Чар')
        self.file = 'img/z1.gif'
        self.pos = 200, 100
