import random

from domain.asignare_dto import AsignareDTO
from domain.asignare_notare_laborator import AsignareNotareLaborator
from domain.dto_sub_5 import DtoStudentSub5
from domain.validators.validator_exceptions import ValidatorExceptions
from repository.repository_exceptions import RepositoryException
from service.service_exceptions import ServiceException




class ServiceAsignareNotareLaborator():
    def __init__(self,repoAsignari,repoStudenti,repoLaboratoare,validator):
        """
        Constructor
        :param repoAsignari: bazad e date cu asignari
        :param repoStudenti:  baza de date cu studenti
        :param repoLaboratoare: baza de date cu laboratore
        :param validator: validator pt asignari
        """
        self.__repoAsignari = repoAsignari
        self.__repoStudenti = repoStudenti
        self.__repoLaboratoare = repoLaboratoare
        self.__validator = validator


    def add(self,id_asignare,id_student,id_problema_lab,nota = None):
        """
        Metoda adauga o problema laborator
        :param id_asignare: un int
        :param student: un obiect de tip student
        :param problema_lab: un obiect de tip problema laborator
        :param nota: un int
        :return: -
        """
        student = self.__repoStudenti.find(id_student)
        problema_lab = self.__repoLaboratoare.find(id_problema_lab)
        asiganre = AsignareNotareLaborator(id_asignare,student,problema_lab,nota)
        self.__validator.valideaza(asiganre)
        self.__repoAsignari.add(asiganre)


    def get_all(self):
        """
        Functia returneaza toate asignarile
        :return: o lista cu toate asignarile
        """
        return self.__repoAsignari.get_all()

    def find(self,id_asignare):
        """
        Metoda initiaza returneaza asignarea cu id asignare
        :param id_asignare: un int
        :return: o asignare
        """
        return self.__repoAsignari.find(id_asignare)

    def remove(self,id_asignare):
        """
        Metoda initiaza stergerea
        :param id_asignare: un int pozitiv
        :return: -
        """
        self.__repoAsignari.remove(id_asignare)

    def update(self,id_asignare,id_student,id_problema_lab,nota = None):
        """
        Metoda initiaza updateul unei asignari
        :param id_asignare: un int
        :param id_student: un int
        :param id_problema_lab: un tuple
        :param nota: un int
        :return:-
        """
        student = self.__repoStudenti.find(id_student)
        problema_lab = self.__repoLaboratoare.find(id_problema_lab)
        asignare = AsignareNotareLaborator(id_asignare,student,problema_lab,nota)
        self.__validator.valideaza(asignare)
        self.__repoAsignari.update(asignare)

    def genereaza_x_asignari(self, x):
        """
        Metoda genereaza X asignarile
        :param x: un int
        :return: -
        """
        studenti = self.__repoStudenti.get_all()
        probleme_laborator = self.__repoLaboratoare.get_all()
        if len(studenti) == 0:
            raise ServiceException("Nu exista studenti!")
        if len(probleme_laborator) == 0:
            raise ServiceException("Nu exista probleme laborator!")


        for i in range(x):
            random.seed(i)
            id_asignare = len(self.__repoAsignari.get_all()) + 1
            student = random.choice(studenti)
            problema_lab = random.choice(probleme_laborator)
            nota = float(random.randint(1, 10))

            while True:
                try:
                    asignare = AsignareNotareLaborator(id_asignare,student,problema_lab,nota)
                    self.__validator.valideaza(asignare)
                    self.__repoAsignari.add(asignare)
                    break
                except (ValidatorExceptions,RepositoryException) as e:
                    id_asignare += 1

    def ordoneaza_alfabetic(self, id_problema_laborator):
        """
        Metoda prepara lista pentru a fi afisata in ordine alfabetica
        :param id_problema_laborator: un tuple
        :return: o lista ordonata alfabetic dupa nume
        """
        lista = self.__repoAsignari.get_all()
        if len(lista) == 0:
            raise ServiceException("Nu exista asignari!")

        lista_filtrata = []
        for asignare in lista:
            if asignare.get_problema_laborator().get_id_problema_laborator() == id_problema_laborator:
                student = asignare.get_student()
                asignare_dto = AsignareDTO(student.get_id_student(),student.get_nume_student(),asignare.get_nota())
                lista_filtrata.append(asignare_dto)

        if len(lista_filtrata) == 0:
            raise ServiceException("Nu exista probleme laborator!")

        lista_filtrata.sort(key=lambda x: x.get_nume_student(),reverse=False)

        return lista_filtrata

    def ordoneaza_dupa_nota(self,id_problema_laborator):
        """
        Metoda prepara lista pentru a fi afisata in ordine descrescatoare dupa nota
        :param id_problema_laborator: un tuple
        :return: o lista ordobata descrescator dupa nota
        """
        lista = self.__repoAsignari.get_all()
        if len(lista) == 0:
            raise ServiceException("Nu exista asignari!")

        lista_filtrata = []
        for asignare in lista:
            if asignare.get_problema_laborator().get_id_problema_laborator() == id_problema_laborator:
                student = asignare.get_student()
                asignare_dto = AsignareDTO(student.get_id_student(), student.get_nume_student(), asignare.get_nota())
                lista_filtrata.append(asignare_dto)

        if len(lista_filtrata) == 0:
            raise ServiceException("Nu exista probleme laborator!")

        lista_filtrata.sort(key=lambda x: x.get_nota(), reverse=True)

        return lista_filtrata

    def statistica_sub_5_la_lab(self, id_lab):
        """
        Funcia returneaza o lista cu studentii care au media sub 5 la un laborator cu id : id_lab
        :param id_lab: un int pozitiv
        :return: -
        """
        asignari = self.__repoAsignari.get_all()
        situatie_medii = self.__medii_generale_la_un_lab(asignari,id_lab)
        medii_sub_5 = self.__calculare_medii_generale(situatie_medii)
        medii_sub_5.sort(key=lambda x: x.get_nota(), reverse=True)

        return medii_sub_5



    def __medii_generale_la_un_lab(self,lista_asignari,id_lab):
        """
        Medii generale sub 5 la un lab
        :param lista_asignari:
        :param id_lab:
        :return: un dictionar care are ca si cheie id ul studentului iar ca si values o lista cu 2 elemente , primul reprezentand suma notelor, iar al doilea reprezentand contorul lor
        """
        medii_laborator = {}
        for asignare in lista_asignari:
            if asignare.get_problema_laborator().get_id_laborator() == id_lab:
                student = asignare.get_student()
                id_student = student.get_id_student()
                nota = asignare.get_nota()
                if not id_student in medii_laborator:
                    medii_laborator[id_student] = [0,0]
                medii_laborator[id_student][0] += nota
                medii_laborator[id_student][1] += 1

        return medii_laborator

    def __calculare_medii_generale(self, situatie_medii):
        """
        Calculeaza exact media generala iar pe cele care sunt sub 5 le adauga in lista de return
        Functia calclueaza mediile generale
        :param situatie_medii:
        :return: o lista cu obiecte de tip dto_sub_5  unde se alfa doar situatiile cu media sub 5
        """
        medii_sub_5 = []
        for id_student in situatie_medii:
            nume_student = self.__repoStudenti.find(id_student).get_nume_student()
            if situatie_medii[id_student][0] == 0:
                medie = 0
            else :
                medie = situatie_medii[id_student][0]/situatie_medii[id_student][1]

            if medie < 5 :
                student_dto = DtoStudentSub5(nume_student,medie)
                medii_sub_5.append(student_dto)

        return medii_sub_5



































