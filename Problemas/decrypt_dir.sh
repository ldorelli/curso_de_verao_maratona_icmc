for file in $(ls $1 | grep .aes)
do
	./decrypt.sh $1$file
done
