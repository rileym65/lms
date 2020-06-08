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
	makedoc $(FLAGS) realism.d
	makedoc $(FLAGS) tutorial_1.d
	makedoc $(FLAGS) tutorial_2.d
	makedoc $(FLAGS) tutorial_3.d
	makedoc $(FLAGS) tutorial_4.d
	makedoc $(FLAGS) tutorial_7.d
	makedoc $(FLAGS) tutorial_8.d
	makedoc $(FLAGS) tutorial_9.d
	makedoc $(FLAGS) tutorial_9a.d
	makedoc $(FLAGS) tutorial_9b.d
	makedoc $(FLAGS) tutorial_10.d
	makedoc $(FLAGS) tutorial_11.d

clean:
	-rm *.doc

