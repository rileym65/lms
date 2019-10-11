# For creating Unix documentation
FLAGS = -u

# For creating Windows documentation
#FLAGS = -w

all: csmcomputer.d lmcomputer.d panel.d keys.d
	makedoc $(FLAGS) csmcomputer.d
	makedoc $(FLAGS) lmcomputer.d
	makedoc $(FLAGS) panel.d
	makedoc $(FLAGS) keys.d
	makedoc $(FLAGS) readme.d
	makedoc $(FLAGS) tutorial_1.d
	makedoc $(FLAGS) tutorial_2.d
	makedoc $(FLAGS) tutorial_7.d

clean:
	-rm *.doc

