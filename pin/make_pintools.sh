#!/bin/bash

PIN_DIR=~/pin/
TARGET=intel64

pushd "$PIN_DIR/source/tools/ManualExamples"
make all TARGET=$TARGET

cd ../SimpleExamples
make all TARGET=$TARGET

popd

cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/inscount0.so" pintools
cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/inscount1.so" pintools
cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/inscount2.so" pintools
#cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/isampling.so" pintools
#cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/itrace.so" pintools
#cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/pinatrace.so" pintools
cp "$PIN_DIR/source/tools/ManualExamples/obj-$TARGET/proccount.so" pintools
cp "$PIN_DIR/source/tools/SimpleExamples/obj-$TARGET/catmix.so" pintools
cp "$PIN_DIR/source/tools/SimpleExamples/obj-$TARGET/dcache.so" pintools
cp "$PIN_DIR/source/tools/SimpleExamples/obj-$TARGET/jumpmix.so" pintools
cp "$PIN_DIR/source/tools/SimpleExamples/obj-$TARGET/opcodemix.so" pintools


