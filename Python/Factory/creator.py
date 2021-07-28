class Creator:
    """НЕ РАБОЧИЙ ПРИМЕР создателя списка классов"""
    def __init__(self):
        self.dict_creator = {}

    def add_class(self, type_class, new_class):
        self.dict_creator[type_class] = new_class

    def get_class(self, type_class):
        new_class = self.dict_creator.get(type_class)
        if not creator:
            raise ValueError(type_class)
        return new_class()

# Для клиента
creator = Creator()
creator.add_class('TERRAN', Terran)
creator.add_class('ZERG', Zerg)
creator.add_class('PROTOSS', Protoss)
