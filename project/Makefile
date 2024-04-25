# configuration
COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I./h -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all:
	(cd timerLib && make install)
	make buzzer.elf

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o ./lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh $^

clean: $^
	(cd timerLib && make clean)
	rm -f *.o *.elf
	rm -rf h lib

buzzer.c: buzzer.h
buzzerMain.c: buzzer.h
