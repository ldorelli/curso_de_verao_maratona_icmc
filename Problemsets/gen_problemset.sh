if [ -z "$1" ]; then
	echo "Insira o nome do problemset!"
	exit 2	
fi

mkdir $1

for line in $(cat config) 
do
	pset=$1/$line.html
	touch $pset
	echo "<html>" >> $pset 
	echo "<head><style>" >> $pset
	style=$(<../Problemas/TEMPLATE/problemas.css)
	echo "$style" >> $pset
	echo "</head></style>" >> $pset
	echo "<body>" >> $pset

	for problem in $(ls ../Problemas/$line | grep .html)
	do	
		value=$(<../Problemas/$line/$problem)		
		echo "$value" >> $pset
	done

	for img in $(ls ../Problemas/$line | grep 'png\|jpg')
	do
		cp ../Problemas/$line/$img $1
	done
	
	echo "</body>" >> $pset
	echo "</html>" >> $pset
done

