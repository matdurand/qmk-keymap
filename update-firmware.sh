#!/bin/bash

#Copy the keymap source into the qmk-firmware
(mkdir -p ./../qmk_firmware/keyboards/annepro2/keymaps/matdurand)
(cd ./keymap; cp * ../../qmk_firmware/keyboards/annepro2/keymaps/matdurand)

echo "Making keymap firmware"
(cd ../qmk_firmware; make "annepro2/c18")

echo "Making Shine firmware"
(cd ../AnnePro2-Shine; make clean; make C18)

read -p "Press [LShift + RShift + B] on AnnePro2 to switch to IAP mode for flashing, and then press any key on laptop keyboard..."

echo "Building anne pro 2 tools"
(cd ../AnnePro2-Tools; cargo build --release)

echo "Uploading keymap firmware"
../AnnePro2-Tools/target/release/annepro2_tools ../qmk_firmware/annepro2_c18_matdurand.bin

echo "Uploading led firmware"
../AnnePro2-Tools/target/release/annepro2_tools --boot -t led ../AnnePro2-Shine/build/annepro2-shine-C18.bin
