from Repository.RepositoryMelodii import RepositoryMelodiiFisier
from domain.validator.validator_melodie import ValidatorMelodie
from service.ServiceMelodii import ServiceMelodii
from teste.teste import Teste
from UI.console import Console

test = Teste()
test.ruleaza_toate_testele()

cale_fisier = r'C:\Users\octav\Desktop\examen fp\melodii'
repo = RepositoryMelodiiFisier(cale_fisier)
validator = ValidatorMelodie()
service = ServiceMelodii(repo,validator)

consola = Console(service)
consola.run()
