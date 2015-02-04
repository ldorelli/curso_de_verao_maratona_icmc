red='\033[0;31m'
green='\033[0;32m'
NC='\033[0m' # No Color

for path in $(ls -d */)
do
	if [ "$path" != "TEMPLATE/" ] 
	then
		echo "Analyzing " $path
		for code in $(ls $path | grep .cpp)
		do
			if [ "$code" != "gen.cpp" ]; then
				echo "Compiling " $path$code
	
				g++ $path$code -O2 -o $path/a.out
				pname_lo=$(echo "$path" | tr '[:upper:]' '[:lower:]')
				pname_lo=${pname_lo%/}
				$path/a.out < $path$pname_lo.in > $path/out
				diff_res=$(diff "$path"out $path$pname_lo.out)
				
				if [ ! -z $diff_res ]; then
					echo -e $red "Something went wrong with problem " $pname_lo 
					echo $red "Please check it out." $NC
				else 
					echo -e $green "Tests match" $NC
				fi 
				rm "$path"a.out	
				rm "$path"out
			fi
		done
	fi
done
