#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

import sys
import struct

# Define constants for the ELF header fields
EI_NIDENT = 16
EI_CLASS = 4
EI_DATA = 5
EI_VERSION = 6
EI_OSABI = 7
EI_ABIVERSION = 8
EI_PAD = 9
EI_MAG0 = 0
EI_MAG1 = 1
EI_MAG2 = 2
EI_MAG3 = 3
EI_MAG_IDENT = b'\x7fELF'

# Define constants for the ELF class and data encodings
ELFCLASS32 = 1
ELFCLASS64 = 2
ELFDATA2LSB = 1
ELFDATA2MSB = 2

def parse_elf_header(filename):
    """
    Parses the ELF header of the given ELF file and prints its contents.

    Args:
        filename (str): The path to the ELF file.
    """
    with open(filename, "rb") as f:
        # Read the ELF header
        elf_header = f.read(EI_NIDENT)

        # Verify that the file is an ELF file
        if elf_header[EI_MAG0] != EI_MAG_IDENT[0] \
                or elf_header[EI_MAG1] != EI_MAG_IDENT[1] \
                or elf_header[EI_MAG2] != EI_MAG_IDENT[2] \
                or elf_header[EI_MAG3] != EI_MAG_IDENT[3]:
            print(f"Error: {filename} is not an ELF file.")
            return

        # Parse the ELF header fields
        ei_class = elf_header[EI_CLASS]
        ei_data = elf_header[EI_DATA]
        ei_version = elf_header[EI_VERSION]
        ei_osabi = elf_header[EI_OSABI]
        ei_abiversion = elf_header[EI_ABIVERSION]
        e_type = struct.unpack('H', f.read(2))[0]
        e_machine = struct.unpack('H', f.read(2))[0]
        e_version = struct.unpack('I', f.read(4))[0]

        if ei_class == ELFCLASS32:
            # Parse the rest of the 32-bit ELF header fields
            e_entry = struct.unpack('I', f.read(4))[0]
            e_phoff = struct.unpack('I', f.read(4))[0]
            e_shoff = struct.unpack('I', f.read(4))[0]
            e_flags = struct.unpack('I', f.read(4))[0]
            e_ehsize = struct.unpack('H', f.read(2))[0]
            e_phentsize = struct.unpack('H', f.read(2))[0]
            e_phnum = struct.unpack('H', f.read(2))[0]
            e_shentsize = struct.unpack('H', f.read(2))[0]
            e_shnum = struct.unpack('H', f.read(2))[0]
            e_shstrndx = struct.unpack('H', f.read(2))[0]

            # Print the 32-bit ELF header fields
            print(f"ELF class: {ei_class}")
            print(f"Data encoding: {ei_data}")
            print(f"ELF version: {ei_version}")
            print(f"OS/ABI: {ei_osabi}")
            print(f"ABI version: {ei_abiversion}")
            print(f"Type: {e_type}")
            print(f"Machine: {e_machine}")
            print(f"Version: {e_version}")
            print(f"Entry point address: 0x{e_entry:x}")
	free(header);
	close_elf(o);
	return (0);
}
