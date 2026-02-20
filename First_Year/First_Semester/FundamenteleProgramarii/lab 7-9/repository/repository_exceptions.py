class RepositoryException(Exception):
    def __init__(self,erori):
        self.__erori = erori


    def get_erori(self):
        return self.__erori

    def __str__(self):
        return "".join(self.__erori)