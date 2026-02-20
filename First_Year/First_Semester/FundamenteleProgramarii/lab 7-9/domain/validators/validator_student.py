from domain.validators.validator_exceptions import ValidatorExceptions
class ValidatorStudent:
    def valideaza(self,student):
        """
        Valideaza daca datele sunt ok pt a crea un obiect de tip student
        :param student: un obiect de tip student
        :return:-
        :raises: ValidationException daca nu e ok
        """
        erori = []
        try :
            if int(student.get_id_student()) < 0 :
                erori.append("Id ul studentului este un numar negativ!\n")
        except Exception :
            erori.append("Id ul studentului nu este de tip numar!\n")
        try :
            if student.get_nume_student().strip() == "":
                erori.append("Numele este vid!\n")
            for caracter in student.get_nume_student():
                if caracter in "1234567890":
                    erori.append("Numele contine cifre!\n")
        except Exception :
            erori.append("Numele contine cifre!\n")
        try :
            if int(student.get_grupa_student()) < 0:
                erori.append("Grupa studentului trebuie sa fie un numar pozitiv!\n")
        except Exception :
            erori.append("Grupa nu este de tip numar!\n")

        if len(erori)>0 :
            raise ValidatorExceptions(erori)



