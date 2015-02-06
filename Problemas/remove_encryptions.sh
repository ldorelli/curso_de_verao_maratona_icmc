for path in $(ls -d */)
do
	echo $path
	for file in $(ls $path | grep .aes)
	do
		rm $path$file
	done
done
