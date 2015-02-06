for path in $(ls -d */)
do
	echo $path
	for file in $(ls $path)
	do
		./encrypt.sh $path$file
	done
done
