import shelve


class Save(object):  # ПОКА ТОЛЬКО НАБРОСОК

    def __init__(self):
        path = "save/save_0"
        self.file = shelve.open(path)
        self.info = {
            '1': "",
            '2': "",
            '3': ""
        }

    def __del__(self):
        self.file.close()

    def save_game(self, s1, s2, s3):
        self.file.info = self.info
        self.file.info['1'] = s1
        self.file.info['2'] = s2
        self.file.info['3'] = s3
        print("сохранение ...")

    def load_game(self):
        self.file.info = self.info
        l1 = self.file.info['1']
        l2 = self.file.info['2']
        l3 = self.file.info['3']
        print("загрузка ...", l1, l2, l3)
