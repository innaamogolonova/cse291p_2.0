JULIET_SUPPORT_DIR = third_party/juliet/testcasesupport
JULIET_CFLAGS = -I$(JULIET_SUPPORT_DIR) -Wall -Wextra -g

# Default: compile all 5 Juliet examples to .o files (no linking)
all: build \
     build/CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_loop_12.o \
     build/CWE127_Buffer_Underread__char_alloca_cpy_01.o \
     build/CWE415_Double_Free__malloc_free_char_01.o \
     build/CWE416_Use_After_Free__malloc_free_char_01.o \
     build/CWE476_NULL_Pointer_Dereference__null_check_after_deref_01.o

build:
	mkdir -p build

# Each rule: compile the testcase to an object file (-c), do NOT link
build/CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_loop_12.o: build
	clang $(JULIET_CFLAGS) -DOMITGOOD -c \
		data/juliet/test_cases/CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_loop_12.c \
		-o $@

build/CWE127_Buffer_Underread__char_alloca_cpy_01.o: build
	clang $(JULIET_CFLAGS) -DOMITGOOD -c \
		data/juliet/test_cases/CWE127_Buffer_Underread__char_alloca_cpy_01.c \
		-o $@

build/CWE415_Double_Free__malloc_free_char_01.o: build
	clang $(JULIET_CFLAGS) -DOMITGOOD -c \
		data/juliet/test_cases/CWE415_Double_Free__malloc_free_char_01.c \
		-o $@

build/CWE416_Use_After_Free__malloc_free_char_01.o: build
	clang $(JULIET_CFLAGS) -DOMITGOOD -c \
		data/juliet/test_cases/CWE416_Use_After_Free__malloc_free_char_01.c \
		-o $@

build/CWE476_NULL_Pointer_Dereference__null_check_after_deref_01.o: build
	clang $(JULIET_CFLAGS) -DOMITGOOD -c \
		data/juliet/test_cases/CWE476_NULL_Pointer_Dereference__null_check_after_deref_01.c \
		-o $@

clean:
	rm -rf build
