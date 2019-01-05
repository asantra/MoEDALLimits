#! /bin/bash

sftp asantra@lxplus6.cern.ch << EOF
put *.C /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits
put myTrappingAcceptance/DrellYan*.txt /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits
put myTrappingAcceptance/PhotonFusion*.txt /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits
put myTrappingAcceptance/Combined*.txt /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits
put makeLimitPlots.sh /afs/cern.ch/user/a/asantra/public/MoEDALLimitPlots/Limits
EOF
