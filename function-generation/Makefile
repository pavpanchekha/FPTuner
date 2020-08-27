GENERATORS=$(wildcard generate-*-cfile.sollya)
CFILES=$(patsubst generate-%-cfile.sollya,ord_%.c,${GENERATORS})
TFILES=$(patsubst generate-%-cfile.sollya,ord_%.c.tmp,${GENERATORS})

.PHONY: all
all: ${CFILES} ${TFILES}


ord_%.c.tmp: generate-%-cfile.sollya
	-sollya $^ > $@

ord_%.c: ord_%.c.tmp
	sed "s|^Warning:.*||g" $^ | sed "s|^The.*||g" > $@



.PHONY: clean
clean:
	$(RM) *.fpt
	$(RM) *.tmp
	$(RM) -r log tmp

.PHONY: veryclean
veryclean: clean
	$(RM) *.c
