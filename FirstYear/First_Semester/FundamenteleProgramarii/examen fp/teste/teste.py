from datetime import date

from Repository.RepositoryException import RepositoryException
from Repository.RepositoryMelodii import RepositoryMelodii, RepositoryMelodiiFisier
from domain.melodie import Melodie
from domain.validator.validator_exception import ValidatorException
from domain.validator.validator_melodie import ValidatorMelodie
from service.ServiceException import ServiceException
from service.ServiceMelodii import ServiceMelodii


class Teste:

    def ruleaza_toate_testele(self):
        self.__teste_entitate()
        self.__teste_validator()
        self.__teste_repo()
        self.__setUp_fisier()
        self.__teste_repo_fisier()
        self.__setUp_fisier()
        self.__teste_service()
        self.__setUp_fisier()
        self.__teste_statistici()
        print("Testele au fost rulate cu succes!")


    def __teste_entitate(self):
        #Melodie(titlu,artist,gen,data_aparitie)
        m1 = Melodie("Vorbeste Vinul","Bitza","Pop",date(2006,12,4))

        assert m1.get_titlu() == "Vorbeste Vinul"
        assert m1.get_artist() == "Bitza"
        assert m1.get_gen() == "Pop"
        assert m1.get_data() == date(2006,12,4)
        assert m1.get_id() == (m1.get_titlu(),m1.get_artist())

    def __teste_validator(self):
        validator = ValidatorMelodie()

        m1 = Melodie("Vorbeste Vinul", "Bitza", "Pop", date(2006, 12, 4))
        m_invalid = Melodie("", "", "Altceva", date(2027, 12, 4))

        validator.valideaza(m1)
        try:
            validator.valideaza(m_invalid)
            assert False
        except ValidatorException as e:
            assert str(e) == """Titlul este gol!\nArtistul este gol!\nGenul nu este bun!\nData nu este buna!\n"""

        m_f_gresit = Melodie(123,456,79,456)
        try:
            validator.valideaza(m_f_gresit)
            assert False
        except ValidatorException:
            assert True

    def __teste_repo(self):
        m1 = Melodie("Vorbeste Vinul", "Bitza", "Pop", date(2006, 12, 2))
        m2 = Melodie("x6", "MGK", "Jazz", date(2026, 1, 4))
        m3 = Melodie("Phonk", "Idk", "Rock", date(2014, 12, 5))
        repo = RepositoryMelodii()
        repo.add(m1)
        repo.add(m2)
        repo.add(m3)
        rez = repo.get_all()
        assert len(rez) == 3
        rez2 = repo.find(m1.get_id())
        assert rez2 == m1

    def __setUp_fisier(self):
        text = "Vorbeste Vinul,Bitza,Pop,12,4,2006\nSunete,Petre Stefan,Pop,13,5,2012\nAmazing,Inna,Jazz,14,6,2018\nDessert Rain,Tom,Rock,12,5,2022\nMissing,Tom,Jazz,12,7,2023\nBuletin,Smiley,Pop,10,10,2010\nSirenele,Andra Gogan,Rock,12,5,2015\nMasini,Bogdan,Pop,11,2,2016\nAvioane,Ilie,Jazz,12,3,2015\nMotociclete,Razvan,Rock,12,3,2025\n"
        cale_fisier = r'C:\Users\octav\Desktop\examen fp\melodii_teste'
        with open(cale_fisier,'w') as f:
            f.write(text)

    def __teste_repo_fisier(self):
        cale_fisier = r'C:\Users\octav\Desktop\examen fp\melodii_teste'
        repo = RepositoryMelodiiFisier(cale_fisier)
        rez = repo.get_all()
        assert len(rez) >= 10
        """
        for el in rez:
            print(el)
        """

        m1 = Melodie("Vorbeste Vinul","Bitza","Rock",date(2005,4,12))
        repo.update(m1)
        id = ("Vorbeste Vinul","Bitza")
        rez2 = repo.find(id)
        assert rez2.get_gen() == "Rock"
        assert rez2.get_data() == date(2005,4,12)
        rez3 = repo.get_all()
        m2 = Melodie("Vorbeste Vinul","Bitza","Rock",date(2005,4,12))

        try :
            repo.add(m2)
            assert False
        except RepositoryException:
            assert True

        m3 = Melodie("Vorbeste Vinul12", "Bitza12", "Rock", date(2005, 4, 12))
        repo.add(m3)
        rez4 = repo.get_all()
        assert len(rez4) == len(rez3) + 1


    def __teste_service(self):
        cale_fisier = r'C:\Users\octav\Desktop\examen fp\melodii_teste'
        repo = RepositoryMelodiiFisier(cale_fisier)
        validator = ValidatorMelodie()
        service = ServiceMelodii(repo,validator)

        titluri = "Vara,Toamna,Primava,Eu,Si,Iarna,Sunt,Pe,Val"
        artisti = "Ariana,Adriana,Octavian,George,Ionut,David"
        service.genereaza_melodii(150,titluri,artisti)

        titluri = "as5da6dca6d4aef864ew8f1asc32_-0!@#$%^&*("
        artisti = ""
        try:
            service.genereaza_melodii(150,titluri,artisti)
            assert False
        except (ServiceException,RepositoryException,ValidatorException):
            assert True

        titluri = "a, s, d, f, w, s, f, fd, s, d, sd, as, f, adsf, ad, asd"
        artisti = "a, s, d, d, s, s, w, r"
        service.genereaza_melodii(100,titluri,artisti)

    def __teste_statistici(self):
        cale_fisier = r'C:\Users\octav\Desktop\examen fp\melodii_teste'
        repo = RepositoryMelodiiFisier(cale_fisier)
        validator = ValidatorMelodie()
        service = ServiceMelodii(repo, validator)


