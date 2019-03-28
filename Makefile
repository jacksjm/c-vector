# GNU Makefile

CC = gcc
CCFLAGS = -Wall -O3
LDFLAGS =
TARGET = sort gera_vector help
TAMARQ = 10
TIPSORT = 3 #1-QuickSort;2-BubbleSort;3-MergeSort
TIPORD = -9999 #-9999 - Aleatório;-8888 - Ordem Crescente;-7777 - Ordem Decrescente

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

sort: main_sort.c toolsvector.o vector.o sort.o
	$(CC) $(CCFLAGS) toolsvector.o vector.o sort.o main_sort.c -o $@ $(LDFLAGS)

gera_vector: gera_vector.c toolsvector.o vector.o
		$(CC) $(CCFLAGS) vector.o toolsvector.o gera_vector.c -o $@ $(LDFLAGS)

help:
	./gera_vector $(TAMARQ) $(TIPORD)
	./sort vector-$(TAMARQ).map $(TIPSORT)

clean:
	rm -f *.o *~ $(TARGET) *.map *.map-result
