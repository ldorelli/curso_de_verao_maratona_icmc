pname=$1
pname_lo=$(echo "$pname" | tr '[:upper:]' '[:lower:]')
cp TEMPLATE/template.html $1/$pname_lo.html
touch $1/Summary
touch $1/Tags
 
