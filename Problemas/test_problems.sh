red='\033[0;31m'
green='\033[0;32m'
blue='\033[0;34m'
NC='\033[0m' # No Color

for path in $(ls -d */)
do
	if [ "$path" != "TEMPLATE/" ] 
	then
		echo "======================================"
		echo "PROBLEM: " $path
		echo "======================================"
		for code in $(ls $path | grep .cpp)
		do
			if [ "$code" != "gen.cpp" ]; then
				pname_lo=$(echo "$path" | tr '[:upper:]' '[:lower:]')
				pname_lo=${pname_lo%/}
				
				# COMPILING
				echo -e $blue "Compiling " $pname_lo $NC
	
				g++ $path$code -O2 -o $path/a.out 2> errlog
				gout=$(cat errlog)
				# if G++ shows errors 
				if [ ! -z "$gout" ]; then
					echo -e $red "Trouble Compiling " $pname_lo :
					echo $gout $NC
				else 
					echo -e $green "=== Compilation OK ===" $NC
				fi
				rm errlog


				# RUNNING
				echo -e $blue "Running Tests" $NC
				run_res=$($path/a.out < $path$pname_lo.in > $path/out)
				# if could not run
				if [ ! -z $run_res ]; then 
					echo -e $red "Trouble running " $pname_lo :
					echo $run_res $NC
				else
					echo -e $green "=== Running OK ===" $NC
				fi	
				
				
				# COMPARING
				echo -e $blue "Running Diff" $NC
				diff_res=$(diff "$path"out $path$pname_lo.out)
				if [ ! -z $diff_res ]; then
					echo -e $red "Something went wrong with problem " $pname_lo 
					echo $red "Please check it out." $NC
				else 
					echo -e $green "=== Diff OK ===" $NC
				fi 
	
				rm "$path"a.out	
				rm "$path"out
			fi
		done
	fi
done
