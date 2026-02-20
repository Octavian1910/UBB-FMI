from domain.problema_laborator import ProblemaLaborator
from domain.student import Student
from domain.validators.validator_exceptions import ValidatorExceptions

class ValidatorAsignareNotareLaborator():

    def valideaza(self,asignare_notare_laborator):
        """
        Metoda valideaza o asignare/notare laborator
        :param asignare_notare_laborator: un obiect de tip asignare notare laborator
        :return: -
        :raises: ValidationException daca ceva nu este ok
        """
        erori = []
        try:
            if int(asignare_notare_laborator.get_id_asignare()) < 0 :
                erori.append("Id ul trebuie sa fie pozitiv!\n")
        except ValueError:
            erori.append("Id ul trb sa fie numar!\n")

        if not isinstance(asignare_notare_laborator.get_student(),Student):
            erori.append("Studentul nu este un obiect de tip student!\n")

        if not isinstance(asignare_notare_laborator.get_problema_laborator(),ProblemaLaborator):
            erori.append("Problema laborator nu este un obiect de tip problema laborator!\n")

        try:
            if float(asignare_notare_laborator.get_nota()) < 0:
                erori.append("Nota trb sa fie pozitiva\n")
        except ValueError:
            erori.append("Nota trb sa fie numar!\n")

        if len(erori) > 0:
            raise ValidatorExceptions(erori)