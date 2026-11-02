Documentatie Lab - Retea de socializare

1. Factory si configurare
- In RepositoryFactory citesc tipul de repo din config.properties (MEMORY, FILE, DB).
- Am folosit un Map cu Supplier (ex: InMemoryRepository::new sau lambda) ca sa nu mai fac switch clasic. Repository-ul se instantiaza doar cand apelez metoda de create.
- Daca vreau sa adaug un repo nou, doar il trec in map-ul de suppliers si nu trebuie sa modific restul aplicatiei.

2. Gestionare fisiere si erori
- Daca fisierul text nu exista cand porneste aplicatia, nu dau crash. Verific cu Files.exists(), iar daca lipseste, aplicatia pleaca cu repo-ul gol. Fisierul se creaza automat la primul add() prin Files.createDirectories() si Files.write().
- Pentru linii corupte (date aiurea, format gresit, id-uri care nu-s numere), am pus try-catch in forEach. Daca o linie crapa la parsare, se afiseaza un mesaj de eroare in consola si se trece mai departe, ca sa nu pierdem restul datelor valide.

3. SOLID si Design Patterns
- SRP: User/FriendShip tin datele, validatorii doar verifica, AbstractFileRepository se ocupa de fisiere, serviciile au logica de business, iar Console doar afiseaza.
- OCP: Pot adauga usor reguli noi de validare sau tipuri de repo fara sa rescriu codul existent.
- LSP: Orice repo concret poate inlocui direct interfata Repository peste tot in proiect.
- ISP: Interfetele sunt mici si contin doar ce trebuie (Entity, Validator, Repository).
- DIP: Serviciile depind doar de interfetele Repository si Validator, nu de clase concrete.
- Patterns:
  * Factory: RepositoryFactory pentru crearea repo-urilor.
  * Template Method: in AbstractFileRepository (loadFromFile si writeToFile sunt scheletul, iar clasele copil implementeaza extractEntity si createEntityAsString).
  * Strategy: interfata Validator cu implementarile UserValidator si FriendShipValidator.

4. Modificari cu Stream API si Functional
- In UserValidator si FriendShipValidator am facut un record intern ValidationRule(Predicate, String):
  * L-am folosit ca sa leg conditia de mesajul de eroare intr-un mod imutabil si scurt, fara boilerplate (fara getteri, equals etc.).
  * In validate() parcurg lista de reguli cu stream(): filtrez ce nu respecta predicatul, iau mesajul de eroare cu map() si le strang intr-o lista cu toList(). Nu mai am niciun if si niciun StringBuilder.
- In interfata Repository am pus o metoda default findAll(Predicate filter) care filtreaza entitatile direct cu Stream.
- In FriendShipService am inlocuit buclele pentru extragerea prietenilor cu stream(), filter(), map() si toList().
- In NetworkService am folosit stream() cu max() si comparator pentru a gasi cea mai sociabila comunitate.

Unde am inlocuit cod vechi cu Stream:
- Citire fisiere: in loc de BufferedReader si while(readLine), am folosit Files.lines() cu filter() si forEach().
- Scriere fisiere: in loc de BufferedWriter si for clasic, am folosit Files.write() cu entities.values().stream().map().toList().
- Validari: in loc de if-uri multe si StringBuilder, am folosit lista de reguli cu stream().filter().map().toList().
- Extragere prieteni: in loc de for si if, am pus repository.findAll().stream().filter().map().toList().
- Teste: in loc de 6 linii de try-catch pentru fiecare eroare asteptata, am facut metoda assertThrows() cu lambda intr-o singura linie.

De ce am pastrat bucle clasice in NetworkService:
- In getDistance() (algoritmul BFS): avem o coada (Queue) din care scoatem si adaugam noduri in timp ce o parcurgem. Coada variaza mereu ca dimensiune, deci un while (!queue.isEmpty()) este mult mai clar, natural si eficient decat daca as fi fortat un Stream.
- In getLongestPathInCommunity(): parcurg toate perechile de noduri cu doua bucle for clasice pentru ca e simplu de urmarit si nu creeaza obiecte inutile in memorie.