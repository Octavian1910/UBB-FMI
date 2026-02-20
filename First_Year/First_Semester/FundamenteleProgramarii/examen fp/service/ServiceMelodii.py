import random

from Repository.RepositoryException import RepositoryException
from domain.validator.validator_exception import ValidatorException
from service.ServiceException import ServiceException
from domain.melodie import Melodie
from datetime import date

class ServiceMelodii:

    def __init__(self,repo,validator):
        """
        Constructor
        :param repo: RepositoryMelodieFisier
        :param validator: ValidatorMelodie
        """
        self.__repo = repo
        self.__validator = validator

    # Melodie(titlu,artist,gen,data_aparitie)
    def update(self,titlu,artist,gen,data):
        """
        Initiaza update
        :param titlu: un string nevid
        :param artist: un string nevid
        :param gen: unul dintr Rock Jazz Pop
        :param data: un date care este mai mic decat data de azi
        :return: -
        """
        m1 = Melodie(titlu,artist,gen,data)
        try:
            self.__validator.valideaza(m1)
            self.__repo.update(m1)
        except (ValidatorException,RepositoryException) as e:
            raise ServiceException(e)

    def get_all(self):
        """
        Initiaza returnarea o lista cu toate melodiile
        :return: o lista cu toate melodiile
        """
        return self.__repo.get_all()

    def genereaza_melodii(self,nr_melodii,titluri,artisti):
        """
        Metoda genereaza x melodii
        :param nr_melodii: un int
        :param titluri: un string cu titluri separate prin virgula
        :param artisti: un string cu artisti separati prin virgula
        :return: nr melodii_adaugate
        """
        lista_titluri = self.__imparte_stringul(titluri)
        lista_artisti = self.__imparte_stringul(artisti)
        nr_generari_maxime = (len(lista_titluri)) * (len(lista_artisti))
        se_vor_genera = min(nr_generari_maxime,nr_melodii)
        for i in range(se_vor_genera):
            while True:
                titlu = random.choice(lista_titluri)
                artist = random.choice(lista_artisti)
                lista_gen = ["Rock","Pop","Jazz"]
                gen = random.choice(lista_gen)
                an = random.randint(2000,2025)
                luna = random.randint(2,11)
                zi = random.randint(1,25)
                data = date(an,luna,zi)
                m1 = Melodie(titlu,artist,gen,data)
                try:
                    self.__validator.valideaza(m1)
                    self.__repo.add(m1)
                    break
                except (ValidatorException,RepositoryException) as e:
                    continue
        return se_vor_genera


    def __imparte_stringul(self,text):
        """
        Separa elementele din text care sunt separate prin virgula si el pune in lista
        :param text: un string nevid
        :return: o lista cu elementele separate
        """
        rezultat = []
        cheie = {}
        if text.strip() == "":
            raise ServiceException("Stringul este vid!")
        try:
            elemente = text.strip().split(",")
            for element in elemente:
                if element not in cheie.keys():
                    cheie[element] = element
        except Exception:
            raise ServiceException("Ceva nu este bine!")
        for el in cheie.values():
            rezultat.append(el)
        return rezultat


    def statistici(self):
        """
        Afla cea mai veche si cea mai noua melodie
        Nr de melodii per gen
        Artistul cu cele mai multe melodii
        :return: un string cu informatiile cerute
        """
        melodii = self.__repo.get_all()
        oldest_melody = melodii[0].get_data()
        newest_melody = melodii[0].get_data()
        text_oldest = f"{melodii[0].get_titlu()}"
        text_newest = f"{melodii[0].get_titlu()}"
        genuri = {"Rock" : 0,
                  "Jazz" : 0,
                  "Pop" : 0
                  }
        artisti = {}
        #cea mai noua si cea mai veche piesa
        for melodie in melodii:

            if melodie.get_data() <= oldest_melody:
                text_oldest = f"{melodie.get_titlu()}"
                oldest_melody = melodie.get_data()

            if melodie.get_data() >= newest_melody:
                text_newest = f"{melodie.get_titlu()}"
                newest_melody = melodie.get_data()

            if melodie.get_gen() in genuri.keys():
                genuri[melodie.get_gen()] += 1

            if melodie.get_artist() in artisti.keys():
                artisti[melodie.get_artist()] += 1
            else:
                artisti[melodie.get_artist()] = 1

        nr_gen_rock = genuri['Rock']
        nr_gen_pop = genuri['Pop']
        nr_gen_jazz = genuri['Jazz']
        artistul_cu_cele_mai_multe_melodii = ""
        nr_piese = 0
        for artist in artisti.keys():
            if artisti[artist] > nr_piese:
                artistul_cu_cele_mai_multe_melodii = artist
                nr_piese = artisti[artist]

        text = f"Cea mai veche melodie : {text_oldest} \nCea mai noua melodie : {text_newest} \nNr per gen : \nRock : {nr_gen_rock}\nPop : {nr_gen_pop}\nJazz : {nr_gen_jazz}\nArtistul cu cele mai multe piese este : {artistul_cu_cele_mai_multe_melodii} cu {nr_piese} piese.\n"
        return text










