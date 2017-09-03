# makefile configuration
NAME            = bigvar
OBJECTS         = main.o bigvar.o

# base
MSPBASE=/cygdrive/c/ti/msp430_gcc/bin
# configuration
MSPCC=$(MSPBASE)/msp430-elf-gcc
MSPCCFLAGS=-Wall -Os -fdata-sections -ffunction-sections -mmcu=msp430c1111 
MSPLDFLAGS=-mmcu=msp430c1111 -Wl,--gc-sections -minrt -T linker.x 
MSPOBJCOPY=$(MSPBASE)/msp430-elf-objcopy
MSPOBJDUMP=$(MSPBASE)/msp430-elf-objdump
MSPSIZE=$(MSPBASE)/msp430-elf-size

all: $(NAME).elf $(NAME).a43 $(NAME).lst

%.o: %.c
	$(MSPCC)  $(MSPCCFLAGS) -c $< -o $@

$(NAME).elf: $(OBJECTS)
	$(MSPCC) $(MSPLDFLAGS) $(OBJECTS) -o $@
	$(MSPSIZE) $@

$(NAME).a43: $(NAME).elf
	$(MSPOBJCOPY) -O ihex $^ $@

$(NAME).lst: $(NAME).elf
	$(MSPOBJDUMP) -dSt $^ >$@

clean:
	rm -f $(NAME) $(NAME).a43 $(NAME).lst $(NAME).elf *.o *~

