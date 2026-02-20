class RepositoryException(Exception):

    def __init__(self,erori):
        self.__erori = erori

    def __str__(self):
        return str(self.__erori)