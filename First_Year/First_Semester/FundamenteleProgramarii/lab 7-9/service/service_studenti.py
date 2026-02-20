from domain.student import Student
import random

from repository.repository_exceptions import RepositoryException


class ServiceStudenti:

    def __init__(self , repoStudenti , repoAsignari, validator_Student):
        """
        Constructor
        :param repoStudenti: baza de date cu studenti
        """
        self.__repoStudenti = repoStudenti
        self.__repoAsignari = repoAsignari
        self.__validator = validator_Student

    def add(self , id , nume , grupa):
        """
        Functia creeaza obiectul student , il valideaza si il trimite la repo
        :param id: un int
        :param nume: un stirng
        :param grupa: un int
        :return: -
        """
        student = Student(id , nume , grupa)
        self.__validator.valideaza(student)
        self.__repoStudenti.add(student)


    def get_all(self):
        """
        Functia returneaza toti studentii din repo
        :return: O lista cu studentii din repo
        """
        return self.__repoStudenti.get_all()

    def find(self, id_student):
        """
        Functia returneaza studentul al carui id este id student
        :id_student: un int
        :return: un obiect de tip student
        """
        return self.__repoStudenti.find(id_student)


    def remove(self, id_student):
        """
        Functia scoate din baza de date studentul al carui id este id_studenet
        :param id_student: un int
        :return: -
        """
        self.__repoStudenti.remove(id_student)
        self.__repoAsignari.remove_by_id_student(id_student)


    def update(self,id,nume,grupa):
        """
        Functia modifica datele studentului al carui id este id student
        :param id: un int
        :param nume:  un string
        :param grupa:  un int
        :return: -
        """
        student = Student(id , nume , grupa)
        self.__validator.valideaza(student)
        self.__repoStudenti.update(student)

    def genereaza_X_studenti(self, x):
        """
        Functia genereaza x studenti
        :param x: un int pozitiv
        :return: -
        """
        for i in range(x):
            random.seed(i)
            id = len(self.__repoStudenti.get_all()) + 1
            len_nume = random.randint(5,10)
            nume = ""
            for i in range(len_nume):
                nume += chr(ord('A') + random.randint(0, 25))
            grupa = random.randint(200,900)
            while True:
                try:
                    student = Student(id, nume, grupa)
                    self.__validator.valideaza(student)
                    self.__repoStudenti.add(student)
                    break
                except RepositoryException :
                    id += 1










