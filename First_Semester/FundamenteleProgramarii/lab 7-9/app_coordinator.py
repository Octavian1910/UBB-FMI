from domain.validators.validator_asignare_notare_laborator import ValidatorAsignareNotareLaborator
from domain.validators.validator_student import ValidatorStudent
from repository.repository_asignare_notare_laborator import RepositoryAsignareNotareLaborator, \
    RepositoryFisierAsignareNotareLaborator
from repository.repository_probleme_laboratoare import RepositoryProblemeLaborator, RepositoryFisierProblemeLaborator
from repository.repository_studenti import RepositoryStudenti, RepositoryFisiereStudenti
from service.service_asignare_notare_laborator import ServiceAsignareNotareLaborator
from service.service_probleme_laboratoare import ServiceProblemeLaboratoare
from service.service_studenti import ServiceStudenti
from domain.validators.validator_problema_laborator import ValideazaProblemaLaborator
from UI.console import Console

print("==" * 15)
print("1)MEMORIE")
print("2)FISIERE")
print("==" * 15)
comanda = int(input("Comanda : "))

if comanda == 1:
    repoStudenti = RepositoryStudenti()
    repoProblemeLaboratoare = RepositoryProblemeLaborator()
    repoAsignareNotareLaborator = RepositoryAsignareNotareLaborator()

    validatorStudenti = ValidatorStudent()
    validatorProblemeLaboratoare = ValideazaProblemaLaborator()
    validatorAsignari = ValidatorAsignareNotareLaborator()


    serviceStudenti = ServiceStudenti(repoStudenti,repoAsignareNotareLaborator,validatorStudenti)
    serviceProblemeLaboratoare = ServiceProblemeLaboratoare(repoProblemeLaboratoare,repoAsignareNotareLaborator,validatorProblemeLaboratoare)
    serviceAsignari = ServiceAsignareNotareLaborator(repoAsignareNotareLaborator,repoStudenti,repoProblemeLaboratoare,validatorAsignari)


    console = Console(serviceStudenti,serviceProblemeLaboratoare,serviceAsignari)
    console.run()

if comanda == 2:
    cale_fisier_studenti = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\studenti.txt'
    cale_fisier_pb = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\probleme_laboratoare.txt'
    cale_fisier_asignari = r'C:\Users\octav\Desktop\Facultate\FundamenteleProgramarii\laboratoare\refacere_de_la_0_lab 7-9\asignari.txt'
    repoStudenti = RepositoryFisiereStudenti(cale_fisier_studenti)
    repoProblemeLaboratoare = RepositoryFisierProblemeLaborator(cale_fisier_pb)
    repoAsignareNotareLaborator = RepositoryFisierAsignareNotareLaborator(cale_fisier_asignari,repoStudenti,repoProblemeLaboratoare)

    validatorStudenti = ValidatorStudent()
    validatorProblemeLaboratoare = ValideazaProblemaLaborator()
    validatorAsignari = ValidatorAsignareNotareLaborator()

    serviceStudenti = ServiceStudenti(repoStudenti,repoAsignareNotareLaborator, validatorStudenti)
    serviceProblemeLaboratoare = ServiceProblemeLaboratoare(repoProblemeLaboratoare,repoAsignareNotareLaborator, validatorProblemeLaboratoare)
    serviceAsignari = ServiceAsignareNotareLaborator(repoAsignareNotareLaborator, repoStudenti, repoProblemeLaboratoare,
                                                     validatorAsignari)

    console = Console(serviceStudenti, serviceProblemeLaboratoare, serviceAsignari)
    console.run()

