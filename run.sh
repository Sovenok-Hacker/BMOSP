#!/bin/sh
qemu-system-x86_64 -cpu max -m 1G -smp 1 -bios ovmf/OVMF.fd -hda bmosp.hdd