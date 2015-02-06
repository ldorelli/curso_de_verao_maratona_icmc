if [ -n "$1" ]; then
	echo "Entre com uma mensagem de commit"
	exit 2
fi

./encrypt_all.sh
git add .
git commit -m "$1"
git push
