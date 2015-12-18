CXX=gcc


.SUFFIXES: .x

.PHONY : clean

proj.x : proj.o
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	 rm -f *.o *.x core.*
