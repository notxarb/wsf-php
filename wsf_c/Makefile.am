datadir=$(prefix)
docsdir=$(prefix)/docs
samplesdir=$(prefix)/samples
SUBDIRS=axis2c $(SANDESHA_DIR) $(RAMPART_DIR) $(SAVAN_DIR) $(WSCLIENT_DIR) 
docs_DATA=
data_DATA=config/axis2.xml README \
        INSTALL COPYING NEWS CREDITS NOTICE 

dist-hook:
	sh dist_hook.sh

samples:
	sh build_samples.sh $(prefix)

install-data-hook:
	cp -rf docs/* $(DESTDIR)$(docsdir)
	cp -rf examples/* $(DESTDIR)$(samplesdir)
	rm -rf `find $(DESTDIR)$(samplesdir)/ -type d -name *.svn`
	rm -rf `find $(DESTDIR)$(samplesdir)/ -type d -name *.libs`
	rm -rf `find $(DESTDIR)$(samplesdir)/ -type d -name *.deps`
	rm -rf `find $(DESTDIR)$(samplesdir)/ -type f -name Makefile`
	rm -rf `find $(DESTDIR)$(samplesdir)/ -type d -name autom4te.cache`

EXTRA_DIST=build_samples.sh config build.bat clean.bat docs CREDITS NOTICE examples LICENSE configure.in link_samples.sh link.sh build/build_optional.bat build/optional.mk build/init.bat build/versions.in

