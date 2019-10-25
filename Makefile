all:
	cd Documentation; \
	make
	cd Lms; \
	make
	cd MapGen; \
	make
	cd GcAsm; \
	make
	cd Planner; \
	make

clean:
	cd Documentation; \
	make clean
	cd Lms; \
	make cleanall
	cd MapGen; \
	make clean
	cd GcAsm; \
	make clean
	cd Planner; \
	make clean
