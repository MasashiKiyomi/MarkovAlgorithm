markov: markov.cc
	g++ -o markov -O3 markov.cc

clean:
	rm -f markov_algorithm

dist:
	rm -f markov_algorithm
	mkdir markov_algorithm
	cp README Makefile markov.cc *.ma markov
	tar cvaf markov_algorithm.tar.xz markov_algorithm
	rm -r markov_algorithm
