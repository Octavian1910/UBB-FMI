from datetime import date

from domain.validator.validator_exception import ValidatorException


class ValidatorMelodie:

    def valideaza(self,melodie):
        """
        Valideaza daca melodia este ok
        :param melodie: un obiect de tip melodie
        :return: -
        :raises: ValidationException daca melodia nu este ok
        """
        # Melodie(titlu,artist,gen,data_aparitie)
        erori = ""
        try :
            if melodie.get_titlu().strip() == "":
                erori += "Titlul este gol!\n"
            if melodie.get_artist().strip() == "":
                erori += "Artistul este gol!\n"

            gen = melodie.get_gen()
            genuri = ["Rock","Jazz","Pop"]
            if gen not in genuri:
                erori += "Genul nu este bun!\n"
            data_azi =  date.today()
            if melodie.get_data() > data_azi:
                erori += "Data nu este buna!\n"
        except Exception as e:
            erori += str(e)

        if len(erori) > 0:
            raise ValidatorException(erori)

