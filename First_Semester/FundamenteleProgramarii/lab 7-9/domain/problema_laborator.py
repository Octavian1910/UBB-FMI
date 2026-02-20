from domain.validators.validator_exceptions import ValidatorExceptions
from repository.repository_exceptions import RepositoryException


class ProblemaLaborator:

    def __init__(self, id_problema_laborator, descirere, deadline):
        """
        Creeaza o instanta a clasei ProblemaLaborator
        :param id_problema_laborator: un tuple din 2 elemente
        :param descirere: un string
        :param deadline: un date
        """
        self.__id_problema_laborator = id_problema_laborator
        self.__descriere = descirere
        self.__deadline = deadline

    def get_id_problema_laborator(self):
        """
        Functia returneaza id ul problemei laborator
        :return: un tuple
        """
        return self.__id_problema_laborator

    def get_id_problema(self):
        """
        Returneaza id ul problemei
        :return: un int
        """
        return self.__id_problema_laborator[1]

    def get_id_laborator(self):
        """
        Functia returneaza id ul laboratorului
        :return: un int
        """
        return self.__id_problema_laborator[0]

    def get_descriere_problema_laborator(self):
        """
        Functia returneaza descrierea problemei laborator
        :return: un string
        """
        return self.__descriere

    def get_deadline_problema_laborator(self):
        """
        Functia returneaza deadline ul problemei
        :return: un date
        """
        return self.__deadline

    def set_descriere_problema_laborator(self, descriere_noua):
        """
        Functia seteaza descrierea problemei laboratorului
        :param descriere_noua: un string
        :return: -
        """
        self.__descriere = descriere_noua

    def set_deadline_problema_laborator(self, deadline_nou):
        """
        Functia seteaza noul deadline problemei laboratorului
        :param deadline_nou: un date
        :return: -
        """
        self.__deadline = deadline_nou


    def __eq__(self, other):
        """
        Functia decide daca 2 obiecte sunt egale
        :param other: un obiect de tip ProblemaLaborator
        :return: True daca sunt egale , False altfel
        """
        if not isinstance(other, ProblemaLaborator):
            raise ValidatorExceptions("ProblemaLaborator nu este din aceeasi instanta!")

        if self.__id_problema_laborator == other.get_id_problema_laborator():
            return True
        else :
            return False

    def __str__(self):
        """
        Functia redefineste print ul
        :return: un string
        """
        return f"Lab : {self.get_id_laborator()} | Problema : {self.get_id_problema()} | Descriere : {self.__descriere} | Deadline : {self.get_deadline_problema_laborator()}"

