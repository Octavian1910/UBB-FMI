class AsignareDTO:

    def __init__(self,id_student,nume_student,nota):
        """
        Constructor
        :param id_student: un int
        :param nume_student: un string
        :param nota: o nota
        """
        self.__id_student = id_student
        self.__nume_student = nume_student
        if nota == None:
            self.__nota = 0
        else :
            self.__nota = nota

    def get_id_student(self):
        """
        Functia returneaza id ul studentului
        :return: un int reprezentand id ul studentului
        """
        return self.__id_student

    def get_nume_student(self):
        """
        Functia returneaza numele studentului
        :return: un stirng
        """
        return self.__nume_student

    def get_nota(self):
        """
        Functia returneaza nota studentului
        :return: un int reprezentand nota studentului
        """
        return self.__nota

    def __str__(self):
        """
        Suprascrie str
        :return: un string frumos
        """
        return f"ID : {self.__id_student} | Nume : {self.__nume_student} | Nota : {self.__nota}"

