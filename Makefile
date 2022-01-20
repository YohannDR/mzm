TARGET = mzm_us.gba
BASEROM = baserom_us.gba
SHA1FILE = mzm.sha1

# Binaries
RM = rm -f
SHA1SUM = sha1sum

# Enable verbose output
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif


.PHONY: all
all: $(TARGET)

.PHONY: check
check: all
	$(MSG) SHA1SUM $(SHA1FILE)
	$Q$(SHA1SUM) -c $(SHA1FILE)

.PHONY: clean
clean:
	$(MSG) RM $(TARGET)
	$Q$(RM) $(TARGET)


$(TARGET):
	$(MSG) CP $(BASEROM) $(TARGET)
	$Qcp $(BASEROM) $@
