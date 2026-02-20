class Melodie:

    # Melodie(titlu,artist,gen,data_aparitie)
    def __init__(self,titlu,artist,gen,data):
        """
        Constructor
        :param titlu: un string nevid
        :param artist: un string nevid
        :param gen: unul dintr Rock,Pop,Jazz
        :param data: un date
        """
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__data = data

    def get_titlu(self):
        """
        Metoda pt obtinerea titlului
        :return: un string reprezentand titlul
        """
        return self.__titlu

    def get_artist(self):
        """
        Metoda pt obtinerea artistuliu
        :return: un string reprezentand artistul
        """
        return self.__artist

    def get_gen(self):
        """
        Metoda pt obtinerea genului
        :return: un string reprezentand genul
        """
        return self.__gen

    def get_data(self):
        """
        Metoda pt obtinerea datei
        :return: un date reprezentand  data
        """
        return self.__data

    def get_id(self):
        """
        Returneaza id ul
        :return: un tuple format din titlu , artist
        """
        id = (self.__titlu,self.__artist)
        return id

    def __eq__(self, other):
        if not isinstance(other,Melodie):
            return False
        if other.get_id() == self.get_id():
            return True
        else:
            return False

    def __str__(self):
        """
        Facem print frumos
        :return: un string frumos
        """
        # Melodie(titlu,artist,gen,data_aparitie)
        titlu = self.__titlu
        artist = self.__artist
        gen = self.__gen
        data = self.__data
        return f"Titlu : {titlu} | Artist : {artist} | Gen : {gen} | Data : {data}"


