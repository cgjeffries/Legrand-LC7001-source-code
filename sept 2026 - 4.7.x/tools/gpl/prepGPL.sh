#!/bin/bash
# This file prepares a tar file for distribution under GPLv2

SCRIPT=`realpath $0`
SCRIPTPATH=`dirname $SCRIPT`

cd $SCRIPTPATH/../..

LCMPATH=`pwd`

# Delete folders that we don't want to include
rm -rf MQX
rm -rf azure-poc-linux
rm -rf latest-artik.s19
rm -rf .git*
rm -rf tools/heroku
rm -rf Doc/ReleaseNotes.md
rm -rf tools/gpl
rm -rf tools/PROGACMP

# Remove Eliot API key
sed -i '/ELIOT_API_KEY/s/".*"/"KEY"/' Embedded/Sources/Eliot_REST_Task.c

cd ..

tar -czvf LCM-source.tar.gz LCM
