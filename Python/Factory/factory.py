from race import Race
from units import Units
from terran import Terran
from zerg import Zerg
from protoss import Protoss


class Factory:
    """Фабричный метод"""
    def new_unit(self, unit_race):
        factory_dict = {
            Race.TERRAN: Terran,
            Race.ZERG: Zerg,
            Race.PROTOSS: Protoss
        }
        return factory_dict[unit_race]()
