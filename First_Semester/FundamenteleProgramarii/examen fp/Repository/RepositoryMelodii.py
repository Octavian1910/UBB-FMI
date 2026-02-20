
from Repository.RepositoryException import RepositoryException
from datetime import date
from domain.melodie import Melodie
from domain.validator.validator_melodie import ValidatorMelodie


class RepositoryMelodii:

    def __init__(self):
        self.__repo = {}

    def get_all(self):
        """
        Obtine toate elementele din repo
        :return: o lista cu elementele de tip melodie din repo
        """
        return list(self.__repo.values())

    def add(self,melodie):
        """
        Adauga o melodie in repo
        :param melodie:un obiect de tip melodie
        :return:-
        """
        if melodie.get_id() in self.__repo:
            raise RepositoryException("Id ul este deja utilizat!")
        self.__repo[melodie.get_id()] = melodie

    def update(self,melodie):
        """
        Da update la gen si data
        :param melodie: un obiect de tip melodie
        :return:-
        """
        if melodie.get_id() not in self.__repo:
            raise RepositoryException("Id ul nu exista!")
        self.__repo[melodie.get_id()] = melodie

    def find(self,id):
        """
        Cauta o melodie dupa id
        :param id: un tuple format din (titlu , artist)
        :return: Melodia daca exista
        """
        return self.__repo[id]


class RepositoryMelodiiFisier(RepositoryMelodii):
    def __init__(self,cale_fisier):
        self.__cale_fisier = cale_fisier
        super().__init__()
        self.__citeste_din_fisier()

    def __citeste_din_fisier(self):
        try:
            with open(self.__cale_fisier,"r") as f:
                linii = f.readlines()
                validator = ValidatorMelodie()
                for linie in linii:
                    if linie.strip() != "":
                        parasre = linie.strip().split(",")
                        # Melodie(titlu,artist,gen,data_aparitie)
                        titlu = parasre[0]
                        artist = parasre[1]
                        gen = parasre[2]
                        zi = int(parasre[3])
                        luna = int(parasre[4])
                        an = int(parasre[5])
                        data =  date(an,luna,zi)
                        m1 = Melodie(titlu,artist,gen,data)
                        validator.valideaza(m1)
                        super().add(m1)
        except OSError:
            print("Nu s a putut citi din fisier!")


    def __scrie_in_fisier(self):
        try:
            with open(self.__cale_fisier,"w") as f:
                melodii = super().get_all()
                for melodie in melodii:
                    text = ""
                    # Melodie(titlu,artist,gen,data_aparitie)
                    titlu = melodie.get_titlu()
                    artist = melodie.get_artist()
                    gen = melodie.get_gen()
                    data = str(melodie.get_data())
                    data = data.split("-")
                    an = data[0]
                    luna = data[1]
                    zi = data[2]
                    text = f"{titlu},{artist},{gen},{zi},{luna},{an}\n"
                    f.write(text)
        except OSError:
            print("Nu s a putut scrie in fisier")


    def update(self,melodie):
        """
        Suprascrie metoda de update
        :param melodie: un obiect de tip melodie
        :return:-
        """
        super().update(melodie)
        self.__scrie_in_fisier()

    def add(self,melodie):
        """
        Suprascrie metoda de add
        :param melodie: un obiect de tip melodie
        :return: -
        """
        super().add(melodie)
        self.__scrie_in_fisier()




