#  hello world,
#  bas de bruin



#  hij vraagt de gebruiker wat z'n naam is
name = input("Hallo, wat is je naam?  ")



#  hij herhaald de naam van de gebruiker en vraagt of hij de gebruiker Sjoerd mag noemen
antwoord = input("Ok {}, is het goed als ik je Sjoerd noem?  ".format(name))



#  als de gebruiker ja antwoorden is alles goed,
#  als de gebruiker iets anders invullen dan krijgen ze een egatief antwoord
if antwoord == "ja":
    print("Ok, Sjoerd")
else:
    print("Sorry, het goede antwoord was ja.")
