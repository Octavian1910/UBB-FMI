from domain.asignare_notare_laborator import AsignareNotareLaborator
from repository.repository_exceptions import RepositoryException


class RepositoryAsignareNotareLaborator:
    def __init__(self):
        self.__repo = {}

    def add(self,asignare_notare_laborator):
        """
        Metoda adauga in repo o problema laborator
        :param asignare_notare_laborator: un obiect de tip asignare notare
        :return: -
        """
        self.__repo[asignare_notare_laborator.get_id_asignare()] = asignare_notare_laborator

    def get_all(self):
        """
        Functia returneaza o lista cu toate asignarile
        :return: o lista cu toate asignarile
        """
        return list(self.__repo.values())

    def find(self,id_asignare):
        """
        Functia returneaza asignarea dorita in functie de id
        :param id_asignare: un int pozitiv
        :return: asignarea dorita
        """
        if not id_asignare in self.__repo:
            raise RepositoryException("Id ul nu s a gasit!")
        return self.__repo[id_asignare]

    def remove(self,id_asignare):
        """
        Functia sterge asignarea cu id_asignare
        :param id_asignare: un int pozitiv
        :return:-
        :raises: RepositoryException daca nu exista
        """
        if not id_asignare in self.__repo:
            raise RepositoryException("Id ul nu s a gasit!")

        self.__repo.pop(id_asignare)

    def remove_by_id_student(self,id_student):
        """
        Metoda sterge si asignarile daca un student e sters
        :param id_student: un int pozitiv reprezentand id ul studentului
        :return: -
        """
        asignari = self.get_all()
        lista_de_sters = []
        for asignare in asignari:
            if asignare.get_student().get_id_student() == id_student:
                lista_de_sters.append(asignare.get_id_asignare())

        for id_asignare in lista_de_sters:
            self.remove(id_asignare)


    def remove_by_id_pb(self,id_pb):
        """
        Functia sterge din repo pb
        :param id_pb: un tuple
        :return:
        """
        asignari = self.get_all()
        lista_de_sters = []
        for asignare in asignari:
            if asignare.get_problema_laborator().get_id_problema_laborator() == id_pb:
                lista_de_sters.append(asignare.get_id_asignare())

        for id_asignare in lista_de_sters:
            self.remove(id_asignare)



    def update(self,asignare_notare_laborator):
        """
        Da update la asignare notare laborator
        :return:-
        :raises: RepositoryException daca nu exista
        """
        if not asignare_notare_laborator.get_id_asignare() in self.__repo:
            raise RepositoryException("Id ul nu s a gasit!")
        self.__repo[asignare_notare_laborator.get_id_asignare()] = asignare_notare_laborator

    def __len__(self):
        """
        Suprascrie len
        :return: un int reprezentand cate elem sunt in repo
        """
        return len(self.__repo.keys())



class RepositoryFisierAsignareNotareLaborator(RepositoryAsignareNotareLaborator):
    def __init__(self,cale_fisier,repo_studenti,repo_probleme_laboratoare):
        super().__init__()
        self.__cale_fisier = cale_fisier
        self.__repo_studenti = repo_studenti
        self.__repo_probleme_laboratoare = repo_probleme_laboratoare
        self.__citeste_din_fisier()


    def __citeste_din_fisier(self):
        try:
            with open(self.__cale_fisier,"r") as fisier:
                linii = fisier.readlines()
                for linie in linii:
                    parti = linie.split(',')
                    id_asignare = int(parti[0])
                    id_student = int(parti[1])
                    id_laborator = int(parti[2])
                    id_problema = int(parti[3])
                    id_pb = (id_laborator, id_problema)
                    nota = float(parti[4])
                    try:
                        student = self.__repo_studenti.find(id_student)
                        pb = self.__repo_probleme_laboratoare.find(id_pb)
                    except RepositoryException:
                        continue
                    asignare = AsignareNotareLaborator(id_asignare,student,pb, nota)
                    super().add(asignare)
        except IOError:
            raise RepositoryException("Nu s a putut citi din fisierul : " + self.__cale_fisier)



    def __scrie_in_fisier(self):
        try:
            with open(self.__cale_fisier,"w") as fisier:
                asignari = super().get_all()
                for asignare in asignari:
                    id_nota = asignare.get_id_asignare()
                    student_id = asignare.get_student().get_id_student()
                    id_lab = asignare.get_problema_laborator().get_id_laborator()
                    id_pb = asignare.get_problema_laborator().get_id_problema()
                    nota = asignare.get_nota()
                    text = f"{id_nota},{student_id},{id_lab},{id_pb},{nota}\n"
                    fisier.write(text)
        except IOError:
            raise RepositoryException("Nu s a putut scrie in fisierul : " + self.__cale_fisier)



    def add(self,asignare):
        """
        Adauga o asignare in fisier
        :param asignare: un obiect de tip asignare
        :return: -
        """
        super().add(asignare)
        self.__scrie_in_fisier()

    def remove(self,id_asignare):
        """
        Sterge o asignare din fisier
        :param id_asignare: un int
        :return: -
        """
        super().remove(id_asignare)
        self.__scrie_in_fisier()

    def update(self,asignare):
        """
        Da update la o asignare din fisier
        :param asignare: o asignare
        :return: -
        """
        super().update(asignare)
        self.__scrie_in_fisier()

