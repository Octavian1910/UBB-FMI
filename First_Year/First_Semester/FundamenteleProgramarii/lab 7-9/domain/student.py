from domain.validators.validator_exceptions import ValidatorExceptions


class Student:

    def __init__(self, id , nume , grupa ):
        """
        Creeaza o instanta a clasei student
        :param id: un int pozitiv
        :param nume: un stirng nevid
        :param grupa: un intr pozitiv
        """
        self.__id = id
        self.__nume = nume
        self.__grupa = grupa


    def get_id_student(self):
        """
        Functia intoarce id ul studentului
        :return:  un int reprezentand id ul studentului
        """
        return self.__id


    def get_nume_student(self):
        """
        Functia intoarce numele studentului
        :return: un string reprezentand numele studentului
        """
        return self.__nume


    def get_grupa_student(self):
        """
        Functia intoarce grupa studentului
        :return: un intr reprezentand grupa studentului
        """
        return self.__grupa

    def set_nume_student(self, nume_nou):
        """
        Seteaza numele studentului
        :param nume_nou: un string reprezentand noul nume al studentului
        :return: -
        """
        self.__nume = nume_nou

    def set_grupa_student(self, grupa_noua):
        """
        Seteaza grupa studentului
        :grupa_noua: un int reprezentand noua grupa a studentului
        :return: -
        """
        self.__grupa = grupa_noua


    def __eq__(self, other):
        """
        Redefinim functia eq
        :param other:  un alt student
        :return: True sau false
        """
        if not isinstance(other, Student):
            raise ValidatorExceptions("Trebuie comparate 2 entitati de tip student!")
        if other.get_id_student() == self.__id:
            return True
        else :
            return False


    def __str__(self):
        """
        Redefinim functia str
        :return: un str frumos
        """
        return f"ID : {self.__id} | Nume : {self.__nume} | Grupa : {self.__grupa}"



