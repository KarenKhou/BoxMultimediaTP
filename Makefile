##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme
#

PROG_BOX = boxmulti
PROG_CLIENT = client
PROG_SERVER = server

#
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
#
SOURCES_BOX = multimedia.cpp gestionmultimedia.cpp groupe.cpp main.cpp
SOURCES_CLIENT = client.cpp ccsocket.cpp
SOURCES_SERVER = server.cpp tcpserver.cpp ccsocket.cpp multimedia.cpp gestionmultimedia.cpp groupe.cpp

#
# Fichiers objets (ne pas modifier sauf si l'extension n'est pas .cpp)
#
#OBJETS = ${SOURCES:%.cpp=%.o}
OBJETS_BOX = ${SOURCES_BOX:%.cpp=%.o}
OBJETS_CLIENT = ${SOURCES_CLIENT:%.cpp=%.o}
OBJETS_SERVER = ${SOURCES_SERVER:%.cpp=%.o}

#
# Compilateur C++
#
CXX = c++

#
# Options du compilateur C++
#   -g pour debugger, -O optimise, -Wall affiche les erreurs, -I pour les headers
#   -std=c++11 pour C++11
# Exemple: CXXFLAGS= -std=c++11 -Wall -O -I/usr/local/qt/include
#
CXXFLAGS = -std=c++11 -Wall -g

#
# Options de l'editeur de liens
#
LDFLAGS = 

#
# Librairies a utiliser
# Exemple: LDLIBS = -L/usr/local/qt/lib -lqt
#
LDLIBS = -lpthread


##########################################
#
# Regles de construction/destruction des .o et de l'executable
# depend-${PROG} sera un fichier contenant les dependances
#
 
all: $(PROG_BOX) $(PROG_CLIENT) $(PROG_SERVER)
$(PROG_BOX): $(OBJETS_BOX)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(PROG_CLIENT): $(OBJETS_CLIENT)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(PROG_SERVER): $(OBJETS_SERVER)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

run-box: ./$(PROG_BOX)

run-client: ./$(PROG_CLIENT)

run-server: ./$(PROG_SERVER)



clean:
	-@$(RM) *.o depend-${PROG} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) ${PROG} 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de g++ (attention tous les compilateurs n'ont pas cette option)
#
depend-${PROG}:
	${CXX} ${CXXFLAGS} -MM ${SOURCES} > depend-${PROG}


###########################################
#
# Regles implicites
#

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<


#############################################
#
# Inclusion du fichier des dependances
#
-include depend-${PROG}
