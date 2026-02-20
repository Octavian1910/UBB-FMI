from domain.problema_laborator import ProblemaLaborator
import random
from datetime import date
from repository.repository_exceptions import RepositoryException


class ServiceProblemeLaboratoare:


    def __init__(self,repoProblemeLaobratoare,repoAsignari,validator):
        self.__repo = repoProblemeLaobratoare
        self.__repo_asignari = repoAsignari
        self.__validator = validator

    def add(self,id_lab,id_problema,descriere,deadline):
        """
        Functia construieste un obiect de tip problema laborator si l adauga in repo daca trece validarea
        :param id_lab:  un int
        :param id_problema:  un int
        :param descriere:  un string
        :param deadline: un date
        :return: -
        """
        id_problema = (id_lab,id_problema)
        problema_laborator = ProblemaLaborator(id_problema,descriere,deadline)
        self.__validator.valideaza(problema_laborator)
        self.__repo.add(problema_laborator)

    def find(self, id_lab,id_problema):
        """
        Metoda returneaza problema laboratorului dorit
        :param id_lab: un int
        :param id_problema: un int
        :return: un obiect de tip problema laborator
        """
        id = (id_lab,id_problema)
        return self.__repo.find(id)

    def get_all(self):
        """
        Functia returneaza o lista cu toate problemele din repo
        :return: o lista cu toti studentii din repo
        """
        return self.__repo.get_all()


    def remove(self,id_lab,id_problema):
        """
        Metoda initiaza stergerea din repo
        :param id_lab: un int
        :param id_problema: un int
        :return: -
        """
        id = (id_lab,id_problema)
        self.__repo.remove(id)
        self.__repo_asignari.remove_by_id_pb(id)


    def update(self,id_lab,id_prob,descriere,deadline):
        """
        Initiaza update ul problemei
        :param id_lab:  un int
        :param id_prob: un int
        :param descriere: un string
        :param deadline: un deadline
        :return: -
        """
        id = (id_lab,id_prob)
        pb = ProblemaLaborator(id,descriere,deadline)
        self.__validator.valideaza(pb)
        self.__repo.update(pb)

    def genereaza_X_probleme_laborator(self, x):
        """
        Functia genereaza X probleme laborator
        :param X: un int
        :return: -
        """
        for i in range(x):
            random.seed(i)
            id_lab = random.randint(1,10)
            id_problema = random.randint(1,10)
            lungime_descriere = random.randint(2,100)
            text = ""
            for i in range(lungime_descriere):
                text += chr(ord('a') + random.randint(0, 25))

            data = date(random.randint(2000,2025),random.randint(1,12),random.randint(1,28))

            while True:
                try:
                    problema = ProblemaLaborator((id_lab, id_problema), text, data)
                    self.__validator.valideaza(problema)
                    self.__repo.add(problema)
                    break
                except RepositoryException:
                    id_problema += 1



