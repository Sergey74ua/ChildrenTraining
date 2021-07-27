from race import Race
from terran import Terran
from zerg import Zerg
from protoss import Protoss


class Factory:
    """Фабричный метод"""
    factory_dict = {
        Race.TERRAN: Terran,
        Race.ZERG: Zerg,
        Race.PROTOSS: Protoss
    }

    def new_unit(self, race):
        return self.factory_dict[race]()
