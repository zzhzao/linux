.PHONY:all
all:loop mykill

loop:loop.cc
	g++ -o $@ $^
mykill:mykill.cc
	g++ -o $@ $^
.PHONY:clean
clean:
	rm -rf mykill