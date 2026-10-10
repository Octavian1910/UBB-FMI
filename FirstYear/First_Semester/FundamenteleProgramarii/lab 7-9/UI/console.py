from domain.validators.validator_exceptions import ValidatorExceptions
from repository.repository_exceptions import RepositoryException
from datetime import date

from service.service_exceptions import ServiceException


class Console:

    def __init__(self,serviceStudenti,serviceProblemeLaborator,serviceAsignari):
        """

        :param serviceStudenti:
        :param serviceProblemeLaborator:
        :param serviceAsignari:
        """
        self.__serviceStudenti = serviceStudenti
        self.__serviceProblemeLaborator = serviceProblemeLaborator
        self.__serviceAsignari = serviceAsignari

    def __meniu_principal(self):
        print("==" * 15)
        print("MENIU PRINCIPAL")
        print("==" * 15)
        print("1)Meniu Studenti")
        print("2)Meniu Probleme Laborator")
        print("3)Meniu Asignare/Notare")
        print("4)Rapoarte")
        print("5)Iesire")
        print("==" * 15)

    def __read_type(self,text,type):
        while True:
            rezultat = input(text)
            try:
                return type(rezultat)
            except ValueError:
                print("Tip incorect de date!")

    def run(self):
        while True:
            self.__meniu_principal()
            try:
                comanda = self.__read_type("Da comanda : " , int)
                if comanda == 1:
                    self.__run_studenti()
                elif comanda == 2:
                    self.__run_probleme_laborator()
                elif comanda == 3:
                    self.__run_asignari()
                elif comanda == 4:
                    self.__run__rapoarte()
                elif comanda == 5:
                    break
                else:
                    print("Comanda nu exista!")
            except Exception as e:
                print(str(e))


    def __meniu_studenti(self):
        """
        Meniul pt studenti
        :return: -
        """
        print("==" * 15)
        print("MENIU STUDENTI")
        print("==" * 15)
        print("1)Adauga student")
        print("2)Afiseaza toti studentii")
        print("3)Gaseste un student")
        print("4)Modifica un student")
        print("5)Sterge student")
        print("6)Genereaza x studenti")
        print("7)Revino la meniul principal")
        print("==" * 15)

    def __run_studenti(self):
        while True:
            self.__meniu_studenti()
            try:
                comanda = self.__read_type("Da comanda : " , int)
                if comanda == 1: #adauga student
                    id_student = self.__read_type("ID student : ",int)
                    nume_student = self.__read_type("Nume student : ", str)
                    grupa_student = self.__read_type("Grupa student : ",int)
                    self.__serviceStudenti.add(id_student,nume_student,grupa_student)
                    print("Studentul a fost adaugat cu succes!")

                elif comanda == 2: # afiseaza toti studentii
                    rezultat = self.__serviceStudenti.get_all()
                    for student in rezultat:
                        print(student)
                    print("Studentii au fost afisati cu succes!")

                elif comanda == 3: #afiseaza un student
                    id_student = self.__read_type("ID student : ",int)
                    rezultat = self.__serviceStudenti.find(id_student)
                    print(rezultat)
                    print("Studentul a fost afisat cu succes!")

                elif comanda == 4: #modifica student
                    id_student = self.__read_type("ID student : ",int)
                    nume_student = self.__read_type("Nume student : ", str)
                    grupa_student = self.__read_type("Grupa student : ", int)
                    self.__serviceStudenti.update(id_student,nume_student,grupa_student)
                    print("Studentul a fost modificat cu succes!")

                elif comanda == 5: #delete student
                    id_student = self.__read_type("ID student : ",int)
                    self.__serviceStudenti.delete(id_student)
                    print("Studentul a fost sters cu succes!")

                elif comanda == 6: #genereaza x studneti
                    x = self.__read_type("X : ", int)
                    self.__serviceStudenti.genereaza_X_studenti(x)
                    print(f"S au generat {x} studenti cu succes!")

                elif comanda == 7 : #revenire la meniu principal
                    break
                else :
                    print("Comanda invalida!")
            except (RepositoryException,ValidatorExceptions,ServiceException) as e:
                print(e)

    def __meniu_probleme_laborator(self):
        print("==" * 15)
        print("MENIU PROBLEME LABORATOR")
        print("==" * 15)
        print("1)Adauga problema laborator")
        print("2)Afiseaza toate problemele laborator")
        print("3)Gaseste o problema laborator")
        print("4)Modifica o problema de la laboratorul dorit")
        print("5)Sterge o problema laborator")
        print("6)Genereaza x probleme laborator")
        print("7)Revino la meniul principal")
        print("==" * 15)

    def __run_probleme_laborator(self):
        while True:
            self.__meniu_probleme_laborator()
            try:
                comanda = self.__read_type("Da comanda : " , int)
                if comanda == 1: #adauga problema laborator
                    nr_lab = self.__read_type("Nr laboarator : " , int)
                    nr_problema = self.__read_type("Nr problema : " , int)
                    descriere = self.__read_type("Descriere : " , str)
                    an = self.__read_type("An : " , int)
                    luna = self.__read_type("Luna : " , int)
                    zi = self.__read_type("Zi : " , int)
                    deadline = date(an,luna,zi)
                    self.__serviceProblemeLaborator.add(nr_lab,nr_problema,descriere,deadline)
                    print("Problema laborator s a adaugat!")

                elif comanda == 2: #afiseaza problememe laborator
                    rezultat = self.__serviceProblemeLaborator.get_all()
                    for problema in rezultat:
                        print(problema)

                elif comanda == 3 : #afiseaza o problema laborator
                    nr_lab = self.__read_type("Nr laboarator : " , int)
                    nr_problema = self.__read_type("Nr problema : " , int)
                    problema_lab = self.__serviceProblemeLaborator.find(nr_lab,nr_problema)
                    print(problema_lab)
                    print("Problema laborator dorita a fost afisata!")

                if comanda == 4 : #modifica o problema lab dorita
                    nr_lab = self.__read_type("Nr laboarator : ", int)
                    nr_problema = self.__read_type("Nr problema : ", int)
                    descriere = self.__read_type("Descriere : ", str)
                    an = self.__read_type("An : ", int)
                    luna = self.__read_type("Luna : ", int)
                    zi = self.__read_type("Zi : ", int)
                    deadline = date(an, luna, zi)
                    self.__serviceProblemeLaborator.update(nr_lab, nr_problema, descriere, deadline)
                    print("Problema laborator a fost modificata cu succes!")

                elif comanda == 5 : #sterge problema lab
                    nr_lab = self.__read_type("Nr laboarator : ", int)
                    nr_problema = self.__read_type("Nr problema : ", int)
                    self.__serviceProblemeLaborator.remove(nr_lab,nr_problema)

                    print("Problema laborator dorita a fost stearsa!")

                elif comanda == 6 : #genereaza x probleme lab
                    x = self.__read_type("X : ", int)
                    self.__serviceProblemeLaborator.genereaza_X_probleme_laborator(x)
                    print("Problemele laborator au fost generate cu succes!")

                elif comanda == 7 :
                    break

                else :
                    print("Comanda invalida!")

            except (RepositoryException,ValidatorExceptions,ServiceException) as e:
                print(e)


    def __meniu_asignari(self):
        print("=" * 15)
        print("MENIU ASIGNARI")
        print("=" * 15)
        print("1)Asignare Laborator")
        print("2)Afiseaza asignari")
        print("3)Afiseaza asignare dorita")
        print("4)Modifica asignare")
        print("5)Sterge asignare")
        print("6)Genereaza X asignari")
        print("7)Revino la meniul prinicpal!")
        print("==" * 15)


    def __run_asignari(self):
        while True:
            self.__meniu_asignari()
            try:
                comanda = self.__read_type("Da comanda : " , int)
                if comanda == 1: #adauga asignare
                    id_asignare = self.__read_type("ID asignare : " , int)
                    id_student = self.__read_type("ID student : " , int)
                    id_laborator = self.__read_type("ID laborator : " , int)
                    id_problema = self.__read_type("ID problema : " , int)
                    id_problema_laborator = (id_laborator, id_problema)
                    nota = self.__read_type("Nota(daca nu doriti scrieti 0) : " , int)
                    self.__serviceAsignari.add(id_asignare,id_student,id_laborator,id_problema_laborator,nota)
                    print("Asignare/Notare efectuata cu succes!")
                elif comanda == 2: #afisare asignari
                    rezutat = self.__serviceAsignari.get_all()
                    for asignare in rezutat:
                        print(asignare)
                    print("Asignari/Notari afisate cu succes!")
                elif comanda == 3 : #afiseaza o anumita asignare
                    id_asignare = self.__read_type("ID asignare : " , int)
                    rezultat = self.__serviceAsignari.find(1)
                    print(rezultat)
                elif comanda == 4 : #modifica asignare
                    id_asignare = self.__read_type("ID asignare : ", int)
                    id_student = self.__read_type("ID student : ", int)
                    id_laborator = self.__read_type("ID laborator : ", int)
                    id_problema = self.__read_type("ID problema : ", int)
                    id_problema_laborator = (id_laborator, id_problema)
                    nota = self.__read_type("Nota(daca nu doriti scrieti 0) : ", int)
                    self.__serviceAsignari.update(id_asignare, id_student, id_laborator, id_problema_laborator, nota)
                    print("Asignare/Notare modificata cu succes!")
                elif comanda == 5:
                    id_asignare = self.__read_type("ID asignare : ", int)
                    self.__serviceAsignari.remove(id_asignare)
                    print("Asignare/Notare stearsa cu succes!")
                elif comanda == 6 : #genereaza x asignari
                    x = self.__read_type("X : " , int)
                    self.__serviceAsignari.genereaza_x_asignari(x)
                    print(f"Cele {x} asignari au fost generate cu succes!")
                elif comanda == 7:
                    break
                else :
                    print("Comanda invalida!")

            except (RepositoryException,ValidatorExceptions,ServiceException) as e:
                print(e)


    def __meniu_rapoarte(self):
        print("==" * 15)
        print("MENIU RAPOARTE")
        print("=" * 15)
        print("1)Ordoneaza alfabetic (la o problema de laborator) : ")
        print("2)Ordoneaza descrescator dupa nota (la o problema de laborator) : ")
        print("3)Toti studentii cu media sub 5(media notelor la un laborator) : ")


    def __run__rapoarte(self):
        while True:
            self.__meniu_rapoarte()
            try:
                comanda = self.__read_type("Comanda : " , int)
                if comanda == 1: #ordoneaza alfabetic
                    id_lab = self.__read_type("ID laborator : " , int)
                    id_problema = self.__read_type("ID problema : " , int)
                    id = (id_lab, id_problema)
                    lista = self.__serviceAsignari.ordoneaza_alfabetic(id)
                    for asignare in lista:
                        print(asignare)
                elif comanda == 2: #ordoneaza dupa nota
                    id_lab = self.__read_type("ID laborator : ", int)
                    id_problema = self.__read_type("ID problema : ", int)
                    id = (id_lab, id_problema)
                    lista = self.__serviceAsignari.ordoneaza_dupa_nota(id)
                    for asignare in lista:
                        print(asignare)
                elif comanda == 3 :
                    id_lab = self.__read_type("ID laborator : ", int)
                    rezultat = self.__serviceAsignari.statistica_sub_5_la_lab(id_lab)
                    for situatie in rezultat:
                        print(situatie)
                elif comanda == 4 :
                    break
                else :
                    print("Comanda invalida!")
            except (RepositoryException,ValidatorExceptions,ServiceException) as e:
                print(e)





