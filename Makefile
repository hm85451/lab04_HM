CXX=clang++

testWordCount: testWordCount.o WordCount.o tddFuncs.o
	${CXX} -o testWordCount testWordCount.cpp WordCount.cpp tddFuncs.cpp
	
clean:
	rm -f testWordCount *.o
