aescrypt -d -k ~/Documents/secret.key $1
if [ "$?" = "0" ]; then
	rm $1
fi
