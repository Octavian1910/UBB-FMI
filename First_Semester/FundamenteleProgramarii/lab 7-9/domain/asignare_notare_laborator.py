from domain.validators.validator_exceptions import ValidatorExceptions


class AsignareNotareLaborator:

    def __init__(self, id_asignare,student,problema_laborator,nota = None):
        """
        Constructor
        :param id_asignare: un int pozitiv
        :param student:  un student
        :param problema_laborator: o problema lab
        :param nota: un float pozitiv
        """
        self.__id_asignare = id_asignare
        self.__student = student
        self.__problema_laborator = problema_laborator
        self.__nota = nota

    def get_id_asignare(self):
        """
        Functia returneaza id ul asignarii
        :return: un int
        """
        return self.__id_asignare

    def get_student(self):
        """
        Functia returneaza studentul la care i s a asignat nota
        :return: un obiect de tip student
        """
        return self.__student

    def get_problema_laborator(self):
        """
        Functia returneaza problema laborator care s a asignat
        :return: un obiect de tip problema laborator
        """
        return self.__problema_laborator

    def get_nota(self):
        """
        Functia returneaza nota din asignare daca exista
        :return: un float daca exista nota sau 0 daca nu exista
        """
        if self.__nota == None:
            return 0
        return self.__nota

    def set_student(self,student_nou):
        """
        Seteaza la un nou student
        :param student_nou: un obiect de tip student
        :return: -
        """
        self.__student = student_nou

    def set_problema_laborator(self,problema_laborator):
        """
        Metoda seteaza la o noua problema laborator
        :param problema_laborator: o problema laborator
        :return: -
        """
        self.__problema_laborator = problema_laborator

    def set_nota(self,nota):
        """
        Functia seteaza nota
        :param nota: un int
        :return: -
        """
        self.__nota = nota



    def __eq__(self,other):
        """
        Suprascriem cand 2 obiecte sunt egale
        :return: True daca sunte egale false altfel
        """
        if not isinstance(other,AsignareNotareLaborator):
            raise ValidatorExceptions("Ambele trebuie sa fie obiecte de tip asignare!")

        if self.__id_asignare == other.get_id_asignare():
            return True
        else:
            return False

    def __str__(self):
        """
        Metoda redefineste printul
        :return: un string frumos
        """
        return f"ID : {self.__id_asignare} | Student : {self.get_student().get_nume_student()} | Lab-Problema : {self.get_problema_laborator().get_id_problema_laborator()} | Nota : {self.get_nota()}"




