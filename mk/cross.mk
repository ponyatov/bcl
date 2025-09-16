HW ?= pc
# HW ?= qemu386
# HW ?= a7n8x
# HW ?= rpi3bp
# HW ?= opi800
# HW ?= rpi4
# HW ?= rpi5
# HW ?= pillf030
# HW ?= pillf103
# HW ?= lm3s6
# HW ?= iskra
# HW ?= f4disco
# HW ?= f429disco
# HW ?= l496disco
# HW ?= esp8266
# HW ?= esp32

include   hw/$(HW)/$(HW).mk
include  cpu/$(CPU)/$(CPU).mk
include arch/$(ARCH)/$(ARCH).mk
include   os/$(OS)/$(OS).mk

ELF = bin/$(BINFILE).elf
DFU = bin/$(BINFILE).dfu

.PHONY: elf
elf: $(ELF)
	$(QEMU) $(QEMU_CFG) -gdb tcp::3333 -S -kernel $<

.PHONY: dfu
dfu: $(DFU)
$(DFU): $(ELF)
	~/elf2dfuse/bin/elf2dfuse $< $@
