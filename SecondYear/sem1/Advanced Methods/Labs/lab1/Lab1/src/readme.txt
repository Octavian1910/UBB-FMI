README - Laborator 1

1. Descriere

Problema presupune citirea din linia de comanda a unei expresii formate din
numere complexe si un operator. Numerele complexe sunt de forma a + b*i,
iar operatorul poate fi +, -, * sau /.

Programul trebuie sa verifice daca expresia introdusa este valida si, daca este
valida, sa calculeze si sa afiseze rezultatul.

Exemplu:

2 + 3*i + 5 - 6*i + -2 + i

Pentru aceasta expresie se foloseste operatorul '+' intre numerele complexe,
iar rezultatul este:

5 - 2*i


2. Structura aplicatiei

Am ales sa impart aplicatia in mai multe clase, fiecare avand o responsabilitate
cat mai clara.

- Complex - reprezinta un numar complex si contine partea reala si partea
  imaginara. Clasa contine metode pentru obtinerea acestor valori si pentru
  afisarea numarului.

- Operation - este o interfata care defineste metoda execute(). Toate operatiile
  matematice implementeaza aceasta interfata.

- AddOperation - realizeaza adunarea a doua numere complexe.

- SubtractOperation - realizeaza scaderea a doua numere complexe.

- MultiplyOperation - realizeaza inmultirea a doua numere complexe.

- DivideOperation - realizeaza impartirea a doua numere complexe.

- OperationFactory - primeste simbolul operatiei si creeaza obiectul
  corespunzator. De exemplu, pentru "+" va crea un AddOperation.

- ComplexParser - se ocupa de transformarea unui text care reprezinta un numar
  complex intr-un obiect de tip Complex.

- ExpressionParser - se ocupa de verificarea expresiei si de evaluarea ei.
  Foloseste ComplexParser pentru numerele complexe si OperationFactory pentru
  obtinerea operatiei care trebuie executata.

- Main - reprezinta punctul de pornire al aplicatiei si transmite argumentele
  din linia de comanda catre ExpressionParser.


3. Principii SOLID

SRP (Single Responsibility Principle)

Am incercat ca fiecare clasa sa aiba o responsabilitate clara. De exemplu,
clasa Complex se ocupa de numere complexe, ComplexParser se ocupa de parsare,
iar clasele AddOperation, SubtractOperation, MultiplyOperation si
DivideOperation se ocupa fiecare de o singura operatie.

OCP (Open/Closed Principle)

Interfata Operation permite adaugarea unor operatii noi fara sa fie nevoie sa
modificam clasele existente. De exemplu, daca ar trebui adaugata o operatie
noua, se poate crea o noua clasa care implementeaza Operation.

LSP (Liskov Substitution Principle)

Obiectele claselor AddOperation, SubtractOperation, MultiplyOperation si
DivideOperation pot fi folosite prin tipul Operation, deoarece toate respecta
contractul definit de interfata.

DIP (Dependency Inversion Principle)

ExpressionParser lucreaza cu Operation si nu trebuie sa cunoasca direct
implementarea fiecarei operatii. OperationFactory se ocupa de crearea
implementarii potrivite.


4. Design Patterns

Strategy Pattern

Interfata Operation si clasele AddOperation, SubtractOperation,
MultiplyOperation si DivideOperation pot fi privite ca o aplicare a
Strategy Pattern.

Operation reprezinta interfata comuna, iar fiecare operatie reprezinta o
strategie diferita pentru efectuarea calculului.

Astfel, ExpressionParser poate folosi o operatie fara sa depinda direct de
implementarea ei.


Factory Pattern

OperationFactory foloseste ideea de Factory Pattern. In functie de simbolul
primit ("+", "-", "*" sau "/"), fabrica creeaza obiectul corespunzator.

In acest fel, logica de creare a operatiilor este separata de restul
aplicatiei.


5. Modul de functionare

Programul porneste din Main, unde sunt primite argumentele din linia de
comanda.

Argumentele sunt trimise catre ExpressionParser.

ExpressionParser verifica daca argumentele au forma corecta:

numar complex -> operator -> numar complex -> operator -> numar complex ...

Pentru fiecare numar complex se poate folosi ComplexParser pentru a obtine un
obiect Complex.

Pentru operator, ExpressionParser foloseste OperationFactory. Fabrica primeste
simbolul operatorului si returneaza operatia corespunzatoare.

Dupa ce operatia este obtinuta, se apeleaza metoda execute() pentru a calcula
rezultatul.

Procesul se repeta pentru toate numerele din expresie, iar la final este
returnat rezultatul expresiei.


6. Exemplu de functionare

Pentru:

2 + 3*i + 5 - 6*i

programul identifica:

2 + 3*i
+
5 - 6*i

Operatorul este "+", OperationFactory va crea un AddOperation.

Apoi se apeleaza:

execute(first, second)

iar rezultatul celor doua numere complexe este calculat.

Rezultatul final este afisat de program.


7. Concluzie

Prin aceasta structura am incercat sa separ partea de parsare de partea de
calcul si sa evit ca ExpressionParser sa contina implementarea tuturor
operatiilor.

Interfata Operation permite adaugarea mai usoara a unor operatii noi, iar
OperationFactory se ocupa de crearea obiectului potrivit in functie de
operator.