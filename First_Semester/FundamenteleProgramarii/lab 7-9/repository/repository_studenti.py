from domain import student
from repository.repository_exceptions import RepositoryException
from domain.student import Student

class RepositoryStudenti:
    #C
    #R
    #U
    #D

    def __init__(self):
        self.__repo = {}

    def add(self,student):
        """
        Functia adauga in repository un student
        :param student: un obiect de tip student/
        :return: -
        :raises: RepositoryException daca id ul exista deja
        """
        id_student = student.get_id_student()
        if id_student in self.__repo:
            raise RepositoryException("Id ul studentului exista deja!")
        self.__repo[id_student] = student

    def get_all(self):
        """
        Functia returneaza toti studentii
        :return: o lista cu toti studentii
        """
        return list(self.__repo.values())

    def __len__(self):
        """
        Functia returneaza nr de studenti din baza de date
        :return:
        """
        return len(self.__repo.keys())

    def remove(self, id_student):
        """
        Functia da remove la studentul care are id student
        :param id_student: un int
        :return: -
        :raises: RepositoryException daca id ul nu exista
        """
        if not id_student in self.__repo:
            raise RepositoryException("Id ul nu exista!")
        self.__repo.pop(id_student)

    def find(self, id_student):
        """
        Functia iti returneaza studentul al carui id este id_student
        :param id_student: un int , poiztiv
        :return: un student
        :raises: RepositoryException daca id ul nu exista in repo
        """
        if not id_student in self.__repo:
            raise RepositoryException("Id ul nu exista!")

        return self.__repo[id_student]

    def update(self, student):
        """
        Functia actualizeaza studentul din repo in fucntie de id ul din interiorul obiectului student transmis ca parametru
        :param student: un obiect de tip student
        :return: -
        :raises: RepositoryException daca id ul nu exista in repo:
        """
        if not student.get_id_student() in self.__repo:
            raise RepositoryException("Id ul nu exista!")

        self.__repo[student.get_id_student()] = student


class RepositoryFisiereStudenti(RepositoryStudenti):
    def __init__(self,cale_fisier):
        super().__init__()
        self.__cale_fisier = cale_fisier
        self.__citeste_din_fisier()

    def __citeste_din_fisier(self):
        """
        Prelucreaza liniile din fisier
        :return: -
        :raises: RepositoryException daca ceva nu a mers bine
        """
        try:
            with open(self.__cale_fisier,"r") as fisier:
                linii = fisier.readlines()
                for linie in linii:
                    parti = linie.split(",")
                    id_student = int(parti[0])
                    nume_student = parti[1]
                    grupa = int(parti[2])
                    student = Student(id_student,nume_student,grupa)
                    RepositoryStudenti.add(self,student)
        except IOError:
            raise RepositoryException("Fisierul nu se poate deschide : " + self.__cale_fisier)


    def __scrie_in_fisier(self):
        studenti = RepositoryStudenti.get_all(self)
        try:
            with open(self.__cale_fisier,"w") as fisier:
                for student in studenti:
                    text = f"{student.get_id_student()},{student.get_nume_student()},{student.get_grupa_student()}\n"
                    fisier.write(text)
        except IOError:
            raise RepositoryException("In fisierul nu se poate scrie : " + self.__cale_fisier)


    def add(self,student):
        """
        Adauga un student in fisier
        :param student: un student
        :return: -
        """
        super().add(student)
        self.__scrie_in_fisier()

    def remove(self,id_student):
        """
        Metoda sterge din fisier
        :param id_student:
        :return: -
        :raises: RepositoryException daca id ul nu exista in repo
        """
        super().remove(id_student)
        self.__scrie_in_fisier()

    def update(self,student):
        """
        Metoda da update in fisier
        :param student: un obiect de tip student
        :return: -
        """
        super().update(student)
        self.__scrie_in_fisier()






