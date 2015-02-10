for path in $(ls -d */)
do
	echo $path
	./decrypt_dir $path
done
