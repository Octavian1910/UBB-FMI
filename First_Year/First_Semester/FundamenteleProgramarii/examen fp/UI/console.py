from datetime import date

class Console:

    def __init__(self,service):
        self.__service = service

    def __meniu(self):
        print(15*"==")
        print("Meniu melodii")
        print("1)Modifica melodie")
        print("2)Creeaza aleator melodii")
        print("3)Statistici")
        print("4)Toate melodiile")
        print("5) Iesire")
        print(15 * "==")

    def __read_type(self,text,type):
        while True:
            rez = input(text)
            try:
                return type(rez)
            except Exception:
                print("Tipul nu este bun!")

    def run(self):
        while True:
            self.__meniu()
            try:
                comanda = self.__read_type("Da comanda : ",int)
                try:
                    if comanda == 1: #Modifica melodie
                        # Melodie(titlu,artist,gen,data_aparitie)
                        titlu = self.__read_type("Da titlu : ",str)
                        artist = self.__read_type("Da artist : ",str)
                        gen = self.__read_type("Da gen : ",str)
                        print("Datele cand au aparut melodie sunt : ")
                        zi = self.__read_type("Da zi : ", int)
                        luna = self.__read_type("Da luna : ", int)
                        an = self.__read_type("Da an : ", int)
                        data = date(an,luna,zi)
                        self.__service.update(titlu,artist,gen,data)
                        print("S a updatat cu succes!")
                    elif comanda == 2:
                        nr_melodii = self.__read_type("Cate melodii generezi :",int)
                        titluri = self.__read_type("Scrie titlurile separate prin virgula : ",str)
                        artisti = self.__read_type("Scrie artistii separate prin virgula : ",str)
                        rez = self.__service.genereaza_melodii(nr_melodii,titluri,artisti)
                        mesaj = f"S au generat {rez} melodii."
                        print(mesaj)
                    elif comanda == 3 :
                        rez = self.__service.statistici()
                        print(rez)
                    elif comanda == 4:
                        melodii = self.__service.get_all()
                        for melodie in melodii:
                            print(melodie)
                        print("S au afisat toate melodiile!")
                    elif comanda == 5:
                        break
                except Exception as e:
                    print(e)
            except Exception as e:
                print(e)



