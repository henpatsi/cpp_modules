#!/bin/bash

TEST_DIR=tests



IN=$TEST_DIR/test1
OUT_SED=$IN.replacesed
OUT_MYSED=$IN.replace

OLD="dogs"
NEW="cats"

cp $IN $OUT_SED
sed -i "s/$OLD/$NEW/g" $OUT_SED
./mysed $IN "$OLD" "$NEW"
diff $OUT_SED $OUT_MYSED

rm -f $OUT_SED $OUT_MYSED



IN=$TEST_DIR/test2
OUT_SED=$IN.replacesed
OUT_MYSED=$IN.replace

OLD="replace me"
NEW="i am replaced"

cp $IN $OUT_SED
sed -i "s/$OLD/$NEW/g" $OUT_SED
./mysed $IN "$OLD" "$NEW"
diff $OUT_SED $OUT_MYSED

rm -f $OUT_SED $OUT_MYSED