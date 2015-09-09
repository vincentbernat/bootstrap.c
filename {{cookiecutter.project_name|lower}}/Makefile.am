ACLOCAL_AMFLAGS = -I m4

SUBDIRS        = src
EXTRA_DIST     = get-version autogen.sh
DISTCLEANFILES = ChangeLog
dist_doc_DATA  = README.md
doc_DATA       = ChangeLog

# Build changelog from git history
.PHONY: ChangeLog
ChangeLog:
	$(AM_V_GEN)if test -e $(top_srcdir)/.git; then \
		prev=$$(git describe --tags --always --match '[0-9]*' 2> /dev/null) ; \
		for tag in $$(git tag | $(EGREP) '^[0-9]+(\.[0-9]+){1,}$$' | sort -t. -k 1,1nr -k 2,2nr -k 3,3nr); do \
			if [ x"$$prev" = x ]; then prev=$$tag ; fi ; \
			if [ x"$$prev" = x"$$tag" ]; then continue; fi ; \
			echo "$$prev [$$(git log $$prev -1 --pretty=format:'%ai')]:" ; \
			echo "" ; \
			git log --pretty=' - [%h] %s (%an)' $$tag..$$prev ; \
			echo "" ; \
			prev=$$tag ; \
		done > $@ ; \
	else \
		touch $@ ; \
	fi

dist-hook:
	echo $(VERSION) > $(distdir)/.dist-version
