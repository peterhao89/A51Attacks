XX=g++
FLAG=-O2 -std=c++11 -fopenmp -lntl -lgmp -lm
merge:mainA51.cpp A51Impl.hpp GuessDetermineCP.hpp CommonUtils.hpp PracticalAttack.hpp
	$(XX) -o merge mainA51.cpp $(FLAG)
