lineq:
	@gcc lineq.c -o lineq

.PHONY: install uninstall

install:
	@cp lineq /usr/local/bin

uninstall:
	@rm /usr/local/bin/lineq
