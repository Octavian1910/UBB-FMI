

class DtoStudentSub5():
    def __init__(self,nume_student,nota):
        """
        Constructor
        :param nume_student: un string
        :param nota: o nota
        """
        self.__nume_student = nume_student
        self.__nota = nota

    def get_nume(self):
        """
        Reutneaza numele
        :return: un string
        """
        return self.__nume_student

    def get_nota(self):
        """
        Reutneaza nota
        :return: un float
        """
        return self.__nota

    def __str__(self):
        """
        Suprascrie string
        :return:  un stirng nevid frumos
        """
        return f"Nume : {self.__nume_student} | Nota : {self.__nota}"

