
SECTIONS = start-up


all: $(SECTIONS)
	cd $^ ; make
	mkdir -p public
	cp -fr $^/public/* public/$^

clean:
	rm -rf public
