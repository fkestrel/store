OPTS = -DMAIN_TEST -Wall

objects = cfunction.o

out: $(objects)
	g++ -o out $(objects)

%.o:%.cpp
	g++ $(OPTS) -c $<
	
#out:
#	g++ $(OPTS) -c cfunction.cpp
#	g++ -o out cfunction.o


.PHONY: clean
clean:
	rm -f *.o
	rm -f out
