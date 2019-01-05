#! /bin/bash

sftp asantra@lxplus6.cern.ch << EOF
get -r /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits/limitplots_2018_Final
EOF
