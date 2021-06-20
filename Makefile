all : 	
	cd libodes && $(MAKE)
	cd libodes_apps && $(MAKE)
doc :
	cd libodes && $(MAKE) doc
	cd libodes_apps && $(MAKE) doc

clean :
	cd libodes && $(MAKE) clean
	cd libodes_apps && $(MAKE) clean

.PHONY: all doc clean
