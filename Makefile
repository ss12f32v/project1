lab1_solve.out:lab1_solve.o Sudoku.o
	g++ -o lab1_solve.out lab1_solve.o Sudoku.o
lab1_solve.o: lab1_solve.cpp Sudoku.h
	g++ -c lab1_solve.cpp
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
lab1_give_question.out:lab1_give_question.o Sudoku.o
	g++ -o lab1_give_question.out lab1_give_question.o Sudoku.o
lab1_give_question.o: lab1_give_question.cpp Sudoku.h
	g++ -c lab1_give_question.cpp