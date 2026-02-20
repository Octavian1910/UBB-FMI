from domain.problema_laborator import ProblemaLaborator
from repository.repository_exceptions import RepositoryException
from datetime import date

class RepositoryProblemeLaborator:

    def __init__(self):
        self.__repo = {}


    def add(self,problema_laborator):
        """
        Functia adauga in repo  ProblemaLaborator
        :param ProblemaLaborator: un obiect de tip problema laborator
        :return: -
        :raises: RepositoryException daca id ul problemei si al laboratorului sunt deja in repo
        """

        if problema_laborator.get_id_problema_laborator() in self.__repo:
            raise RepositoryException("Id ul este deja utilizat!")

        self.__repo[problema_laborator.get_id_problema_laborator()] = problema_laborator


    def __len__(self):
        return len(self.__repo.keys())

    def find(self, id):
        """
        Functia returneaza problema laborator de la id ul dorit
        :param id: un tuple
        :return: un obiect de tip problema laborator
        """
        if id not in self.__repo:
            raise RepositoryException("Id ul nu exista!")
        return self.__repo[id]

    def get_all(self):
        """
        Functia returneaza toate probleme laborator
        :return: O lista cu toate obiectele problema laborator
        """
        return list(self.__repo.values())


    def update(self,problema_laborator):
        """
        Functia actualizeaza datele problemei laborator din repo
        :param problema_laborator:  un obiect de tip problema laborator
        :return: -
        :raises: RepositoryException daca id ul problemei laborator nu exista
        """
        if not problema_laborator.get_id_problema_laborator() in self.__repo:
            raise RepositoryException("Id ul nu s a gasit!")

        self.__repo[problema_laborator.get_id_problema_laborator()] = problema_laborator


    def remove(self, id_problema_laborator):
        """
        Functia sterge problema laborator din repo
        :param id_problema_laborator: un obiect de tip problema laborator
        :return: -
        :raises: RepositoryException daca problema laborator nu se afla in repo
        """
        if not id_problema_laborator in self.__repo:
            raise RepositoryException("Id ul nu exista!")
        self.__repo.pop(id_problema_laborator)


class RepositoryFisierProblemeLaborator(RepositoryProblemeLaborator):
    def __init__(self,cale_fisier):
        super().__init__()
        self.__cale_fisier = cale_fisier
        self.__citeste_din_fisier()

    def __citeste_din_fisier(self):
        try:
            with open(self.__cale_fisier, "r") as file:
                linii = file.readlines()
                for linie in linii:
                    parti = linie.split(',')
                    id_lab = int(parti[0])
                    id_problema = int(parti[1])
                    descriere = parti[2]
                    an = int(parti[3])
                    luna = int(parti[4])
                    zi = int(parti[5])
                    date1 = date(an,luna,zi)
                    id = (id_lab,id_problema)
                    pb = ProblemaLaborator(id,descriere,date1)
                    super().add(pb)
        except IOError:
            print("Nu se poate citi din fisier :" + self.__cale_fisier)

    def __scrie_in_fisier(self):
        try:
            with open(self.__cale_fisier, "w") as file:
                probleme_laboratoare = super().get_all()
                for pb in probleme_laboratoare:
                    data = pb.get_deadline_problema_laborator()
                    an = data.year
                    luna = data.month
                    zi = data.day
                    text = f"{pb.get_id_laborator()},{pb.get_id_problema()},{pb.get_descriere_problema_laborator()},{an},{luna},{zi}\n"
                    file.write(text)
        except IOError:
            raise RepositoryException("Nu s a putut scrie in fisier!" + self.__cale_fisier)

    def add(self,problema_laborator):
        """
        Metoda adauga o problema laborator in fisier
        :param problema_laborator: un obiect de tip problema laborator
        :return: -
        """
        super().add(problema_laborator)
        self.__scrie_in_fisier()

    def remove(self,id_problema_laborator):
        """
        Metoda saterge problema laborator din fisier
        :param id_problema_laborator: un tuple reprezentand id ul
        :return: -
        """
        super().remove(id_problema_laborator)
        self.__scrie_in_fisier()

    def update(self,problema_laborator):
        """
        Metoda actualizeaza datele problemei laborator din fisier
        :param problema_laborator: un obiect de tip problema laborator
        :return: -
        """
        super().update(problema_laborator)
        self.__scrie_in_fisier()

