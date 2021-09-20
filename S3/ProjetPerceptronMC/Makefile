SHELL:=/bin/bash
MODULES_APPRENTISSAGE:= lib/dbg/specification.o lib/dbg/apprentissage.o lib/dbg/reseau.o lib/dbg/couches_entree.o lib/dbg/couches_sortie.o  lib/dbg/couches_activation.o  lib/dbg/couches_matrice.o lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 
#MODULES_APPRENTISSAGE:= lib/specification.o lib/apprentissage.o lib/reseau.o lib/couches_entree.o lib/couches_sortie.o  lib/couches_activation.o  lib/couches_matrice.o lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 
MODULES_EVALUATION:=lib/dbg/specification.o lib/dbg/lire_db.o lib/dbg/evaluation.o lib/reseau.o lib/dbg/couches_entree.o lib/dbg/couches_sortie.o  lib/dbg/couches_activation.o lib/dbg/couches_matrice.o  lib/dbg/activation.o lib/dbg/matrices_accesseurs.o lib/dbg/matrices_operations.o lib/dbg/matrices.o lib/utils.o 
MAIN:=bin/apprentissage bin/evaluation
LIBS:=-lm 
INCLUDE_PATH:= include
LIBRARY_PATH:= lib
DEBUG:= -g3 -Wno-unused-value
# DEBUG:= -DNDEBUG 
CFLAGS:=-Wall -I $(INCLUDE_PATH) -L$(LIBRARY_PATH) 
#CFLAGS:=-Wall  -Werror $(DEBUG)  -I $(INCLUDE_PATH) -L$(LIBRARY_PATH)

.PHONY: evalue apprend all

all: $(MAIN)

#bin/apprentissage: src/main_apprentissage.c $(MODULES_APPRENTISSAGE)
#	gcc $(CFLAGS) src/main_apprentissage.c -o bin/apprentissage  $(MODULES_APPRENTISSAGE) $(LIBS)

bin/apprentissage: src/squelettes/main_apprentissage.c $(MODULES_APPRENTISSAGE)
	gcc $(CFLAGS) src/squelettes/main_apprentissage.c -o bin/apprentissage  $(MODULES_APPRENTISSAGE) $(LIBS)
	
#bin/evaluation: src/main_evaluation.c $(MODULES_EVALUATION)
#	gcc $(CFLAGS) src/main_evaluation.c -o bin/evaluation  $(MODULES_EVALUATION) $(LIBS)

bin/evaluation: src/squelettes/main_evaluation.c $(MODULES_EVALUATION)
	gcc $(CFLAGS) src/squelettes/main_evaluation.c -o bin/evaluation  $(MODULES_EVALUATION) $(LIBS)
	
lib/%.o: src/%.c 
	gcc $(CFLAGS) -c $< -o $@ 


reseau.mat apprend: bin/apprentissage
	./bin/apprentissage tests/fonction_lineaire.csv < tests/input_lineaire_exact.txt

evalue: bin/evaluation reseau.mat
	./bin/evaluation tests/fonction_lineaire.csv 

clean:
	find bin -maxdepth 1 -type f -exec \rm {} \;
	find lib -maxdepth 1 -type f -exec \rm {} \;
	find . -name '*~' -exec \rm {} \;
	if [[ -e "pmc.tgz" ]] ; then \rm mlp.tgz ; fi

pkg: clean
	cd .. ; tar czvf pmc.tgz PMC ; mv pmc.tgz PMC/
