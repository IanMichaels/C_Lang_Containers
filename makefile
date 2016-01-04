CXX=gcc


.SUFFIXES: .x

.PHONY : clean

proj.x : proj.o c_list.o mem_tools.o
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	 rm -f *.o *.x core.*
