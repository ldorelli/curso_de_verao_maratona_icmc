for file in $(ls $1 | grep -v '.aes')
do
	./encrypt.sh $1$file
done
