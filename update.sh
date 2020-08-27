#get latest keymap
newest_file=`perl -le '@sorted = map {$_->[0]} 
sort {$a->[1] <=> $b->[1]} 
map {[$_, -M $_]} 
@ARGV;
print $sorted[0]
' /mnt/c/Users/nicsu/Downloads/nic*plan*.json`
echo found new keymap file: $newest_file
cp $newest_file /mnt/e/src/qmk-nicsuzor/planck/keymap.json

#get latest keymap
newest_file=`perl -le '@sorted = map {$_->[0]} 
sort {$a->[1] <=> $b->[1]} 
map {[$_, -M $_]} 
@ARGV;
print $sorted[0]
' /mnt/c/Users/nicsu/Downloads/nic_split_iris*.json`

echo found new keymap file: $newest_file
cp $newest_file /mnt/e/src/qmk-nicsuzor/iris1/keymap.json


#get latest keymap
newest_file=`perl -le '@sorted = map {$_->[0]} 
sort {$a->[1] <=> $b->[1]} 
map {[$_, -M $_]} 
@ARGV;
print $sorted[0]
' /mnt/c/Users/nicsu/Downloads/nic_split_lily*.json`

echo found new keymap file: $newest_file
cp $newest_file /mnt/e/src/qmk-nicsuzor/lily/keymap.json

rsync -avh /mnt/e/src/qmk-nicsuzor/iris1/ keyboards/keebio/iris/keymaps/nicsuzor/
rsync -avh /mnt/e/src/qmk-nicsuzor/lily/ keyboards/lily58/keymaps/nicsuzor/
rsync -avh /mnt/e/src/qmk-nicsuzor/planck/ keyboards/planck/keymaps/nicsuzor/
echo adding to git.

git add --all keyboards/keebio/iris/keymaps/nicsuzor
git add --all keyboards/lily58/keymaps/nicsuzor
git add --all keyboards/planck/keymaps/nicsuzor
