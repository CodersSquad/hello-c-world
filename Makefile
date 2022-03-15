
SECTIONS = start-up


all: $(SECTIONS)
	cd $^ ; make
	rm -rf public/$^
	mkdir -p public
	mv -f $^/public/ public/$^

clean:
	rm -rf public
