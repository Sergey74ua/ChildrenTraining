class Units:
    """Базовый класс"""
    def __init__(self, planet):
        self.planet = planet
        self.pos = None

    def from_planet(self):
        return self.planet
