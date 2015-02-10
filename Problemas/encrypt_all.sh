for path in $(ls -d */)
do
	echo $path
	./encrypt_dir $path
done
