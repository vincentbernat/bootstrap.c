ACLOCAL_AMFLAGS = -I m4

SUBDIRS      = src

dist_doc_DATA = README.md ChangeLog

# Build changelog from git history
dist-hook: $(distdir)/ChangeLog
$(distdir)/ChangeLog:
	$(AM_V_GEN)if test -d $(top_srcdir)/.git; then \
		prev=$$(git describe --tags --always --match [0-9]* 2> /dev/null) ; \
		for tag in $$(git tag | grep -E '^[0-9]+(\.[0-9]+){1,}$$' | sort -rn); do \
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
ChangeLog:
	touch $@

.PHONY: $(distdir)/ChangeLog
