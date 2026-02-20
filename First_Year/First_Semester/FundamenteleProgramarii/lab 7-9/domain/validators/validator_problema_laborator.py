from datetime import date

from domain.problema_laborator import ProblemaLaborator
from domain.validators.validator_exceptions import ValidatorExceptions


class ValideazaProblemaLaborator:

    def valideaza(self,problema_laborator):
        """
        Functia valideaza problema laborator
        :param problema_laborator:
        :return:
        """
        erori = []

        id_laborator = problema_laborator.get_id_problema_laborator()
        if not isinstance(id_laborator,tuple):
            erori.append("Id ul problemei nu este un tuple!\n")
        elif len(id_laborator) != 2 :
            erori.append("Id ul laboratorului nu contine 2 elemente!\n")
        else :
            try :
                if int(problema_laborator.get_id_laborator()) < 0 :
                    erori.append("Id ul laboratului este negativ!\n")
            except Exception :
                erori.append("Id ul laboratului nu este un numar!\n")

            try :
                if int(problema_laborator.get_id_problema()) < 0 :
                    erori.append("Id ul problemei este negativ!\n")
            except Exception :
                erori.append("Id ul problemei nu este un numar!\n")

        try:
            if problema_laborator.get_descriere_problema_laborator().strip() == "":
                erori.append("Descrierea problemei este goala!\n")
        except Exception :
            erori.append("Descrierea problemei nu este string!\n")

        if not isinstance(problema_laborator.get_deadline_problema_laborator(),date):
            erori.append("Deadline problemei nu este o data!\n")

        if len(erori) > 0 :
            raise ValidatorExceptions(erori)