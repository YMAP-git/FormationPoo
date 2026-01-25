#Lister les noms des différents fichiers à compiler


SRC_FILES	= auteur.cpp date.cpp lecteur.cpp main.cpp livre.cpp

#Création du nom de l'exécutable APP
APP			= app

#Choisir le compilateur
CXX	= g++

#Options de compilation (Warning, etc...) 
CXXFLAGS	= -Wall -std=c++20

#Indicateur de dépendance. Inclure les fichiers .d crées par le compilateur
DEPFLAGS	= -MMD

#Editeur de Lien Pas d'indicateur à ce niveau
LDFLAGS		=

#Repertoire de compilation
BUILDIR		= build

#Création des fichiers objets.o  résultants des fichiers source .cpp
OBJ_FILES	= $(patsubst %.cpp, $(BUILDIR)/%.o, $(SRC_FILES))

#Création du repertoire binaire
BINDIR		= bin

#Création d'un target;le path de l'exécutable
TARGET		= $(BINDIR)/$(APP)

#Création des dépendances. Tous les .o se transforment en .d
DEPS		= $(OBJ_FILES:.o=.d)

all: $(TARGET)

#Lier les fichiers objets à l'exécutable dans le fichier binaire
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o  $(TARGET) $(OBJ_FILES)

#Compiler les fichiers sources en fichiers objets dans le repertoire de compilation
$(BUILDIR)/%.o: %.cpp
	@mkdir -p $(BUILDIR)
	 $(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

#Nettoyer le repertoire de compilation
clean: 
	rm -rf $(BUILDIR)
	rm -rf $(BINDIR)

#Inclure les dépendances générées par le compilateur
-include $(DEPS)

#Fausse cible
.PHONY: all clean
