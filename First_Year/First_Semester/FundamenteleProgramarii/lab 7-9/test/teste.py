
from domain.student import Student
from unittest import TestCase
from datetime import date
from repository.repository_asignare_notare_laborator import RepositoryAsignareNotareLaborator, \
    RepositoryFisierAsignareNotareLaborator
from domain.validators.validator_asignare_notare_laborator import ValidatorAsignareNotareLaborator
from domain.validators.validator_exceptions import ValidatorExceptions
from domain.validators.validator_student import ValidatorStudent
from domain.problema_laborator import ProblemaLaborator
from domain.validators.validator_problema_laborator import ValideazaProblemaLaborator
from repository.repository_probleme_laboratoare import RepositoryProblemeLaborator, RepositoryFisierProblemeLaborator
from repository.repository_studenti import RepositoryStudenti, RepositoryFisiereStudenti

from repository.repository_exceptions import RepositoryException
from service.service_asignare_notare_laborator import ServiceAsignareNotareLaborator
from service.service_probleme_laboratoare import ServiceProblemeLaboratoare
from service.service_studenti import ServiceStudenti
from domain.asignare_notare_laborator import AsignareNotareLaborator

class teste_domain_student(TestCase):
    def setUp(self):
        self.__student = Student(1,"Stanislav Octavian",216)
        self.__validator_student = ValidatorStudent()


    def test_entitate_student(self):
        self.assertEqual(self.__student.get_id_student(),1)
        self.assertEqual(self.__student.get_nume_student(),"Stanislav Octavian")
        self.assertEqual(self.__student.get_grupa_student(),216)

        self.__student.set_nume_student("Fulea Adriana")
        self.__student.set_grupa_student(218)
        self.assertEqual(self.__student.get_nume_student(),"Fulea Adriana")
        self.assertEqual(self.__student.get_grupa_student(),218)


    def test_valideaza_entiate_student(self):

        self.__validator_student.valideaza(self.__student)


        student_id_invalid = Student('BMW',"Stanislav Octavian",216)

        with self.assertRaises(ValidatorExceptions) as e:
            self.__validator_student.valideaza(student_id_invalid)

        self.assertIn("Id ul studentului nu este de tip numar!", str(e.exception))


        student_nume_invalid = Student(132, "Stanislav123Octavian", 216)

        with self.assertRaises(ValidatorExceptions) as e:
            self.__validator_student.valideaza(student_nume_invalid)

        self.assertIn("Numele contine cifre!\n", e.exception.get_erori())

        student_grupa_invalida = Student(123, "Stanislav Octavian", "masina")
        with self.assertRaises(ValidatorExceptions) as e:
            self.__validator_student.valideaza(student_grupa_invalida)

        self.assertIn("Grupa nu este de tip numar!\n", e.exception.get_erori())


        student_complet_invalid = Student("BMW",123,"bobita")
        with self.assertRaises(ValidatorExceptions) as e:
            self.__validator_student.valideaza(student_complet_invalid)

        erori_asteptate = [
            "Id ul studentului nu este de tip numar!\n",
            "Numele contine cifre!\n",
            "Grupa nu este de tip numar!\n"
        ]
        self.assertEqual(erori_asteptate, e.exception.get_erori())

        self.assertEqual(self.__student.get_grupa_student(), 216)



class teste_repository_studenti(TestCase):


    def setUp(self):
        self.__repo = RepositoryStudenti()
        self.__student1 = Student(1,"Octavian" , 215)
        self.__student2 = Student(2,"Ionut" , 216)
        self.__student3 = Student(3,"David Posa" , 67)
        self.__repo.add(self.__student1)
        self.__repo.add(self.__student2)
        self.__repo.add(self.__student3)




    def test_add(self):
        self.__repo = RepositoryStudenti()
        self.__repo.add(self.__student1)
        self.assertEqual(len(self.__repo), 1)
        self.__repo.add(self.__student2)
        self.assertEqual(len(self.__repo), 2)
        with self.assertRaises(RepositoryException):
            self.__repo.add(self.__student1)
        self.__repo.add(self.__student3)
        self.assertEqual(len(self.__repo), 3)

    def test_get_all(self):
        student1_copy = Student(1,"Marius" , 215)
        self.assertEqual(self.__repo.get_all(), [self.__student1,self.__student2,self.__student3])
        self.assertEqual(len(self.__repo.get_all()), 3)
        rezultat = self.__repo.get_all()
        self.assertEqual(student1_copy,rezultat[0])


    def test_remove(self):
        self.assertEqual(len(self.__repo.get_all()), 3)
        self.__repo.remove(1)
        self.assertEqual(len(self.__repo.get_all()), 2)
        lista = self.__repo.get_all()
        for student in lista:
            if student.get_id_student() == 1:
                assert False

        with self.assertRaises(RepositoryException):
            self.__repo.remove(1)


    def test_find(self):
        self.assertEqual(len(self.__repo.get_all()), 3)
        rezultat = self.__repo.find(1)
        self.assertEqual(rezultat,self.__student1)
        rezultat = self.__repo.find(2)
        self.assertEqual(rezultat,self.__student2)


    def test_update(self):

        self.assertEqual(len(self.__repo.get_all()), 3)
        rezultat1 = self.__repo.find(1)
        student = Student(1,"Nume Nou" , 644)
        self.__repo.update(student)
        rezultat2 = self.__repo.find(1)
        if rezultat1.get_nume_student() == rezultat2.get_nume_student():
            assert False




class test_service_studenti(TestCase):
    def setUp(self):
        self.__repo = RepositoryStudenti()
        self.__repoAsignari = RepositoryAsignareNotareLaborator()
        self.__validator = ValidatorStudent()
        self.__student1 = Student(1,"Marius" , 215)
        self.__student2 = Student(2,"Ionut" , 216)
        self.__student3 = Student(3,"David Posa" , 67)
        self.__service = ServiceStudenti(self.__repo,self.__repoAsignari,self.__validator)
        self.__service.add(self.__student1.get_id_student(),self.__student1.get_nume_student(),self.__student1.get_grupa_student())
        self.__service.add(self.__student2.get_id_student(),self.__student2.get_nume_student(),self.__student2.get_grupa_student())
        self.__service.add(self.__student3.get_id_student(),self.__student3.get_nume_student(),self.__student3.get_grupa_student())

    def test_add(self):
        with self.assertRaises(RepositoryException):
            self.__service.add(1,"Adri Cola" , 214)


        self.assertEqual(len(self.__repo.get_all()), 3)



    def test_get_all(self):
        rezulat = self.__service.get_all()
        self.assertEqual(rezulat,[self.__student1,self.__student2,self.__student3])

    def test_remove(self):
        self.assertEqual(len(self.__service.get_all()), 3)
        self.__service.remove(1)
        self.assertEqual(len(self.__service.get_all()), 2)
        with self.assertRaises(RepositoryException):
            rezultat = self.__service.find(1)



    def test_update(self):
        self.assertEqual(len(self.__service.get_all()), 3)
        rezultat1 = self.__service.find(1)
        self.__service.update(1,"Dorian Popa" , 216)
        rezultat2 = self.__service.find(1)
        if rezultat1.get_nume_student() == rezultat2.get_nume_student():
            assert False

        with self.assertRaises(ValidatorExceptions):
            self.__service.update(10,"12","Octa")


    def test_genreaza_X_studenti(self):
        self.__repo = RepositoryStudenti()
        self.__repoAsignari = RepositoryAsignareNotareLaborator()
        self.__service = ServiceStudenti(self.__repo,self.__repoAsignari,self.__validator)
        self.assertEqual(len(self.__repo.get_all()), 0)
        self.__service.genereaza_X_studenti(150)
        rezultat = len(self.__repo.get_all())
        self.assertEqual(len(self.__repo.get_all()), 150)







class test_domain_problema_laboratore(TestCase):
    def setUp(self):
        self.__problema_laborator = ProblemaLaborator((1, 2), "Descrierea este interesanta", date(2025, 9, 12))
        self.__validator_problema_laborator = ValideazaProblemaLaborator()

    def test_entitate_problema_laborator(self):
        self.assertEqual(self.__problema_laborator.get_id_problema_laborator(), (1, 2))
        self.assertEqual(self.__problema_laborator.get_id_problema(), 2)
        self.assertEqual(self.__problema_laborator.get_id_laborator(), 1)
        self.assertEqual(self.__problema_laborator.get_descriere_problema_laborator(), "Descrierea este interesanta")
        self.assertEqual(self.__problema_laborator.get_deadline_problema_laborator(), date(2025, 9, 12))
        self.__problema_laborator.set_descriere_problema_laborator("Descriere noua!")
        self.__problema_laborator.set_deadline_problema_laborator(date(2006, 4, 19))
        self.assertEqual(self.__problema_laborator.get_descriere_problema_laborator(), "Descriere noua!")
        self.assertEqual(self.__problema_laborator.get_deadline_problema_laborator(), date(2006, 4, 19))

    def test_valideaza_problema_laborator(self):

        self.__validator_problema_laborator.valideaza(self.__problema_laborator)

        problema_laborator_id_invalid = ProblemaLaborator((1,), "Descriere", date(2006, 4, 19))

        with self.assertRaises(ValidatorExceptions) as e:
            self.__validator_problema_laborator.valideaza(problema_laborator_id_invalid)

        self.assertEqual("Id ul laboratorului nu contine 2 elemente!\n", str(e.exception))

        problema_laborator_descriere_gresita = ProblemaLaborator((1, 3), "", date(2006, 4, 19))
        with self.assertRaises(ValidatorExceptions):
            self.__validator_problema_laborator.valideaza(problema_laborator_descriere_gresita)

        problema_laborator_deadline_invalid = ProblemaLaborator((1, 3), "Miau", "Audi")
        with self.assertRaises(ValidatorExceptions):
            self.__validator_problema_laborator.valideaza(problema_laborator_deadline_invalid)

class test_repository_probleme_laborator(TestCase):
    def setUp(self):
        self.__repo = RepositoryProblemeLaborator()
        self.__pb1 = ProblemaLaborator((1,1),"Descriere interesanta", date(2019,5,14))
        self.__pb2 = ProblemaLaborator((1,2),"Zece la Asc" , date(2025,8,12))
        self.__pb3 = ProblemaLaborator((2,1),"Trei la Fp" , date(2025,8,15))
        self.__repo.add(self.__pb1)
        self.__repo.add(self.__pb2)
        self.__repo.add(self.__pb3)


    def test_add(self):
        self.assertEqual(len(self.__repo), 3)

        pb4 = ProblemaLaborator((2,2),"Problema 4 " , date(2014,9,7))
        self.__repo.add(pb4)

        self.assertEqual(len(self.__repo), 4)

        with self.assertRaises(RepositoryException) :
            self.__repo.add(pb4)


    def test_find(self):
        self.assertEqual(len(self.__repo), 3)

        rezultat = self.__repo.find((1,1))

        self.assertEqual(rezultat, self.__pb1)

        with self.assertRaises(RepositoryException) :
            rezultat = self.__repo.find((154,0))



    def test_get_all(self):
        self.assertEqual(len(self.__repo), 3)

        rezultat = self.__repo.get_all()

        self.assertEqual(rezultat, [self.__pb1,self.__pb2,self.__pb3])


    def test_update(self):
       pb1_updated = ProblemaLaborator((1,1),"Descriere noua" , date(1997,5,14))
       rezultat1 = self.__repo.find((1,1))
       self.__repo.update(pb1_updated)
       rezultat2 = self.__repo.find((1,1))
       assert rezultat1 == rezultat2
       assert(rezultat1.get_descriere_problema_laborator() != rezultat2.get_descriere_problema_laborator())
       assert(rezultat1.get_deadline_problema_laborator() != rezultat2.get_deadline_problema_laborator())

    def test_remove(self):
        assert(len(self.__repo) == 3)
        rezultat1 = self.__repo.get_all()
        self.__repo.remove(self.__pb1.get_id_problema_laborator())
        assert(len(self.__repo) == 2)
        rezulat2 = self.__repo.get_all()
        self.assertNotEqual(rezultat1, rezulat2)
        self.assertEqual([self.__pb2,self.__pb3],rezulat2)
        with self.assertRaises(RepositoryException) :
            self.__repo.remove(self.__pb1.get_id_laborator())


class test_service_probleme_laborator(TestCase):
    def setUp(self):
        self.__repo = RepositoryProblemeLaborator()
        self.__repoAsignari = RepositoryAsignareNotareLaborator()
        self.__validator = ValideazaProblemaLaborator()
        self.__pb1 = ProblemaLaborator((1, 1), "Descriere interesanta", date(2019, 5, 14))
        self.__pb2 = ProblemaLaborator((1, 2), "Zece la Asc", date(2025, 8, 12))
        self.__pb3 = ProblemaLaborator((2, 1), "Trei la Fp", date(2025, 8, 15))
        self.__service = ServiceProblemeLaboratoare(self.__repo,self.__repoAsignari,self.__validator)
        self.__service.add(1,1,"Descriere interesanta", date(2019, 5, 14))
        self.__service.add(1,2, "Zece la Asc", date(2025, 8, 12))
        self.__service.add(2,1, "Trei la Fp", date(2025, 8, 15))

    def test_add(self):
        self.assertEqual(len(self.__repo), 3)
        pb4 = ProblemaLaborator((2,2),"Descriere interesanta" , date(2025,8,12))
        self.__service.add(2,2,"Descriere interesanta" , date(2025,8,12))
        self.assertEqual(len(self.__repo), 4)

        with self.assertRaises(ValidatorExceptions) :
            self.__service.add(1,-1,124,"masina")

        with self.assertRaises(ValidatorExceptions) as e:
            self.__service.add(1, -1, 124, "masina")


        erori = ['Id ul problemei este negativ!\n',
                'Descrierea problemei nu este string!\n',
                'Deadline problemei nu este o data!\n']
        self.assertEqual(e.exception.get_erori() ,erori)


    def test_find(self):
        rezulat = self.__service.find(1,1)
        self.assertEqual(self.__pb1,self.__service.find(1,1))

        with self.assertRaises(RepositoryException) :
            self.__service.find(1,4)


    def test_get_all(self):
        self.assertEqual(len(self.__service.get_all()),3)
        self.assertEqual(self.__service.get_all(),[self.__pb1,self.__pb2,self.__pb3])

    def test_update(self):
        rezultat  = self.__service.find(1,1)
        self.__service.update(1,1,"Descriere noua",date(2019,5,29))
        rezultat2 = self.__service.find(1,1)
        self.assertEqual(rezultat, rezultat2)
        self.assertNotEqual(rezultat.get_descriere_problema_laborator(),rezultat2.get_descriere_problema_laborator())
        self.assertNotEqual(rezultat.get_deadline_problema_laborator(),rezultat2.get_deadline_problema_laborator())

    def test_genereaza_X_probleme_laborator(self):
        self.__repo = RepositoryProblemeLaborator()
        self.__repoAsignari = RepositoryAsignareNotareLaborator()
        self.__service = ServiceProblemeLaboratoare(self.__repo,self.__repoAsignari,self.__validator)
        self.assertEqual(len(self.__service.get_all()),0)
        self.__service.genereaza_X_probleme_laborator(150)
        self.assertEqual(len(self.__service.get_all()),150)




class test_domain_asignare_notare_laborator(TestCase):
    def setUp(self):
        self.__student1 = Student(1, "Marius", 215)
        self.__student2 = Student(2, "Ionut", 216)
        self.__student3 = Student(3, "David Posa", 67)
        self.__pb1 = ProblemaLaborator((1, 1), "Descriere interesanta", date(2019, 5, 14))
        self.__pb2 = ProblemaLaborator((1, 2), "Zece la Asc", date(2025, 8, 12))
        self.__pb3 = ProblemaLaborator((2, 1), "Trei la Fp", date(2025, 8, 15))
        self.__asignare1 = AsignareNotareLaborator(1,self.__student1,self.__pb1)
        self.__asignare2 = AsignareNotareLaborator(2,self.__student2,self.__pb2)
        self.__notare3 = AsignareNotareLaborator(3,self.__student3,self.__pb3,10)


    def test_entitate(self):
        self.assertEqual(self.__asignare1.get_id_asignare(),1)
        self.assertEqual(self.__asignare1.get_student(),self.__student1)
        self.assertEqual(self.__asignare1.get_problema_laborator(),self.__pb1)
        self.assertEqual(self.__asignare1.get_nota(),0)
        self.assertEqual(self.__notare3.get_nota(),10)
        self.__asignare2.set_nota(5)
        self.assertEqual(self.__asignare2.get_nota(),5)
        self.__asignare1.set_student(self.__student3)
        self.assertEqual(self.__asignare1.get_student(),self.__student3)
        self.__asignare1.set_problema_laborator(self.__pb2)
        self.assertEqual(self.__asignare1.get_problema_laborator(),self.__pb2)
        self.__asignare1.set_nota(5)
        self.assertEqual(self.__asignare1.get_nota(),5)

    def test_validator(self):
        validator = ValidatorAsignareNotareLaborator()
        id_invalid = AsignareNotareLaborator(-1,self.__student1,self.__pb1)
        with self.assertRaises(ValidatorExceptions) as e:
            validator.valideaza(id_invalid)

        self.assertEqual(str(e.exception),"Id ul trebuie sa fie pozitiv!\n")

        student_invalid = AsignareNotareLaborator(1,10,self.__pb1)
        with self.assertRaises(ValidatorExceptions) as e:
            validator.valideaza(student_invalid)

        self.assertEqual(str(e.exception),"Studentul nu este un obiect de tip student!\n")

        complet_invalid = AsignareNotareLaborator(-1,10,7,"abc")
        with self.assertRaises(ValidatorExceptions) as e:
            validator.valideaza(complet_invalid)

        erori = ["Id ul trebuie sa fie pozitiv!\n",
                "Studentul nu este un obiect de tip student!\n",
                "Problema laborator nu este un obiect de tip problema laborator!\n",
                "Nota trb sa fie numar!\n"]
        self.assertEqual(e.exception.get_erori(),erori)


class test_Repository_asiganri(TestCase):
    def setUp(self):
        self.__repo = RepositoryAsignareNotareLaborator()
        self.__student1 = Student(1, "Marius", 215)
        self.__student2 = Student(2, "Ionut", 216)
        self.__student3 = Student(3, "David Posa", 67)
        self.__pb1 = ProblemaLaborator((1, 1), "Descriere interesanta", date(2019, 5, 14))
        self.__pb2 = ProblemaLaborator((1, 2), "Zece la Asc", date(2025, 8, 12))
        self.__pb3 = ProblemaLaborator((2, 1), "Trei la Fp", date(2025, 8, 15))
        self.__asignare1 = AsignareNotareLaborator(1, self.__student1, self.__pb1)
        self.__asignare2 = AsignareNotareLaborator(2, self.__student2, self.__pb2)
        self.__notare3 = AsignareNotareLaborator(3, self.__student3, self.__pb3, 10)
        self.__repo.add(self.__asignare1)
        self.__repo.add(self.__asignare2)
        self.__repo.add(self.__notare3)

    def test_add(self):
        self.assertEqual(len(self.__repo),3)

    def test_get_all(self):
        self.assertEqual(self.__repo.get_all(),[self.__asignare1,self.__asignare2,self.__notare3])


    def test_find(self):
        self.assertEqual(self.__repo.find(1),self.__asignare1)
        self.assertEqual(self.__repo.find(2),self.__asignare2)

    def test_remove(self):
        self.__repo.remove(1)
        self.assertEqual(len(self.__repo),2)

        with self.assertRaises(RepositoryException) as e:
            self.__repo.remove(1)

        self.assertEqual(str(e.exception),"Id ul nu s a gasit!")

    def test_update(self):
        student4 = Student(4, "Darius", 67)
        pb = ProblemaLaborator((1,2),"asd",date(2002, 5, 14))
        asignare1_updated = AsignareNotareLaborator(1, student4,pb,5)
        self.__repo.update(asignare1_updated)
        rezultat = self.__repo.find(1)
        self.assertEqual(rezultat.get_problema_laborator(),pb)
        self.assertEqual(rezultat.get_student(),student4)
        self.assertEqual(rezultat.get_nota(),5)


class test_service_asignari(TestCase):
    def setUp(self):
        self.__repo_asignari = RepositoryAsignareNotareLaborator()
        self.__repoStudenti = RepositoryStudenti()
        self.__repoProblemeLaborator = RepositoryProblemeLaborator()
        self.__validator = ValidatorAsignareNotareLaborator()
        self.__service = ServiceAsignareNotareLaborator(self.__repo_asignari,self.__repoStudenti,self.__repoProblemeLaborator,self.__validator)
        self.__student1 = Student(1, "Marius", 215)
        self.__student2 = Student(2, "Ionut", 216)
        self.__student3 = Student(3, "David Posa", 67)
        self.__repoStudenti.add(self.__student1)
        self.__repoStudenti.add(self.__student2)
        self.__repoStudenti.add(self.__student3)

        self.__pb1 = ProblemaLaborator((1, 1), "Descriere interesanta", date(2019, 5, 14))
        self.__pb2 = ProblemaLaborator((1, 2), "Zece la Asc", date(2025, 8, 12))
        self.__pb3 = ProblemaLaborator((2, 1), "Trei la Fp", date(2025, 8, 15))
        self.__repoProblemeLaborator.add(self.__pb1)
        self.__repoProblemeLaborator.add(self.__pb2)
        self.__repoProblemeLaborator.add(self.__pb3)


        self.__service.add(1,1,(1,1),10)
        self.__service.add(2,2,(1,2),5)
        self.__service.add(3,3,(2,1))

        self.__asignare1 = AsignareNotareLaborator(1, self.__student1, self.__pb1)
        self.__asignare2 = AsignareNotareLaborator(2, self.__student2, self.__pb2)
        self.__asignare3 = AsignareNotareLaborator(3, self.__student3, self.__pb3)

    def test_add_asignare(self):
        self.assertEqual(len(self.__repo_asignari.get_all()),3)

    def test_get_all(self):
        self.assertEqual(self.__service.get_all(),[self.__asignare1,self.__asignare2,self.__asignare3])

    def test_find(self):
        rezultat = self.__service.find(1)
        self.assertEqual(rezultat,self.__asignare1)

    def test_remove(self):
        self.__service.remove(1)
        self.assertEqual(len(self.__service.get_all()),2)
        self.assertEqual(self.__repo_asignari.get_all(),[self.__asignare2,self.__asignare3])

    def test_update(self):
        self.__service.update(1,3,(2,1),7)
        rezultat = self.__service.find(1)
        self.assertEqual(rezultat.get_nota(),7)
        self.assertEqual(rezultat.get_problema_laborator(),self.__pb3)
        self.assertEqual(rezultat.get_student(),self.__student3)


    def test_genereaza_X_asignari(self):
        self.__service = ServiceAsignareNotareLaborator(self.__repo_asignari,self.__repoStudenti,self.__repoProblemeLaborator,self.__validator)
        self.__service.genereaza_x_asignari(150)
        self.assertEqual(len(self.__repo_asignari.get_all()),153)



class Rapoarte(TestCase):
    def setUp(self):
        self.__repo_probleme = RepositoryProblemeLaborator()
        self.__repo_asignari = RepositoryAsignareNotareLaborator()
        self.__repo_studenti = RepositoryStudenti()
        self.__validator_pb = ValideazaProblemaLaborator()
        self.__service_probleme = ServiceProblemeLaboratoare(self.__repo_probleme,self.__repo_asignari,self.__validator_pb)
        self.__validator_studenti = ValidatorStudent()
        self.__service_studenti = ServiceStudenti(self.__repo_studenti,self.__repo_asignari,self.__validator_studenti)
        self.__validator = ValidatorAsignareNotareLaborator()
        self.__service_asignari = ServiceAsignareNotareLaborator(self.__repo_asignari,self.__repo_studenti,self.__repo_probleme,self.__validator)
        self.__service_studenti.genereaza_X_studenti(15)
        self.__service_probleme.genereaza_X_probleme_laborator(3)
        self.__service_asignari.genereaza_x_asignari(45)


    def test_statistica_alfabetica(self):
        laboratoare = self.__service_probleme.get_all()
        lab1 = laboratoare[0]
        id_pb = lab1.get_id_problema_laborator()
        lista_ordonata = self.__service_asignari.ordoneaza_alfabetic(id_pb)
        for i in range(len(lista_ordonata)- 1):
            if lista_ordonata[i].get_nume_student() > lista_ordonata[i+1].get_nume_student():
                assert False

    def test_statistica_dupa_nota(self):
        laboratoare = self.__service_probleme.get_all()
        lab1 = laboratoare[0]
        id_pb = lab1.get_id_problema_laborator()
        lista_ordonata = self.__service_asignari.ordoneaza_dupa_nota(id_pb)
        for i in range(len(lista_ordonata)- 1):
            if lista_ordonata[i].get_nota() < lista_ordonata[i+1].get_nota():
                assert False

    def test_media_la_un_lab_sub_5(self):
        laboratoare = self.__service_probleme.get_all()
        id_lab = 1
        lista_sub_5 = self.__service_asignari.statistica_sub_5_la_lab(1)
        for dto_studenti in lista_sub_5:
            if dto_studenti.get_nota() >= 5:
                assert False


class test_fisier_repo_studenti(TestCase):
    def setUp(self):
        self.cale_fisier = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\studenti.txt'

        with open(self.cale_fisier, "w") as f:
            f.write("1,Octavian,214\n")
            f.write("2,David Posa,454\n")
            f.write("3,Prodea Octav,124\n")
            f.write("4,Raul Mirza,214\n")
            f.write("5,Buburuza,216\n")

        self.__repo_studenti = RepositoryFisiereStudenti(self.cale_fisier)

        self.__student1 = Student(1, "Octavian", 214)
        self.__student2 = Student(2, "David Posa", 454)
        self.__student3 = Student(3, "Prodea Octav", 124)
        self.__student4 = Student(4, "Raul Mirza", 214)
        self.__student5 = Student(5, "Buburuza", 216)



    def test_read_from_file(self):
        self.assertEqual(len(self.__repo_studenti.get_all()),5)
        rezultat = self.__repo_studenti.get_all()


        self.assertEqual(rezultat,[self.__student1,self.__student2,self.__student3,self.__student4,self.__student5])
        self.assertEqual(rezultat[0].get_nume_student() ,"Octavian")
        self.assertEqual(rezultat[0].get_id_student() ,1)
        self.assertEqual(rezultat[0].get_grupa_student() ,214)

    def test_add_to_file(self):
        student1 = Student( 6,"Adri cola", 206)
        student2 = Student( 7,"Adri Maria", 216)
        self.__repo_studenti.add(student1)
        self.__repo_studenti.add(student2)

    def test_remove_from_file(self):
        self.__repo_studenti.remove(1)
        rezultat = self.__repo_studenti.get_all()
        self.assertEqual(rezultat,[self.__student2,self.__student3,self.__student4,self.__student5])

    def test_update_from_file(self):
        student1_updatat = Student( 1,"Adriananana", 240)
        self.__repo_studenti.update(student1_updatat)
        rezultat = self.__repo_studenti.find(1)
        self.assertEqual(rezultat.get_nume_student() ,"Adriananana")
        self.assertEqual(rezultat.get_grupa_student() ,240)

class test_fisier_repo_probleme_laborator(TestCase):
    def setUp(self):
        self.__cale_fisier = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\probleme_laboratoare.txt'

        with open(self.__cale_fisier, "w") as f:
            f.write("1,1,Cainele mananca salam,2006,11,4\n")
            f.write("1,2,Ca boieru la volan conduc dacia logan,2025,4,12\n")
            f.write("2,1,Eu merg cu dacia iar tu pe jos,2014,4,9\n")
            f.write("2,2,Nu mor caii cand vor cainii,2002,4,16\n")

        self.__repo_pb = RepositoryFisierProblemeLaborator(self.__cale_fisier)

        self.__pb1 = ProblemaLaborator((1,1),"Cainele mananca salam",date(2006,11,4))
        self.__pb2 = ProblemaLaborator((1,2),"Ca boieru la volan conduc dacia logan",date(2025,4,12))
        self.__pb3 = ProblemaLaborator((2,1),"Eu merg cu dacia iar tu pe jos",date(2014,4,9))
        self.__pb4 = ProblemaLaborator((2,2),"Nu mor caii cand vor cainii",date(2002,4,16))


    def test_read_from_file(self):
        self.assertEqual(len(self.__repo_pb.get_all()),4)
        rezultat = self.__repo_pb.get_all()
        self.assertEqual(rezultat,[self.__pb1,self.__pb2,self.__pb3,self.__pb4])

    def test_add_to_file(self):
        pb_noua = ProblemaLaborator((1,3),"Octavian",date(2006,11,4))
        self.__repo_pb.add(pb_noua)
        self.assertEqual(len(self.__repo_pb.get_all()),5)

        repo_nou = RepositoryFisierProblemeLaborator(self.__cale_fisier)

        rezultat = repo_nou.get_all()

        self.assertEqual(len(rezultat), 5)
        self.assertEqual(rezultat[4].get_deadline_problema_laborator(),date(2006,11,4))

    def test_remove_from_file(self):
        self.__repo_pb.remove((1,1))
        rezultat = self.__repo_pb.get_all()
        self.assertEqual(rezultat,[self.__pb2,self.__pb3,self.__pb4])
        self.assertEqual(len(self.__repo_pb.get_all()),3)

    def test_update_from_file(self):
        pb1_updated = ProblemaLaborator((1,1),"Octavian",date(2006,11,4))
        self.__repo_pb.update(pb1_updated)
        rezultat = self.__repo_pb.find((1,1))
        self.assertEqual(rezultat.get_descriere_problema_laborator() ,"Octavian")
        self.assertEqual(rezultat.get_deadline_problema_laborator() ,date(2006,11,4))



class teste_fisier_asignari(TestCase):
    def setUp(self):
        self.__cale_fisier_pb = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\probleme_laboratoare.txt'

        self.__cale_fisier_studenti = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\studenti.txt'

        self.__cale_fisier_asignari = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\asignari.txt'

        with open(self.__cale_fisier_studenti, "w") as f:
            f.write("1,Marius,215\n")
            f.write("2,Ionut,216\n")
            f.write("3,David Posa,67\n")
            f.write("4,Darius,67\n")

        self.__repo_studenti = RepositoryFisiereStudenti(self.__cale_fisier_studenti)


        with open(self.__cale_fisier_pb, "w") as f:
            f.write("1,1,Descriere interesanta,2019,5,14\n")
            f.write("1,2,Zece la Asc,2025,8,12\n")
            f.write("2,1,Trei la Fp,2025,8,15\n")
            f.write("2,2,Nu mor caii cand vor cainii,2002,4,16\n")

        self.__repo_pb = RepositoryFisierProblemeLaborator(self.__cale_fisier_pb)

        with open(self.__cale_fisier_asignari,"w") as f:
            f.write("1,1,1,1,10\n")
            f.write("2,1,2,2,7\n")
            f.write("3,2,1,1,6\n")
            f.write("4,2,2,1,8\n")



        self.__repo_asignari = RepositoryFisierAsignareNotareLaborator(self.__cale_fisier_asignari, self.__repo_studenti,self.__repo_pb)

        self.__student1 = self.__repo_studenti.find(1)
        self.__pb1 = self.__repo_pb.find((1,1))
        self.__asignare1 = AsignareNotareLaborator(1,self.__student1,self.__pb1,10)

        self.__student2 = self.__repo_studenti.find(2)
        self.__pb2 = self.__repo_pb.find((1,2))
        self.__asignare2 = AsignareNotareLaborator(2,self.__student2,self.__pb2,7)

        self.__student3 = self.__repo_studenti.find(3)
        self.__pb3 = self.__repo_pb.find((2,1))
        self.__asignare3 = AsignareNotareLaborator(3,self.__student3,self.__pb3,6)

        self.__student4 = self.__repo_studenti.find(4)
        self.__pb4 = self.__repo_pb.find((2,2))
        self.__asignare4 = AsignareNotareLaborator(4,self.__student4,self.__pb4,8)

    def test_read_from_file(self):
        rezultat = self.__repo_asignari.get_all()

        self.assertEqual(len(rezultat), 4)
        self.assertEqual(rezultat, [
            self.__asignare1,
            self.__asignare2,
            self.__asignare3,
            self.__asignare4
        ])

    def test_adauga(self):
        asignare_noua = AsignareNotareLaborator(5,self.__student3,self.__pb1,2)
        self.__repo_asignari.add(asignare_noua)
        self.assertEqual(len(self.__repo_asignari), 5)
        rezultat = self.__repo_asignari.find(5)
        self.assertEqual(rezultat.get_student(),self.__student3 )
        self.assertEqual(rezultat.get_problema_laborator(),self.__pb1 )
        self.assertEqual(rezultat.get_nota(),2 )

        self.__repo_asignari = RepositoryFisierAsignareNotareLaborator(self.__cale_fisier_asignari,self.__repo_studenti,self.__repo_pb)
        self.assertEqual(len(self.__repo_asignari.get_all()),5)


    def test_sterge(self):
        self.__repo_asignari.remove(1)
        self.assertEqual(len(self.__repo_asignari), 3)
        self.assertEqual(self.__repo_asignari.get_all(),[self.__asignare2,self.__asignare3,self.__asignare4])

    def test_update(self):
        asignare1_noua = AsignareNotareLaborator(1,self.__student2,self.__pb1,4)
        self.__repo_asignari.update(asignare1_noua)
        rezultat = self.__repo_asignari.find(1)
        self.assertEqual(rezultat.get_nota(),asignare1_noua.get_nota())
        self.assertEqual(rezultat.get_student(),self.__student2 )
        self.assertEqual(rezultat.get_problema_laborator(),self.__pb1 )

