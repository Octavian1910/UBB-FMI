DOCUMENTATIE PROIECT - LABORATOR 3 (Retea de socializare)


1. FUNCTIONAREA FACTORY-ULUI SI TRANZITIA LA BAZA DE DATE (LABORATORUL 4)
---
- RepositoryFactory (Simple Factory) este singura clasa din aplicatie
  care cunoaste implementarile concrete de repository (InMemoryRepository,
  UserFileRepository/FriendShipFileRepository, UserDbRepository/FriendShipDbRepository).
- Tipul persistenței (MEMORY, FILE, DATABASE) si parametrii de conectare/fisiere
  sunt incarcati la runtime din "resources/config.properties" folosind java.util.Properties.
- Service-urile, Consola si clasa Main depind exclusiv de interfata generica
  Repository<ID, E>, fara a folosi operatorul "new" pe clase concrete de repository.
- Pentru trecerea la baza de date la Laboratorul 4:
  1) Se va schimba in config.properties: "repository.type=DATABASE".
  2) Se va implementa codul JDBC in metodele claselor schelet existente
     (UserDbRepository si FriendShipDbRepository).
  3) Straturile Service, UI (Console) si Main vor ramane 100% NESCHIMBATE.

Discutie OCP (Simple Factory vs Abstract Factory):
- Varianta aleasa (Simple Factory cu switch pe enum) este directa si simpla,
  insa la adaugarea unui nou tip de persistenta necesita modificarea switch-ului
  (incalca partial Open-Closed Principle).
- Alternativa (Abstract Factory cu o interfata Factory si implementari precum
  FileRepositoryFactory, DbRepositoryFactory) respecta strict OCP (adaugarea unui
  mecanism nou se face prin adaugarea unei clase noi, fara modificare de cod existent),
  dar creste numarul de clase si complexitatea initiala a proiectului.

2. GESTIUNEA FISIERULUI LIPSĂ SI A LINIILOR CORUPTE

- Fisier inexistent: Daca fisierul configurat nu exista la pornirea aplicatiei,
  AbstractFileRepository nu arunca eroare; aplicatia porneste cu un repository gol,
  iar fisierul este creat automat la prima operatie de salvare (add).
- Linii corupte / invalide: In metoda loadFromFile(), fiecare linie este citita
  si validata individual intr-un bloc try-catch. Daca o linie contine date invalide
  (numar incorect de campuri, ID ne-numeric, format data ISO invalid etc.),
  linia respectiva este raportata in System.err cu numarul liniei si motivul,
  fiind ignorata. Am ales ignorarea liniilor corupte (in loc de oprirea aplicatiei)
  pentru a asigura disponibilitatea aplicatiei si recuperarea datelor valide ramase.

3. PRINCIPII DE PROIECTARE (SOLID) APLICATE

- Single Responsibility Principle (SRP):
  * Domain entities (User, FriendShip) pastreaza doar datele si identitatea.
  * UserValidator / FriendShipValidator se ocupa exclusiv de regulile de validare.
  * AbstractFileRepository gestioneaza exclusiv I/O-ul pe disc.
  * UserService / FriendShipService coordoneaza logica de afaceri.
  * NetworkService raspunde exclusiv de algoritmii pe graf (DFS, BFS).
  * Console se ocupa doar de I/O cu utilizatorul.
  * Main doar asambleaza dependintele aplicatiei.
- Open-Closed Principle (OCP):
  * Adaugarea de validari noi sau tipuri noi de stocare se face prin extinderea
    interfetelor Validator<T> si Repository<ID, E>, fara modificarea codului client.
- Liskov Substitution Principle (LSP):
  * Orice clasa care mosteneste AbstractFileRepository sau InMemoryRepository poate
    fi substituita in locul interfetei Repository<ID, E> fara a afecta corectitudinea aplicatiei.
- Dependency Inversion Principle (DIP):
  * Modulele de nivel inalt (Services, UI) nu depind de modulele de nivel jos (File Repositories),
    ci ambele depind de abstractiuni (Repository<ID, E>, Validator<T>).

4. SABLOANE DE PROIECTARE (DESIGN PATTERNS)

- Factory Pattern (Simple Factory): Incapsulat in RepositoryFactory pentru crearea
  instantei corespunzatoare de Repository pe baza fisierului de configurare.
- Template Method Pattern: In AbstractFileRepository, unde scheletul algoritmului
  de citire/scriere (loadFromFile, writeToFile) este definit in clasa parinte,
  iar pasii variabili de serializare/deserializare sunt delegati metodelor abstracte
  extractEntity(String) si createEntityAsString(E) implementate in subclase.
- Strategy Pattern: Interfata Validator<T> defineste strategia de validare,
  implementata concret de UserValidator si FriendShipValidator si injectata in servicii.
- Decorator Pattern: Utilizat la operatiile de I/O prin impachetarea fluxurilor pe caractere:
  BufferedReader peste FileReader si BufferedWriter peste FileWriter pentru eficienta I/O.