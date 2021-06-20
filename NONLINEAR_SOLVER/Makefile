all : 	
	cd libnls && $(MAKE)
	cd libnls_apps && $(MAKE)
doc :
	cd libnls && $(MAKE) doc
	cd libnls_apps && $(MAKE) doc

clean :
	cd libnls && $(MAKE) clean
	cd libnls_apps && $(MAKE) clean

.PHONY: all doc clean
