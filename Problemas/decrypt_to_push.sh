for dir in "$@"
do
	./decrypt_dir.sh $dir
	git add $dir/*
done
