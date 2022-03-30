CC ?= cc
AR ?= ar
SDKROOT ?= $(shell xcrun --sdk macosx --show-sdk-path)
INSTALL ?= install

all:
	$(CC) -c CrashReporterClient.c
	$(AR) rcs libCrashReporterClient.a CrashReporterClient.o

install:
	$(INSTALL) -m644 libCrashReporterClient.a $(SDKROOT)/usr/lib

clean:
	rm CrashReporterClient.o libCrashReporterClient.a
