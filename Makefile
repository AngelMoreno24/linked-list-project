
output: moreno_angel_assn4.o moreno_list.o
	g++ moreno_angel_assn4.o moreno_list.o -o output

moreno_angel_assn4.o: moreno_angel_assn4.cpp
	g++ -c moreno_angel_assn4.cpp

moreno_list.o: moreno_angel_assn4.cpp moreno_list.h
	g++ -c moreno_list.cpp

clean:
	rm *.o output




