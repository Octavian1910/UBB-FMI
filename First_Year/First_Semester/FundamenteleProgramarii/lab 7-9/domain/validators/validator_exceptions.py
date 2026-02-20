class ValidatorExceptions(Exception):

    def __init__(self,erori):
        self.__erori = erori

    def get_erori(self):
        """
        Metodaca care returneaza erorile
        :return:
        """
        return self.__erori

    def __str__(self):
        return "".join(self.__erori)